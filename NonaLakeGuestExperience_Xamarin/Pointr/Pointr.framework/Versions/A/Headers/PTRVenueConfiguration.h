//
//  PTRVenueConfiguration.h
//  Pods
//
//  Created by Ege AKPINAR on 28/05/2017.
//
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"


NS_ASSUME_NONNULL_BEGIN

@interface PTRVenueConfiguration : PTRConfigurationInterface

/**
 * Numeric internal (Pointr) identifier of venue
 */
@property (nonatomic, assign) int internalIdentifier;

/**
 * External (customer) identifier of venue
 */
@property (nonatomic, retain) NSString *externalIdentifier;

/**
 *  Name of venue, used in welcome message.
 */
@property (nonatomic, strong) NSString *name;

/**
 *  Type / Brand of beacon used
 */
@property (nonatomic, strong) NSString *beaconType;

@end

NS_ASSUME_NONNULL_END
