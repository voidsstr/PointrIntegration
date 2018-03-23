//
//  PTRWallManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Data
#import "PTRWall.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declare dependencies
@protocol PTRDataManagerDelegate;
@protocol PTRConfigurationManagerDelegate;

/**
 *  Delegate to keep track of Wall data updates
 */
@protocol PTRWallManagerDelegate <NSObject>

@optional

/**
 *  Notifies when current Wall data is updated
 *  This could happen due to various reasons, including
 *  - data update
 *  - configuration update (venue or facility change)
 *
 *  Listeners should reload Walls once they hear this callback
 */
- (void)onWallManagerCurrentWallsUpdated;

@end

/**
 * Main interface to manage accessing Wall content
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRWallManagerInterface
    : PTRPointrManagerInterface <id<PTRWallManagerDelegate>> <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 * Returns all walls, in venue
 */
- (NSArray<PTRWall *> *)getAllWalls;

/**
 * Returns all walls, filtered for specified criteria, in venue
 */
- (NSArray<PTRWall *> *)getAllWallsOnLevel:(NSNumber *_Nullable)level inFacility:(NSNumber *_Nullable)facility;

/**
 Checks whether the Wall content is present & ready for the given venue
 It expect at least one wall to return true

 @param venueId int venue id
 @return BOOL Graph content is present & ready for the given venue
 */
- (BOOL)hasContentForVenue:(int)venueId;

@end

NS_ASSUME_NONNULL_END
