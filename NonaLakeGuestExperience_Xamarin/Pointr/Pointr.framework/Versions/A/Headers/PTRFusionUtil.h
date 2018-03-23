//
//  PTRUtil.h
//  Fusion
//
//  Created by Pointr Labs on 02/04/2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Vendor
#import "CoreMotion/CoreMotion.h"

#define TO_RADIANS(ang) ((ang / 180.0) * M_PI)
#define TO_DEGREES(rads) ((rads / M_PI) * 180.0)

#define G_VALUE -9.80665

NS_ASSUME_NONNULL_BEGIN

@interface PTRFusionUtil : NSObject

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

+ (float)calculateHeadingFromQuat:(CMQuaternion)quaternion;
+ (double)normalizeAngle:(double)angle;
+ (double)normalizeAngle:(double)angle withBaseAngle:(double)baseAngle;
+ (double)getAngleChangeFrom:(double)srcAngle to:(double)destAngle;
+ (double)getListMean:(NSArray<NSNumber *> *)list;
+ (double)phi:(double)x;
+ (double)Phi:(double)z;
+ (double)PhiInversePositiveWithY:(double)y andSigma:(double)sigma;
+ (double)PhiInverse:(double)y;
+ (double)PhiInverseWithY:(double)y delta:(double)delta low:(double)lo andHigh:(double)hi;
+ (NSArray *)getGaussianPositionsWithNumPositions:(int)numPositions max:(double)max andMaxSigma:(double)maxSigma;
+ (BOOL)equalsDouble1:(double)a double2:(double)b withLimit:(double)limit;
+ (double)distanceWithX1:(double)x1 y1:(double)y1 x2:(double)x2 andY2:(double)y2;
+ (float)getAltitudeWithP0:(float)p0 p:(float)p;

/**
 Used for pretty printing
 Useful for debugging trends of very rapidly changing values (eg accelerometer sensors)
 */
+ (void)print:(float)value base:(float)base;

@end

NS_ASSUME_NONNULL_END
