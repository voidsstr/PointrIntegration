//
//  PTRPathDirection.h
//  Pointr
//
//  Created by Pointr Labs on 17/09/2015.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "PTRNodeInterface.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PTRPathDirectionType) {
    PTRPathDirectionGoStraight,
    PTRPathDirectionTurnSlightLeftAndKeepStraight,
    PTRPathDirectionTurnLeft,
    PTRPathDirectionTurnSlightRightAndKeepStraight,
    PTRPathDirectionTurnRight,
    PTRPathDirectionChangeLevel,
    PTRPathDirectionRotateBack,
    PTRPathDirectionRotateLeft,
    PTRPathDirectionRotateRight,
    PTRPathDirectionPrepareToTurnRight,
    PTRPathDirectionPrepareToTurnLeft,
    PTRPathDirectionChangeFacility,
    PTRPathDirectionSecurity,
    PTRPathDirectionBorderControl
};
// TODO- Add different types for lift/escalator/staircase
// TODO- Add different types for left turn, U-turn, or 180+ turn

/**
 Building block of turn by turn directions for path objects
 */
@interface PTRPathDirection : NSObject <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  Where this direction should be applied
 */
@property (nonatomic, readonly) PTRNodeInterface *startNode;

/**
 *  Where this direction should end (NOTE- Might be nil for single node directions)
 */
@property (nonatomic, readonly) PTRNodeInterface *endNode;

/**
 *  Type enumeration of the path direction
 */
@property (nonatomic, readonly) PTRPathDirectionType type;

/**
 *  Human readable explanation of direction
 */
@property (nonatomic, readonly) NSString *message;

/**
 *  Angle of turn, with respect to walking direction (in radians, valid only for turns)
 */
@property (nonatomic, readonly) float angle;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Initialisers
/////////////////////////////////////////////////////////////////////////

/**
 *  Direction to go straight between nodes
 *
 *  @param start Starting point (node).
 *  @param end   End point (node).
 *
 *  @return Path direction between the given nodes.
 */
- (instancetype)initStraightDirectionFrom:(PTRNodeInterface *)start to:(PTRNodeInterface *)end;

/**
 *  Direction to make a turn at given node.
 *
 *  @param node   Next node to be arrived.
 *  @param isLeft Flag determining if its a left turn.
 *  @param angle  Angle respective to travel path, in radians
 *
 *  @return Path direction at the specified node.
 */
- (instancetype)initTurnDirectionAtNode:(PTRNodeInterface *)node isLeft:(BOOL)isLeft withAngle:(float)angle;

/**
 *  Direction to make a slight turn at given node and continue straight
 *
 *  @param node   Next node to be arrived.
 *  @param isLeft Flag determining if its a left turn.
 *  @param angle  Angle respective to y-axis, in radians
 *
 *  @return Path direction at the specified node.
 */
- (instancetype)initTurnSlightDirectionAtNode:(PTRNodeInterface *)node isLeft:(BOOL)isLeft withAngle:(float)angle;

/**
 *  Direction to change level between nodes
 *
 *  @param start Starting point (node).
 *  @param end   End point (node).
 *
 *  @return Path direction between specified nodes.
 */
- (instancetype)initChangeLevelDirectionFrom:(PTRNodeInterface *)start to:(PTRNodeInterface *)end;

/**
 *  Direction to change facility between nodes
 *
 *  @param start Starting point (node).
 *  @param end   End point (node).
 *
 *  @return Path direction between specified nodes.
 */
- (instancetype)initChangeFacilityDirectionFrom:(PTRNodeInterface *)start to:(PTRNodeInterface *)end;

/**
 *  Direction to pass through Security
 *
 *  @param start Starting point (node)
 *  @param end  End point (node)
 */
- (instancetype)initSecurityDirectionFrom:(PTRNodeInterface *)start to:(PTRNodeInterface *)end;

/**
 *  Direction to pass through Border Control
 *
 *  @param start Starting point (node)
 *  @param end  End point (node)
 */
- (instancetype)initBorderControlDirectionFrom:(PTRNodeInterface *)start to:(PTRNodeInterface *)end;

/**
 * Represents a direction with direction type and angle.
 * @param type Represented path direction type.
 * @param angle Angle value of turn
 * @return Direction representing only type
 */
- (instancetype)initWithType:(PTRPathDirectionType)type andWithAngle:(float)angle;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Updates start node. This method is used to reuse direction objects and be able to update their start nodes (e.g. as
 * you progress on this path) Only sensible for continuous direction objects (such as 'straight' or 'slight turn and
 * straight' types)
 *
 *  @param newStartNode New start node for path
 */
- (void)updateStartNodeTo:(PTRNodeInterface *)newStartNode;

@end

NS_ASSUME_NONNULL_END
