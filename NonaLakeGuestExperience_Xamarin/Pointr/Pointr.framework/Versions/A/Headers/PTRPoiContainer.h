//
//  PTRPoiContainer.h
//  Pointr
//
//  Created by Pointr Labs on 29/08/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRSortedDictionary.h"
#import "PTRPoiGroup.h"

NS_ASSUME_NONNULL_BEGIN

@class PTRPoi;

/**
 * Contains poi results of poi management search query
 */
@interface PTRPoiContainer : NSObject

/**
 Initialiser with a poi

 @param poi PTRPoi object put in container
 @return PTRContainer which has only one poi
 */
- (instancetype)initWithPoi:(PTRPoi *)poi;

/**
 Initialiser with a poiGroup

 @param poiGroup PTRPoiGroup object including pois
 @return PTRContainer which has only pois with initial poiGrops pois
 */
- (instancetype)initWithPoiGroup:(PTRPoiGroup *)poiGroup;

/**
 Initializes new Container with sortedDictionary puts objects in order that sorted dictionary gave

 @param sortedDict PTRSortedDictionary object
 @return PTRContainer created from PTRSortedDictionary
 */
- (instancetype)initWithSortedDictionary:(PTRSortedDictionary<NSString *, NSArray<PTRPoi *> *> *)sortedDict;

/**
 Gets poi Array of all contained pois for container

 @return Array of PTRPoi
 */
- (NSArray<PTRPoi *> *)getPoiList;

/**
 Gets PTRPoiGroup Array of all contained pois for container

 @return Array of PTRPoi
 */
- (NSArray<PTRPoiGroup *> *)getPoiGroupList;

@end

NS_ASSUME_NONNULL_END
