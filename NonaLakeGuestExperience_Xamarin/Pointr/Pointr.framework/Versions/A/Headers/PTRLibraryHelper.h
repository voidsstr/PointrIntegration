//
//  PTRHelper.h
//  Pointr
//
//  Created by Pointr Labs on 24/12/2015.
//  Copyright © 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRLibraryHelper : NSObject

extern void PTRDispatchAsyncOnMainQueue(void (^block)(void));
extern void PTRDispatchSyncOnMainQueue(void (^block)(void));

/**
 Returns YES if device has poor CPU/memory. NO otherwise.
 This flag is used to determine whether low memory mode should be activated.
 */
+ (BOOL)isOldDevice;

/////////////////////////////////////////////////////////////////////////
#pragma mark - String helpers
/////////////////////////////////////////////////////////////////////////

/**
 *  Return search-friendly version of given string, lowercase and without accents (eg. è -> e)
 *  Used to create search tokens mainly
 */
+ (NSString *_Nullable)searchFriendlyString:(NSString *)str;

+ (NSString *)stringForLevel:(int)level;

/**
 *  Strips string of any character other than alphabetic (eg. numbers, spaces, symbols)
 *  Converts accents also (eg. é -> e)
 *  Used to match string from Pointr Cloud mainly
 */
+ (NSString *)alphabetOnlyLowercaseStringFromString:(NSString *)string;

/**
 Finds angle between two points

 @param x1 x for 1st point
 @param y1 y for 1st point
 @param x2 x for 2nd point
 @param y2 y for 2nd point
 @return the angle of vector (x2,y2) -> (x1,y1) in radians,
         in coordinate system: (0,0) top-left, (1,1) bottom-right; angle 0 north, increasing clockwise
 */
+ (float)findAngleBetweenTwoPointsWithX1:(float)x1 y1:(float)y1 x2:(float)x2 y2:(float)y2;

/**
 Helper method for [[UIApplication sharedApplication] applicationState]
 Returns UIApplicationState of app but no need to use main thread
 Used in internal callbacks which may not be in main thread
 */
+ (UIApplicationState)applicationState;

@end

NS_ASSUME_NONNULL_END
