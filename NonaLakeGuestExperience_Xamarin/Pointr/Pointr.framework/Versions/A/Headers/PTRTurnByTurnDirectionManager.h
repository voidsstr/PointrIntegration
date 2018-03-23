//
//  PTRTurnByTurnDirectionManager.h
//  Pointr
//
//  Created by Pointr Labs on 17/09/2015.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

#import "PTRSingletonProtocol.h"
// Pathfinding
#import "PTRPath.h"
#import "PTRPositioningTypes.h"
#import "PTRCalculatedLocation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Using nodes from an PTRPath object, adds turn-by-turn text directions (e.g. "Go forward for 50 metres")
 *  These can then be shown to user as text or audio feedback
 */
@interface PTRTurnByTurnDirectionManager : NSObject <PTRSingletonProtocol>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Adds new directions for specified path.
 *
 *  @param path The path which has the directions.
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)addDirectionsForPath:(PTRPath *_Nullable)path;

/**
 *  Updates directions of given path, removing directions that are already passed
 *
 *  @param path The path which has the directions.
 *
 *  @return YES if successful, NO otherwise
 */
- (BOOL)updateDirectionsForPath:(PTRPath *_Nullable)path;

/**
 * Updates current location of the turn by turn direction manager.
 * @param location Latest location
 */
- (void)updateLocation:(PTRCalculatedLocation *)location;

@end

NS_ASSUME_NONNULL_END
