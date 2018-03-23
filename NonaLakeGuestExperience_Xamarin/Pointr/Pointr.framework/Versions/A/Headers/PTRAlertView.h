//
//  PTRAlertView.h
//  Pointr
//
//  Created by Pointr Labs on 22.09.2016.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "QuartzCore/QuartzCore.h"
#import "PTRStarView.h"

/**
 Types of different Alert view screens

 - PTRAlertViewTypeNone: Plain alertView.
 - PTRAlertViewTypeError: Red main color with a cross on alertView.
 - PTRAlertViewTypeWarning: Orange main color Scheme with ! on alertView.
 - PTRAlertViewTypeSuccess: Green main color Scheme with tick on alertView.
 - PTRAlertViewTypeInfo: Blue main color with i on alertView.
 - PTRAlertViewTypeYesNo: Red and Green buttoned alertView.
 - PTRAlertViewTypeVisitPage: Done action sends to link property.
 - PTRAlertViewTypeRating: Orange main color Scheme with star rating.
 - PTRAlertViewTypeWithoutButton: Simple description alertView.
 */
typedef NS_ENUM(int, PTRAlertViewType) {
    PTRAlertViewTypeNone,
    PTRAlertViewTypeError,
    PTRAlertViewTypeWarning,
    PTRAlertViewTypeSuccess,
    PTRAlertViewTypeInfo,
    PTRAlertViewTypeYesNo,
    PTRAlertViewTypeVisitPage,
    PTRAlertViewTypeRating,
    PTRAlertViewTypeWithoutButton
};

@protocol PTRAlertViewDelegate;

/**
 Custom PTRAlertView class for Pointr.
 */
@interface PTRAlertView : UIView <PTRStarViewDelegate>

NS_ASSUME_NONNULL_BEGIN
/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Properties
/////////////////////////////////////////////////////////////////////////

/**
 Delegate for alert view callbacks.
 */
@property (nonatomic, weak) _Nullable id<PTRAlertViewDelegate> delegate;

/**
 AlertView Title
 */
@property (nonatomic, strong) NSString *_Nullable title;

/**
 Subtitle Text
 */
@property (nonatomic, strong) NSString *_Nullable subTitle;

/**
 AlertView Customizations
 */
@property (nonatomic, strong) UIView *_Nullable alertBackground;

@property NSInteger numberOfButtons;
@property NSInteger autoHideSeconds;
@property BOOL dismissOnOutsideTouch;
@property (nonatomic) BOOL shouldHideAllButtons;
@property (nonatomic) BOOL shouldHideDoneButton;
@property (nonatomic) BOOL shouldHideCustomImageTint;
@property (nonatomic) BOOL blurBackground;
@property (nonatomic, strong) NSDictionary *_Nullable infoDict;
@property (nonatomic) PTRAlertViewType alertviewType;

// Color Schemes

@property (nonatomic, strong) UIColor *_Nullable mainColorScheme;
@property (nonatomic, strong) UIColor *_Nullable secondaryColorScheme;
@property (nonatomic, strong) UIColor *_Nullable titleColor;
@property (nonatomic, strong) UIColor *_Nullable subTitleColor;

// link for Visit Type
@property (nonatomic, strong) NSString *_Nullable link;
// main image in alertView should set after init
@property (nonatomic, strong) UIImage *_Nullable mainImage;
// main imageURL in alertView should set after init
@property (nonatomic, strong) NSString *_Nullable mainImageURL;

// rating beginning value 5/10
@property uint rating;
@property BOOL shouldEnableRating;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Static Methods
/////////////////////////////////////////////////////////////////////////

/**
 Set the font name

 @param fontName name of font
 */
+ (void)setAlertViewFontName:(NSString *)fontName;

/**
 Set default colors for default alert Types
 If values are nil hardcoded defaults are valid

 @param errorColor default color for error alerts
 @param warningColor default color for warning alerts
 @param successColor default color for success alerts
 @param infoColor default color for info alerts
 */
+ (void)setAlertViewDefaultColorsForError:(UIColor *_Nullable)errorColor
                               forWarning:(UIColor *_Nullable)warningColor
                               forSuccess:(UIColor *_Nullable)successColor
                                  forInfo:(UIColor *_Nullable)infoColor;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init Methods without Type
/////////////////////////////////////////////////////////////////////////

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @return PTRAlertView object
 */
- (instancetype)initWithTitle:(NSString *_Nullable)title subtitle:(NSString *_Nullable)subtitle;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param icon The icon on top of the alert view
 @return PTRAlertView object
 */
- (instancetype)initWithTitle:(NSString *_Nullable)title
                     subtitle:(NSString *_Nullable)subtitle
                   headerIcon:(UIImage *_Nullable)icon;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param icon The icon on top of the alert view
 @param done Title for the done button
 @return PTRAlertView object
 */
- (instancetype)initWithTitle:(NSString *_Nullable)title
                     subtitle:(NSString *_Nullable)subtitle
                   headerIcon:(UIImage *_Nullable)icon
              doneButtonTitle:(NSString *_Nullable)done;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param icon The icon on top of the alert view
 @param done Title for the done button
 @param buttonTitles Additional button titles
 @return PTRAlertView object
 */
- (instancetype)initWithTitle:(NSString *_Nullable)title
                     subtitle:(NSString *_Nullable)subtitle
                   headerIcon:(UIImage *_Nullable)icon
              doneButtonTitle:(NSString *_Nullable)done
                 buttonTitles:(NSArray<NSString *> *_Nullable)buttonTitles;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Init Methods with type
/////////////////////////////////////////////////////////////////////////

/**
 Initialise method for the alert view

 @param type Special type of alert view for special purposes.
 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @return PTRAlertView object
 */
- (instancetype)initWithType:(PTRAlertViewType)type
                       title:(NSString *_Nullable)title
                    subtitle:(NSString *_Nullable)subtitle;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param type Special type of alert view for special purposes.
 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param done Title for the done button
 @return PTRAlertView object
 */
- (instancetype)initWithType:(PTRAlertViewType)type
                       title:(NSString *_Nullable)title
                    subtitle:(NSString *_Nullable)subtitle
             doneButtonTitle:(NSString *_Nullable)done;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param type Special type of alert view for special purposes.
 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param done Title for the done button
 @param buttonTitles Additional button titles
 @return PTRAlertView object
 */
- (instancetype)initWithType:(PTRAlertViewType)type
                       title:(NSString *_Nullable)title
                    subtitle:(NSString *_Nullable)subtitle
             doneButtonTitle:(NSString *_Nullable)done
                buttonTitles:(NSArray<NSString *> *_Nullable)buttonTitles;

/**
 Initialise method for the alert view

 @warning Function must be called from main thread.

 @param type Special type of alert view for special purposes.
 @param title Main title of the ALert View
 @param subtitle The subtitle text on the Alert View
 @param done Title for the done button
 @param buttonTitles Additional button titles
 @param icon The icon on top of the alert view
 @return PTRAlertView object
 */
- (instancetype)initWithType:(PTRAlertViewType)type
                       title:(NSString *_Nullable)title
                    subtitle:(NSString *_Nullable)subtitle
             doneButtonTitle:(NSString *_Nullable)done
                buttonTitles:(NSArray<NSString *> *_Nullable)buttonTitles
                  headerIcon:(UIImage *_Nullable)icon;

/////////////////////////////////////////////////////////////////////////
#pragma mark - AlertView Show Short Cut Methods
/////////////////////////////////////////////////////////////////////////

/**
 Error type PTRAlertView

 @warning Function must be called from main thread.

 @param subtitle information below title
 */
+ (void)showErrorWithSubtitle:(NSString *)subtitle;

/**
 Success type PTRAlertView

 @warning Function must be called from main thread.

 @param subtitle information below title
 */
+ (void)showSuccessWithSubtitle:(NSString *)subtitle;

/**
 Warning type PTRAlertView

 @warning Function must be called from main thread.

 @param subtitle information below title
 */
+ (void)showWarningWithSubtitle:(NSString *)subtitle;

/**
 Info type PTRAlertView

 @warning Function must be called from main thread.

 @param subtitle information below title
 */
+ (void)showInfoWithSubtitle:(NSString *)subtitle;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Alert Show and Dismiss
/////////////////////////////////////////////////////////////////////////

/**
 Displays the notification on scereen
 */
- (void)show;

// Dismissing AlertView
- (void)dismiss;

// Alert Action Block Method
// to do nice to have
typedef void (^PTRActionBlock)(void);

@property (nonatomic, copy) PTRActionBlock actionBlock;
@property (nonatomic, copy) PTRActionBlock doneBlock;

@end

@protocol PTRAlertViewDelegate <NSObject>

@optional

/**
 Taking clicked button index

 @param alertView PTRAlertView object
 @param index     index of buttons
 */
- (void)onPTRAlertView:(PTRAlertView *)alertView clickedButtonAtIndex:(NSInteger)index;

/**
 Dismissed alertView

 @param alertView PTRAlertView object
 */
- (void)onPTRAlertViewDismissed:(PTRAlertView *)alertView;

/**
 AlertViewWillAppear

 @param alertView PTRAlertView object
 */
- (void)onPTRAlertViewWillAppear:(PTRAlertView *)alertView;

/**
 AlertDoneButtonClicked

 @param alertView PTRAlertView object
 */
- (void)onPTRAlertViewDoneButtonClicked:(PTRAlertView *)alertView;  // PTRAlertViewDoneButton

NS_ASSUME_NONNULL_END

@end
