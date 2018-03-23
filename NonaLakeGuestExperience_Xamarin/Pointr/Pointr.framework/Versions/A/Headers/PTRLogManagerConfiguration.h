//
//  PTRLogManagerConfiguration.h
//  Pointr
//
//  Created by Pointr on 04/10/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

// Logging
#import "PTRLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRLogManagerConfiguration : PTRConfigurationInterface

/**
 * Level of the console logs that will be shown.
 */
@property (nonatomic, assign) PTRLoggerLevel loggerLevel;

@end

NS_ASSUME_NONNULL_END
