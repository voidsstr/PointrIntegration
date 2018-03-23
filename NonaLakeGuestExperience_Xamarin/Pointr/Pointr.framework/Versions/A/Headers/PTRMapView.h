//
//  PTRMapView.h
//
//  Created by Pointr Labs on 01/07/16.
//  Copyright © 2016 Pointr. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "PTRPath.h"
#import "PTRUserInterfaceConfiguration.h"
#import "PTRLineMapDrawable.h"
#import "PTRRegionMapDrawable.h"
#import "PTRCalculatedLocation.h"

NS_ASSUME_NONNULL_BEGIN

@class PTRMapView;
@class PTRTiledMapView;
static NSString *const kPTRUserPinDrawableKey = @"kPTRUserPinDrawableKey";

typedef NS_ENUM(NSInteger, PTRMapLoadingState) {
    PTRMapLoadingStateOff,
    PTRMapLoadingStateLoading,  // loading data to display
    PTRMapLoadingStateReady,    // map for current configuration is ready to display
    PTRMapLoadingStateError     // ther is an error while displaying map for current configuration
};

/////////////////////////////////////////////////////////////////////////
#pragma mark - NSNotificationCenter notifications
/////////////////////////////////////////////////////////////////////////

/**
 The main delegate to handle any interactions regarding the map view.
 */
@protocol PTRMapViewDelegate <NSObject>
@optional

/**
 *  Notifies when user selects a destination from map view.
 *
 *  @param mapView  Current map view.
 *  @param view Selected view.
 *  @param drawable PTRMapDrawable related to view
 */
- (void)mapView:(PTRMapView *)mapView onViewTouched:(UIView *)view forDrawable:(id<PTRMapDrawable>)drawable;

/**
 *  Notifies when the level of map changes.
 *
 *  @param mapView Current map view.
 *  @param level   New level.
 */
- (void)mapView:(PTRMapView *)mapView onMapLevelChangedTo:(int)level;

/**
 *  Notifies when user changes the map rotation mode.
 *
 *  @param mapView Current map view.
 *  @param mapMode New mode.
 */
- (void)mapView:(PTRMapView *)mapView onMapRotationModeChangedTo:(PTRMapMode)mapMode;

/**
 *  Notifies when map view is tapped.
 *
 *  @param mapView           Current map view.
 *  @param gestureRecognizer Gesture recognizer containing information of the tap.
 */
- (void)mapView:(PTRMapView *)mapView didReceiveSingleFingerTap:(UIGestureRecognizer *)gestureRecognizer;

/**
 *  This callback's result will be presented to map view directly when the user zooms in or out.
 *
 *  @param mapView Current map view.
 *  @param zoomLevel The curent (updated) zoom level.
 */
- (void)mapView:(PTRMapView *)mapView didZoomToLevel:(float)zoomLevel;

/**
 *  This callback's result will be presented to map view directly when the user zooms in or out.
 *
 *  @param mapView Current map view.
 *  @param isSuccessful initialization success of MapView
 */
- (void)mapView:(PTRMapView *)mapView didInitializeSuccessfully:(BOOL)isSuccessful;

/**
 Callback of change for load state

 @param mapView Current mapView object
 @param loadingState current loading state of map
 */
- (void)mapView:(PTRMapView *)mapView onLoadingStateChangedTo:(PTRMapLoadingState)loadingState;

/**
 Callback for screenRect changed

 @param mapView Current mapView object
 @param screenRect new screenRect for mapView
 */
- (void)mapView:(PTRMapView *)mapView onScreenRectChanged:(CGRect)screenRect;

@end

/**
 Used for View returning functions
 Can be used for custon header or footer views and custom poi and or drawablePointViews
 */
@protocol PTRMapViewDataSource <NSObject>

@optional

/**
 *  This callback's result will be presented to map view directly, without any interference to returned result
 *  If returned nil default view will be created
 *
 *  @param mapView  Current map view.
 *  @param drawable drawable typed variable
 *
 *  @return A custom view for POI pins.
 */
- (UIView *_Nullable)mapView:(PTRMapView *)mapView viewForDrawable:(id<PTRMapDrawable>)drawable;

/**
 *  This callback's resulting layer will be used for design purposes
 *  Drawing to right position and path will be made by sdk no need to use add a path to CAShapeLayer
 *  If returned nil no view will appear in screen
 *
 *  @param mapView  Current map view.
 *  @param drawable PTRRegionMapDrawable typed variable which has a region array
 *
 *  @return A shape on map
 */
- (CAShapeLayer *_Nullable)mapView:(PTRMapView *)mapView layerForRegionDrawable:(id<PTRRegionMapDrawable>)drawable;

/**
 *  This callback's resulting layer will be used for design purposes
 *  Drawing to right position and path will be made by sdk no need to use add a path to CAShapeLayer
 *  If returned nil no view will appear in screen
 *
 *  @param mapView  Current map view.
 *  @param drawable PTRLineMapDrawable typed variable which has a points array
 *
 *  @return A shape on map
 */
- (CAShapeLayer *_Nullable)mapView:(PTRMapView *)mapView layerForLineMapDrawable:(id<PTRLineMapDrawable>)drawable;

@end

// predefined zoomscales
typedef NS_ENUM(int, PTRMapViewMinimumZoomScale) {
    PTRMapViewMinimumZoomScaleAspectFit,  // aspect fit map fits itself to screen
    PTRMapViewMinimumZoomScaleAspectFill  // aspect fill map fills the screen no white areas
};

/**
 *  The standart Map View implementation for maps and navigation.
 */
@interface PTRMapView : UIView

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Properties
/////////////////////////////////////////////////////////////////////////

// Delegate
@property (nonatomic, weak) _Nullable id<PTRMapViewDataSource> dataSource;
/**
 *  Maximum zoom supported by the map view.
 */
@property (nonatomic, assign) float maximumZoomScale;

/**
 *  Minimum zoom supported by the map view.
 */
@property (nonatomic, assign) float minimumZoomScale;

/**
 Frame of mapView content, used for map algoritms
 */
@property (nonatomic, readonly) CGRect screenRect;

/**
 Frame of showable area in mapView content
 Other areas exist but can not scroll to those areas
 Use display area poi for setting layoutLimits dynamically
 */
@property (nonatomic) CGRect layoutLimits;

/**
 The current level display on the map view.
 @warning setCurrentLevel does nothing if mapView.currentLevel is equals to given value and
    bool mapView.isFirstMapShown is true
 */
@property (nonatomic, assign) int currentLevel;

/**
 The current position given to mapView
 */
@property (atomic, strong) PTRCalculatedLocation *currentLocation;

/**
 The current facility mapView showing
 */
@property (nonatomic, readonly) int currentFacility;

//
//- (void)setDisplayVenue:(int)venueToDisplay facility:(int)facilityToDisplay andLevel:(int)levelToDisplay;

/**
 The current map mode.
 */
@property (nonatomic, assign) PTRMapMode currentMapMode;

/**
 The current load state of MapView
 */
@property (nonatomic, assign) PTRMapLoadingState loadingState;

/**
 Opens joystickView if YES
 */
@property (nonatomic, assign) BOOL shouldShowJoyStick;

/**
 id of current showing facility
 */
@property (nonatomic) int forcedFacilityId;

/**
 Path object of mapview set it for draw and refresh path
 Set path to nil for deleting it
 */
@property (nonatomic, strong) PTRPath *_Nullable path;

/**
 BOOL for First Map is shown
 */
@property (nonatomic) BOOL isFirstMapShown;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public Methods
/////////////////////////////////////////////////////////////////////////

/**
 Tiled Map View Layer in Map

 @return PTRTiledMapView
 */
- (PTRTiledMapView *)tiledMap;

/**
 *  Shows the map.
 */
- (void)show;

/**
 Centers map to Position without zooming
 And setting level of position

 @param position PTRPosition object to centering area
 */
- (void)centerMapToPosition:(PTRPosition)position;

/**
 * Sets the zoom to user's current location.
 */
- (void)zoomViewToCurrentPosition;

/**
 *  Zooms the map view to selected POI at maps half zoom level.
 *
 *  @param drawable PTRMapDrawable to zoom
 */
- (void)zoomViewToDrawable:(id<PTRMapDrawable>)drawable;

/**
 Zooms the map view to selected POI at given zoom scale

 @param drawable PTRMapDrawable to zoom
 @param zoomLevel Wanted zoom value
 */
- (void)zoomViewToDrawable:(id<PTRMapDrawable>)drawable zoomLevel:(float)zoomLevel;

/**
 Sets the zoom to the given x and y

 @param x zoom position at x axis value between (0,1)
 @param y zoom position at y axis value between (0,1)
 */
- (void)zoomViewToX:(float)x andY:(float)y;

/**
 Sets the zoom to the given location at the given zoom level

 @param x zoom position at x axis value between (0,1)
 @param y zoom position at y axis value between (0,1)
 @param zoomLevel The zoom level
 */
- (void)zoomViewToX:(float)x andY:(float)y withZoomLevel:(float)zoomLevel;

/**
 function to get View from drawable
 returns both visible or recycled views

 @param drawable drawable for already created view
 @return UIView for given drawable
 */
- (UIView *)viewWithDrawable:(id<PTRMapDrawable>)drawable;

/**
 Rotates map and drawables if rotation available

 @param userPinScreenCoordinates CGPoint of where to put userPin
 */
- (void)tryRotateCanvasWithUserPinCoordinates:(CGPoint)userPinScreenCoordinates;

/**
 Centers map with given coordinate

 @param coordinate CGPoint of where to put userPin
 */
- (void)setMapContentCenterIfAvailableToCoordinate:(CGPoint)coordinate;

/**
 returns current zoom scale of tiled map or rasterMap
 @warning returns INVALID_ZOOM if no map is shown

 @return float zoomScale
 */
- (float)zoomScale;

/**
 returns current content size of map
 returns 0,0 if tile and raster map are not available
 @return CGSize zoomScale
 */
- (CGSize)contentSize;

/**
 Returns if map is scrolling at the moment

 @return BOOL isScrolling
 */
- (BOOL)isScrolling;

/**
 Returns if map is zooming at the moment

 @return BOOL isZooming
 */
- (BOOL)isZooming;

/**
 Returns if given point visible on mapViews frame

 @param point CGPoint of asked position
 @return bool is inside
 */
- (BOOL)isPointVisibleInMap:(CGPoint)point;

/**
 Sets minimum zoom scale to a predefined value
 Needed float value to give aspect fill or fit will be calculated automatıcally in funct

 @param value enum from PTRMapViewMinimumZoomScale
 */
- (void)setMinimumZoomScaleWithPredefinedValue:(PTRMapViewMinimumZoomScale)value;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Listener-Delegate methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Adds listener to receive callbacks
 *
 *  @param listener An object which conforms to PTRPositionManagerDelegate protocol
 */
- (void)addListener:(id<PTRMapViewDelegate>)listener;

/**
 *  Removes listener to receive callbacks
 *
 *  @param listener An object which conforms to PTRPositionManagerDelegate protocol
 */
- (void)removeListener:(id<PTRMapViewDelegate>)listener;

/////////////////////////////////////////////////////////////////////////
#pragma mark - drawable Handling
/////////////////////////////////////////////////////////////////////////

/**
 Returns the drawable with given identifier

 @param identifier identifier of drawable
 @return drawable object
 */
- (id<PTRMapDrawable>)drawableWithIdentifier:(NSString *)identifier;
/**
 Chack if given drawable exist for map

 @param drawable PTRMapDrawable object to chack in map
 @return Boolean to send if drawable exist for map
 */
- (BOOL)isDrawableExist:(id<PTRMapDrawable>)drawable;

/**
 Removes all drawables and views for drawables
 Clears cache for views too if it will be added again callback viewfor drawable will called again
 */
- (void)removeAllDrawables;

/**
 Removes the given list of drawables and their views from map view.
 Clears cache for views too if it will be added again callback viewfor drawable will called again
 @param drawables An array of <PTRMapDrawable> objects.
 */
- (void)removeDrawables:(NSArray<id<PTRMapDrawable>> *)drawables;

/**
 Remove the given drawable and its view from map view.
 Clears cache for view too if it will be added again callback viewfor drawable will called again

 @param drawable <PTRMapDrawable> object to remove from map.
 */
- (void)removeDrawable:(id<PTRMapDrawable>)drawable;

/**
 Adds the given drawable to the map view.

 @param drawable <PTRMapDrawable> object to add to map.
 */
- (void)addDrawable:(id<PTRMapDrawable>)drawable;

/**
 Adds the given list of drawables to the map view.

 @param drawables An array of <PTRMapDrawable> objects.
 */
- (void)addDrawables:(NSArray<id<PTRMapDrawable>> *)drawables;

/**
 Deletes all views and layers even from the cache and add them again
 viewForDrawable and layerForRegionDrawable callbacks will called
 when dawables will be on screen
 */
- (void)refreshAllDrawables;

/**
 Deletes views and layer even from the cache and add drawable again
 viewForDrawable and layerForRegionDrawable callbacks will called
 when drawable will be on screen
 */
- (void)refreshDrawable:(id<PTRMapDrawable>)drawable;

/**
 Corrects position of drawable and view without deleting the view
 */
- (void)realignDrawable:(id<PTRMapDrawable>)drawable;

/**
 Corrects position of all drawables and views without deleting the view
 */
- (void)realignDrawables;

@end

NS_ASSUME_NONNULL_END
