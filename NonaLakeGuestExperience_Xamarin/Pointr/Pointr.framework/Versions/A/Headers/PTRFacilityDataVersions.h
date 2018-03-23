//
//  PTRFacilityDataVersions.h
//  Pointr
//
//  Created by Ege AKPINAR on 09/03/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Map
#import "PTRMapVersion.h"

#define INVALID_VERSION -1

extern NSString *const kPTRKeyDataVersionsFacilityVersions;
extern NSString *const kPTRKeyDataVersionsConfigurationVersion;
extern NSString *const kPTRKeyDataVersionsBeaconVersion;
extern NSString *const kPTRKeyDataVersionsPoiVersion;
extern NSString *const kPTRKeyDataVersionsGraphVersion;
extern NSString *const kPTRKeyDataVersionsWallVersion;
extern NSString *const kPTRKeyDataVersionsMapVersions;  // NOTE- Also used in PTRVenueDataVersions
@interface PTRFacilityDataVersions : NSObject

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 * ID of facility to which this configuration belongs
 */
@property (nonatomic, assign) int facilityId;

/**
 * Version for facility configuration
 */
@property (nonatomic, assign) float configurationVersion;

/**
 * Version for facility Beacon content
 */
@property (nonatomic, assign) float beaconVersion;

/**
 * Version for facility Poi content
 */
@property (nonatomic, assign) float poiVersion;

/**
 * Version for facility graph content
 */
@property (nonatomic, assign) float graphVersion;

/**
 * Version for facility wall content
 */
@property (nonatomic, assign) float wallVersion;

/**
 * Versions for facility maps, mapped by level -> MapVersion object
 */
@property (nonatomic, strong) NSDictionary<NSNumber *, PTRMapVersion *> *mapVersions;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithConfigurationVersion:(float)configurationVersion
                               beaconVersion:(float)beaconVersion
                                  poiVersion:(float)poiVersion
                                graphVersion:(float)graphVersion
                                 wallVersion:(float)wallVersion
                                 mapVersions:(NSDictionary<NSNumber *, PTRMapVersion *> *)mapVersions
                                  facilityId:(int)facilityId;
@end
