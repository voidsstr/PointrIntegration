//
//  PTRSingletonProtocol.h
//  Pointr
//
//  Created by Pointr on 01/05/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PTRSingletonProtocol <NSObject>

@required

/**
 * Returns singleton instance for this class
 */
+ (_Nonnull instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
