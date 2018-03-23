//
//  PTRDataManagerConfiguration.h
//  Pointr
//
//  Created by Igal Benardete on 17/05/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Configuration items related to data processing and endpoints.
 */
@interface PTRDataManagerConfiguration : PTRConfigurationInterface

/**
 * Endpoint for sending Analytics information to server.
 */
@property (nonatomic, retain) NSString *analyticsApi;

/**
 * Endpoint for receiving Configuration from server.
 */
@property (nonatomic, retain) NSString *configurationApi;

/**
 * Determines if data management will start automatically.
 */
@property (nonatomic, assign) BOOL downloadDataAutomatically;

/**
 * Endpoint for receiving Graph data from server.
 */
@property (nonatomic, retain) NSString *graphApi;

/**
 TODO - SHOULD BE REMOVED
 */
@property (nonatomic, retain) NSString *licenseValidationApi;

/**
 * Endpoint for uploading beacon maintenance data to server
 */
@property (nonatomic, retain) NSString *maintenanceApi;

/**
 * Endpoint for receiving POI data from server.
 */
@property (nonatomic, retain) NSString *poiApi;

/**
 * Endpoint for receiving mapped beacon data from server.
 */
@property (nonatomic, retain) NSString *beaconApi;

/**
 * Endpoint for receiving Wall data from server.
 */
@property (nonatomic, retain) NSString *wallApi;

/**
 * Endpoint for receiving Version data from server.
 */
@property (nonatomic, retain) NSString *versionApi;

/**
 Endpoint for sending crash reports to server.
 */
@property (nonatomic, retain) NSString *crashReportingApi;

@end

NS_ASSUME_NONNULL_END
