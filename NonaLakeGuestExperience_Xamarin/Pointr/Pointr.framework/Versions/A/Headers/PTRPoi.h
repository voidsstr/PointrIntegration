//
//  PTRPoi.h
//
//  Created by Pointr on 14/07/15
//  Copyright (c) 2015 Pointr Labs Ltd. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "UIKit/UIKit.h"
#import "PTRLocation.h"
#import "PTRRegionMapDrawable.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, PTRPoiZoomLevel) { PTRInvalidZoomLevel, PTROuterZoomLevel, PTRMediumZoomLevel, PTRInnerZoomLevel };

/**
 *  Object representing pointr of interests.
 */
@interface PTRPoi : NSObject <NSCoding, PTRMapDrawable>

/**
 * Location of Poi
 */
@property (nonatomic, readonly) PTRLocation *position;

/**
 *  Name of the point of interest
 */
@property (nonatomic, readonly) NSString *name;

/**
 *  Detailed description for point of interest.
 */
@property (nonatomic, readonly) NSString *_Nullable longDescription;

/**
 *  Keywords related to pointr of interest/
 */
@property (nonatomic, readonly)
    NSArray<NSString *> *_Nullable keywords;  // Array of keywords (originally separated by comma)

/**
 *  Type of the point of interest
 */
@property (nonatomic, readonly) NSString *type;

/**
 *  YES if portal POI, NO otherwise
 */
@property (nonatomic, readonly) BOOL isPortal;

/**
 Zoom level that the poi will start to show on map.
 */
@property (nonatomic, assign) PTRPoiZoomLevel minimumPoiZoomLevel;

/**
 Zoom level that the poi will shown until
 */
@property (nonatomic, assign) PTRPoiZoomLevel maximumPoiZoomLevel;

/**
 *  A dictionary representing any extra information.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSObject *> *_Nullable extraData;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

/**
 Default initalizer for native parser

 @param identifier NSString
 @param x float
 @param y float
 @param name NSString
 @param longDescription NSString
 @param keywords NSString array
 @param level int
 @param type NSString
 @param isPortal BOOL
 @param extraData Dictionary for arbitrary extra data
 @param translations Dictionary mapping translation dictionaries to language code
 @param minZoomLevel NSString
 @param maxZoomLevel NSString
 @return A PTRPoi object representing a Portal as a point of interest.
 */
- (instancetype _Nullable)
initPoiWithIdentifier:(NSString *)identifier
                    x:(float)x
                    y:(float)y
                level:(int)level
              venueId:(int)venueId
           facilityId:(int)facilityId
                 name:(NSString *)name
           searchName:(NSString *_Nullable)searchName
      longDescription:(NSString *_Nullable)longDescription
searchLongDescription:(NSString *_Nullable)searchLongDescription
             keywords:(NSArray<NSString *> *_Nullable)keywords
       searchKeywords:(NSArray<NSString *> *_Nullable)searchKeywords
                 type:(NSString *)type
           searchType:(NSString *_Nullable)searchType
             isPortal:(BOOL)isPortal
            extraData:(NSDictionary<NSString *, NSObject *> *_Nullable)extraData
         translations:(NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *_Nullable)translations
         minZoomLevel:(NSString *_Nullable)minZoomLevel
      andMaxZoomLevel:(NSString *_Nullable)maxZoomLevel;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////
/**
 Queries whether a given keyword is among the list of the Poi's keyword list

 @param keyword The keyword to be searched
 @return True if the keyword exist within the list;
 */
- (BOOL)containsKeyword:(NSString *)keyword;

/**
 Returns an image by default in terms of keywords if available

 @return UIImage default image
 */
- (nullable UIImage *)getDefaultImage;

- (void)fillZoomLevelPropertiesWithMapMinimumZoomScale:(float)minimumZoomScale
                                   mapMaximumZoomScale:(float)maximumZoomScale;

@end
NS_ASSUME_NONNULL_END
