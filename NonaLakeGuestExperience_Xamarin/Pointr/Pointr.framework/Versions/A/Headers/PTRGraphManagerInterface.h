//
//  PTRGraphManagerInterface.h
//  Pointr
//
//  Created by Pointr Labs on 21/03/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Data
#import "PTRVenueGraph.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declare dependencies
@protocol PTRDataManagerDelegate;
@protocol PTRConfigurationManagerDelegate;

/**
 *  Keeps track of Graph related updates.
 */
@protocol PTRGraphManagerDelegate <NSObject>

@optional

/**
 *  Notifies listeners on Graph updates.
 */
- (void)onGraphManagerGraphUpdated;

@end

/**
 * Main interface to manage accessing Graph content
 * @warn This class deals with content only, for pathfinding see @PTRPathManagerInterface
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRGraphManagerInterface
    : PTRPointrManagerInterface <id<PTRGraphManagerDelegate>> <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Returns graph for current venue
 */
- (PTRVenueGraph *_Nullable)getGraph;

/**
 Checks whether the Graph content is present & ready for the given venue

 @param venueId int venue id
 @return BOOL Graph content is present & ready for the given venue
 */
- (BOOL)hasContentForVenue:(int)venueId;

@end

NS_ASSUME_NONNULL_END
