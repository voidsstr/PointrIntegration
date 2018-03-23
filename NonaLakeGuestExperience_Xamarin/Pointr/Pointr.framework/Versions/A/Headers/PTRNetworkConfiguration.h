//
//  PTRNetworkConfiguration.h
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

@interface PTRNetworkConfiguration : PTRConfigurationInterface

@property (nonatomic, assign) int cacheDataLimit;
/**
 Lower limit value for network queue
 */
@property (nonatomic, assign) int lowerThreshold;

/**
 Delay to be applied to network coodinator queue run cycle
 */
@property (nonatomic, assign) float networkQueueCycleIntervalInSeconds;

/**
 Upper limit value for network queue
 */
@property (nonatomic, assign) int upperThreshold;

@end

NS_ASSUME_NONNULL_END
