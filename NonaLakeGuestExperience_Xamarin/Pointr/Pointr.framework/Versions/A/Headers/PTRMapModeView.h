//
//  PTRMapModeView.h
//  Pointr
//
//  Created by Erkan on 10.03.2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

#import "PTRUserInterfaceConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@class PTRMapModeView;
@protocol PTRMapModeViewDelegate <NSObject>

/**
 Change MapMode

 @param mapModeView PTRMapModeView self
 */
- (void)userDidTapOnMapModeView:(PTRMapModeView *)mapModeView;

@optional
- (void)onMapModeView:(PTRMapModeView *)mapModeView changedMapMode:(PTRMapMode)mapMode;
@end

@interface PTRMapModeView : UIView

@property (nonatomic) PTRMapMode currentMapMode;
@property (nonatomic) PTRMapMode previousMapMode;  // previous map mode other than free

// images for modes
// change the images after initializations to see the given images
@property (nonatomic, strong) UIImage *imageFreeMode;  // aka locate Me
@property (nonatomic, strong) UIImage *imageTrackingMode;
@property (nonatomic, strong) UIImage *imagePathTrackingMode;
@property (nonatomic, strong) UIImage *imageRotatingMode;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  The object that acts as the delegate of the mapmodeView.
 */
@property (nonatomic, weak) _Nullable id<PTRMapModeViewDelegate> delegate;

NS_ASSUME_NONNULL_END
@end
