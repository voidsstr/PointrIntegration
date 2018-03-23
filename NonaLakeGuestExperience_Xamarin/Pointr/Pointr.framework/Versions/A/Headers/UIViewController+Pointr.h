//
//  UIViewController+Pointr.h
//
//  Created by Pointr Labs on 27/12/2014.
//  Copyright (c) 2014 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

@interface UIViewController (Pointr)

/////////////////////////////////////////////////////////////////////////
#pragma mark - Transitions
/////////////////////////////////////////////////////////////////////////

/**
 Custom implementation of pushing a VC onto the current VC
 */
- (void)_transitionTo:(UIViewController *)vc withCompletion:(void (^)(void))block;

/**
 Custom implementation of popping back the VC
 */
- (void)_popBackWithCompletion:(void (^)(void))block;

@end
