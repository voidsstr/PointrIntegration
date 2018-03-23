//
//  PTRPortalNode.h
//  Pointr
//
//  Created by Pointr on 25/02/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "PTRGraphNode.h"

// Pathfinding
#import "PTRNodeInterface.h"
#import "PTRPortalNodeChildNode.h"

/**
 *  Portal nodes in graph, used for navigating across levels usually (eg. lift)
 */
@interface PTRPortalNode : PTRNodeInterface <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithStartNode:(PTRPortalNodeChildNode *)startNode
                          endNode:(PTRPortalNodeChildNode *)endNode
                      isStartNode:(BOOL)isStartNode
                             type:(PTRNodeType)type
                       travelTime:(int)travelTime
                     isAccessible:(BOOL)isAccessible
                    isComfortable:(BOOL)isComfortable
                       facilityId:(int)facilityId;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Checks if node has start and end nodes
 *  @return YES if valid, NO otherwise
 */
- (BOOL)isValid;

/**
 *  Unlike PTRGraphNode, this class allows adding neighbours post initialisation
 *  This is useful for performance
 *  @warn You can only add neighbours for endNode. Trying to add neighbours to startNode will cause exception.
 */
- (void)addNeighbour:(PTRNeighbourInterface *)neighbour;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Portal starts from this node
 */
@property (nonatomic, readonly) PTRPortalNodeChildNode *startNode;

/**
 *  Portal ends at this node
 */
@property (nonatomic, readonly) PTRPortalNodeChildNode *endNode;

/**
 *  Each portal node contains two nodes
 *  This flag determines which
 *
 *  @return YES if this node represents its startNode
 *  NO if this node represents its endNode
 */
@property (nonatomic, readonly) BOOL isStartNode;

/**
 *  Type of node (eg. lift, staircase)
 */
@property (nonatomic, readonly) PTRNodeType type;

/**
 *  Travel time (of using this portal) in seconds
 */
@property (nonatomic, readonly) int travelTime;

/**
 *  YES if this portal is step-free, suitable for users with accessibility needs
 *  NO otherwise
 */
@property (nonatomic, readonly) BOOL isAccessible;

/**
 *  YES if this portal is suitable for large groups (eg. family with kids)
 *  NO otherwise
 */
@property (nonatomic, readonly) BOOL isComfortable;

@end
