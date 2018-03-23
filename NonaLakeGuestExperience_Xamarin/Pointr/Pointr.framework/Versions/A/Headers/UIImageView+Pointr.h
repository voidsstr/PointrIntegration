//
//  UIImageView+Pointr.h
//  Pointr
//
//  Created by Erkan on 14.11.2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "UIKit/UIKit.h"

@interface UIImageView (Pointr)
NS_ASSUME_NONNULL_BEGIN
/**
 Set an image from URL and put a placeholderImage till it downloads

 @param urlString url string
 @param placeholder place holder image
 */
- (void)setImageFromUrlString:(NSString *)urlString withPlaceHolderImage:(UIImage *)placeholder;

/**
 Set an image from URL and put a activity inducator animating till download finishes

 @param urlString UrlString url string
 */
- (void)setImageFromUrlString:(NSString *)urlString;
NS_ASSUME_NONNULL_END
@end
