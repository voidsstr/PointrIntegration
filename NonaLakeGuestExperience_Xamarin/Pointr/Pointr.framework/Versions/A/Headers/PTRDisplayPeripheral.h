//
//  PTRDisplayPeripheral.h
//
//  Created by Pointr on 18/04/15.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Object class representing other displayable positions.
 */
@interface PTRDisplayPeripheral : NSObject

/**
 *  The floor on which the peripheral is.
 */
@property (nonatomic, assign) int level;

/**
 *  X Coordinate of the peripheral's position
 */
@property (nonatomic, assign) float x;

/**
 *  Y Coordinate of the peripheral's position
 */
@property (nonatomic, assign) float y;

/**
 *  Heading rotation in radians, including venue offset
 */
@property (nonatomic, assign) float rotation;

/**
 *  Name of the peripheral
 */
@property (nonatomic, strong) NSString *name;

/**
 *  Unique identifier of the peripheral
 */
@property (nonatomic, strong) NSString *identifier;

/**
 *  RSSI value of the peripheral
 */
@property (nonatomic, assign) int rssi;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Default initialisation method
 *
 *  @param dictionary JSON dictionary representation
 *
 *  @return PTRDisplayPeripheral object or nil if there is an error.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
