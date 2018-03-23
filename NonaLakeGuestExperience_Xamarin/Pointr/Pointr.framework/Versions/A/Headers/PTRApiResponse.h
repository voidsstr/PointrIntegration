//
//  PTRApiResponse.h
//  Pointr
//
//  Created by Pointr Labs on 19/01/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Main response object that will be received from all the Network related requests.
 */
@interface PTRApiResponse : NSObject

/**
 *  Status code as returned from Pointr Cloud. -1 if invalid.
 */
@property (nonatomic, assign) int statusCode;  //

/**
 *  Optional (typically NSArray or NSDictionary or NSData)
 */
@property (nonatomic, retain, nullable) NSObject *body;

/**
 *  Human friendly error mesages (optional).
 */
@property (nonatomic, retain) NSString *errorMessage;  //

/**
 *  For debugging only (optional).
 */
@property (nonatomic, retain) NSString *debugErrorMessage;  //

/**
 *  String Json data for C++ parsing.
 */

@property (nonatomic, retain) NSString *strData;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Default initialiser to create a response object.
 *
 *  @param dictionary The dictionary received from server as JSON.
 *
 *  @return A PTRResponse object parsed from dictionary, or nil.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 *  Default initialiser to create an error response manually.
 *
 *  @param errorMessage      String representing the error issue
 *  @param debugErrorMessage A more technical description of the error.
 *
 *  @return A PTRResponse object, or nil.
 */
- (instancetype)initWithErrorMessage:(NSString *)errorMessage andDebugErrorMessage:(NSString *)debugErrorMessage;

/**
 *  A convenience method to check if the received response has been successful.
 *
 *  @return YES if request is successful, NO otherwise.
 */
- (BOOL)isSuccessful;

/**
 *  Used to check if at any point within the program the server returns 401
 *  This means the authentication has failed.
 *
 *  @return YES if authentication is require, NO otherwise.
 */
- (BOOL)authenticationFailed;

@end

NS_ASSUME_NONNULL_END
