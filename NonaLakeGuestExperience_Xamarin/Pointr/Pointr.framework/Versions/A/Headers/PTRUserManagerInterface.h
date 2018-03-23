//
//  PTRUserManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//
#import "PTRApiResponse.h"

// Management
#import "PTRPointrManagerInterface.h"
#import "PTRUserSession.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  UserManagerDelegate keeps track of user session, login and logout.
 */
@protocol PTRUserManagerDelegate <NSObject>

@optional

/**
 *  This function is called when current user session is updated (eg. log out, log in)
 */
- (void)onUserManagerSessionUpdatedTo:(PTRUserSession *)newSession;

/**
 *  This callback gets called when preferred user language is changed
 */
- (void)onUserManagerPreferredLanguageUpdatedTo:(NSString *)newLangCode;

@end

/**
 *  Main class responsible for user sessions, registration and login.
 */
@interface PTRUserManagerInterface : PTRPointrManagerInterface <id<PTRUserManagerDelegate>>

/////////////////////////////////////////////////////////////////////////
#pragma mark - API methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Registers the device with anonymous user. (Works with no knowledge of user.)
 *
 *  @param callback Asynchronous block which will be returned along with server response regarding device registration.
 */
- (void)registerDeviceWithCallback:(void (^)(PTRApiResponse *))callback;

/**
 *  Logs out current user and resets user session accordingly.
 *
 *  @param callback Asynchrnous block which will be returned along with server response regarding logout.
 */
- (void)logoutWithCallback:(void (^)(PTRApiResponse *))callback;

/**
 *  Sets preferred language for current user.
 *  This allows content to have relevant translation if available. If not, content is returned in default language.
 *  SDK will remember user's preferred language until it's set to another language or reset.
 *
 *  @warn This is stored on device only. Pointr Cloud will not know user's preference.
 *  @warn This method may only be called when there is an active user session. Otherwise it will have no effect.
 *  @param languageCode ISO language code (eg. "en", "jp").
 *  Passing in nil will reset user preference to default.
 */
- (void)setPreferredLanguage:(NSString *_Nullable)languageCode;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Returns current user session (if any) or nil
 */
@property (nonatomic, readonly) PTRUserSession *currentUserSession;

@end

NS_ASSUME_NONNULL_END
