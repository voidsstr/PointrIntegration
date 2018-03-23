//
//  PTRMapVersion.h
//  Pods
//
//  Created by Ege AKPINAR on 04/06/2017.
//
//

#import "Foundation/Foundation.h"

// Data
#import "PTRDataTypes.h"

@interface PTRMapVersion : NSObject
NS_ASSUME_NONNULL_BEGIN
/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 * Version number of map
 */
@property (nonatomic, readonly) int version;

/**
 *  Width of tiled map in pixels
 *  For raster map, get dimensions directly from the map image
 *  @warn Only valid if type is PTRMapTypeTiled
 */
@property (nonatomic, readonly) float width;

/**
 *  Height of tiled map in pixels
 *  For raster map, get dimensions directly from the map image
 *  @warn Only valid if type is PTRMapTypeTiled
 */
@property (nonatomic, readonly) float height;

/**
 * Level of detail, used internally for scaling map across screen
 * Calculated dynamically based on screen and map dimensions
 */
@property (nonatomic, readonly) int levelOfDetail;

/**
 * URL address for low resolution raster map
 */
@property (nonatomic, readonly) NSString *levelTitle;

/**
 * Type of map (raster, tiled, etc.)
 * @warn Type wil be initially PTRDataTypeNone. It will only be specified during local storage.
 */
@property (nonatomic, readonly) PTRDataType mapType;

/**
 * URL address for low resolution raster map
 */
@property (nonatomic, readonly) NSString *_Nullable urlRasterLowResolution;

/**
 * URL address for standard resolution raster map
 */
@property (nonatomic, readonly) NSString *_Nullable urlRaster;

/**
 * URL address for archive containin map tiles
 */
@property (nonatomic, readonly) NSString *_Nullable urlTileArchive;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

- (instancetype _Nonnull)initWithVersion:(int)version
                                   width:(float)width
                                  height:(float)height
                              levelTitle:(NSString *)levelTitle
                                 mapType:(PTRDataType)mapType
                  urlRasterLowResolution:(NSString *_Nullable)urlRasterLowResolution
                               urlRaster:(NSString *_Nullable)urlRaster
                          urlTileArchive:(NSString *_Nullable)urlTileArchive;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Helper methods
/////////////////////////////////////////////////////////////////////////

/**
 * Name used for storing / accessing tiles
 */
+ (NSString *_Nonnull)tileNameForLevel:(int)level scale:(int)scale row:(int)row column:(int)column;

NS_ASSUME_NONNULL_END
@end
