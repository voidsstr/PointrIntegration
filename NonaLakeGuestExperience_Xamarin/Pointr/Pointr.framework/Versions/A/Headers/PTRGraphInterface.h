//
//  PTRGraph.h
//
//
//  Created by Pointr on 11/12/14.
//  Copyright (c) 2014 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

// Models
#import "PTRNodeInterface.h"

/**
 *  Object representing the Graph.
 */
@interface PTRGraphInterface : NSObject <NSCoding>

/**
 *  The dictionary of Nodes representing graph.
 *  NOTE- This contains all nodes, including portal nodes.
 */
@property (nonatomic, retain)
    NSDictionary<NSString *, PTRNodeInterface *> *allNodes;  // Key: Node unique identifier -> Value: Graph node

/**
 *  dx value for the graph
 *  Useful for debugging only
 */
@property (nonatomic, assign) float dx;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Returns NodeInterface object (GraphNode, PortalNode or InterFacilityPortalNode)
 *  for specified unique node identifier
 *
 *  @return PTRGraphNode object with the given ID. Nil if it does not exist.
 */
- (PTRNodeInterface *)getNodeWithIdentifier:(NSString *)nodeUniqueIdentifier;

/**
 *  Checks validity of graph (eg. node count)
 *
 *  @return YES if graph is valid, NO otherwise
 */
- (BOOL)isValid;

@end
