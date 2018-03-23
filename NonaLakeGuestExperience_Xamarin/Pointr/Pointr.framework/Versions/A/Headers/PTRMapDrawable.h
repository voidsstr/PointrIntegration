//
//  PTRMapDrawable.h
//  Pods
//
//  Created by Erkan Sen on 26.09.2017.
//
//  Interface for all drawable object on mapView
//  Simply add a id<PTRDrawble> object to mapView with addDrawable:
//

#import "Foundation/Foundation.h"
#import "PTRCorner.h"

NS_ASSUME_NONNULL_BEGIN
@protocol PTRMapDrawable <NSObject>
@required
/**
 Position on screen.
 @warning The position values must be between [0,1] (ie : CGPointMake(0.25,0.56) )
 */
@property (nonatomic, assign) CGPoint centerPoint;

/**
 Zoom level that the drawable will start to show on map.
 Below this level of zoom drawable will be hidden
 */
@property (nonatomic) float minimumZoomLevel;

/**
 Zoom level that the drawable will shown until
 Above this level of zoom drawable will be hidden
 */
@property (nonatomic) float maximumZoomLevel;

/**
 Determines if the drawable will rotate or not.
 */
@property (nonatomic, assign) BOOL isRotatable;

/**
 Determines if the drawable will be tapable or not.
 */
@property (nonatomic, assign) BOOL isInteractive;

/**
 Determines if the drawable will be tapable or not.
 */
@property (nonatomic, assign) BOOL canBeHiddenWhenClashed;

/**
 Determines if the drawable will be tapable or not.
 */
@property (nonatomic, assign) BOOL canHideOthersWhenClashed;

/**
 *  Unique string ID
 */
@property (nonatomic, strong) NSString *identifier;

@end

NS_ASSUME_NONNULL_END
