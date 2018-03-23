//
//  PTRPathfindingConfig.h
//  Pointr
//
//  Created by Ismail Pointr on 25/08/2015.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Different modes for Path Finding
 */
typedef NS_ENUM(NSInteger, PTRPathfindingDistanceMode) {
    /**
     *  Standard path finding
     */
    PTRPathfindingDistanceNormal,
    /**
     *  Special mode for exhibition halls
     */
    PTRPathfindingDistanceExhibition
};

@interface PTRPathManagerConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Assume user has arrived at his destination if he's closer than X metres
 */
@property (nonatomic, assign) float arrivalThresholdInMetres;

/**
 *  Reroute path if deviated from the path by X metres
 */
@property (nonatomic, assign) float rerouteThresholdInMetres;

/**
 *  Flag to turn on/off turn-by-turn directions. YES by default.
 */
@property (nonatomic, assign) BOOL isTurnByTurnDirectionsEnabled;

/**
 *  SmartRerouting suggests a closer POI from a group during navigation.[True by Default]
 */
@property (nonatomic, assign) BOOL isSmartReroutingEnabled;

/**
 *  Can be set to special modes such as exhibition. [Normal by default]
 */
@property (nonatomic, assign) PTRPathfindingDistanceMode distanceMode;

/**
 *  If enabled, turn by turn directions are accompanied with voice. ON by default.
 */
@property (nonatomic, assign) BOOL isVoiceGuidanceEnabled;

@end

NS_ASSUME_NONNULL_END
