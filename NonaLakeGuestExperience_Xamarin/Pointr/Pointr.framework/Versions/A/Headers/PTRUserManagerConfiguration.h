//
//  PTRUserManagerConfiguration.h
//  Pointr
//
//  Created by Pointr Labs on 20/01/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  User related configurations.
 */
@interface PTRUserManagerConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 Relative path for device registration end point.
 */
@property (nonatomic, retain) NSString *registerDeviceApi;

/**
 Relative path for user registration end point.
 */
@property (nonatomic, retain) NSString *registerUserForDeviceApi;

/**
 Relative path for user logout end point.
 */
@property (nonatomic, retain) NSString *logoutApi;

/**
 Relative path for push registration en point.
 */
@property (nonatomic, retain) NSString *registerDeviceForPushTokenApi;

/**
 Relative path for push un-registering
 */
@property (nonatomic, retain) NSString *unregisterDeviceForPushTokenApi;

/**
 YES if login requires password. NO by default.
 */
@property (nonatomic, assign) BOOL isPasswordRequired;

@end

NS_ASSUME_NONNULL_END
