//
//  PTRNeighbourInterface.h
//  Pods
//
//  Created by Ege AKPINAR on 06/06/2017.
//
//

#import "Foundation/Foundation.h"

/**
 *  Interface for neighbour from a Node to another Node
 *  Common implementing class is class PTRGraphNodeNeighbour
 */
@interface PTRNeighbourInterface : NSObject <NSCoding>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithOriginalNodeId:(long)originalNodeId facilityId:(int)facilityId;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Checks if neighbour is initialised
 *  @warn Doesn't check whether neighbour node exists or not
 *  @return YES if neighbour is initialised, NO by default
 */
- (BOOL)isValid;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Unique identifier, indicating neighbour graph node
 */
@property (nonatomic, readonly) NSString *uniqueIdentifier;

/**
 *  Original node id of neighbour
 */
@property (nonatomic, readonly) long originalNodeId;

@end
