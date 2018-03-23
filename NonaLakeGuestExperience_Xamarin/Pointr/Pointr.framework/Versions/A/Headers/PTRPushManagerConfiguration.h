//
//  PTRPushManagerConfiguration.h
//  Pointr
//
//  Created by Pointr on 04/10/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRPushManagerConfiguration : PTRConfigurationInterface

/**
 *  YES if push permission should be requested.[Default True]
 */
@property (nonatomic, assign) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
