//
//  PTRPositionManager.h
//  Pointr
//
//  Created by Pointr Labs on 11/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "CoreMotion/CoreMotion.h"

// Management
#import "PTRPointrManagerInterface.h"

#import "PTRPositioningTypes.h"
#import "PTRCalculatedLocation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  PositionManagerDelegate keeps track of position related changes and callbacks
 */
@protocol PTRPositionManagerDelegate <NSObject>

@optional
/**
 *  Notifies listeners when a new location is calculated.
 *
 *  @warning This callback will only be fired if a valid location can be calculated.
 *
 *  @param calculatedLocation New location of the user.
 */
- (void)onPositionManagerCalculatedLocation:(PTRCalculatedLocation *)calculatedLocation;

/**
 *  Notifies listeners on service state changes
 *
 *  @param state New state of the positioning service.
 */
- (void)onPositionManagerPositioningServiceStateChangedTo:(PTRPositioningServiceState)state;

/**
 *  Notifies listeners on level change
 *
 *  @param level New level.
 */
- (void)onPositionManagerDetectedPositionLevelChange:(int)level;

/**
 *  Notifies listeners on position is fading after specified threshold.
 */
- (void)onPositionManagerPositionIsFading;

/**
 *  Notifies listeners on position is lost after specified threshoild.
 */
- (void)onPositionManagerPositionIsLost;

@end

/**
 * Main interface for all positioning functionality
 */
@interface PTRPositionManagerInterface : NSObject

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Last calculated valid position of the user.
 */
@property (nonatomic, readonly) PTRCalculatedLocation *lastValidCalculatedLocation;
/**
 * Current position of the user
 */
@property (nonatomic, readonly) PTRCalculatedLocation *currentCalculatedLocation;

/**
 *  Current positioning service state.
 */
@property (nonatomic, readonly) PTRPositioningServiceState serviceState;

/**
 *  3D-orientation cache (computed by CoreMotion)
 */
@property (nonatomic, readonly) CMAttitude *attitude;

/**
 * Starts manager, setting up all necessary subscriptions
 */
- (void)start;

/**
 * Stops manager, tearing down all subscriptions
 */
- (void)stop;

/**
 * Adds listener to start receiving callbacks
 */
- (void)addListener:(id<PTRPositionManagerDelegate>)listenerToAdd;

/**
 * Removes listener to stop receiving callbacks
 */
- (void)removeListener:(id<PTRPositionManagerDelegate>)listenerToRemove;

@end

NS_ASSUME_NONNULL_END
