//
//  PTRVenueGraph.h
//  Pointr
//
//  Created by Ege AKPINAR on 25/02/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "PTRGraphInterface.h"

#import "PTRLineMapDrawable.h"
// Pathfinding
#import "PTRFacilityGraph.h"
#import "PTRInterFacilityPortalNode.h"

static NSString *const kPTRKeyVenueGraph = @"kPTRKeyVenueGraph";
@interface PTRVenueGraph : PTRGraphInterface <NSCoding, PTRLineMapDrawable>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithVenueId:(int)venueId
                 facilityGraphs:(NSDictionary<NSNumber *, PTRFacilityGraph *> *)facilityGraphs
       interFacilityPortalNodes:(NSDictionary<NSString *, PTRInterFacilityPortalNode *> *)interFacilityPortalNodes;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Internal identifier of venue
 */
@property (nonatomic, readonly) int venueId;

/**
 *  Graph per facility in this venue
 *  Mapped by facility identifier
 */
@property (nonatomic, readonly) NSDictionary<NSNumber *, PTRFacilityGraph *> *facilityGraphs;

/**
 *  Portals across facilities, within same venue, used to change facility (eg. shuttle from one terminal to another at
 * an airport) Mapped by node unique identifier
 */
@property (nonatomic, readonly) NSDictionary<NSString *, PTRInterFacilityPortalNode *> *interFacilityPortalNodes;

@end
