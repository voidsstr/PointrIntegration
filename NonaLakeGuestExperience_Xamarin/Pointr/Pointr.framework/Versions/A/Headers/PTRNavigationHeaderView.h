//
//  PTRNavigationHeaderView.h
//
//  Created by Pointr Labs on 20/07/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "PTRPath.h"

NS_ASSUME_NONNULL_BEGIN
@class PTRNavigationHeaderView;

@protocol PTRNavigationHeaderViewDelegate <NSObject>
@optional

/**
 *  Notifies when user swiped down the footerView
 */
- (void)headerViewSwipedUp:(PTRNavigationHeaderView *)headerView;

@end

@interface PTRNavigationHeaderView : UIView

/**
 Delegate listener of footerView
 */
@property (nonatomic, weak) _Nullable id<PTRNavigationHeaderViewDelegate> delegate;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////
+ (void)setBackgroundColor:(UIColor *)backgroundColor;
+ (void)setMainColorScheme:(UIColor *)colorScheme;
+ (void)setFontName:(NSString *)fontName;

- (void)setTotalPathTime:(float)time;
- (void)updateHeaderForPath:(PTRPath *)path;
- (void)updateHeaderForPathfindingError:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
