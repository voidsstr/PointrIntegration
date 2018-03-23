//
//  PTROwnQueueProtocol.h
//  Pointr
//
//  Created by Pointr on 01/05/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PTROwnQueueProtocol <NSObject>

@required

/**
 * Returns dedicated queue of this class
 */
- (dispatch_queue_t)getQueue;

@end

NS_ASSUME_NONNULL_END
