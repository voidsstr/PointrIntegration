//
//  PTRNavigationFooterView.h
//
//  Created by Pointr Labs on 20/07/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

NS_ASSUME_NONNULL_BEGIN

@class PTRMapView;
@class PTRPoi;
@class PTRNavigationFooterView;

@protocol PTRNavigationFooterViewDelegate <NSObject>
@optional

/**
 *  Notifies when user swiped down the footerView
 */
- (void)footerViewSwipedDown:(PTRNavigationFooterView *)footerView;

@end

@interface PTRNavigationFooterView : UIView

- (void)updateFooterWithPoi:(PTRPoi *)poi;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Static Methods
/////////////////////////////////////////////////////////////////////////

/**
 Set Title color of Footer

 @param color UIColor for Title Color
 */
+ (void)setDefaultTitleColor:(UIColor *)color;

/**
 Set subtitle color of Footer

 @param color UIColor for subtitle Color
 */
+ (void)setDefaultSubtitleColor:(UIColor *)color;

/**
 Set Button Title subtitle of Footer

 @param color UIColor for Button title Color
 */
+ (void)setDefaultButtonTitleColor:(UIColor *)color;

/**
 Set Button Background subtitle of Footer

 @param color UIColor for Button Background Color
 */
+ (void)setDefaultButtonBackgroundColor:(UIColor *)color;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

// TODO- These properties are not working properly at the moment

/**
 bool value that indicates if patfinding started
 */
@property (nonatomic, assign) BOOL hasStartedPathfinding;
/**
 *  Background colour for footer
 */
@property (nonatomic, strong) UIColor *customBackgroundColour;

/**
 *  Colour for footer label
 */
@property (nonatomic, strong) UIColor *customLabelTextColour;

/**
 *  Font for footer label
 */
@property (nonatomic, strong) UIFont *customLabelFont;

/**
 *  Colour for footer button
 */
@property (nonatomic, strong) UIColor *customButtonTextColour;

/**
 *  Font for footer button
 */
@property (nonatomic, strong) UIFont *customButtonFont;

/**
 Delegate listener of footerView
 */
@property (nonatomic, weak) _Nullable id<PTRNavigationFooterViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
