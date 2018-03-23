//
//  PTRLocation.h
//  Pods
//
//  Created by Ege AKPINAR on 27/05/2017.
//
//

#import "Foundation/Foundation.h"

// Positioning
#import "PTRPositioningTypes.h"

/**
 * Class to represent any inside/outside location
 */
@interface PTRLocation : NSObject <NSCoding>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 * Initialiser for indoor location
 */
- (instancetype)initInvalidLocation;

- (instancetype)initWithX:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId;

- (instancetype)initWithX:(float)x
                        y:(float)y
                      lat:(double)lat
                      lon:(double)lon
                    level:(int)level
                  venueId:(int)venueId
               facilityId:(int)facilityId;

/**
 returns valid by checking x y and level and facility

 @return return valid if no field has an invalid value
 */
- (BOOL)isValid;

/**
 returns valid by checking x y and level
 @warning it does not check facility or venue
 @return bool valid position
 */
- (BOOL)isValidExceptVenueFacility;

- (PTRPosition)convertToPosition;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 * X coordinate (if inside facility)
 * INVALID_POSITION by default
 */
@property (nonatomic, readonly) float x;

/**
 * Y coordinate (if inside facility)
 * INVALID_POSITION by default
 */
@property (nonatomic, readonly) float y;

/**
 * Geographic latitude coordinate
 * INVALID_GEO_POSITION by default
 * @warn It might not be possible to calculate latitude
 */
@property (nonatomic, readonly) double lat;

/**
 * Geographic longitude coordinate
 * INVALID_GEO_POSITION by default
 * @warn It might not be possible to calculate longitude
 */
@property (nonatomic, readonly) double lon;

/**
 * Level / Floor number
 */
@property (nonatomic, readonly) int level;

/**
 * Internal identifier of location's venue
 */
@property (nonatomic, readonly) int venueId;

/**
 * Internal identifier of location's facility
 */
@property (nonatomic, readonly) int facilityId;

@end
