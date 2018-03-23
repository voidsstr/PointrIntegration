//
//  PTRRouteVC.h
//  Pointr
//
//  Created by Erkan on 27.03.2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

#import "PTRPoi.h"
#import "PTRPathDirection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The main delegate to handle any search related interactions regarding the search view.
 */
@protocol PTRRouteVCDelegate <NSObject>

@optional

/**
 Sends signal to start PathFinding
 */
- (void)routeViewUserDidTapRouteStartButton;

@end

@interface PTRRouteVC : UIViewController

/**
 *  The object that acts as the delegate of the routeVC.
 */
@property (nonatomic, weak) _Nullable id delegate;

@property (nonatomic, strong) NSArray<PTRPathDirection *> *routeArray;
@property (nonatomic, strong) NSArray<NSNumber *> *minutesArray;
@property (nonatomic, strong) PTRPoi *endPoint;
@property int totalTime;

- (void)initialisePropertiesAndTryToPresentWithDelegate:(id)delegate;
+ (void)setMainColorScheme:(UIColor *)colorScheme;
+ (void)setFontName:(NSString *)fontName;

@end

NS_ASSUME_NONNULL_END
