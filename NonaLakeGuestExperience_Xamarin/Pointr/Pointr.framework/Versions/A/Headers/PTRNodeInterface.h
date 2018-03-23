//
//  PTRNodeInterface.h
//  Pods
//
//  Created by Ege AKPINAR on 07/06/2017.
//
//

#import "Foundation/Foundation.h"

// Positioning
#import "PTRNeighbourInterface.h"
#import "PTRLocation.h"

/**
 * Types of nodes used for pathfinding and turn by turn directions.
 */
typedef NS_ENUM(int, PTRNodeType) {
    PTRNodeTypeUnknown,   // Not initialised
    PTRNodeTypeRegular,   // Regular walking node
    PTRNodeTypeRotation,  // Fake node to indicate rotation (eg. "rotate left")
    PTRNodeTypeTurn,      // Regular walking node, with a turn (eg. "turn left")
    PTRNodeTypeLift,
    PTRNodeTypeEscalator,
    PTRNodeTypeTravelator,        // Walking band / slide
    PTRNodeTypeAngularStairs,     // Stairs with an angle (different x,y on different floors)
    PTRNodeTypeRotationalStairs,  // Staircase (same x,y on each floor)
    PTRNodeTypeServiceLift,       // Lift for service / internal use
    PTRNodeTypeSecurityControl,   // Security checkpoint (eg. at the airport entrance)
    PTRNodeTypeBorderControl,     // Border control checkpoint (eg. at the immigration border)
    PTRNodeTypeRamp,
    PTRNodeTypeSteps,          // Small steps on a floor
    PTRNodeTypeServiceStairs,  // Stairs for service
    PTRNodeTypeTrain,
    PTRNodeTypeShuttle,
    PTRNodeTypeMetro
};

/**
 *  Interface for all nodes, used in pathfinding
 *  Current implementing classes are class PTRGraphNode, class PTRPortalNode and class PTRInterFacilityPortalNode
 */
@interface PTRNodeInterface : NSObject <NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Unique identifier, used to identify this node
 *  Created internally by SDK
 */
- (NSString *_Nonnull)uniqueIdentifier;

/**
 *  Location of this node
 */
- (PTRLocation *_Nonnull)location;

/**
 *  Type of this node
 *  @see PTRNodeType enumeration above
 */
- (PTRNodeType)type;

/**
 *  All neighbours of this node
 */
- (NSArray<PTRNeighbourInterface *> *_Nullable)neighbours;

/**
 *  Checks if node has a portal type such as lifts or stairs or shuttle
 *  @return YES if node is of portal type, NO otherwise
 */
- (BOOL)isPortalType;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Helper methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Used to convert data (from server of offline) to enum
 *  @warn This method does not revert method stringFromNodeType:
 */
+ (PTRNodeType)typeFromString:(NSString *_Nullable)typeString;

/**
 *  String to represent type
 *  @warn This method does not revert method typeFromString:
 */
+ (NSString *_Nonnull)stringFromNodeType:(PTRNodeType)type;

/**
 *  User friendly string to represent type, to be displayed to users
 *  @warn This method does not revert method typeFromString:
 */
+ (NSString *_Nonnull)friendlyStringFromNodeType:(PTRNodeType)type;

@end
