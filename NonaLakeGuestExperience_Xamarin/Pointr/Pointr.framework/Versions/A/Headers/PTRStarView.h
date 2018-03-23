//
//  PTRStarView.h
//  Pointr
//
//  Created by Pointr Labs on 29.09.2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PTRStarViewDelegate;

/**
 A customised rating star view.
 */
@interface PTRStarView : UIView
/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Variables
/////////////////////////////////////////////////////////////////////////

/**
 Delegate for PTRStarView
 */
@property (weak, nonatomic) id<PTRStarViewDelegate> delegate;

/**
 Sets the empty image (e.g. a star outline)
 */
@property (strong, nonatomic) UIImage *emptySelectedImage;

/**
 Sets the full image (e.g. a star filled)
 */
@property (strong, nonatomic) UIImage *fullSelectedImage;

/**
 Sets the half filled image (e.g. a star half filled)
 */
@property (strong, nonatomic) UIImage *halfSelectedImage;

/**
 Rating value 0-10 to contain also .5 values
 */
@property uint rating;

@end

/////////////////////////////////////////////////////////////////////////
#pragma mark - Delegate Method
/////////////////////////////////////////////////////////////////////////
@protocol PTRStarViewDelegate <NSObject>

@optional
/**
 Returns the rating value when touch events end.
 */
- (void)starView:(PTRStarView *)starView ratingDidChange:(CGFloat)rating;

@end

NS_ASSUME_NONNULL_END
