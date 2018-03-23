//
//  Pointr.h
//
//
//  Created by Pointr on 04/12/14.
//  Copyright (c) 2014 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

#import "PTRAdvertiser.h"
#import "PTRSingletonProtocol.h"
#import "PointrMode.h"
#import "PointrDebugMode.h"
#import "PointrReleaseMode.h"
#import "PTRLogger.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const POINTR_VERSION_NUMBER;
extern NSString *const POINTR_VENDOR_NAME;

@class PTRAnalyticsManagerInterface;
@class PTRConfigurationManagerInterface;
@class PTRDataManagerInterface;
@class PTRGeofenceManagerInterface;
@class PTRGraphManagerInterface;
@class PTRLocationSharingManagerInterface;
@class PTRMaintenanceManagerInterface;
@class PTRMapManagerInterface;
@class PTRPathManagerInterface;
@class PTRPoiManagerInterface;
@class PTRPositionManagerInterface;
@class PTRPushManagerInterface;
@class PTRUserManagerInterface;
@class PTRWallManagerInterface;
@class PTRStorage;
@class PTRNetworkCoordinator;

typedef NS_ENUM(int, PointrState) {
    PointrStateOff,  // Pointr not started yet or stopped or failed to start
    PointrStateConfiguring,
    PointrStateValidating,
    PointrStateRegistering,
    PointrStateRunning
};

extern NSString *_Nonnull PTRPointrStateToString(PointrState state);

/**
 * Delegate methods to follow Pointr library start / progress / stop
 */
@protocol PointrBaseDelegate <NSObject>

@optional

/**
 * Triggered when Pointr stops itself or is stopped externally
 */
- (void)onPointrBaseStop;

/**
 * Triggered upon every state change
 */
- (void)onPointrBaseStateChangedTo:(PointrState)state withMessages:(NSArray<NSString *> *_Nullable)messages;

@end

/**
 * Callback method when Pointr fails to start
 *
 * @param warningMessages - array of warning messages generated during start (optional)
 */
typedef void (^PointrOnErrorCallback)(NSArray<NSString *> *_Nullable warningMessages);

/**
 * Callback method when Pointr state changes
 *
 * param message - warning or information message for the state change (optional)
 */
typedef void (^PointrOnStateChangedCallback)(PointrState state, NSArray<NSString *> *_Nullable warningMessages);

/**
 *  Main Pointr Class to interact with start callbacks and managers.
 */
@interface PointrBase : PTRAdvertiser <id<PointrBaseDelegate>> <PTRSingletonProtocol>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 * Flag to control whether Pointr internal crash handling is enabled or not.
 * YES by default.
 */
@property (nonatomic, assign) BOOL isCrashHandlingEnabled;

/**
 Indicates library start state
 */
@property (nonatomic, assign) PTRLoggerLevel loggerLevel;

/**
 The running mode for Pointr SDK
 */
@property (nonatomic, strong) PointrMode *mode;

/**
 Indicates library start state
 */
@property (nonatomic, readonly) PointrState state;

/**
 * Version number for this library
 */
@property (nonatomic, readonly) NSString *_Nonnull version;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

- (void)startWithLicenseKey:(NSString *_Nonnull)licenseKey
             onStateChanged:(_Nonnull PointrOnStateChangedCallback)onStateChanged
                    onError:(_Nonnull PointrOnErrorCallback)onError;
/**
 *  Stops all position calculation and data management operations.
 */
- (void)stop;

/**
 *  Resets stored configuration data (for all venues and facilities)
 *  Allows clean configuration state
 *  Useful if BaseConfiguration is changed
 */
- (void)resetConfiguration;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Pointr Managers
/////////////////////////////////////////////////////////////////////////

/**
 *  Allows access to the shared instance for Analytics manager
 *
 *  @return PTRAnalyticsManager
 */
- (nullable PTRAnalyticsManagerInterface *)getAnalyticsManager;


/**
 Allows access to the shared instance for Configuration Manager

 @return PTRConfigurationManager
 */
- (PTRConfigurationManagerInterface *_Nonnull)getConfigurationManager;

/**
 *  Allows access to the shared instance for Data Manager
 *
 *  @return PTRDataManager
 */
- (nullable PTRDataManagerInterface *)getDataManager;

/**
 *  Allows access to the shared instance for Geofence Manager
 *
 *  @return PTRGeofenceManager
 */
- (nullable PTRGeofenceManagerInterface *)getGeofenceManager;

/**
 *  Allows access to the shared instance for Graph Manager
 *
 *  @return PTRGraphManager
 */
- (nullable PTRGraphManagerInterface *)getGraphManager;

/**
 *  Allows access to the shared instance for Location Sharing Manager
 *
 *  @return PTRLocationSharingManager
 */
- (nullable PTRLocationSharingManagerInterface *)getLocationSharingManager;

/**
 *  Allows access to the shared instance for Carpark manager
 *
 *  @return PTRMaintenanceManager
 */
- (nullable PTRMaintenanceManagerInterface *)getMaintenanceManager;

/**
 *  Allows access to the shared instance for Map Manager
 *
 *  @return PTRMapManager
 */
- (nullable PTRMapManagerInterface *)getMapManager;

/**
 *  Allows access to the shared instance for Path Manager
 *
 *  @return PTRPathManager
 */
- (nullable PTRPathManagerInterface *)getPathManager;

/**
 *  Allows access to the shared instance for POI Manager
 *
 *  @return PTRPoiManager
 */
- (nullable PTRPoiManagerInterface *)getPoiManager;

/**
 *  Allows access to the shared instance for Position Manager
 *
 *  @return PTRPositionManager
 */
- (nullable PTRPositionManagerInterface *)getPositionManager;

/**
 *  Allows access to the shared instance for Push Manager
 *
 *  @return PTRPushManager
 */
- (nullable PTRPushManagerInterface *)getPushManager;

/**
 *  Allows access to the shared instance for User Manager
 *
 *  @return PTRUserManager
 */
- (nullable PTRUserManagerInterface *)getUserManager;

/**
 *  Allows access to the shared instance for Wall Manager
 *
 *  @return PTRWallManager
 */
- (nullable PTRWallManagerInterface *)getWallManager;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Internal methods
/////////////////////////////////////////////////////////////////////////

@property (nonatomic, strong, readonly) PTRStorage *storage;
@property (nonatomic, strong, readonly) PTRNetworkCoordinator *networkCoordinator;

- (void)initVariables;

- (void)resetVariables;

@end

NS_ASSUME_NONNULL_END
