//
//  PTRPathManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Pathfinding
#import "PTRPath.h"
#import "PTRPositioningTypes.h"
#import "PTRGraphNode.h"
#import "PTRPoiContainer.h"

NS_ASSUME_NONNULL_BEGIN

/* Pathfinding types determining the working algorithm of path finding.*/
typedef NS_ENUM(int, PTRPathfindingMode) {
    /*Default mode : Shortest path available*/
    PTRPathfindingModeNormal,
    /* May use some steps and may not be the shortest available path but relatively comfortable path for families and
       elderly. */
    PTRPathfindingModeEasy,
    /* Does not include any steps in paths. It is the most comfortable path for people with having difficulty with
       walking.*/
    PTRPathfindingModeAccessible
};

/**
 *  Callback type for Path suggestion.
 *
 *  @param shouldTakeSuggestion The asynchronous block that includes user response to suggested path.
 */
typedef void (^PTRPathManagerSuggestionCallback)(BOOL shouldTakeSuggestion);

/**
 *  PathManagerDelegate keeps track of arrivals and path suggestions
 */
@protocol PTRPathManagerDelegate <NSObject>

@optional

/**
 *  Notifies when path manager finds a better alternative to current path, for the same Poi group
 *
 *  @param callback An asynchronous block with type PTRPathManagerSuggestionCallback
 *  @warning This should be handled once, even if there are multiple listeners. If callback is called multiple times for
 * same path, result is unreliable.
 */
- (void)onPathManagerHasSmartSuggestion:(PTRPathManagerSuggestionCallback _Nonnull)callback;

/**
 *  Notifies when user arrived at the currently designated destination.
 */
- (void)onPathManagerHasArrivedAtDestination;

/**
 * Notifies when path manager calculates a new path.
 * @param path Calculated path. Can be nil if the path calculations conditions are not met.
 */
- (void)onPathManagerHasCalculatedPath:(PTRPath *_Nullable)path;

/**
 * Notifies when path manager has failed to calculate a path.
 * @param errorMsg The error message indicating why path calculation failed.
 */
- (void)onPathManagerPathCalculationFailedWithErrorMessage:(NSString *_Nullable)errorMsg;

/**
 *  Notifies when path calculation is aborted.
 */
- (void)onPathManagerPathCalculationAborted;

/**
 * Notifies when path calculation is started.
 */
- (void)onPathManagerStartedPathFindingTo:(PTRPoiContainer *)poiSelection;

@end

/**
 * Main interface for all pathfinding functionality
 */
@interface PTRPathManagerInterface : NSObject

/////////////////////////////////////////////////////////////////////////
#pragma mark - Manager methods
/////////////////////////////////////////////////////////////////////////

/**
 * Starts manager, setting up all necessary subscriptions
 */
- (void)start;

/**
 * Stops manager, tearing down all subscriptions
 */
- (void)stop;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Path calculation
/////////////////////////////////////////////////////////////////////////

/**
 * Starts pathfinding, should be called after POI selection.
 */
- (void)startPathfinding;

/**
 * Aborts pathfinding, resetting existing path
 */
- (void)abortPathfinding;

/**
 * Sets pathfinding mode
 */
- (void)setCurrentMode:(PTRPathfindingMode)newMode;

/**
 * Flag to check if pathfinding is currently active
 */
- (BOOL)isPathFindingStarted;

/**
 *  Calculates path from user's last calculated position to user's last selected Poi/PoiGroup
 *
 *  @return A PTRPath object leading a path to the selected POI
 *  @warning User Poi/PoiGroup selection must be recorded through PoiManager
 */
- (PTRPath *_Nullable)calculatePath;

/**
 *  Calculates path between specified positions
 *  Clever enough to re-calculate path only when user deviates from existing path (configurable)
 *
 *  @param source      Initial location for the path
 *  @param destination Destination location for the path
 *
 *  @return A PTRPath object leading a path to the selected POI
 */
- (PTRPath *_Nullable)calculatePathFromLocation:(PTRLocation *)source toLocation:(PTRLocation *)destination;

/**
 *  Calculates path to the closest positioned POI from the given array of POI Positions
 *
 *  @param source       Initial location for the path
 *  @param destinations A position array of POI position of the selected PoiGroup.
 *
 *  @return A PTRPath object leading a path to the closest Poi within PoiGroup
 */
- (PTRPath *_Nullable)calculatePathFromLocation:(PTRLocation *)source
                     toNearestPositionFromArray:(NSArray<PTRLocation *> *)destinations;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Advertisement methods
/////////////////////////////////////////////////////////////////////////

/**
 * Adds listener to start receiving callbacks
 */
- (void)addListener:(id<PTRPathManagerDelegate>)listenerToAdd;

/**
 * Removes listener to stop receiving callbacks
 */
- (void)removeListener:(id<PTRPathManagerDelegate>)listenerToRemove;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Helper methods
/////////////////////////////////////////////////////////////////////////

- (float)calculateActualDistanceBetweenLocation:(PTRLocation *)first andLocation:(PTRLocation *)second;

- (PTRTravelEstimation *)calculateTravelEstimationBetweenNode:(PTRNodeInterface *)node1
                                                      andNode:(PTRNodeInterface *)node2;

- (PTRTravelEstimation *)calculateTravelEstimationForPath:(PTRPath *)path untilNode:(PTRNodeInterface *)endNode;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Debugging methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Returns array of all graph nodes (as PTRGraphNode objects)
 *  @warn Used for debugging only
 */
- (NSDictionary<NSString *, PTRNodeInterface *> *)getAllGraphNodes;

@end

NS_ASSUME_NONNULL_END
