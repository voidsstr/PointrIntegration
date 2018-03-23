//
//  PTRLevelSelectorVC.h
//  Pointr
//
//  Created by Erkan on 20.04.2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

/**
 The main delegate to handle any interactions regarding the levelSelector.
 */
@protocol PTRLevelSelectorVCDelegate <NSObject>
@optional

/**
 Level change delegate

 @param level int level
 */
- (void)userDidTapToGoLevel:(int)level;
@end

@interface PTRLevelSelectorVC : UIViewController

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  The object that acts as the delegate of the Level Selector VC.
 */
@property (nonatomic, weak) _Nullable id<PTRLevelSelectorVCDelegate> delegate;

@property (nonatomic) int selectedLevel;

- (void)tryToOpenWithDelegate:(nonnull id)delegate andSelectedLevel:(int)level;

@end
