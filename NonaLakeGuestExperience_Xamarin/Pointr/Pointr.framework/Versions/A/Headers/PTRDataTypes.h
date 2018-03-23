//
//  PTRDataTypes.h
//  Pointr
//
//  Created by Pointr Labs on 22/02/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

typedef NS_ENUM(NSInteger, PTRDataType) {
    PTRDataTypeNone,

    PTRDataTypeBaseConfiguration,
    PTRDataTypeVenueConfiguration,
    PTRDataTypeFacilityConfiguration,

    PTRDataTypeVenueDataVersions,
    PTRDataTypeFacilityDataVersions,

    PTRDataTypeVenueGraph,
    PTRDataTypeFacilityGraph,

    PTRDataTypeRasterMap,
    PTRDataTypeTiledMap,

    PTRDataTypeVenuePois,
    PTRDataTypeFacilityPois,

    PTRDataTypeVenueWalls,
    PTRDataTypeFacilityWalls,

    PTRDataTypeUserSession,

    PTRDataTypeVenueBeacons,

    PTRDataTypeAll
};

@interface PTRDataTypes : NSObject

/////////////////////////////////////////////////////////////////////////
#pragma mark - Helper methods
/////////////////////////////////////////////////////////////////////////

/**
 * Convert type to String
 */
+ (NSString *)dataTypeToString:(PTRDataType)type;

@end
