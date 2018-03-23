//
//  PTRPoiManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"
#import "PTRPositionManagerInterface.h"

// Poi
#import "PTRPoi.h"
#import "PTRPoiContainer.h"

// Data Structure
#import "PTRSortedDictionary.h"

NS_ASSUME_NONNULL_BEGIN

// Forward declare dependencies
@protocol PTRDataManagerDelegate;
@protocol PTRConfigurationManagerDelegate;
@protocol PTRPositionManagerDelegate;

/**
 *  Delegate to keep track of Poi data updates
 */
@protocol PTRPoiManagerDelegate <NSObject>

@optional

/**
 *  Notifies when current Poi data is updated
 *  This could happen due to various reasons, including
 *  - data update
 *  - configuration update (venue or facility change)
 *
 *  Listeners should reload Pois once they hear this callback
 */
- (void)onPoiManagerCurrentPoisUpdated;

/**
 *  Notifies when a Poi is selected (typically as pathfinding destination)
 *
 *  @param poiSelection PTRPoiContainer object with the Selected Poi object.
 */
- (void)onPoiManagerSelectedPoi:(PTRPoiContainer *)poiSelection;

/**
 *  Notifies when user is detected inside a trigger Poi
 */
- (void)onPoiManagerEnterTrigger:(PTRPoi *)triggerPoi;

@end

/**
 * Main interface to manage accessing Poi content
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRPoiManagerInterface
    : PTRPointrManagerInterface <id<PTRPoiManagerDelegate>>
      <PTRDataManagerDelegate, PTRConfigurationManagerDelegate, PTRPositionManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Getters
/////////////////////////////////////////////////////////////////////////

/**
 Method which returns a poi with regionArray which shows the area of store to show

 @param level level
 @param facilityId facilityID
 @return drawable with regionArray
 */
- (id<PTRRegionMapDrawable>)getStoreLayoutPoiForLevel:(int)level forFacility:(int)facilityId;

/**
 * Retrieves users Poi selection
 *
 * @return RequestedPoi object.
 */
- (PTRPoiContainer *_Nullable)getSelectedPoi;

/**
 * Returns all Poi objects in current venue.
 * Sorted alphabetically ignoring case by title.
 * Note there might be multiple Poi objects with the same title.
 *
 * @return All pois
 */
- (PTRPoiContainer *_Nullable)getAllPoi;

/**
 * Returns all Poi objects, matching provided criteria, in current venue. Null criteria are ignored.
 * Sorted alphabetically ignoring case by title.
 * Note there might be multiple Poi objects with the same title.
 */
- (PTRPoiContainer *)getAllPoisOnLevel:(NSNumber *_Nullable)level
                              withType:(NSString *_Nullable)type
                            inFacility:(NSNumber *_Nullable)facilityId;

/**
 * Returns Poi object with specified identifier.
 *
 * @param identifier specifying the Poi.
 */
- (PTRPoiContainer *)getPoiWithIdentifier:(NSString *)identifier;

/**
 * Returns all Poi's with given name, in current venue.
 */
- (PTRPoiContainer *)getPoiByName:(NSString *)name;

/**
 Returns all Poi's types.

 @return array of poi type strings
 */
- (NSArray<NSString *> *_Nullable)getAllPoiTypes;

/**
 Checks whether the POI content is present & ready for the given venue
 It expect at least one POI to return true

 @param venueId int venue id
 @return BOOL POI content is ready for the given venue
 */
- (BOOL)hasContentForVenue:(int)venueId;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Search
/////////////////////////////////////////////////////////////////////////

/**
 * Returns PTRPoiContainer that match the given search string.
 * Search is done on single word typically and is case insensitive. If more than one word is supplied, an OR search is
 * performed using every word. Sorted alphabetically ignoring case by title.
 *
 * @param searchString the search string
 * @return the requested poi
 */
- (PTRPoiContainer *_Nullable)searchPoi:(NSString *)searchString;

/**
 * Returns PTRPoiContainer that match the given search string.
 * Search is done on single word typically and is case insensitive. If more than one word is supplied, an OR search is
 * performed using every word. Sorted alphabetically ignoring case by title.
 *
 * @param searchString the search string
 * @param facilityId the facility in which the search will done
 * @return the requested poi
 */
- (PTRPoiContainer *)searchPoi:(NSString *)searchString inFacility:(int)facilityId;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Poi selection
/////////////////////////////////////////////////////////////////////////

/**
 *  Resets user's selected Poi
 *  @warning This does not cancel navigation. This solely resets the cached Poi selection in this manager.
 */
- (void)resetSelectedPoiContainer;

/**
 * Marks user's Poi selection which is typically used as destination in navigation
 *
 *
 * @param poiSelection the poiSelection
 */
- (void)setSelectedPoiContainer:(PTRPoiContainer *)poiSelection;

@end

NS_ASSUME_NONNULL_END
