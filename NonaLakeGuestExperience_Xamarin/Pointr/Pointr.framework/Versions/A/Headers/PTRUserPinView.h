//
//  PTRUserPinView.h
//
//  Created by Pointr Labs on 02/06/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "PTRMapDrawablePointView.h"

#import "PTRPositioningTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRUserPinView : PTRMapDrawablePointView

/**
 *  The radius multiplier for the accuracy circle
 */
@property (nonatomic) CGFloat accuracyRadius;

/**
 User Pin Image
 */
@property (nonatomic, strong) UIImage *pinImage;

/**
 accuracy value for users pin orientation
 */
@property (nonatomic) PTROrientationAccuracyClass orientationAccuracyClass;

/**
 Heading radian value of userpinview
 */
@property (nonatomic) float rotation;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Animation Methods
/////////////////////////////////////////////////////////////////////////

/**
 Calculates accuracy radius and sets it to self.accuracyRadius

 @param accuracy accuracy of position
 @param contentSize contentSize of map
 */
- (void)calculateAndSetAccuracyCircleRadiusWithAccuracy:(float)accuracy mapContentSize:(CGSize)contentSize;

/**
 Starts user pin animation
 */
- (void)startAnimatingAccuracy;

/**
 Stops user pin animation
 */
- (void)stopAnimatingAccuracy;

/**
 Fades out the User Pin.

 @param newAlpha Alpha value to fade out the pin.
 */
- (void)fadeTo:(CGFloat)newAlpha;

/**
 Animate the User Pin

 @param animate Animation flag.
 */
- (void)animate:(BOOL)animate;
/////////////////////////////////////////////////////////////////////////
#pragma mark - Static Methods
/////////////////////////////////////////////////////////////////////////

/**
 If yes no arms will appear in pinview.

 @param shouldDisableHuggingArms Set bool for hugging arms
 */
+ (void)setShouldDisableHuggingArms:(BOOL)shouldDisableHuggingArms;

@end

NS_ASSUME_NONNULL_END
