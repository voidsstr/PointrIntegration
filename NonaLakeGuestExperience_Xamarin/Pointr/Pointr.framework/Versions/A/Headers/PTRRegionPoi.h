//
//  PTRRegionPoi.h
//  Pointr
//
//  Created by Erkan Sen on 20.12.2017.
//

#import "Pointr.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRRegionPoi : PTRPoi <PTRRegionMapDrawable>

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
 @param regionArray NSValue(CGPoint) Array
 @param translations Dictionary mapping translation dictionaries to language code
 @param minZoomLevel NSString
 @param maxZoomLevel NSString
 @return A PTRPoi object representing a Portal as a point of interest.
 */
- (instancetype _Nullable)
initPoiWithIdentifier:(NSString *_Nonnull)identifier
                    x:(float)x
                    y:(float)y
                level:(int)level
              venueId:(int)venueId
           facilityId:(int)facilityId
                 name:(NSString *)name
           searchName:(NSString *)searchName
      longDescription:(NSString *_Nullable)longDescription
searchLongDescription:(NSString *_Nullable)searchLongDescription
             keywords:(NSArray<NSString *> *_Nullable)keywords
       searchKeywords:(NSArray<NSString *> *_Nullable)searchKeywords
                 type:(NSString *)type
           searchType:(NSString *)searchType
             isPortal:(BOOL)isPortal
          regionArray:(NSArray *_Nullable)regionArray
            extraData:(NSDictionary<NSString *, NSObject *> *_Nullable)extraData
         translations:(NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *_Nullable)translations
         minZoomLevel:(NSString *_Nullable)minZoomLevel
      andMaxZoomLevel:(NSString *_Nullable)maxZoomLevel;

/**
 PTRCorner array of region points
 */
@property (nonatomic, strong) NSArray<PTRCorner *> *_Nullable regionArray;

@end

NS_ASSUME_NONNULL_END
