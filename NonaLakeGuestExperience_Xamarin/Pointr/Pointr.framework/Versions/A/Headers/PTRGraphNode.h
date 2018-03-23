//
//  PTRGraphNode.h
//  Pointr
//
//  Created by Pointr Labs on 10/11/15.
//  Copyright © 2015 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Pathfinding
#import "PTRNodeInterface.h"
#import "PTRNeighbourInterface.h"
#import "PTRGraphNodeNeighbour.h"

// Positioning
#import "PTRLocation.h"

/**
 *  Nodes in graph
 *
 *  Eg.
 *
 *    {
 *      "id": 4583,
 *      "x": 0.537,
 *      "y": 0.355,
 *      "neighbours": [
 *          [
 *              4582,   -> Node id
 *              2       -> Speed
 *          ],
 *          [
 *              4562,
 *              1
 *          ],
 *          [
 *              4604,
 *              2
 *          ]
 *      ],
 *      "portalNeighbours": [
 *          120,
 *          130
 *      ]
 *    }
 *
 */
@interface PTRGraphNode : PTRNodeInterface <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

// TODO- For now, we're storing a lot of data per node. These can be optimised in the future (eg. venueId, facilityId)

/**
 *  Default initialiser
 *
 *  @param neighbours have specific class (rather than the generic interface)
 */
- (instancetype)initWithOriginalNodeId:(long)originalNodeId
                                     x:(float)x
                                     y:(float)y
                                 level:(int)level
                               venueId:(int)venueId
                            facilityId:(int)facilityId
                            neighbours:(NSArray<PTRGraphNodeNeighbour *> *)neighbours
                      portalNeighbours:(NSArray<NSNumber *> *)portalNeighbours;

/**
 *  Alternative initialiser with string portal neighbours
 *
 *  @param neighbours have specific class (rather than the generic interface)
 *  @param portalNeighbours of type string rather than number
 */
- (instancetype)initWithOriginalNodeId:(long)originalNodeId
                              location:(PTRLocation *)location
                            neighbours:(NSArray<PTRGraphNodeNeighbour *> *)neighbours
                   strPortalNeighbours:(NSArray<NSString *> *)portalNeighbours;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Checks if node has valid neighbours
 *  @warn Doesn't check if nodes exist
 *  @return YES if this node has neighbours and they are valid, NO otherwise
 */
- (BOOL)isValid;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
/////////////////////////////////////////////////////////////////////////

@property (nonatomic, readonly) long originalNodeId;  // As received from server

/**
 *  Array of portal neighbour identifiers
 *  @warn We convert from node id (numeric) to unique identifier (string)
 *  @warn These nodes are already contained within -neighbours // TODO- Maybe this is redundant?
 */
@property (nonatomic, readonly) NSArray<NSString *> *portalNeighbours;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Virtual properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Unique identifier assigned by SDK
 */
@property (nonatomic, readonly) NSString *uniqueIdentifier;

@end
