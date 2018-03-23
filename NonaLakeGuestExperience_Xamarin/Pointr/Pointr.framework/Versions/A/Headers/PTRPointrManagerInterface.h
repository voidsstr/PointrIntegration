//
//  PTRPointrManagerInterface.h
//  Pointr
//
//  Created by Pointr on 17/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Generic
#import "PTRAdvertiser.h"
#import "PTROwnQueueProtocol.h"
#import "PTRSingletonProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Common interface implemented by all Pointr managers
 */
@interface PTRPointrManagerInterface <T> : PTRAdvertiser<T> <PTROwnQueueProtocol, PTRSingletonProtocol>

/**
 * Starts manager, setting up all necessary subscriptions
 */
- (void)start;

/**
 * Stops manager, tearing down all subscriptions
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
