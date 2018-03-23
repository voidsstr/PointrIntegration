//
//  NSString+Pointr.h
//  Pointr
//
//  Creatd by Pointr on 15/04/2015.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

@interface NSString (Pointr)

/**
 Crash-safe version of substringFromIndex:
 */
- (NSString *)_safeSubstringFromIndex:(NSUInteger)from;

/**
 Crash-safe version of substringToIndex:
 */
- (NSString *)_safeSubstringToIndex:(NSUInteger)to;

/**
 Crash-safe version of substringWithRange:
 */
- (NSString *)_safeSubstringWithRange:(NSRange)range;

/**
 String comparison, ignoring case
 */
- (BOOL)_isEqualToStringIgnoringCase:(NSString *)str;

/**
 *  String trimmed from whitespace
 */
- (NSString *)_trimmedString;

/**
 *  Returns YES if string consists of numbers only, NO otherwise
 */
- (BOOL)_isNumeric;

@end
