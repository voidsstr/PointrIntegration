//
//  PTRGraphNodeNeighbour.h
//  Pods
//
//  Created by Ege AKPINAR on 08/06/2017.
//
//

#import "Foundation/Foundation.h"

// Pathfinding
#import "PTRNeighbourInterface.h"

/**
 *  Neighbour to a class PTRGraphNode
 */
@interface PTRGraphNodeNeighbour : PTRNeighbourInterface <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithOriginalNodeId:(long)originalNodeId speed:(int)speed facilityId:(int)facilityId;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Speed of this link (in m/s)
 */
@property (nonatomic, readonly) int speed;

@end
