//
//  NSURL+Pointr.h
//  Pointr
//
//  Created by Pointr Labs on 05/04/2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

@interface NSURL (Pointr)

/**
 Exception-safe version of default initialiser
 */
- (instancetype)_safeInitWithString:(NSString *)URLString;

@end
