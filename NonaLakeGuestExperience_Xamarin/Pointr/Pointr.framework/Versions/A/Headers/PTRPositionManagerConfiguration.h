//
//  PTRPositionManagerConfiguration.h
//
//  Creatd by Pointr on 15/01/15.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/** Constants **/
typedef NS_ENUM(int, PTRHeadingMode) {
    PTRHeadingModeQuaternion = 0,
    PTRHeadingModeComplementaryFilter = 1,
    PTRHeadingModeNotAvailable = -1
};

/**
 *  Configuration parameters for position calculations.
 */
@interface PTRPositionManagerConfiguration : PTRConfigurationInterface

/**
 *  Number of beacons to be used to determine location
 */
@property (nonatomic, assign) int numberOfNearestBeaconsToUse;

/**
 *  Number of measurements required before first position is calculated.
 */
@property (nonatomic, assign) int requiredMeasurementsForPositionReporting;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float measurementHistoryTimespan;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float biasPower;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float maxWalkingSpeed;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float calculationTimeStep;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float accuracyMultiplier;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) float stepInterval;

/**
 *  If set to YES, positioning will also work in background (subject to OS restrictions) [NO by default.]
 */
@property (nonatomic, assign) BOOL isBackgroundPositioningEnabled;

/**
 *  If set to YES, positioning will use more sensors (and battery) to provide higher accuracy.
 *  YES by default,
 */
@property (nonatomic, assign) BOOL isFusionEnabled;

/**
 * @property rotationPrecision
 * @brief default (1.0)
 */
@property (nonatomic, assign) float rotationPrecision;
/**
 *  <#Description#>
 */
@property (nonatomic, assign) BOOL isCoreBluetoothEnabled;

/**
 *  If YES, CoreLocation framework will be used for beacon ranging and compass. [Default True]
 */
@property (nonatomic, assign) BOOL isCoreLocationEnabled;

/**
 *  Stop background ranging (via CoreLocation) if no beacons are heard since last X seconds
 */
@property (nonatomic, assign) float beaconSilenceTimeInSeconds;

/**
 *  Diffrence degrees indicating maximum degrees that can be change in one compass heading update.
 */
@property (nonatomic, assign) float headingThrottlingThresholdInDegrees;

/**
 * Threshold to notify on fade out position after given seconds of invalid position
 */
@property (nonatomic, assign) float thresholdForFadingPositionInSeconds;

/**
 * Threshold to notify on lost position after given seconds of invalid position
 */
@property (nonatomic, assign) float thresholdForLosingPositionInSeconds;

/**
 Latitude of top left point of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double latitudeTopLeft;

/**
 Longitude of top left point of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double longitudeTopLeft;

/**
 Latitude of top right point of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double latitudeTopRight;

/**
 Longitude of top right point of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double longitudeTopRight;

/**
 Latitude of the bottom left of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double latitudeBottomLeft;

/**
 Longitude of the bottom left of map

 @warning This parameter is required to be set in order for Geo Position calculation to work.
 */
@property (nonatomic, assign) double longitudeBottomLeft;

/**
 * Measurement history timespan for level change algorithm
 */
@property (nonatomic, assign) float levelChangeHistoryTimespan;

/**
 * Typical level height
 */
@property (nonatomic, assign) float typicalLevelHeight;

/**
 * Level change grace threshold: how much change about current level should be observed to allow a level change
 */
@property (nonatomic, assign) float levelChangeGraceThreshold;

/////////////////////////////////////////////////////////
#pragma mark - Fusion
/////////////////////////////////////////////////////////
/**
 *  General
 */
@property (nonatomic, assign) BOOL shouldResetOnLevelChange;

/**
 *  Core Motion
 */
@property (nonatomic, assign) int sensorSamplingPeriodInMicrosecs;

/**
 *  Inertial Navigator
 */
@property (nonatomic, assign) int inHeadingMode;
@property (nonatomic, assign) int inHeadingDelayWindowSize;
@property (nonatomic, assign) int inCorrectionPeriod;
@property (nonatomic, assign) double inSpeedNoiseSigma;
@property (nonatomic, assign) double inMeasNoiseSigma;
@property (nonatomic, assign) int inCompassHeadingWindowSize;

/**
 *  Heading Estimator (Enabled in Complementary Filter Heading Mode)
 */
@property (nonatomic, assign) double headingFilterCoefAccel;
@property (nonatomic, assign) double headingFilterCoefMagneto;

/**
 *  Inertial Data Concatenation
 */
@property (nonatomic, assign) int numConcatInertialSamples;

/**
 *  Movement Info Reporting
 */
@property (nonatomic, assign) BOOL movementInfoReportingEnabled;

/**
 *  Fusion
 */
@property (nonatomic, assign) double speedNoiseSigma;
@property (nonatomic, assign) double headingChangeNoiseSigma;
@property (nonatomic, assign) double measNoiseSigma;

/**
 *  Visual Smoothing
 */
@property (nonatomic, assign) BOOL maSmoothingEnabled;
@property (nonatomic, assign) int maSmoothingWindowSize;

/**
 *  Initial Convergence
 */
@property (nonatomic, assign) int icNumClones;
@property (nonatomic, assign) double icCloneKillDistance;
@property (nonatomic, assign) double icHeadingConfidenceThreshold;

/**
 *  Obstacle Handling
 */
@property (nonatomic, assign) BOOL obstacleHandlingEnabled;
@property (nonatomic, assign) double ohCloneDistributionRadius;
@property (nonatomic, assign) int ohNumClonesInRadius;
@property (nonatomic, assign) BOOL ohHeadingDispersionEnabled;
@property (nonatomic, assign) double ohHeadingDispersionMaxAngle;
@property (nonatomic, assign) int ohMinNumClones;
@property (nonatomic, assign) int ohMaxNumClones;
@property (nonatomic, assign) BOOL ohGridClusteringEnabled;
@property (nonatomic, assign) double ohGridClusteringCellSize;
@property (nonatomic, assign) double ohMinCloneDiversity;

@end

NS_ASSUME_NONNULL_END
