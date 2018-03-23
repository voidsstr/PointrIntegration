//
//  PTRUserInterfaceConfiguration.h
//  Pointr
//
//  Created by Pointr on 04/10/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"
#import "UIKit/UIKit.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PTRMapMode) {
    PTRMapModeFree = 0,
    PTRMapModeTracking = 1,
    PTRMapModeRotationalTracking = 2,
    PTRMapModePathTracking = 3,
};

@interface PTRUserInterfaceConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init Methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Initialisation method from JSON Dictionary.
 *
 *  @param dictionary JSON Dictionary.
 *
 *  @return PTRMapConfig object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, strong) NSArray *enabledMapModes;
@property (nonatomic, assign) float mapRotationLimitAngleInDegrees;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Path properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Width of the line of drawn path on the map.
 *  Size of a dot when map path mode is dotted
 */
@property (nonatomic, assign) float pathWidth;

/**
 *  Path simplification skips graph nodes for path, when it is feasible
 *  YES by default
 */
@property (nonatomic, assign) BOOL isPathSimplificationEnabled;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Pin Properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Determines if an accuracy circle should be used or not
 */
@property (nonatomic, assign) BOOL shouldEnableAccuracyCircle;

/**
 *  Minimum size of the accuracy circle around the pin.
 *
 *  Be aware accuracy min size will be minimum 2x from blue dot in pixels
 *  So if pixel representation of MinSizeInMeters is below this value it wont have an effect.
 */
@property (nonatomic, assign) float accuracyCircleMinSizeInMeters;

/**
 *  Maximum size of the accuracy circle around the pin.
 *
 *  Be aware accuracy max size will be maximum 6x from blue dot in pixels
 *  So if pixel representation of MaxSizeInMeters is above this value it wont have an effect.
 */
@property (nonatomic, assign) float accuracyCircleMaxSizeInMeters;

/**
 *  Color of the pulsating part of the accuracy circle around the pin.
 */
@property (nonatomic, strong) UIColor *accuracyCirclePulseColour;

/**
 *  Color of the static part of the accuracy circle around the pin.
 */
@property (nonatomic, strong) UIColor *accuracyCircleStaticColour;

/**
 *  Color of the static part of the accuracy circle around the pin.
 */
@property (nonatomic, strong) UIColor *orientationCircleColor;

/**
 *  Fade out time when invalid position is supplied.
 */
@property (nonatomic, assign) float pinFadeOutTime;

/**
 *  Dissapear time after fading out.
 */
@property (nonatomic, assign) float pinDisappearTime;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Map Properties
/////////////////////////////////////////////////////////////////////////
/**
 *  Indicates the maximum zoom level of detail map will have.
 */
@property (nonatomic, assign) int maximumMapDetailLevel;

@property (nonatomic, assign) float maxZoomScale;

@property (nonatomic, assign) float minZoomScale;

/**
 *  Decides if the debugging overlay will be shown on screen.
 */
@property (nonatomic, assign) BOOL shouldShowDebuggingPanel;

/**
 *  Drawable clash prevention
 */
@property (nonatomic, assign) BOOL shouldCheckAnnotationClash;

/**
 *  Determines if the footer with logo and mode changer should be visible or not.
 */
@property (nonatomic, assign) BOOL willShowMapFooter;

/**
 Determines if a poi should enlarge when selected
 */
@property (nonatomic, assign) BOOL shouldEnlargeSelectedPoi;

/////////////////////////////////////////////////////////////////////////
#pragma mark - General UI Properties
/////////////////////////////////////////////////////////////////////////

@property (nonatomic, assign) BOOL isDataDownloadPromptEnabled;

/**
 Enables Augmented Reality functionality.
 */
@property (nonatomic, assign) BOOL isAugmentedRealityEnabled;

/**
 Enables On Screen Translation functionality.
 */
@property (nonatomic, assign) BOOL isOnScreenTranslationEnabled;

@end

NS_ASSUME_NONNULL_END
