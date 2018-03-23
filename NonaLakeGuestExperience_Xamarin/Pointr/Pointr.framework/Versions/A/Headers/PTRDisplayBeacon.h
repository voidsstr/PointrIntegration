//
//  PTRDisplayBeacon.h
//
//  Created by Pointr on 20/02/15.
//  Copyright (c) 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRDisplayBeacon : NSObject

@property (nonatomic, assign) int level;
@property (nonatomic, assign) float x;
@property (nonatomic, assign) float y;
@property (nonatomic, assign) float accuracy;  // Radius accuracy in metres
@property (nonatomic, assign) float distance;

@end

NS_ASSUME_NONNULL_END
