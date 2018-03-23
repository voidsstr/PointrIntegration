//
//  PTRSearchView.h
//
//  Created by Pointr Labs on 19/07/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"

#import "PTRPoi.h"

NS_ASSUME_NONNULL_BEGIN

@class PTRSearchView;

/**
 *  The main delegate to handle any search related interactions regarding the search view.
 */
@protocol PTRSearchViewDelegate <NSObject>

@optional

/**
 *  Notifies when search view is cancelled.
 *
 *  @param searchView        Current search view.
 *  @param isCancelled       if it is cancelled or not
 */
- (void)searchView:(PTRSearchView *)searchView didCancelSearch:(BOOL)isCancelled;

/**
 Notifies when user selects a destination from search view's table view.

 @param searchView Current search view.
 @param poi        Selected Poi object.
 */
- (void)searchView:(PTRSearchView *)searchView didSelectPoi:(PTRPoi *)poi;

/**
 *  Notifies when user presses on search text field.
 */
- (void)searchViewOnUserPressedSearchField;

/**
 Notifies when user tapped route button
 */
- (void)searchViewStartedPathFinding;
@end

/**
 *  The standart search view implementation for searching POIs.
 */
@interface PTRSearchView : UIView

/////////////////////////////////////////////////////////////////////////
#pragma mark - Initializers
/////////////////////////////////////////////////////////////////////////

/**
 Initialize searchView with button

 @param frame       frame of search button
 @param searchImage image of search button
 @param cancelImage image of cancel button
 @return self
 */
- (instancetype)initWithFrame:(CGRect)frame searchImage:(UIImage *)searchImage cancelImage:(UIImage *)cancelImage;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 *  The object that acts as the delegate of the search view.
 */
@property (weak) id delegate;

/**
 *  Text colour for search box
 */
@property (nonatomic, retain) UIColor *customSearchBoxTextColour;

/**
 *  Text colour for search results table
 */
@property (nonatomic, retain) UIColor *customResultTableTextColour;

/**
 *  Background colour for search results table
 */
@property (nonatomic, retain) UIColor *customResultTableBackgroundColour;

/**
 *  Font for search box
 */
@property (nonatomic, retain) UIFont *customSearchBoxFont;

/**
 *  Font for search results
 */
@property (nonatomic, retain) UIFont *customResultTableFont;

/**
 *  Placeholder text that is shown inside search box
 */
@property (nonatomic, retain) NSString *customSearchPlaceholderText;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Method
/////////////////////////////////////////////////////////////////////////

/**
 Deletes searchText and hides search results
 */
- (void)hideSearchView;

@end

NS_ASSUME_NONNULL_END
