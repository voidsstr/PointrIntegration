//
//  PTRAugmentedRealityVC.h
//  Pointr
//
//  Created by Pointr Labs on 10/04/2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "PTRPath.h"
#import "PTRPositioningTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PTRAugmentedRealityControllerDelegate
@optional
- (void)augmentedRealityDissmissedByUserWithTapEvent:(UIEvent *_Nullable)tapEvent;
@end

@interface PTRAugmentedRealityVC : UIViewController

@property (nonatomic, weak) _Nullable id delegate;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Methods
/////////////////////////////////////////////////////////////////////////
- (BOOL)canUserEnableAugmentedReality;

@end

NS_ASSUME_NONNULL_END
