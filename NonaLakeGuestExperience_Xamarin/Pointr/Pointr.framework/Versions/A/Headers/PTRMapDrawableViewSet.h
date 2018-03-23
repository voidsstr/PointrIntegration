//
//  PTRMapDrawableViewSet.h
//  Pointr
//
//  Created by Erkan Sen on 29.09.2017.
//

#import "Foundation/Foundation.h"
#import "PTRMapDrawable.h"

@interface PTRMapDrawableViewSet : NSObject

- (void)addView:(UIView *)view forDrawable:(id<PTRMapDrawable>)drawable;
- (void)removeViewAndDrawable:(id<PTRMapDrawable>)drawable;
- (NSArray<UIView *> *)allViews;
- (NSArray<id<PTRMapDrawable>> *)allDrawables;

- (UIView *)viewForDrawable:(id<PTRMapDrawable>)drawable;
- (UIView *)viewForReuseIdentifier:(NSString *)reuseIdentifier;
- (id<PTRMapDrawable>)drawableForView:(UIView *)view;

@end
