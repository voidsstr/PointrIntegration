//
//  PTRConfigurationManagerInterface.h
//  Pointr
//
//  Created by Pointr on 17/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Configuration
#import "PTRCoreConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

// Forward declare dependencies
@protocol PTRGeofenceManagerDelegate;
@protocol PTRDataManagerDelegate;

@protocol PTRConfigurationManagerDelegate <NSObject>

@required

/**
 * Called when current configuration is updated
 */
- (void)onConfigurationManagerUpdate;

@optional

/**
 * Called when configuration fails to update
 */
- (void)onConfigurationManagerUpdateFail;

@end

#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRConfigurationManagerInterface : PTRPointrManagerInterface <id<PTRConfigurationManagerDelegate>>
                                              <PTRGeofenceManagerDelegate, PTRDataManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 * Returns currently set configuration
 * Returns nil if no configuration is set (unlikely)
 */
- (PTRCoreConfiguration *_Nullable)getCurrentConfiguration;

/**
 * Switches from current configuration to specified facility's configuration
 * Triggers data downloads as necessary
 */
- (void)switchConfigurationToFacility:(int)facilityId;

/**
 * Switches from current configuration to specified facility's configuration
 * Triggers data downloads as necessary
 */
- (void)switchConfigurationToFacilityString:(NSString *)facilityIdString;

/**
 *  Returns configuration for specified facility, from device storage
 *
 *  @param facilityId internal identifier for facility
 *  @return PTRCoreConfiguration object for facility (or nil if none stored on device)
 */
- (PTRCoreConfiguration *_Nullable)getConfigurationForFacility:(int)facilityId;

/**
 *  Checks if currently configured facility matches user's actual facility (physically)
 *  @return NO if it current facility is certainly different, YES if they are or may be the same
 */
- (BOOL)getIsConfiguredToPhysicalFacility;

@end

NS_ASSUME_NONNULL_END
