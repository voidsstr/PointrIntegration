//
//  PTRTravelEstimation.h
//  Pointr
//
//  Created by Erkan Sen on 17.11.2017.
//
//  Object that represents travel estimation
//  In terms of distance and time(seconds)

#import "Foundation/Foundation.h"

/// This value indicates the distance a fast walking person can travel in a minute.
static float const kPTR1MinuteFastWalkingDistance = 80.0F;
/// This value indicates the distance a slow walking person can travel in a minute.
static float const kPTR1MinuteSlowWalkingDistance = 40.0F;

@interface PTRTravelEstimation : NSObject <NSCopying, NSCoding>

// time estimations for travel in seconds
@property (nonatomic) float minimumTime;  // time in which a slow walking person can finish path
@property (nonatomic) float averageTime;  // time in which an average person can finish path
@property (nonatomic) float maximumTime;  // time in which a fast walking person can finish path

// total distance of travel
@property (nonatomic) float distance;

/**
 Initialiser for travel estimation
 adds average time as average of min and max time

 @param distance distance of estimation in metres
 @param minTime min estimatedTime in seconds
 @param maxTime max estimatedTime in seconds
 @return PTRTravelEstimation object
 */
- (instancetype)initWithDistance:(float)distance minimumTime:(float)minTime maximumTime:(float)maxTime;

/**
 Initialiser for travel estimation
 Adds time by dividing distance to kPTR1MinuteFastWalkingDistance and kPTR1MinuteSlowWalkingDistance

 @param distance distance of estimation in metres
 @return PTRTravelEstimation object
 */
- (instancetype)initWithDistance:(float)distance;

/**
 Adds newEstimations values to self
 e.g. self.distance += newEstimation.distance

 @param newEstimation another PTRTravelEstimation object to add values to self
 */
- (void)addEstimation:(PTRTravelEstimation *)newEstimation;

@end
