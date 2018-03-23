//
//  PTRCoreConfiguration.h
//  Level11
//
//  Creatd by Pointr on 15/01/15.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Framework
#import "UIKit/UIKit.h"

// Config
#import "PTRSdkConfiguration.h"
#import "PTRDataManagerConfiguration.h"
#import "PTRPoiManagerConfiguration.h"
#import "PTRUserManagerConfiguration.h"
#import "PTRGeofenceManagerConfiguration.h"
#import "PTRPositionManagerConfiguration.h"
#import "PTRLocationSharingConfiguration.h"
#import "PTRUserInterfaceConfiguration.h"
#import "PTRPathManagerConfiguration.h"
#import "PTRNetworkConfiguration.h"
#import "PTRFacilityConfiguration.h"
#import "PTRVenueConfiguration.h"
#import "PTRLogManagerConfiguration.h"
#import "PTRPushManagerConfiguration.h"
#import "PTRSimulationConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/*
        TODO : Addd documentation to all configuration files.
 */
@interface PTRCoreConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Properties
/////////////////////////////////////////////////////////////////////////

@property (nonatomic, strong) PTRSdkConfiguration *sdkConfiguration;
@property (nonatomic, strong) PTRDataManagerConfiguration *dataManagerConfiguration;
@property (nonatomic, strong) PTRFacilityConfiguration *facilityConfiguration;
@property (nonatomic, strong) PTRVenueConfiguration *venueConfiguration;
@property (nonatomic, strong) PTRGeofenceManagerConfiguration *geofenceManagerConfiguration;
@property (nonatomic, strong) PTRLocationSharingConfiguration *locationSharingConfiguration;
@property (nonatomic, strong) PTRLogManagerConfiguration *logManagerConfiguration;
@property (nonatomic, strong) PTRNetworkConfiguration *networkConfiguration;
@property (nonatomic, strong) PTRPathManagerConfiguration *pathManagerConfiguration;
@property (nonatomic, strong) PTRPoiManagerConfiguration *poiManagerConfiguration;
@property (nonatomic, strong) PTRPositionManagerConfiguration *positionManagerConfiguration;
@property (nonatomic, strong) PTRUserManagerConfiguration *userManagerConfiguration;
@property (nonatomic, strong) PTRUserInterfaceConfiguration *userInterfaceConfiguration;
@property (nonatomic, strong) PTRPushManagerConfiguration *pushManagerConfiguration;

/**
 *  Simulation configuration (eg. Bluetooth event simulation)
 */
@property (nonatomic, strong) PTRSimulationConfiguration *simulationConfiguration;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init Methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Initialisation method from
 *
 *  @param dictionary JSON data represented as dictionary.
 *
 *  @return PTRCoreConfiguration object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (instancetype)updateWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
