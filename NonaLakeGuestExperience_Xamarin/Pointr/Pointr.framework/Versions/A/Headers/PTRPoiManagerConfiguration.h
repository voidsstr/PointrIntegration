//
//  PTRPoiManagerConfiguration.h
//  Pointr
//
//  Created by Igal Benardete on 18/05/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Poi related configuration items.
 */
@interface PTRPoiManagerConfiguration : PTRConfigurationInterface

/**
 *  Flag indicating whether Portals should be showed as POI's
 */
@property (nonatomic, assign) BOOL shouldShowPortalsAsPois;

/**
 *  Check for trigger entry at least after X metres of displacement
 *  5.0 metres by default
 */
@property (nonatomic, assign) float checkTriggerDistanceThresholdInMetres;

@end

NS_ASSUME_NONNULL_END
