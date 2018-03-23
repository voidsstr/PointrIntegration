//
//  PTRDataManagerInterface.h
//  Pointr
//
//  Created by Pointr on 18/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Data
#import "PTRDataTypes.h"

NS_ASSUME_NONNULL_BEGIN

// Forward declare dependencies
@protocol PTRConfigurationManagerDelegate;
@protocol PTRUserManagerDelegate;
@protocol PTRPositionManagerDelegate;

@protocol PTRDataManagerDelegate <NSObject>

@optional

/**
 *  Notifies listeners when all data needed for displaying a venue is available
 *  @warn Note this doesn't mean data is latest. It only means there is valid data to show.
 *  @warn Both raster maps and tile maps are considered for this check.
 *
 *  @param venueId          Identifier of venue where this data belongs to
 */
- (void)onDataManagerReadyForVenue:(int)venueId;

/**
 *  Notifies listeners when Data Manager starts data management for venue and/or facility
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 */
- (void)onDataManagerStartDataManagementForVenue:(int)venueId
                                        facility:(int)facilityId
                                  dataFromOnline:(BOOL)isOnlineData;

/**
 * Notifies listeners when all data processing (both offline and online) have been completed.
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param isSuccessful     Whether all updates have succeeeded or not
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 *  @param errorMessages    (Nullable) A dictionary containing error messages (if any), mapped by data type
 */
- (void)onDataManagerCompleteAllForVenue:(int)venueId
                                facility:(int)facilityId
                            isSuccessful:(BOOL)isSuccessful
                          dataFromOnline:(BOOL)isOnlineData
                           errorMessages:(NSDictionary<NSNumber *, NSString *> *_Nullable)errorMessages;

/**
 *  Notifies listeners when a specific type of data (either offline or online) has started to be processed
 *
 *  @warn This is not triggered for maps. For maps, @see method
 * onDataManagerBeginProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline and method
 * onDataManagerEndProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param dataType         Type of data
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 */
- (void)onDataManagerBeginProcessingDataForVenue:(int)venueId
                                        facility:(int)facilityId
                                        dataType:(PTRDataType)dataType
                                  dataFromOnline:(BOOL)isOnlineData;

/**
 *  Notifies listeners when a specific type of data (either offline or online) has completed processing (whether
 * successful or not)
 *
 *  @warn This is not triggered for maps. For maps, @see method
 * onDataManagerBeginProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline and method
 * onDataManagerEndProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param dataType         Type of data
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 *  @param isSuccessful     Whether update has succeeeded or not
 *  @param errorMessages    (Nullable) A list of error message (if any)
 */
- (void)onDataManagerEndProcessingDataForVenue:(int)venueId
                                      facility:(int)facilityId
                                      dataType:(PTRDataType)dataType
                                dataFromOnline:(BOOL)isOnlineData
                                  isSuccessful:(BOOL)isSuccessful
                                 errorMessages:(NSArray<NSString *> *_Nullable)errorMessages;

/**
 *  Notifies listeners when a map update has started
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param level            Level of map
 *  @param mapType          Type of map
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 */
- (void)onDataManagerBeginProcessingMapUpdateForVenue:(int)venueId
                                             facility:(int)facilityId
                                                level:(int)level
                                              mapType:(PTRDataType)mapType
                                       dataFromOnline:(BOOL)isOnlineData;

/**
 *  Notifies listeners when a map update has completed
 *
 *  @param venueId          Identifier of venue where this map belongs (or INVALID_VENUE if data management is not venue
 * specific)
 *  @param facilityId       Identifier of facility where this map belongs (or INVALID_FACILITY if data management is not
 * facility specific)
 *  @param level            Level of map
 *  @param mapType          Type of map
 *  @param isOnlineData     Whether data is from server (online) or local bundle (offline)
 *  @param isSuccessful     Whether update has succeeeded or not
 *  @param errorMessages    (Nullable) A list of error message (if any)
 */
- (void)onDataManagerEndProcessingMapUpdateForVenue:(int)venueId
                                           facility:(int)facilityId
                                              level:(int)level
                                            mapType:(PTRDataType)mapType
                                     dataFromOnline:(BOOL)isOnlineData
                                       isSuccessful:(BOOL)isSuccessful
                                      errorMessages:(NSArray<NSString *> *_Nullable)errorMessages;

@end

/**
 *  Data Manager is responsible for all data management (online and offline)
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRDataManagerInterface
    : PTRPointrManagerInterface <id<PTRDataManagerDelegate>> <PTRConfigurationManagerDelegate, PTRUserManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 * Loads Base Configuration from data storage
 */
- (void)loadBaseConfiguration;

/**
 * Loads Configuration from data storage and online
 * NOTE- This method assumes no configuration for facility exists and should only be called in that case
 */
- (void)loadConfigurationForFacility:(int)facilityId;

/**
 *  Returns YES if venue has all content (maps, poi's, etc.) available to display
 *  @param shouldAcceptRasterMapsAlso If YES, raster maps or tile maps are considered.
 *  If NO, only tile maps are considered.
 */
- (BOOL)isContentReadyForVenue:(int)venueId shouldAcceptRasterMapsAlso:(BOOL)shouldAcceptRasterMapsAlso;

/**
 prioritises Map image for level because need this level map

 @param level NSNumber value of level
 */
- (void)prioritiseMapLevel:(NSNumber *)level;

/**
 Return if map with given parameters is in proccessing queue

 @warn If user is offline, this map data might never become available. This method only indicates whether
 the queue contains map for given parametres

 @param level int level
 @param facilityId id of facility for map
 @param venueId id of venue for map
 @return BOOL is Loading
 */
- (BOOL)isLoadingMapForLevel:(int)level facility:(int)facilityId venue:(int)venueId;

@end

NS_ASSUME_NONNULL_END
