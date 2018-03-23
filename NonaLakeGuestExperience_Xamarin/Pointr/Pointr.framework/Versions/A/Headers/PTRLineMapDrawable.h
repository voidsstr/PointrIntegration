//
//  PTRLineMapDrawable.h
//  Pointr
//
//  Created by Erkan Sen on 20.12.2017.
//
//  Interface for lineDrawable object on mapView
//  Only difference from PTRMapDrawable is points array which includes the points of the line
//  Simply add a id<PTRDrawble> object to mapView with addDrawable:
//

#import "Foundation/Foundation.h"
#import "PTRMapDrawable.h"
#import "PTRLocation.h"

/**
 *  NOTE: Since ObjC doesn't support OO interfaces, this class is `implementing` PTRDrawable, rather than `extending` it
 */
@protocol PTRLineMapDrawable <PTRMapDrawable>

@required

/**
 PTRLocation array of region points
 */
@property (nonatomic, strong) NSArray<PTRLocation *> *_Nullable pointsArray;

@end
