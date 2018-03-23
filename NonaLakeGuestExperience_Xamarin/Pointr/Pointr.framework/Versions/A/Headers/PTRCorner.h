//
//  PTRCorner.h
//  Pointr
//
//  Created by Pointr Labs on 30/11/15.
//  Copyright © 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRPositioningTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the real corner locations for PTRWall.
 */
@interface PTRCorner : NSObject <NSCoding>

/**
 X coordinate of the corner location.
 */
@property (nonatomic, assign) float x;

/**
 Y coordinate of the corner location.
 */
@property (nonatomic, assign) float y;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

/**
 Main init method for PTRCorner object

 @warning X and Y values needs to be between the defined valid interval.

 @param dictionary JSON dictionary representing a PTRCorner
 @return A PTRCorner object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 * Init method for c++ corner
 * @param x coordinate
 * @param y coordinate
 * @return A PTRCorner object
 */
- (instancetype)initWithX:(float)x andY:(float)y;

/**
 @return CGPoint from corner x and y
 */
- (CGPoint)point;

@end

NS_ASSUME_NONNULL_END
