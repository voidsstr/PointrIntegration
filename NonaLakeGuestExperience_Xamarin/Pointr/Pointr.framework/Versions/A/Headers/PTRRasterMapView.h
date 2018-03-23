//
//  PTRRasterMapView.h
//  Pointr
//
//  Created by Pointr on 24/10/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "UIKit/UIView.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRRasterMapView : UIScrollView

@property (nonatomic) int shownLevel;
@property (weak) id rasterDelegate;
- (void)displayImage:(UIImage *)image;
@property (nonatomic) CGRect layoutLimits;
@end

@protocol PTRRasterMapViewDelegate <NSObject>

- (void)rasterMapViewDidZoom:(PTRRasterMapView *)rasterMap;

@end

NS_ASSUME_NONNULL_END
