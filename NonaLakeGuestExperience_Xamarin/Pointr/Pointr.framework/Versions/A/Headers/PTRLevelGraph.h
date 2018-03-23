//
//  PTRLevelGraph.h
//  Pointr
//
//  Created by Ege AKPINAR on 25/02/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "PTRGraphInterface.h"

// Pathfinding
#import "PTRGraphNode.h"

/**
 *  Graph for single level in a single facility
 */
@interface PTRLevelGraph : PTRGraphInterface <NSCoding>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithFacilityId:(int)facilityId level:(int)level nodes:(NSArray<PTRGraphNode *> *)nodes;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Level / Floor
 */
@property (nonatomic, readonly) int level;

/**
 *  Internal identifier of facility, where this level graph is found
 */
@property (nonatomic, readonly) int facilityId;

@end
