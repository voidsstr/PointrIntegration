//
//  PTRUserSession.h
//  Pointr
//
//  Created by Pointr Labs on 19/01/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRSingletonProtocol.h"

#import "PTRSingletonProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRUserSession : NSObject <NSCoding>

@property (nonatomic, readonly) NSString *_Nullable authenticationToken;
@property (nonatomic, readonly) NSString *_Nullable username;
@property (nonatomic, readonly) NSString *_Nullable deviceIdentifier;

/**
 *  Preferred language for this user session (if any)
 *  ISO language code with or without locale are supported (eg. "en", "jp", "en_US"", "en_UK")
 */
@property (nonatomic, strong) NSString *_Nullable preferredLanguage;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Default constructor
 *  @param authenticationToken unique session token provided by Pointr Cloud
 *  @param deviceIdentifier SDK specific unique identifier for this device
 */
- (instancetype)initWithAuthenticationToken:(NSString *)authenticationToken
                           deviceIdentifier:(NSString *)deviceIdentifier;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Default methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Standard comparator
 */
- (BOOL)isEqual:(PTRUserSession *_Nullable)otherSession;

@end

NS_ASSUME_NONNULL_END
