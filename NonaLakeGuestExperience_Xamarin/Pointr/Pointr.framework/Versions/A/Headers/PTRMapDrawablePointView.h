//
//  PTRMapDrawablePointView.h
//  Pointr
//
//  Created by Pointr Labs on 05/08/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "CoreGraphics/CoreGraphics.h"
#import "PTRMapDrawable.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRMapDrawablePointView : UIView

@property (nonatomic, strong) id<PTRMapDrawable> drawable;
@property (nonatomic, assign) CGPoint position;
@property (nonatomic, assign) CGPoint centerOffset;
@property (nonatomic, strong) NSString *reuseIdentifier;

@property (nonatomic, strong) UIImageView *drawableImageView;

- (instancetype)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable>)drawable;

- (instancetype)initWithView:(UIView *)view forDrawable:(id<PTRMapDrawable>)drawable;

@end

NS_ASSUME_NONNULL_END
