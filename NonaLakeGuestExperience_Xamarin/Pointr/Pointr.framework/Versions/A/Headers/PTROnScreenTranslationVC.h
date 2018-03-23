//
//  PTROnScreenTranslationVC.h
//
//  Created by Pointr Labs on 13/05/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTROnScreenTranslationVC : UIViewController
// language codes should be written in ISO language codes
// for example en for english es for spanish
@property (nonatomic, strong) NSString *fromLang;
@property (nonatomic, strong) NSString *toLang;
@end

NS_ASSUME_NONNULL_END
