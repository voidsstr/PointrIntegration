//
//  PTRPath.h
//
//
//  Created by Pointr on 13/12/14.
//  Copyright (c) 2014 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRPathDirection.h"
#import "PTRLineMapDrawable.h"

// Pathfinding
#import "PTRNodeInterface.h"
#import "PTRTravelEstimation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a navigation path.

 @warning Do not subclass, it may cause runtime exceptions
 */
@interface PTRPath : NSObject <NSCopying, PTRLineMapDrawable>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Ordered list of PTRNodeInterface objects
 *  TODO- Note these are mutable
 */
@property (nonatomic, retain) NSMutableArray<PTRNodeInterface *> *nodes;

/**
 Array of PTRDirection objects, describing the path textually
 */
@property (nonatomic, retain) NSArray<PTRPathDirection *> *directions;

/**
 Cost of travelling this path. Arbitrary units.

 @warning A path with higher travelCost might have higher walkingDistance due to intricacies of cost calcuation.
 */
@property (nonatomic, assign) float travelCost;

/**
 Travel estimation object having bith distance and estimated times
 */
@property (nonatomic, strong) PTRTravelEstimation *travelEstimation;

@end

NS_ASSUME_NONNULL_END
