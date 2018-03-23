//
//  PTRAdvertiser.h
//  Pointr
//
//  Created by Pointr on 17/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Common interface that includes listener management
 */
@interface PTRAdvertiser <__covariant T> : NSObject {
   @protected
    NSHashTable<T> *_listeners;
}

/**
 * Adds listener to start receiving callbacks
 */
- (void)addListener:(T)listenerToAdd;

/**
 * Removes listener to stop receiving callbacks
 */
- (void)removeListener:(T)listenerToRemove;

/**
 * Notifies all listeners with given block
 */
- (void)notifyAllListeners:(void (^)(T listener))block;

@end

NS_ASSUME_NONNULL_END
