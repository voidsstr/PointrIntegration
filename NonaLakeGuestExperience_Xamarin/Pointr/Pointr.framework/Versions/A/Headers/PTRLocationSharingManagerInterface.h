//
//  PTRLocationSharingManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declare dependencies
@protocol PTRConfigurationManagerDelegate;

/**
 *  LocationSharingManagerDelegate keeps track of locations
 */
@protocol PTRLocationSharingManagerDelegate <NSObject>

@required

/**
 *  Notifies when shared locations are updated.
 *
 *  @param devices Dictionary of devices of other shared locations
 */
- (void)onLocationSharingManagerDeviceLocationsUpdated:(NSDictionary *)devices;

@end

/**
 * Main manager class responsible for location upload and sharing.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRLocationSharingManagerInterface
    : PTRPointrManagerInterface <id<PTRLocationSharingManagerDelegate>> <PTRConfigurationManagerDelegate>
#pragma clang diagnostic pop

@end

NS_ASSUME_NONNULL_END
