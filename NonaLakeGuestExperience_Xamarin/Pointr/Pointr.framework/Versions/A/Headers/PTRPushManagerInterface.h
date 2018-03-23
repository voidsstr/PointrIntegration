//
//  PTRPushManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Network
#import "PTRApiResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Main manager class responsible for push related registration and handling.
 */
@interface PTRPushManagerInterface : PTRPointrManagerInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 Currently we are not including this into our SDK. When the time comes just uncomment the definitions.
 */

//- (void)enablePushRegistration;
//
//- (void)disblePushRegistration;
//
//- (BOOL)pushIsEnabled;

/**
 *  Parses the received push information in order to create a presentable notification.
 *
 *  @param userInfo Information received regarding push as a dictionary.
 *
 *  @return A value indicating whether the notification handled properly(true) or not(false).
 */
- (BOOL)handleNotificationWithUserInfo:(NSDictionary *)userInfo;

/**
 *  Registers the device into Pointr Database with the required user and device information.
 *
 *  @param deviceToken Unique ID of the device to register for push.
 *  @param callback    Asynchronous callback block with the server response.
 */
- (void)registerPushToken:(NSData *)deviceToken withCallback:(void (^)(PTRApiResponse *))callback;

/**
 Un-Registers user from Pointr related notifications and callback.

 @param callback Response callback returned from server.
 */
- (void)unregisterUserFromPushwithCallback:(void (^)(PTRApiResponse *))callback;

/**
 *  Must be called to register app for push. This will prompt user with 'App wants to send you notifications' dialogue.
 *  @warning This is called internally. Do not call.
 */
- (void)registerAppForPush;

/**
 *  Plays system sound (only if app is in foreground).
 *
 *  @param inSystemSoundId ID of system sound to be played. Defaults to regular push notification sound if negative
 * value given.
 */
- (void)playSoundForPush:(int)inSystemSoundId;

/**
 *  Sets the badge number representing the number of notifications.
 *
 *  @param badgeNumber Number within the badge to be shown on the application.
 */
- (void)setNotificationBadgeToValue:(int)badgeNumber;

@end

NS_ASSUME_NONNULL_END
