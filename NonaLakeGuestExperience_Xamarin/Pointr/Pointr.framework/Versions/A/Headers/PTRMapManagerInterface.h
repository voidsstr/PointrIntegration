//
//  PTRMapManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"
#import "UIKit/UIKit.h"

// Management
#import "PTRPointrManagerInterface.h"

// Data
#import "PTRDataTypes.h"

// Map
#import "PTRMapVersion.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declare dependencies
@protocol PTRDataManagerDelegate;
@protocol PTRConfigurationManagerDelegate;

/**
 *  MapManagerDelegate keeps track of map related updates.
 */
@protocol PTRMapManagerDelegate <NSObject>

@optional

/**
 *  Notifies when map data for current venue and facility are updated
 *  To listen to all data updates (for other venue and facilities), @see class PTRDataManagerInterface
 *  @warn This also gets called when venue/facility is changed, to trigger map updates everywhere
 *
 *  @param venueId      Identifier of venue where this map belongs
 *  @param facilityId   Identifier of facility where this map belongs
 *  @param level        Level of map
 *  @param mapType      Type of map
 *  @param isOnlineData Whether map data is from server (online) or local bundle (offline)
 */
- (void)onMapManagerMapUpdatedForVenue:(int)venueId
                              facility:(int)facilityId
                                 level:(int)level
                               mapType:(PTRDataType)mapType
                        dataFromOnline:(BOOL)isOnlineData;

/**
 *  Notifies when current map data is updated
 *  This could happen due to various reasons, including
 *  - data update
 *  - configuration update (venue or facility change)
 *
 *  Listeners should reload maps once they hear this callback
 */
- (void)onMapManagerCurrentMapsUpdated;

@end

/**
 * Main interface to manage accessing Map content
 * All methods assume currently configured venue
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRMapManagerInterface
    : PTRPointrManagerInterface <id<PTRMapManagerDelegate>> <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Getter for raster map image
 *  Assumes current venue
 *
 *  @param level Map floor
 *
 *  @return Raster image if found in storage, nil otherwise
 */
- (UIImage *_Nullable)getMapImageForLevel:(int)level forFacility:(int)facilityId;

/**
 *  Getter for map tile image
 *  Assumes current venue
 *
 *  @param level  indicates what level of the building
 *  @param row    the index indicating the row within the tile grid
 *  @param column the index indicating the column within the tile grid
 *  @param scale  the zoom level
 *
 *  @return returns the specific image for the tile
 */
- (UIImage *_Nullable)getMapTileImageForLevel:(int)level
                                  forFacility:(int)facilityId
                                          row:(NSInteger)row
                                       column:(NSInteger)column
                                        scale:(NSInteger)scale;

/**
 *  Returns details for currently stored version of map
 *  Assumes current venue
 */
- (PTRMapVersion *)getMapVersionForFacility:(int)facilityId level:(int)level;

/**
 *  List of all available levels, for current venue and facility
 *  @warn This list doesn't imply maps for these levels are available
 *  @return Array of all levels or nil if no level is found
 */
- (NSArray<NSNumber *> *_Nullable)availableLevels;

/**
 * Checks if there is tiled map content for specified property facilityId and property level
 *  Assumes current venue
 * @return YES if content is found in device storage, NO otherwise
 */
- (BOOL)hasTilesForFacility:(int)facilityId level:(int)level;

/**
 *  Checks if there is raster map content for specified property facilityId and property level
 *  Assumes current venue
 *  @return YES if content is found in device storage, NO otherwise
 */
- (BOOL)hasRasterImageForFacility:(int)facilityId level:(int)level;

/**
 *  Returns YES if full Map content is available (for current configuration)
 *  NO if it's not complete / missing (eg. one level missing)
 *  Assumes current venue
 */
- (BOOL)hasContent;

/**
 Bool if it level has content

 @param level Level number
 @return Returns YES if full Map content is available for given level
 */
- (BOOL)hasContentForLevel:(int)level;

/**
 Checks whether the Graph content is present & ready for the given venue

 @param venueId int venue id
 @param shouldAcceptRasterMapsAlso bool to accept rasterMaps if yes if a map only have raster but no tile it returns
 true if no it only returns yes if tile is ready
 @return BOOL Graph content is present & ready for the given venue
 */
- (BOOL)hasContentForVenue:(int)venueId shouldAcceptRasterMapsAlso:(BOOL)shouldAcceptRasterMapsAlso;
/**
 Returns string for level written in backend level title
 If not found returns predefined strings for level int (e.g. 1 = 1st level)

 @param level level
 @param facilityId facilityId
 @return string for level
 */
- (NSString *)stringForLevel:(int)level facility:(int)facilityId;

@end

NS_ASSUME_NONNULL_END
