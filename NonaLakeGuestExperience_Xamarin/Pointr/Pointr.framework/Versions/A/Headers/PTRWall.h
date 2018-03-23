//
//  PTRWall.h
//
//  Created by Pointr on 14/04/15
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRCorner.h"
#import "PTRRegionMapDrawable.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Different types of walls represented on the map.
 */
typedef NS_ENUM(int, PTRWallType) {
    /**
     *  Unknown type
     */
    PTRWallTypeUnknown,
    /**
     *  Actual physical wall
     */
    PTRWallTypeWall,
    /**
     *  Used for navigation only, virtual wall
     */
    PTRWallTypeTransparentWall
};

/**
 *  Object representing actual wall within the system.
 */
@interface PTRWall : NSObject <NSCoding, PTRRegionMapDrawable>

/**
 *  Unique ID representing a specific PTRWall object.
 */
@property (nonatomic, readonly) long wallId;

/**
 *  The level on which the Wall located.
 */
@property (nonatomic, readonly) int level;

/**
 * Id of Wall's venue
 */
@property (nonatomic, readonly) int venueId;

/**
 * Id of Wall's facility
 */
@property (nonatomic, readonly) int facilityId;

/**
 *  An Array of PTRCorner objects representing the actual corner locations of the wall.
 */
@property (nonatomic, readonly) NSArray<PTRCorner *> *corners;

/**
 *  Type of the wall represented as Enumeration
 */
@property (nonatomic, readonly) PTRWallType type;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

/**
 *
 * @param wallId (long)wallId
 * @param level (int)level
 * @param type (NSString*)type
 * @param corners PTRCorner array
 * @return PTRWall object or nil if super cannot initialized.
 */
- (instancetype)initWithWallId:(long)wallId
                         level:(int)level
                       venueId:(int)venueId
                    facilityId:(int)facilityId
                          type:(NSString *)type
                    andCorners:(NSArray<PTRCorner *> *)corners;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Helper methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Converts given string to a known PTRWallType.
 *
 *  @param str String representation of a Wall Type Enumeration.
 *
 *  @return Enum value of the string.
 */
+ (PTRWallType)typeFromString:(NSString *)str;

/**
 *  Converts given PTRWallType to string.
 *
 *  @param type Wall Type.
 *
 *  @return The representative string.
 */
+ (NSString *)stringFromType:(PTRWallType)type;

@end

NS_ASSUME_NONNULL_END
