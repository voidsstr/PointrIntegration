//
// Created by Pointr Labs on 05/08/16.
// Copyright (c) 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "UIKit/UIKit.h"
#import "CoreGraphics/CoreGraphics.h"

#import "PTRMapDrawablePointView.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRPoiView : PTRMapDrawablePointView

typedef NS_ENUM(int, PTRPoiLabelPlace) {
    PTRPoiLabelPlaceBottom = 0,
    PTRPoiLabelPlaceLeft,
    PTRPoiLabelPlaceRight,
    PTRPoiLabelPlaceNone
};

@property (nonatomic, strong) UIImageView *poiImageView;
@property (nonatomic, strong) UILabel *poiNameLabelBottom;

@property (nonatomic, strong) UILabel *poiNameLabelLeft;
@property (nonatomic, strong) UILabel *poiNameLabelRight;
@property (nonatomic) PTRPoiLabelPlace poiLabelPlace;
@property (nonatomic) BOOL isEnlarged;

/**
 Default initializer for poiView (Namelabel is visible)

 @param frame frame of PoiView
 @param drawable drawable of PoiView
 @param image poiViews Image
 @return PoiView
 */
- (instancetype)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable>)drawable withImage:(UIImage *)image;

/**
 Default initializer for poiView

 @param frame frame of PoiView
 @param drawable drawable of PoiView
 @param image poiViews Image
 @param shouldShowNameLabel boolean for if a label will be shown
 @return PoiView
 */
- (instancetype)initWithFrame:(CGRect)frame
                  forDrawable:(id<PTRMapDrawable>)drawable
                    withImage:(UIImage *)image
          shouldShowNameLabel:(BOOL)shouldShowNameLabel;

/**
 Default initializer for poiView with custom view

 @param frame frame of PoiView
 @param drawable drawable of PoiView
 @param view custom view in poiView
 @param shouldShowNameLabel boolean for if a label will be shown
 @return PoiView
 */
- (instancetype)initWithFrame:(CGRect)frame
                  forDrawable:(id<PTRMapDrawable>)drawable
                     withView:(UIView *)view
          shouldShowNameLabel:(BOOL)shouldShowNameLabel;

/**
 set default poiImage enlarging Rate default 1.5

 @param poiImageEnlargingRate float poi image enlarging rate
 */
+ (void)setPoiImageEnlargingRate:(float)poiImageEnlargingRate;

/**
 Enlarging the poi Image if selected
 */
- (void)enlargePoiImage;

/**
 Shrinking the poi image if deselected
 */
- (void)shrinkPoiImage;

/**
 Returns the visible label

 @return visiable UILabel
 */
- (UILabel *)visibleLabel;

@end

NS_ASSUME_NONNULL_END
