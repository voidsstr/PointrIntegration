//
//  PTRConfigurationInterface.h
//  Pointr
//
//  Created by Pointr on 20/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Common interface for all configuration files
 */
@interface PTRConfigurationInterface : NSObject <NSCoding>

/**
 * Initialises object with default values
 */
- (instancetype)init;

/**
 * Initialises object with given values in the dictionary (and uses default values for others)
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 * Overrides existing configuration file with dictionary values
 * Doesn't change values that are not present in given dictionary
 */
- (instancetype)updateWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isEqual:(PTRConfigurationInterface *)object;

@end

NS_ASSUME_NONNULL_END
