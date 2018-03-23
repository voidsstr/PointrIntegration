//
//  PTRCalculatedLocation.h
//  Pointr
//
//  Created by Erkan Sen on 27.12.2017.
//

#import "Foundation/Foundation.h"
#import "PTRLocation.h"

@interface PTRCalculatedLocation : PTRLocation <NSCoding>

@property (nonatomic, readonly) PTRLocationState state;                                // Lost, Faded, Active or Unknown
@property (nonatomic, readonly) float accuracy;                                        // Confidence radius, in metres
@property (nonatomic, readonly) float orientation;                                     // Orientation in radians
@property (nonatomic, readonly) float orientationAccuracy;                             // Orientation spread in radians
@property (nonatomic, readonly) PTROrientationAccuracyClass orientationAccuracyClass;  // Low or High
@property (nonatomic) double timestamp;                                                // Unix timestamp in seconds

- (instancetype)initInvalidLocation;

- (instancetype)initWithLocation:(PTRLocation *)location
                           state:(PTRLocationState)state
                        accuracy:(float)accuracy
                     orientation:(float)orientation
             orientationAccuracy:(float)orientationAccuracy
        orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;

- (instancetype)initWithX:(float)x
                           y:(float)y
                       level:(int)level
                     venueId:(int)venueId
                  facilityId:(int)facilityId
                       state:(PTRLocationState)state
                    accuracy:(float)accuracy
                 orientation:(float)orientation
         orientationAccuracy:(float)orientationAccuracy
    orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;

- (instancetype)initWithX:(float)x
                           y:(float)y
                         lat:(double)lat
                         lon:(double)lon
                       level:(int)level
                     venueId:(int)venueId
                  facilityId:(int)facilityId
                       state:(PTRLocationState)state
                    accuracy:(float)accuracy
                 orientation:(float)orientation
         orientationAccuracy:(float)orientationAccuracy
    orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;

- (PTRPosition)convertToPosition;
- (CGPoint)getPoint;

@end
