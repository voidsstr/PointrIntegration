//
//  PTRFacilityConfiguration.h
//  Pointr
//
//  Created by Pointr on 04/10/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

#define INVALID_WIDTH -1
#define INVALID_HEIGHT -1
#define INVALID_ZOOM 0.0

NS_ASSUME_NONNULL_BEGIN

@interface PTRFacilityConfiguration : PTRConfigurationInterface

/**
 * Numeric internal (Pointr) identifier of facility
 */
@property (nonatomic, assign) int internalIdentifier;

/**
 * External (customer) identifier of facility
 */
@property (nonatomic, retain) NSString *externalIdentifier;

/**
 *  Name of facility, used in welcome message.
 */
@property (nonatomic, strong) NSString *name;

/**
 *  Real life width of the map area.[Default 100.0]
 */
@property (nonatomic, assign) float mapWidthMeters;

/**
 *  Real life height of the map area.[Default 100.0]
 */
@property (nonatomic, assign) float mapHeightMeters;

/**
 *  Map's lowest level.
 */
@property (nonatomic, assign) int mapMinLevel;

/**
 *  Map's highest level.
 */
@property (nonatomic, assign) int mapMaxLevel;

/**
 *  Heading offset for the pin heading.[Default INVALID_ROTATION]
 */
@property (nonatomic, assign) float headingOffset;

/**
 *  YES if configuration is valid (with valid height, width and min/max levels).
 *  NO otherwise.
 *  NOTE- It is possible to initialise an invalid facility configuration with facilityId only.
 */
@property (nonatomic, readonly) BOOL isValid;

@end

NS_ASSUME_NONNULL_END
