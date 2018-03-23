//
//  NSDictionary+Pointr.h
//  Pointr
//
//  Created by Pointr Labs on 09/11/2015.
//  Copyright © 2015 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

@interface NSDictionary (Pointr)

/**
 Returns object as per usual. Catches if [NSNull null] exists and returns nil if so.
 */
- (id)_objectOrNilForKey:(id)key;

/**
 Returns key objects in a sorted manner.
 */
- (NSArray *)_allKeysSorted;

@end
