//
//  PTRMapMathAlgorithms.h
//  Pods
//
//  Created by Erkan on 11.08.2017.
//
//

#import "Foundation/Foundation.h"
#import "PTRMapDrawable.h"
#import "PTRLocation.h"
#import "PTRMapView.h"
@class PTRTiledMapView;

@interface PTRMapMathAlgorithms : NSObject

+ (float)calculateMinimumZoomScaleForMapSize:(CGSize)mapSize scale:(PTRMapViewMinimumZoomScale)scale;

+ (CGPoint)screenPositionOfPoint:(CGPoint)point inTiledMapView:(PTRTiledMapView *)map;

+ (CGPoint)screenPositionForDrawable:(id<PTRMapDrawable>)drawable inTiledMapView:(PTRTiledMapView *)map;

+ (CGPoint)screenPositionFromLocation:(PTRLocation *)location withScreenRect:(CGRect)screenRect;

+ (CGPoint)screenPositionFromPoint:(CGPoint)point withScreenRect:(CGRect)screenRect;

@end
