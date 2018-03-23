//
//  PTRLocationSharingConfiguration.h
//  Pointr
//
//  Created by Pointr Labs on 07/10/2015.
//  Copyright © 2015 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRLocationSharingConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**-----------------------
 * @name Public Properties
 *------------------------
 */

/**
 *  See other devices through Bluetooth. [Default: NO]
 */

@property (nonatomic, strong) NSString *onlineLocationPollApi;
/*
        TODO : online location poll api [rename]
 */

/**
 Endpoint for sending user locations to server.
 */
@property (nonatomic, retain) NSString *locationUploadApi;
/**
 *  See other people active in last X seconds [Default: 60 seconds]
 *  @warning For online sharing, effective timeout might go up to twice as much (as we're caching on server as well as
 on device). For offline sharing, effective timeout will be equal to this value.

 60 seconds by default

 NOTE- For online sharing, effective timeout might go up to twice as much (as we're caching on server as well as on
 device). For offline sharing, effective timeout will be equal to this value.
 */

/**
 *  See other people active in last X seconds [Default 60 secionds]
 */
@property (nonatomic, assign) double seeOtherPeopleTimeoutInSeconds;

/**
 *  The cycle period the online positions will be received
 */
@property (nonatomic, assign) double onlineLocationPollFrequencyInSeconds;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) double onlineLocationTimeoutInSeconds;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) double advertisementIntervalInSeconds;

/**
 *  See other devices through Bluetooth.[NO by default]
 */
@property (nonatomic, assign) BOOL seeOtherPeopleOfflineEnabled;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) BOOL isOfflineLocationSharingEnabled;

/**
 *  See other devices through data received from server.[YES by default]
 */
@property (nonatomic, assign) BOOL seeOtherPeopleOnlineEnabled;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) BOOL isOnlineLocationSharingEnabled;

/**
 *  The cycle time for position uploader will upload saved positions.
 */
@property (nonatomic, assign) double positionUploadIntervalSeconds;

@property (nonatomic, assign) double positionSamplingRateInSeconds;

@property (nonatomic, assign) int positionUploadThreshold;

@end

NS_ASSUME_NONNULL_END
