//
//  PTRCoordinateTransformer.h
//
//  Created by Pointr on 19/02/15.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRPositioningTypes.h"
#import "PTRLocation.h"
#import "PTRCorner.h"
#import "PTRCalculatedLocation.h"
#import "CoreGraphics/CoreGraphics.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRCoordinateTransformer : NSObject

+ (PTRCalculatedLocation *)convertCalculatedLocationToScreenForZoom:(PTRCalculatedLocation *)normalized
                                                     withScreenRect:(CGRect)screenRect;
+ (CGPoint)convertCornerToScreenPointForZoom:(PTRCorner *)normalized withScreenRect:(CGRect)screenRect;
+ (CGPoint)convertLocationToScreenPointForZoom:(PTRLocation *)normalized withScreenRect:(CGRect)screenRect;

+ (PTRPosition)convertNormalizedToScreenForZoom:(PTRPosition)normalized withScreenRect:(CGRect)screenRect;
+ (CGPoint)convertNormalizedPointToScreenForZoom:(CGPoint)normalized withScreenRect:(CGRect)screenRect;

@end

NS_ASSUME_NONNULL_END
