//
//  UIColor+Pointr.h
//  POHawkinsBrown
//
//  Creatd by Pointr on 25/02/2015.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

@interface UIColor (Pointr)

+ (UIColor *)colorWithHexString:(NSString *)hexString;
+ (CGFloat)colorComponentFrom:(NSString *)string start:(NSUInteger)start length:(NSUInteger)length;

+ (UIColor *)ptrDarkBlue;
+ (UIColor *)ptrLightBlue;
+ (UIColor *)ptrRed;
+ (UIColor *)ptrGray;
+ (UIColor *)ptrGreen;
+ (UIColor *)ptrOrange;
+ (UIColor *)ptrPurple;
+ (UIColor *)ptrYellow;
+ (UIColor *)ptrFlatGreen;
+ (UIColor *)ptrFlatBlue;
+ (UIColor *)ptrFlatOrange;
+ (UIColor *)ptrFlatRed;

@end
