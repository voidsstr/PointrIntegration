//
//  PTRRegionMapDrawable.h
//  Pointr
//
//  Created by Erkan Sen on 20.12.2017.
//
//  Interface for regionDrawable object on mapView
//  Only difference from PTRMapDrawable is regionArray which includes the corners of the region
//  Simply add a id<PTRDrawble> object to mapView with addDrawable:
//

#import "UIKit/UIKit.h"
#import "PTRMapDrawable.h"

@protocol PTRRegionMapDrawable <PTRMapDrawable>
@required

/**
 PTRCorner array of region points
 */
@property (nonatomic, strong) NSArray<PTRCorner *> *_Nullable regionArray;

@end
