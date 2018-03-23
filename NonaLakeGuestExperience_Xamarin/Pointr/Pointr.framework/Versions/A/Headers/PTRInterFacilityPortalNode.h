//
//  PTRInterFacilityPortalNode.h
//  Pods
//
//  Created by Ege AKPINAR on 06/06/2017.
//
//

// Pathfinding
#import "PTRPortalNode.h"

@interface PTRInterFacilityPortalNode : PTRPortalNode <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

- (instancetype)initWithStartNode:(PTRPortalNodeChildNode *)startNode
                          endNode:(PTRPortalNodeChildNode *)endNode
                      isStartNode:(BOOL)isStartNode
                  startFacilityId:(int)startFacilityId
                    endFacilityId:(int)endFacilityId
                             type:(PTRNodeType)type
                       travelTime:(int)travelTime
                     isAccessible:(BOOL)isAccessible
                    isComfortable:(BOOL)isComfortable;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Internal identifier of facility where this inter facility portal begins from
 */
@property (nonatomic, readonly) int startFacilityId;

/**
 *  Internal identifier of facility where this inter facility portal ends at
 */
@property (nonatomic, readonly) int endFacilityId;

@end
