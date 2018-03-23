//
//  PTRAnalyticsManagerInterface.h
//  Pointr
//
//  Created by Pointr on 05/12/2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declare dependencies
@protocol PTRDataManagerDelegate;
@protocol PTRPoiManagerDelegate;
@protocol PTRGeofenceManagerDelegate;

typedef NS_ENUM(int, PTRAnalyticsType) {
    PTRAnalyticsStartedLibrary,
    PTRAnalyticsStartedPathfinding,
    PTRAnalyticsSearchedPoi,
    PTRAnalyticsCancelledPoiSearch,
    PTRAnalyticsCancelledPathfinding,
    PTRAnalyticsArrivedDestination,
    PTRAnalyticsPathDistanceChanged
};

/**
 * Main interface for managing app analytics (eg. number of sessions, number of searches)
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRAnalyticsManagerInterface
    : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRPoiManagerDelegate, PTRGeofenceManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Properties
/////////////////////////////////////////////////////////////////////////

/**
 Current analytics statistics
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSNumber *> *currentStatistics;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Methods
/////////////////////////////////////////////////////////////////////////

/**
 Adds/updates statistics data for given types with given information

 @param type Analytics type to update.
 @param extraInfo Information provided for analytics.
 */
- (void)updateStatistics:(PTRAnalyticsType)type extraInfo:(nullable NSDictionary *)extraInfo;

/**
 * Sends current statistics data to designated server.
 */
- (void)flushCache;

@end

NS_ASSUME_NONNULL_END
