//
//  PTRGeofenceManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Management
#import "PTRPointrManagerInterface.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, PTRGeofencingState) {
    PTRGeofencingStateUnknown,  // Unknown (DEFAULT)
    PTRGeofencingStateIn,       // Inside region
    PTRGeofencingStateOut,      // Outside region
};

/**
 *  PTRGeofenceManager is responsible for users region enters and exits.
 */
@protocol PTRGeofenceManagerDelegate <NSObject>

@optional

/**
 *  Notifies listeners when a region is entered.
 *
 *  @param facilityId The facility which entered by the user.
 */
- (void)onGeofenceManagerDidEnterFacility:(int)facilityId;

/**
 *  Notifies listeners when a region is exited.
 *
 *  @param facilityId The facility which exited by the user.
 */
- (void)onGeofenceManagerDidExitFacility:(int)facilityId;

@end

/**
 *  Main manager class responsible for location related triggers (enter, exit)
 */
@interface PTRGeofenceManagerInterface : PTRPointrManagerInterface <id<PTRGeofenceManagerDelegate>>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

// TODO- Position.facilityId can replace currentFacility in most places
/**
 * Returns Id of currently detected facility
 * Returns INVALID_FACILITY if none detected
 */
@property (nonatomic, readonly) int currentFacility;

/**
 * Returns user's current venue/facility geofencing state (in, out or unknown)
 * Returns PTRGeofencingStateUnknown if state is not determined
 */
@property (nonatomic, readonly) PTRGeofencingState currentState;

@end

NS_ASSUME_NONNULL_END
