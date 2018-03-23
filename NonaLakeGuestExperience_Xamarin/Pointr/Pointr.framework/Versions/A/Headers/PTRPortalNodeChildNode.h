//
//  PTRPortalNodeChildNode.h
//  Pods
//
//  Created by Ege AKPINAR on 06/06/2017.
//
//

#import "Foundation/Foundation.h"

@interface PTRPortalNodeChildNode : NSObject <NSCoding, NSCopying>

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Default initialiser method
 */
- (instancetype)initWithOriginalNodeId:(long)originalNodeId x:(float)x y:(float)y level:(int)level;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Checks if coordinates are valid
 *  @return YES if coordinates are valid, NO otherwise
 */
- (BOOL)isValid;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

@property (nonatomic, readonly) long originalNodeId;  // As received from server
@property (nonatomic, readonly) float x;              // Normalised X coordinate
@property (nonatomic, readonly) float y;              // Normalised Y coordinate
@property (nonatomic, readonly) int level;            // Level / Floor

@end
