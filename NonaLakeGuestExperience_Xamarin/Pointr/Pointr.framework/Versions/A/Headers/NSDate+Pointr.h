//
//  NSDate+Pointr.h
//  Gatwick
//
//  Created by Pointr Labs on 24/09/2015.
//  Copyright © 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

@interface NSDate (Pointr)

/**
 Our server (MS environment) uses ticks since 0/0/0
 This method uses ticks coming from server to create a Cocoa friendly NSDate
 */
- (instancetype)_initWithTicksSinceDawn:(long)ticks;

+ (long)epochTimestampInSeconds;
+ (double)epochTimestampInMillisecods;

@end
