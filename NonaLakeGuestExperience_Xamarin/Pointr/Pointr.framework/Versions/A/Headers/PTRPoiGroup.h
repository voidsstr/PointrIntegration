//
//  PTRPoiGroup.h
//  Pointr
//
//  Created by Erkan Sen on 20.11.2017.
//

#import "Foundation/Foundation.h"
#import "PTRPoi.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRPoiGroup : NSObject
/**
 * PTRPoiGroup represents POI's which have same name and type.
 */
@property (strong, nonatomic, readonly) NSString *groupName;
@property (strong, nonatomic, readonly) NSString *groupType;
@property (strong, nonatomic, readonly) NSString *groupDescription;
@property (strong, nonatomic) NSArray<PTRPoi *> *poiList;

/**
 * Initialises a POI group with a name and an NSArray of PTRPoi elements with the given name.
 */
- (instancetype)initWithPoiList:(NSArray<PTRPoi *> *)poiList;

@end

NS_ASSUME_NONNULL_END
