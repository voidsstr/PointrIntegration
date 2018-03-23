//
//  PTRGeofenceManagerConfiguration.h
//  Pointr
//
//  Created by Pointr Labs on 17/04/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Notificaiton and geofence enter exit related configuration items.
 */
@interface PTRGeofenceManagerConfiguration : PTRConfigurationInterface

/**
 *  Indicates if geofencing is enabled.
 */
@property (nonatomic, assign) BOOL isEnabled;

/**
 *  Number of seconds before library assumes the user exited the refion
 */
@property (nonatomic, assign) double regionTimeoutInterval;

/**
 *  Relative endpoint to which enter/exit notify requests are sent to.
 */
@property (nonatomic, retain) NSString *notifyApi;

/**
 *  Message string for push message on enter.
 */
@property (nonatomic, retain) NSString *welcomePushMessage;

/**
 *  Message string for push message on exit.
 */
@property (nonatomic, retain) NSString *exitPushMessage;

/**
 *  YES if Push messages will be used.
 */
@property (nonatomic, assign) BOOL shouldNotifyWithPushMessage;

/**
 *  TODO - Create comment.
 */
@property (nonatomic, assign) BOOL shouldNotifyServer;

/**
 *  TODO - Create comment.
 */
@property (nonatomic, assign) BOOL shouldNotifyEnterExit;

/**
 *  YES if SDK should switch facility, upon detecting entry, automatically. NO otherwise.
 *  YES by default.
 */
@property (nonatomic, assign) BOOL isAutomaticFacilitySwitchEnabled;

@end

NS_ASSUME_NONNULL_END
