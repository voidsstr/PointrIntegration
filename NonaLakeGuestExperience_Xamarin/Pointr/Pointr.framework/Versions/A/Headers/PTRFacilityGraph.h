//
//  PTRFacilityGraph.h
//  Pointr
//
//  Created by Ege AKPINAR on 25/02/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "PTRGraphInterface.h"

// Pathfinding
#import "PTRLevelGraph.h"
#import "PTRPortalNode.h"
#import "PTRInterFacilityPortalNode.h"

/**
 *  Graph for single facility
 */
@interface PTRFacilityGraph : PTRGraphInterface <NSCoding>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithFacilityId:(int)facilityId
                       portalNodes:(NSDictionary<NSString *, PTRPortalNode *> *)portalNodes
                       levelGraphs:(NSDictionary<NSNumber *, PTRLevelGraph *> *)levelGraphs;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Internal identifier of facility
 */
@property (nonatomic, readonly) int facilityId;

/**
 *  Portal nodes within this facility, typically used to change levels (eg. lift)
 *  Mapped by internal graph node id
 */
@property (nonatomic, readonly) NSDictionary<NSString *, PTRPortalNode *> *portalNodes;

/**
 *  Graph per level in this facility
 *  Mapped by numeric level
 */
@property (nonatomic, readonly) NSDictionary<NSNumber *, PTRLevelGraph *> *levelGraphs;

@end
