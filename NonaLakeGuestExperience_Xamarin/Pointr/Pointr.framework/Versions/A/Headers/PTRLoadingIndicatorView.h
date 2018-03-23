//
//  PTRLoadingView.h
//  Pointr
//
//  Created by Pointr Labs on 3.10.2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRLoadingIndicatorView : UIView

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Properities
/////////////////////////////////////////////////////////////////////////

/**
 Corner radius of indicator view background. Default 15
 */
@property (nonatomic, assign) NSInteger cornerRadius;

/**
 Width of indicator background. Default 100
 */
@property (nonatomic, assign) NSInteger indicatorBGWidth;

/**
 BackGround Color of inducator default white
 */
@property (nonatomic, retain) UIColor *indicatorBGColor;

/**
 Count of image set images. Default 1
 */
@property (nonatomic, assign) uint imageCount;

/**
 Name of image set. Default Pointr Logo
 */
@property (nonatomic, retain) NSString *imageSetName;

/**
 Text of indicator. Default nil
 */
@property (nonatomic, retain) NSString *indicatorText;

/**
 Text color of indicator. Default black
 */
@property (nonatomic, retain) UIColor *indicatorTextColor;

@property (nonatomic, readonly) BOOL isAnimating;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Static Methods
/////////////////////////////////////////////////////////////////////////

/**
 Returns the name of alertView

 @return default Font Name
 */
+ (NSString *)defaultFontName;

/**
 Set the font name

 @param fontName name of font
 */
+ (void)setDefaultFontName:(NSString *)fontName;

/**
 Returns BG color of Loading Indicator

 @return BG color of Loading Indicator
 */
+ (UIColor *)defaultBackgroundColor;

/**
 Set BG color of Loading Indicator

 @param color UIColor for Background Color
 */
+ (void)setDefaultBackgroundColor:(UIColor *)color;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init Methods
/////////////////////////////////////////////////////////////////////////
/**
 Takes text input for Indicator

 @param text NSString for Indicator

 @return PTRLoadingIndicatorView
 */
- (instancetype)initWithText:(NSString *)text;
/**
 Indicator with text and custom imageSet

 @param text  NSString for Indicator
 @param name  Name of the image of the set
 @param count Count of the images in set

 @warning images should have their name like name-1 name-2

 @return PTRLoadingIndicatorView
 */

- (instancetype)initWithText:(NSString *)text
                imageSetName:(NSString *)name
                  imageCount:(int)count
        andAnimationDuration:(float)duration;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Start and stop animation Methods
/////////////////////////////////////////////////////////////////////////

/**
 Stoping animation
 */
- (void)startAnimating;

/**
 Starting animation
 */
- (void)stopAnimating;

@end

NS_ASSUME_NONNULL_END
