using System;
using CoreAnimation;
using CoreFoundation;
using CoreGraphics;
using CoreMotion;
using Foundation;
using ObjCRuntime;
using Pointr;
using UIKit;

namespace Pointr
{
    // audit-objc-generics: @interface PTRAdvertiser<__covariant T> : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRAdvertiser
    {
        // -(void)addListener:(T _Nonnull)listenerToAdd;
        [Export("addListener:")]
        void AddListener(NSObject listenerToAdd);

        // -(void)removeListener:(T _Nonnull)listenerToRemove;
        [Export("removeListener:")]
        void RemoveListener(NSObject listenerToRemove);

        // -(void)notifyAllListeners:(void (^ _Nonnull)(T _Nonnull))block;
        [Export("notifyAllListeners:")]
        void NotifyAllListeners(Action<NSObject> block);
    }

    // @interface PTRStarView : UIView
    [BaseType(typeof(UIView))]
    interface PTRStarView
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRStarViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRStarViewDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull emptySelectedImage;
        [Export("emptySelectedImage", ArgumentSemantic.Strong)]
        UIImage EmptySelectedImage { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull fullSelectedImage;
        [Export("fullSelectedImage", ArgumentSemantic.Strong)]
        UIImage FullSelectedImage { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull halfSelectedImage;
        [Export("halfSelectedImage", ArgumentSemantic.Strong)]
        UIImage HalfSelectedImage { get; set; }

        // @property uint rating;
        [Export("rating")]
        uint Rating { get; set; }
    }

    // @protocol PTRStarViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRStarViewDelegate
    {
        // @optional -(void)starView:(PTRStarView * _Nonnull)starView ratingDidChange:(CGFloat)rating;
        [Export("starView:ratingDidChange:")]
        void RatingDidChange(PTRStarView starView, nfloat rating);
    }

    // @interface PTRAlertView : UIView <PTRStarViewDelegate>
    [BaseType(typeof(UIView))]
    interface PTRAlertView : PTRStarViewDelegate
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRAlertViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRAlertViewDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic, strong) NSString * _Nullable title;
        [NullAllowed, Export("title", ArgumentSemantic.Strong)]
        string Title { get; set; }

        // @property (nonatomic, strong) NSString * _Nullable subTitle;
        [NullAllowed, Export("subTitle", ArgumentSemantic.Strong)]
        string SubTitle { get; set; }

        // @property (nonatomic, strong) UIView * _Nullable alertBackground;
        [NullAllowed, Export("alertBackground", ArgumentSemantic.Strong)]
        UIView AlertBackground { get; set; }

        // @property NSInteger numberOfButtons;
        [Export("numberOfButtons")]
        nint NumberOfButtons { get; set; }

        // @property NSInteger autoHideSeconds;
        [Export("autoHideSeconds")]
        nint AutoHideSeconds { get; set; }

        // @property BOOL dismissOnOutsideTouch;
        [Export("dismissOnOutsideTouch")]
        bool DismissOnOutsideTouch { get; set; }

        // @property (nonatomic) BOOL shouldHideAllButtons;
        [Export("shouldHideAllButtons")]
        bool ShouldHideAllButtons { get; set; }

        // @property (nonatomic) BOOL shouldHideDoneButton;
        [Export("shouldHideDoneButton")]
        bool ShouldHideDoneButton { get; set; }

        // @property (nonatomic) BOOL shouldHideCustomImageTint;
        [Export("shouldHideCustomImageTint")]
        bool ShouldHideCustomImageTint { get; set; }

        // @property (nonatomic) BOOL blurBackground;
        [Export("blurBackground")]
        bool BlurBackground { get; set; }

        // @property (nonatomic, strong) NSDictionary * _Nullable infoDict;
        [NullAllowed, Export("infoDict", ArgumentSemantic.Strong)]
        NSDictionary InfoDict { get; set; }

        // @property (nonatomic) PTRAlertViewType alertviewType;
        [Export("alertviewType", ArgumentSemantic.Assign)]
        PTRAlertViewType AlertviewType { get; set; }

        // @property (nonatomic, strong) UIColor * _Nullable mainColorScheme;
        [NullAllowed, Export("mainColorScheme", ArgumentSemantic.Strong)]
        UIColor MainColorScheme { get; set; }

        // @property (nonatomic, strong) UIColor * _Nullable secondaryColorScheme;
        [NullAllowed, Export("secondaryColorScheme", ArgumentSemantic.Strong)]
        UIColor SecondaryColorScheme { get; set; }

        // @property (nonatomic, strong) UIColor * _Nullable titleColor;
        [NullAllowed, Export("titleColor", ArgumentSemantic.Strong)]
        UIColor TitleColor { get; set; }

        // @property (nonatomic, strong) UIColor * _Nullable subTitleColor;
        [NullAllowed, Export("subTitleColor", ArgumentSemantic.Strong)]
        UIColor SubTitleColor { get; set; }

        // @property (nonatomic, strong) NSString * _Nullable link;
        [NullAllowed, Export("link", ArgumentSemantic.Strong)]
        string Link { get; set; }

        // @property (nonatomic, strong) UIImage * _Nullable mainImage;
        [NullAllowed, Export("mainImage", ArgumentSemantic.Strong)]
        UIImage MainImage { get; set; }

        // @property (nonatomic, strong) NSString * _Nullable mainImageURL;
        [NullAllowed, Export("mainImageURL", ArgumentSemantic.Strong)]
        string MainImageURL { get; set; }

        // @property uint rating;
        [Export("rating")]
        uint Rating { get; set; }

        // @property BOOL shouldEnableRating;
        [Export("shouldEnableRating")]
        bool ShouldEnableRating { get; set; }

        // +(void)setAlertViewFontName:(NSString * _Nonnull)fontName;
        [Static]
        [Export("setAlertViewFontName:")]
        void SetAlertViewFontName(string fontName);

        // +(void)setAlertViewDefaultColorsForError:(UIColor * _Nullable)errorColor forWarning:(UIColor * _Nullable)warningColor forSuccess:(UIColor * _Nullable)successColor forInfo:(UIColor * _Nullable)infoColor;
        [Static]
        [Export("setAlertViewDefaultColorsForError:forWarning:forSuccess:forInfo:")]
        void SetAlertViewDefaultColorsForError([NullAllowed] UIColor errorColor, [NullAllowed] UIColor warningColor, [NullAllowed] UIColor successColor, [NullAllowed] UIColor infoColor);

        // -(instancetype _Nonnull)initWithTitle:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle;
        [Export("initWithTitle:subtitle:")]
        IntPtr Constructor([NullAllowed] string title, [NullAllowed] string subtitle);

        // -(instancetype _Nonnull)initWithTitle:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle headerIcon:(UIImage * _Nullable)icon;
        [Export("initWithTitle:subtitle:headerIcon:")]
        IntPtr Constructor([NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] UIImage icon);

        // -(instancetype _Nonnull)initWithTitle:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle headerIcon:(UIImage * _Nullable)icon doneButtonTitle:(NSString * _Nullable)done;
        [Export("initWithTitle:subtitle:headerIcon:doneButtonTitle:")]
        IntPtr Constructor([NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] UIImage icon, [NullAllowed] string done);

        // -(instancetype _Nonnull)initWithTitle:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle headerIcon:(UIImage * _Nullable)icon doneButtonTitle:(NSString * _Nullable)done buttonTitles:(NSArray<NSString *> * _Nullable)buttonTitles;
        [Export("initWithTitle:subtitle:headerIcon:doneButtonTitle:buttonTitles:")]
        IntPtr Constructor([NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] UIImage icon, [NullAllowed] string done, [NullAllowed] string[] buttonTitles);

        // -(instancetype _Nonnull)initWithType:(PTRAlertViewType)type title:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle;
        [Export("initWithType:title:subtitle:")]
        IntPtr Constructor(PTRAlertViewType type, [NullAllowed] string title, [NullAllowed] string subtitle);

        // -(instancetype _Nonnull)initWithType:(PTRAlertViewType)type title:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle doneButtonTitle:(NSString * _Nullable)done;
        [Export("initWithType:title:subtitle:doneButtonTitle:")]
        IntPtr Constructor(PTRAlertViewType type, [NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] string done);

        // -(instancetype _Nonnull)initWithType:(PTRAlertViewType)type title:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle doneButtonTitle:(NSString * _Nullable)done buttonTitles:(NSArray<NSString *> * _Nullable)buttonTitles;
        [Export("initWithType:title:subtitle:doneButtonTitle:buttonTitles:")]
        IntPtr Constructor(PTRAlertViewType type, [NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] string done, [NullAllowed] string[] buttonTitles);

        // -(instancetype _Nonnull)initWithType:(PTRAlertViewType)type title:(NSString * _Nullable)title subtitle:(NSString * _Nullable)subtitle doneButtonTitle:(NSString * _Nullable)done buttonTitles:(NSArray<NSString *> * _Nullable)buttonTitles headerIcon:(UIImage * _Nullable)icon;
        [Export("initWithType:title:subtitle:doneButtonTitle:buttonTitles:headerIcon:")]
        IntPtr Constructor(PTRAlertViewType type, [NullAllowed] string title, [NullAllowed] string subtitle, [NullAllowed] string done, [NullAllowed] string[] buttonTitles, [NullAllowed] UIImage icon);

        // +(void)showErrorWithSubtitle:(NSString * _Nonnull)subtitle;
        [Static]
        [Export("showErrorWithSubtitle:")]
        void ShowErrorWithSubtitle(string subtitle);

        // +(void)showSuccessWithSubtitle:(NSString * _Nonnull)subtitle;
        [Static]
        [Export("showSuccessWithSubtitle:")]
        void ShowSuccessWithSubtitle(string subtitle);

        // +(void)showWarningWithSubtitle:(NSString * _Nonnull)subtitle;
        [Static]
        [Export("showWarningWithSubtitle:")]
        void ShowWarningWithSubtitle(string subtitle);

        // +(void)showInfoWithSubtitle:(NSString * _Nonnull)subtitle;
        [Static]
        [Export("showInfoWithSubtitle:")]
        void ShowInfoWithSubtitle(string subtitle);

        // -(void)show;
        [Export("show")]
        void Show();

        // -(void)dismiss;
        [Export("dismiss")]
        void Dismiss();

        // @property (copy, nonatomic) PTRActionBlock _Nonnull actionBlock;
        [Export("actionBlock", ArgumentSemantic.Copy)]
        PTRActionBlock ActionBlock { get; set; }

        // @property (copy, nonatomic) PTRActionBlock _Nonnull doneBlock;
        [Export("doneBlock", ArgumentSemantic.Copy)]
        PTRActionBlock DoneBlock { get; set; }
    }

    // typedef void (^PTRActionBlock)();
    delegate void PTRActionBlock();

    // @protocol PTRAlertViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRAlertViewDelegate
    {
        // @optional -(void)onPTRAlertView:(PTRAlertView * _Nonnull)alertView clickedButtonAtIndex:(NSInteger)index;
        [Export("onPTRAlertView:clickedButtonAtIndex:")]
        void OnPTRAlertView(PTRAlertView alertView, nint index);

        // @optional -(void)onPTRAlertViewDismissed:(PTRAlertView * _Nonnull)alertView;
        [Export("onPTRAlertViewDismissed:")]
        void OnPTRAlertViewDismissed(PTRAlertView alertView);

        // @optional -(void)onPTRAlertViewWillAppear:(PTRAlertView * _Nonnull)alertView;
        [Export("onPTRAlertViewWillAppear:")]
        void OnPTRAlertViewWillAppear(PTRAlertView alertView);

        // @optional -(void)onPTRAlertViewDoneButtonClicked:(PTRAlertView * _Nonnull)alertView;
        [Export("onPTRAlertViewDoneButtonClicked:")]
        void OnPTRAlertViewDoneButtonClicked(PTRAlertView alertView);
    }

    // @protocol PTROwnQueueProtocol <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTROwnQueueProtocol
    {
        // @required -(dispatch_queue_t _Nonnull)getQueue;
        [Abstract]
        [Export("getQueue")]
        DispatchQueue Queue { get; }
    }

    // @protocol PTRSingletonProtocol <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRSingletonProtocol
    {
        // @required +(instancetype _Nonnull)sharedInstance;
        [Static, Abstract]
        [Export("sharedInstance")]
        PTRSingletonProtocol SharedInstance();
    }

    // audit-objc-generics: @interface PTRPointrManagerInterface<T> : PTRAdvertiser <PTROwnQueueProtocol, PTRSingletonProtocol>
    [BaseType(typeof(PTRAdvertiser))]
    interface PTRPointrManagerInterface : PTROwnQueueProtocol, PTRSingletonProtocol
    {
        // -(void)start;
        [Export("start")]
        void Start();

        // -(void)stop;
        [Export("stop")]
        void Stop();
    }

    // @interface PTRAnalyticsManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRPoiManagerDelegate, PTRGeofenceManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRAnalyticsManagerInterface : PTRDataManagerDelegate, PTRPoiManagerDelegate, PTRGeofenceManagerDelegate
    {
        // @property (readonly, nonatomic) NSDictionary<NSString *,NSNumber *> * _Nonnull currentStatistics;
        [Export("currentStatistics")]
        NSDictionary<NSString, NSNumber> CurrentStatistics { get; }

        // -(void)updateStatistics:(PTRAnalyticsType)type extraInfo:(NSDictionary * _Nullable)extraInfo;
        [Export("updateStatistics:extraInfo:")]
        void UpdateStatistics(PTRAnalyticsType type, [NullAllowed] NSDictionary extraInfo);

        // -(void)flushCache;
        [Export("flushCache")]
        void FlushCache();
    }

    // @interface PTRApiResponse : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRApiResponse
    {
        // @property (assign, nonatomic) int statusCode;
        [Export("statusCode")]
        int StatusCode { get; set; }

        // @property (retain, nonatomic) NSObject * _Nullable body;
        [NullAllowed, Export("body", ArgumentSemantic.Retain)]
        NSObject Body { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull errorMessage;
        [Export("errorMessage", ArgumentSemantic.Retain)]
        string ErrorMessage { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull debugErrorMessage;
        [Export("debugErrorMessage", ArgumentSemantic.Retain)]
        string DebugErrorMessage { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull strData;
        [Export("strData", ArgumentSemantic.Retain)]
        string StrData { get; set; }

        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);

        // -(instancetype _Nonnull)initWithErrorMessage:(NSString * _Nonnull)errorMessage andDebugErrorMessage:(NSString * _Nonnull)debugErrorMessage;
        [Export("initWithErrorMessage:andDebugErrorMessage:")]
        IntPtr Constructor(string errorMessage, string debugErrorMessage);

        // -(BOOL)isSuccessful;
        [Export("isSuccessful")]
        bool IsSuccessful { get; }

        // -(BOOL)authenticationFailed;
        [Export("authenticationFailed")]
        bool AuthenticationFailed { get; }
    }

    // @interface PTRNeighbourInterface : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRNeighbourInterface : INSCoding
    {
        // -(instancetype)initWithOriginalNodeId:(long)originalNodeId facilityId:(int)facilityId;
        [Export("initWithOriginalNodeId:facilityId:")]
        IntPtr Constructor(nint originalNodeId, int facilityId);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }

        // @property (readonly, nonatomic) NSString * uniqueIdentifier;
        [Export("uniqueIdentifier")]
        string UniqueIdentifier { get; }

        // @property (readonly, nonatomic) long originalNodeId;
        [Export("originalNodeId")]
        nint OriginalNodeId { get; }
    }

    // @interface PTRPositioningTypes : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRPositioningTypes
    {
        // +(float)invalidPosition;
        [Static]
        [Export("invalidPosition")]
        float InvalidPosition { get; }

        // +(double)invalidGeoPosition;
        [Static]
        [Export("invalidGeoPosition")]
        double InvalidGeoPosition { get; }

        // +(float)invalidAccuracy;
        [Static]
        [Export("invalidAccuracy")]
        float InvalidAccuracy { get; }

        // +(int)invalidLevel;
        [Static]
        [Export("invalidLevel")]
        int InvalidLevel { get; }

        // +(float)invalidOrientation;
        [Static]
        [Export("invalidOrientation")]
        float InvalidOrientation { get; }

        // +(float)defaultOrientation;
        [Static]
        [Export("defaultOrientation")]
        float DefaultOrientation { get; }

        // +(float)defaultOrientationAccuracy;
        [Static]
        [Export("defaultOrientationAccuracy")]
        float DefaultOrientationAccuracy { get; }

        // +(unsigned short)invalidMajor;
        [Static]
        [Export("invalidMajor")]
        ushort InvalidMajor { get; }

        // +(unsigned short)invalidMinor;
        [Static]
        [Export("invalidMinor")]
        ushort InvalidMinor { get; }

        // +(int)invalidFacility;
        [Static]
        [Export("invalidFacility")]
        int InvalidFacility { get; }

        // +(int)invalidVenue;
        [Static]
        [Export("invalidVenue")]
        int InvalidVenue { get; }
    }

    // @interface PTRLocation : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRLocation : INSCoding
    {
        // -(instancetype)initWithX:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId;
        [Export("initWithX:y:level:venueId:facilityId:")]
        IntPtr Constructor(float x, float y, int level, int venueId, int facilityId);

        // -(instancetype)initWithX:(float)x y:(float)y lat:(double)lat lon:(double)lon level:(int)level venueId:(int)venueId facilityId:(int)facilityId;
        [Export("initWithX:y:lat:lon:level:venueId:facilityId:")]
        IntPtr Constructor(float x, float y, double lat, double lon, int level, int venueId, int facilityId);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }

        // -(BOOL)isValidExceptVenueFacility;
        [Export("isValidExceptVenueFacility")]
        bool IsValidExceptVenueFacility { get; }

        // -(PTRPosition)convertToPosition;
        [Export("convertToPosition")]
        PTRPosition ConvertToPosition { get; }

        // @property (readonly, nonatomic) float x;
        [Export("x")]
        float X { get; }

        // @property (readonly, nonatomic) float y;
        [Export("y")]
        float Y { get; }

        // @property (readonly, nonatomic) double lat;
        [Export("lat")]
        double Lat { get; }

        // @property (readonly, nonatomic) double lon;
        [Export("lon")]
        double Lon { get; }

        // @property (readonly, nonatomic) int level;
        [Export("level")]
        int Level { get; }

        // @property (readonly, nonatomic) int venueId;
        [Export("venueId")]
        int VenueId { get; }

        // @property (readonly, nonatomic) int facilityId;
        [Export("facilityId")]
        int FacilityId { get; }
    }

    // @interface PTRNodeInterface : NSObject <NSCopying>
    [BaseType(typeof(NSObject))]
    interface PTRNodeInterface : INSCopying
    {
        // -(NSString * _Nonnull)uniqueIdentifier;
        [Export("uniqueIdentifier")]
        string UniqueIdentifier { get; }

        // -(PTRLocation * _Nonnull)location;
        [Export("location")]
        PTRLocation Location { get; }

        // -(PTRNodeType)type;
        [Export("type")]
        PTRNodeType Type { get; }

        // -(NSArray<PTRNeighbourInterface *> * _Nullable)neighbours;
        [NullAllowed, Export("neighbours")]
        PTRNeighbourInterface[] Neighbours { get; }

        // -(BOOL)isPortalType;
        [Export("isPortalType")]
        bool IsPortalType { get; }

        // +(PTRNodeType)typeFromString:(NSString * _Nullable)typeString;
        [Static]
        [Export("typeFromString:")]
        PTRNodeType TypeFromString([NullAllowed] string typeString);

        // +(NSString * _Nonnull)stringFromNodeType:(PTRNodeType)type;
        [Static]
        [Export("stringFromNodeType:")]
        string StringFromNodeType(PTRNodeType type);

        // +(NSString * _Nonnull)friendlyStringFromNodeType:(PTRNodeType)type;
        [Static]
        [Export("friendlyStringFromNodeType:")]
        string FriendlyStringFromNodeType(PTRNodeType type);
    }

    // @interface PTRPathDirection : NSObject <NSCoding, NSCopying>
    [BaseType(typeof(NSObject))]
    interface PTRPathDirection : INSCoding, INSCopying
    {
        // @property (readonly, nonatomic) PTRNodeInterface * _Nonnull startNode;
        [Export("startNode")]
        PTRNodeInterface StartNode { get; }

        // @property (readonly, nonatomic) PTRNodeInterface * _Nonnull endNode;
        [Export("endNode")]
        PTRNodeInterface EndNode { get; }

        // @property (readonly, nonatomic) PTRPathDirectionType type;
        [Export("type")]
        PTRPathDirectionType Type { get; }

        // @property (readonly, nonatomic) NSString * _Nonnull message;
        [Export("message")]
        string Message { get; }

        // @property (readonly, nonatomic) float angle;
        [Export("angle")]
        float Angle { get; }

        // -(instancetype _Nonnull)initStraightDirectionFrom:(PTRNodeInterface * _Nonnull)start to:(PTRNodeInterface * _Nonnull)end;
        [Export("initStraightDirectionFrom:to:")]
        IntPtr Constructor(PTRNodeInterface start, PTRNodeInterface end);

        // -(instancetype _Nonnull)initTurnDirectionAtNode:(PTRNodeInterface * _Nonnull)node isLeft:(BOOL)isLeft withAngle:(float)angle;
        [Export("initTurnDirectionAtNode:isLeft:withAngle:")]
        IntPtr Constructor(PTRNodeInterface node, bool isLeft, float angle);

        // -(instancetype _Nonnull)initTurnSlightDirectionAtNode:(PTRNodeInterface * _Nonnull)node isLeft:(BOOL)isLeft withAngle:(float)angle;
        [Export("initTurnSlightDirectionAtNode:isLeft:withAngle:")]
        IntPtr initTurnSlightDirectionAtNode(PTRNodeInterface node, bool isLeft, float angle);

        // -(instancetype _Nonnull)initChangeLevelDirectionFrom:(PTRNodeInterface * _Nonnull)start to:(PTRNodeInterface * _Nonnull)end;
        [Export("initChangeLevelDirectionFrom:to:")]
        IntPtr initChangeLevelDirectionFrom(PTRNodeInterface start, PTRNodeInterface end);

        // -(instancetype _Nonnull)initChangeFacilityDirectionFrom:(PTRNodeInterface * _Nonnull)start to:(PTRNodeInterface * _Nonnull)end;
        [Export("initChangeLevelDirectionFrom:to:")]
        IntPtr initChangeLevelDirectionFromTo(PTRNodeInterface start, PTRNodeInterface end);

        // -(instancetype _Nonnull)initSecurityDirectionFrom:(PTRNodeInterface * _Nonnull)start to:(PTRNodeInterface * _Nonnull)end;
        [Export("initSecurityDirectionFrom:to:")]
        IntPtr initSecurityDirectionFromTo(PTRNodeInterface start, PTRNodeInterface end);

        // -(instancetype _Nonnull)initBorderControlDirectionFrom:(PTRNodeInterface * _Nonnull)start to:(PTRNodeInterface * _Nonnull)end;
        [Export("initBorderControlDirectionFrom:to:")]
        IntPtr initBorderControlDirectionFromTo(PTRNodeInterface start, PTRNodeInterface end);

        // -(instancetype _Nonnull)initWithType:(PTRPathDirectionType)type andWithAngle:(float)angle;
        [Export("initWithType:andWithAngle:")]
        IntPtr initWithType(PTRPathDirectionType type, float angle);

        // -(void)updateStartNodeTo:(PTRNodeInterface * _Nonnull)newStartNode;
        [Export("updateStartNodeTo:")]
        void UpdateStartNodeTo(PTRNodeInterface newStartNode);
    }

    // @interface PTRCorner : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRCorner : INSCoding
    {
        // @property (assign, nonatomic) float x;
        [Export("x")]
        float X { get; set; }

        // @property (assign, nonatomic) float y;
        [Export("y")]
        float Y { get; set; }

        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);

        // -(instancetype _Nonnull)initWithX:(float)x andY:(float)y;
        [Export("initWithX:andY:")]
        IntPtr Constructor(float x, float y);

        // -(CGPoint)point;
        [Export("point")]
        CGPoint Point { get; }
    }

    // @protocol PTRMapDrawable <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRMapDrawable
    {
        // @required @property (assign, nonatomic) CGPoint centerPoint;
        [Abstract]
        [Export("centerPoint", ArgumentSemantic.Assign)]
        CGPoint CenterPoint { get; set; }

        // @required @property (nonatomic) float minimumZoomLevel;
        [Abstract]
        [Export("minimumZoomLevel")]
        float MinimumZoomLevel { get; set; }

        // @required @property (nonatomic) float maximumZoomLevel;
        [Abstract]
        [Export("maximumZoomLevel")]
        float MaximumZoomLevel { get; set; }

        // @required @property (assign, nonatomic) BOOL isRotatable;
        [Abstract]
        [Export("isRotatable")]
        bool IsRotatable { get; set; }

        // @required @property (assign, nonatomic) BOOL isInteractive;
        [Abstract]
        [Export("isInteractive")]
        bool IsInteractive { get; set; }

        // @required @property (assign, nonatomic) BOOL canBeHiddenWhenClashed;
        [Abstract]
        [Export("canBeHiddenWhenClashed")]
        bool CanBeHiddenWhenClashed { get; set; }

        // @required @property (assign, nonatomic) BOOL canHideOthersWhenClashed;
        [Abstract]
        [Export("canHideOthersWhenClashed")]
        bool CanHideOthersWhenClashed { get; set; }

        // @required @property (nonatomic, strong) NSString * _Nonnull identifier;
        [Abstract]
        [Export("identifier", ArgumentSemantic.Strong)]
        string Identifier { get; set; }
    }

    // @protocol PTRLineMapDrawable <PTRMapDrawable>
    [Protocol, Model]
    interface PTRLineMapDrawable : PTRMapDrawable
    {
        // @required @property (nonatomic, strong) NSArray<PTRLocation *> * _Nullable pointsArray;
        [Abstract]
        [NullAllowed, Export("pointsArray", ArgumentSemantic.Strong)]
        PTRLocation[] PointsArray { get; set; }
    }

    // @interface PTRTravelEstimation : NSObject <NSCopying, NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRTravelEstimation : INSCopying, INSCoding
    {
        // @property (nonatomic) float minimumTime;
        [Export("minimumTime")]
        float MinimumTime { get; set; }

        // @property (nonatomic) float averageTime;
        [Export("averageTime")]
        float AverageTime { get; set; }

        // @property (nonatomic) float maximumTime;
        [Export("maximumTime")]
        float MaximumTime { get; set; }

        // @property (nonatomic) float distance;
        [Export("distance")]
        float Distance { get; set; }

        // -(instancetype)initWithDistance:(float)distance minimumTime:(float)minTime maximumTime:(float)maxTime;
        [Export("initWithDistance:minimumTime:maximumTime:")]
        IntPtr Constructor(float distance, float minTime, float maxTime);

        // -(instancetype)initWithDistance:(float)distance;
        [Export("initWithDistance:")]
        IntPtr Constructor(float distance);

        // -(void)addEstimation:(PTRTravelEstimation *)newEstimation;
        [Export("addEstimation:")]
        void AddEstimation(PTRTravelEstimation newEstimation);
    }

    // @interface PTRPath : NSObject <NSCopying, PTRLineMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRPath : INSCopying, PTRLineMapDrawable
    {
        // @property (retain, nonatomic) NSMutableArray<PTRNodeInterface *> * _Nonnull nodes;
        [Export("nodes", ArgumentSemantic.Retain)]
        NSMutableArray<PTRNodeInterface> Nodes { get; set; }

        // @property (retain, nonatomic) NSArray<PTRPathDirection *> * _Nonnull directions;
        [Export("directions", ArgumentSemantic.Retain)]
        PTRPathDirection[] Directions { get; set; }

        // @property (assign, nonatomic) float travelCost;
        [Export("travelCost")]
        float TravelCost { get; set; }

        // @property (nonatomic, strong) PTRTravelEstimation * _Nonnull travelEstimation;
        [Export("travelEstimation", ArgumentSemantic.Strong)]
        PTRTravelEstimation TravelEstimation { get; set; }
    }

    // @protocol PTRAugmentedRealityControllerDelegate
    [Protocol, Model]
    interface PTRAugmentedRealityControllerDelegate
    {
        // @optional -(void)augmentedRealityDissmissedByUserWithTapEvent:(UIEvent * _Nullable)tapEvent;
        [Export("augmentedRealityDissmissedByUserWithTapEvent:")]
        void AugmentedRealityDissmissedByUserWithTapEvent([NullAllowed] UIEvent tapEvent);
    }

    // @interface PTRAugmentedRealityVC : UIViewController
    [BaseType(typeof(UIViewController))]
    interface PTRAugmentedRealityVC
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        NSObject Delegate { get; set; }

        // @property (nonatomic, weak) id _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // -(BOOL)canUserEnableAugmentedReality;
        [Export("canUserEnableAugmentedReality")]
        bool CanUserEnableAugmentedReality { get; }
    }

    // @interface PTRCalculatedLocation : PTRLocation <NSCoding>
    [BaseType(typeof(PTRLocation))]
    interface PTRCalculatedLocation : INSCoding
    {
        // @property (readonly, nonatomic) PTRLocationState state;
        [Export("state")]
        PTRLocationState State { get; }

        // @property (readonly, nonatomic) float accuracy;
        [Export("accuracy")]
        float Accuracy { get; }

        // @property (readonly, nonatomic) float orientation;
        [Export("orientation")]
        float Orientation { get; }

        // @property (readonly, nonatomic) float orientationAccuracy;
        [Export("orientationAccuracy")]
        float OrientationAccuracy { get; }

        // @property (readonly, nonatomic) PTROrientationAccuracyClass orientationAccuracyClass;
        [Export("orientationAccuracyClass")]
        PTROrientationAccuracyClass OrientationAccuracyClass { get; }

        // @property (nonatomic) double timestamp;
        [Export("timestamp")]
        double Timestamp { get; set; }

        // -(instancetype)initWithLocation:(PTRLocation *)location state:(PTRLocationState)state accuracy:(float)accuracy orientation:(float)orientation orientationAccuracy:(float)orientationAccuracy orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;
        [Export("initWithLocation:state:accuracy:orientation:orientationAccuracy:orientationAccuracyClass:")]
        IntPtr Constructor(PTRLocation location, PTRLocationState state, float accuracy, float orientation, float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);

        // -(instancetype)initWithX:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId state:(PTRLocationState)state accuracy:(float)accuracy orientation:(float)orientation orientationAccuracy:(float)orientationAccuracy orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;
        [Export("initWithX:y:level:venueId:facilityId:state:accuracy:orientation:orientationAccuracy:orientationAccuracyClass:")]
        IntPtr Constructor(float x, float y, int level, int venueId, int facilityId, PTRLocationState state, float accuracy, float orientation, float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);

        // -(instancetype)initWithX:(float)x y:(float)y lat:(double)lat lon:(double)lon level:(int)level venueId:(int)venueId facilityId:(int)facilityId state:(PTRLocationState)state accuracy:(float)accuracy orientation:(float)orientation orientationAccuracy:(float)orientationAccuracy orientationAccuracyClass:(PTROrientationAccuracyClass)orientationAccuracyClass;
        [Export("initWithX:y:lat:lon:level:venueId:facilityId:state:accuracy:orientation:orientationAccuracy:orientationAccuracyClass:")]
        IntPtr Constructor(float x, float y, double lat, double lon, int level, int venueId, int facilityId, PTRLocationState state, float accuracy, float orientation, float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);

        // -(PTRPosition)convertToPosition;
        [Export("convertToPosition")]
        PTRPosition ConvertToPosition { get; }

        // -(CGPoint)getPoint;
        [Export("getPoint")]
        CGPoint Point { get; }
    }

    // @interface PTRConfigurationInterface : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRConfigurationInterface : INSCoding
    {
        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);

        // -(instancetype _Nonnull)updateWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("updateWithDictionary:")]
        PTRConfigurationInterface UpdateWithDictionary(NSDictionary dictionary);

        // -(BOOL)isEqual:(PTRConfigurationInterface * _Nonnull)object;
        [Export("isEqual:")]
        bool IsEqual(PTRConfigurationInterface @object);
    }

    // @interface PTRSdkConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRSdkConfiguration
    {
        // @property (nonatomic, strong) NSString * _Nonnull baseUrl;
        [Export("baseUrl", ArgumentSemantic.Strong)]
        string BaseUrl { get; set; }

        // @property (nonatomic, strong) NSArray<NSDictionary<NSNumber *,NSString *> *> * _Nonnull uuidList;
        [Export("uuidList", ArgumentSemantic.Strong)]
        NSDictionary<NSNumber, NSString>[] UuidList { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull beaconBrandName;
        [Export("beaconBrandName", ArgumentSemantic.Strong)]
        string BeaconBrandName { get; set; }

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }
    }

    // @interface PTRDataManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRDataManagerConfiguration
    {
        // @property (retain, nonatomic) NSString * _Nonnull analyticsApi;
        [Export("analyticsApi", ArgumentSemantic.Retain)]
        string AnalyticsApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull configurationApi;
        [Export("configurationApi", ArgumentSemantic.Retain)]
        string ConfigurationApi { get; set; }

        // @property (assign, nonatomic) BOOL downloadDataAutomatically;
        [Export("downloadDataAutomatically")]
        bool DownloadDataAutomatically { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull graphApi;
        [Export("graphApi", ArgumentSemantic.Retain)]
        string GraphApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull licenseValidationApi;
        [Export("licenseValidationApi", ArgumentSemantic.Retain)]
        string LicenseValidationApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull maintenanceApi;
        [Export("maintenanceApi", ArgumentSemantic.Retain)]
        string MaintenanceApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull poiApi;
        [Export("poiApi", ArgumentSemantic.Retain)]
        string PoiApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull beaconApi;
        [Export("beaconApi", ArgumentSemantic.Retain)]
        string BeaconApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull wallApi;
        [Export("wallApi", ArgumentSemantic.Retain)]
        string WallApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull versionApi;
        [Export("versionApi", ArgumentSemantic.Retain)]
        string VersionApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull crashReportingApi;
        [Export("crashReportingApi", ArgumentSemantic.Retain)]
        string CrashReportingApi { get; set; }
    }

    // @interface PTRPoiManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRPoiManagerConfiguration
    {
        // @property (assign, nonatomic) BOOL shouldShowPortalsAsPois;
        [Export("shouldShowPortalsAsPois")]
        bool ShouldShowPortalsAsPois { get; set; }

        // @property (assign, nonatomic) float checkTriggerDistanceThresholdInMetres;
        [Export("checkTriggerDistanceThresholdInMetres")]
        float CheckTriggerDistanceThresholdInMetres { get; set; }
    }

    // @interface PTRUserManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRUserManagerConfiguration
    {
        // @property (retain, nonatomic) NSString * _Nonnull registerDeviceApi;
        [Export("registerDeviceApi", ArgumentSemantic.Retain)]
        string RegisterDeviceApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull registerUserForDeviceApi;
        [Export("registerUserForDeviceApi", ArgumentSemantic.Retain)]
        string RegisterUserForDeviceApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull logoutApi;
        [Export("logoutApi", ArgumentSemantic.Retain)]
        string LogoutApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull registerDeviceForPushTokenApi;
        [Export("registerDeviceForPushTokenApi", ArgumentSemantic.Retain)]
        string RegisterDeviceForPushTokenApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull unregisterDeviceForPushTokenApi;
        [Export("unregisterDeviceForPushTokenApi", ArgumentSemantic.Retain)]
        string UnregisterDeviceForPushTokenApi { get; set; }

        // @property (assign, nonatomic) BOOL isPasswordRequired;
        [Export("isPasswordRequired")]
        bool IsPasswordRequired { get; set; }
    }

    // @interface PTRGeofenceManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRGeofenceManagerConfiguration
    {
        // @property (assign, nonatomic) BOOL isEnabled;
        [Export("isEnabled")]
        bool IsEnabled { get; set; }

        // @property (assign, nonatomic) double regionTimeoutInterval;
        [Export("regionTimeoutInterval")]
        double RegionTimeoutInterval { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull notifyApi;
        [Export("notifyApi", ArgumentSemantic.Retain)]
        string NotifyApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull welcomePushMessage;
        [Export("welcomePushMessage", ArgumentSemantic.Retain)]
        string WelcomePushMessage { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull exitPushMessage;
        [Export("exitPushMessage", ArgumentSemantic.Retain)]
        string ExitPushMessage { get; set; }

        // @property (assign, nonatomic) BOOL shouldNotifyWithPushMessage;
        [Export("shouldNotifyWithPushMessage")]
        bool ShouldNotifyWithPushMessage { get; set; }

        // @property (assign, nonatomic) BOOL shouldNotifyServer;
        [Export("shouldNotifyServer")]
        bool ShouldNotifyServer { get; set; }

        // @property (assign, nonatomic) BOOL shouldNotifyEnterExit;
        [Export("shouldNotifyEnterExit")]
        bool ShouldNotifyEnterExit { get; set; }

        // @property (assign, nonatomic) BOOL isAutomaticFacilitySwitchEnabled;
        [Export("isAutomaticFacilitySwitchEnabled")]
        bool IsAutomaticFacilitySwitchEnabled { get; set; }
    }

    // @interface PTRPositionManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRPositionManagerConfiguration
    {
        // @property (assign, nonatomic) int numberOfNearestBeaconsToUse;
        [Export("numberOfNearestBeaconsToUse")]
        int NumberOfNearestBeaconsToUse { get; set; }

        // @property (assign, nonatomic) int requiredMeasurementsForPositionReporting;
        [Export("requiredMeasurementsForPositionReporting")]
        int RequiredMeasurementsForPositionReporting { get; set; }

        // @property (assign, nonatomic) float measurementHistoryTimespan;
        [Export("measurementHistoryTimespan")]
        float MeasurementHistoryTimespan { get; set; }

        // @property (assign, nonatomic) float biasPower;
        [Export("biasPower")]
        float BiasPower { get; set; }

        // @property (assign, nonatomic) float maxWalkingSpeed;
        [Export("maxWalkingSpeed")]
        float MaxWalkingSpeed { get; set; }

        // @property (assign, nonatomic) float calculationTimeStep;
        [Export("calculationTimeStep")]
        float CalculationTimeStep { get; set; }

        // @property (assign, nonatomic) float accuracyMultiplier;
        [Export("accuracyMultiplier")]
        float AccuracyMultiplier { get; set; }

        // @property (assign, nonatomic) float stepInterval;
        [Export("stepInterval")]
        float StepInterval { get; set; }

        // @property (assign, nonatomic) BOOL isBackgroundPositioningEnabled;
        [Export("isBackgroundPositioningEnabled")]
        bool IsBackgroundPositioningEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isFusionEnabled;
        [Export("isFusionEnabled")]
        bool IsFusionEnabled { get; set; }

        // @property (assign, nonatomic) float rotationPrecision;
        [Export("rotationPrecision")]
        float RotationPrecision { get; set; }

        // @property (assign, nonatomic) BOOL isCoreBluetoothEnabled;
        [Export("isCoreBluetoothEnabled")]
        bool IsCoreBluetoothEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isCoreLocationEnabled;
        [Export("isCoreLocationEnabled")]
        bool IsCoreLocationEnabled { get; set; }

        // @property (assign, nonatomic) float beaconSilenceTimeInSeconds;
        [Export("beaconSilenceTimeInSeconds")]
        float BeaconSilenceTimeInSeconds { get; set; }

        // @property (assign, nonatomic) float headingThrottlingThresholdInDegrees;
        [Export("headingThrottlingThresholdInDegrees")]
        float HeadingThrottlingThresholdInDegrees { get; set; }

        // @property (assign, nonatomic) float thresholdForFadingPositionInSeconds;
        [Export("thresholdForFadingPositionInSeconds")]
        float ThresholdForFadingPositionInSeconds { get; set; }

        // @property (assign, nonatomic) float thresholdForLosingPositionInSeconds;
        [Export("thresholdForLosingPositionInSeconds")]
        float ThresholdForLosingPositionInSeconds { get; set; }

        // @property (assign, nonatomic) double latitudeTopLeft;
        [Export("latitudeTopLeft")]
        double LatitudeTopLeft { get; set; }

        // @property (assign, nonatomic) double longitudeTopLeft;
        [Export("longitudeTopLeft")]
        double LongitudeTopLeft { get; set; }

        // @property (assign, nonatomic) double latitudeTopRight;
        [Export("latitudeTopRight")]
        double LatitudeTopRight { get; set; }

        // @property (assign, nonatomic) double longitudeTopRight;
        [Export("longitudeTopRight")]
        double LongitudeTopRight { get; set; }

        // @property (assign, nonatomic) double latitudeBottomLeft;
        [Export("latitudeBottomLeft")]
        double LatitudeBottomLeft { get; set; }

        // @property (assign, nonatomic) double longitudeBottomLeft;
        [Export("longitudeBottomLeft")]
        double LongitudeBottomLeft { get; set; }

        // @property (assign, nonatomic) float levelChangeHistoryTimespan;
        [Export("levelChangeHistoryTimespan")]
        float LevelChangeHistoryTimespan { get; set; }

        // @property (assign, nonatomic) float typicalLevelHeight;
        [Export("typicalLevelHeight")]
        float TypicalLevelHeight { get; set; }

        // @property (assign, nonatomic) float levelChangeGraceThreshold;
        [Export("levelChangeGraceThreshold")]
        float LevelChangeGraceThreshold { get; set; }

        // @property (assign, nonatomic) BOOL shouldResetOnLevelChange;
        [Export("shouldResetOnLevelChange")]
        bool ShouldResetOnLevelChange { get; set; }

        // @property (assign, nonatomic) int sensorSamplingPeriodInMicrosecs;
        [Export("sensorSamplingPeriodInMicrosecs")]
        int SensorSamplingPeriodInMicrosecs { get; set; }

        // @property (assign, nonatomic) int inHeadingMode;
        [Export("inHeadingMode")]
        int InHeadingMode { get; set; }

        // @property (assign, nonatomic) int inHeadingDelayWindowSize;
        [Export("inHeadingDelayWindowSize")]
        int InHeadingDelayWindowSize { get; set; }

        // @property (assign, nonatomic) int inCorrectionPeriod;
        [Export("inCorrectionPeriod")]
        int InCorrectionPeriod { get; set; }

        // @property (assign, nonatomic) double inSpeedNoiseSigma;
        [Export("inSpeedNoiseSigma")]
        double InSpeedNoiseSigma { get; set; }

        // @property (assign, nonatomic) double inMeasNoiseSigma;
        [Export("inMeasNoiseSigma")]
        double InMeasNoiseSigma { get; set; }

        // @property (assign, nonatomic) int inCompassHeadingWindowSize;
        [Export("inCompassHeadingWindowSize")]
        int InCompassHeadingWindowSize { get; set; }

        // @property (assign, nonatomic) double headingFilterCoefAccel;
        [Export("headingFilterCoefAccel")]
        double HeadingFilterCoefAccel { get; set; }

        // @property (assign, nonatomic) double headingFilterCoefMagneto;
        [Export("headingFilterCoefMagneto")]
        double HeadingFilterCoefMagneto { get; set; }

        // @property (assign, nonatomic) int numConcatInertialSamples;
        [Export("numConcatInertialSamples")]
        int NumConcatInertialSamples { get; set; }

        // @property (assign, nonatomic) BOOL movementInfoReportingEnabled;
        [Export("movementInfoReportingEnabled")]
        bool MovementInfoReportingEnabled { get; set; }

        // @property (assign, nonatomic) double speedNoiseSigma;
        [Export("speedNoiseSigma")]
        double SpeedNoiseSigma { get; set; }

        // @property (assign, nonatomic) double headingChangeNoiseSigma;
        [Export("headingChangeNoiseSigma")]
        double HeadingChangeNoiseSigma { get; set; }

        // @property (assign, nonatomic) double measNoiseSigma;
        [Export("measNoiseSigma")]
        double MeasNoiseSigma { get; set; }

        // @property (assign, nonatomic) BOOL maSmoothingEnabled;
        [Export("maSmoothingEnabled")]
        bool MaSmoothingEnabled { get; set; }

        // @property (assign, nonatomic) int maSmoothingWindowSize;
        [Export("maSmoothingWindowSize")]
        int MaSmoothingWindowSize { get; set; }

        // @property (assign, nonatomic) int icNumClones;
        [Export("icNumClones")]
        int IcNumClones { get; set; }

        // @property (assign, nonatomic) double icCloneKillDistance;
        [Export("icCloneKillDistance")]
        double IcCloneKillDistance { get; set; }

        // @property (assign, nonatomic) double icHeadingConfidenceThreshold;
        [Export("icHeadingConfidenceThreshold")]
        double IcHeadingConfidenceThreshold { get; set; }

        // @property (assign, nonatomic) BOOL obstacleHandlingEnabled;
        [Export("obstacleHandlingEnabled")]
        bool ObstacleHandlingEnabled { get; set; }

        // @property (assign, nonatomic) double ohCloneDistributionRadius;
        [Export("ohCloneDistributionRadius")]
        double OhCloneDistributionRadius { get; set; }

        // @property (assign, nonatomic) int ohNumClonesInRadius;
        [Export("ohNumClonesInRadius")]
        int OhNumClonesInRadius { get; set; }

        // @property (assign, nonatomic) BOOL ohHeadingDispersionEnabled;
        [Export("ohHeadingDispersionEnabled")]
        bool OhHeadingDispersionEnabled { get; set; }

        // @property (assign, nonatomic) double ohHeadingDispersionMaxAngle;
        [Export("ohHeadingDispersionMaxAngle")]
        double OhHeadingDispersionMaxAngle { get; set; }

        // @property (assign, nonatomic) int ohMinNumClones;
        [Export("ohMinNumClones")]
        int OhMinNumClones { get; set; }

        // @property (assign, nonatomic) int ohMaxNumClones;
        [Export("ohMaxNumClones")]
        int OhMaxNumClones { get; set; }

        // @property (assign, nonatomic) BOOL ohGridClusteringEnabled;
        [Export("ohGridClusteringEnabled")]
        bool OhGridClusteringEnabled { get; set; }

        // @property (assign, nonatomic) double ohGridClusteringCellSize;
        [Export("ohGridClusteringCellSize")]
        double OhGridClusteringCellSize { get; set; }

        // @property (assign, nonatomic) double ohMinCloneDiversity;
        [Export("ohMinCloneDiversity")]
        double OhMinCloneDiversity { get; set; }
    }

    // @interface PTRLocationSharingConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRLocationSharingConfiguration
    {
        // @property (nonatomic, strong) NSString * _Nonnull onlineLocationPollApi;
        [Export("onlineLocationPollApi", ArgumentSemantic.Strong)]
        string OnlineLocationPollApi { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull locationUploadApi;
        [Export("locationUploadApi", ArgumentSemantic.Retain)]
        string LocationUploadApi { get; set; }

        // @property (assign, nonatomic) double seeOtherPeopleTimeoutInSeconds;
        [Export("seeOtherPeopleTimeoutInSeconds")]
        double SeeOtherPeopleTimeoutInSeconds { get; set; }

        // @property (assign, nonatomic) double onlineLocationPollFrequencyInSeconds;
        [Export("onlineLocationPollFrequencyInSeconds")]
        double OnlineLocationPollFrequencyInSeconds { get; set; }

        // @property (assign, nonatomic) double onlineLocationTimeoutInSeconds;
        [Export("onlineLocationTimeoutInSeconds")]
        double OnlineLocationTimeoutInSeconds { get; set; }

        // @property (assign, nonatomic) double advertisementIntervalInSeconds;
        [Export("advertisementIntervalInSeconds")]
        double AdvertisementIntervalInSeconds { get; set; }

        // @property (assign, nonatomic) BOOL seeOtherPeopleOfflineEnabled;
        [Export("seeOtherPeopleOfflineEnabled")]
        bool SeeOtherPeopleOfflineEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isOfflineLocationSharingEnabled;
        [Export("isOfflineLocationSharingEnabled")]
        bool IsOfflineLocationSharingEnabled { get; set; }

        // @property (assign, nonatomic) BOOL seeOtherPeopleOnlineEnabled;
        [Export("seeOtherPeopleOnlineEnabled")]
        bool SeeOtherPeopleOnlineEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isOnlineLocationSharingEnabled;
        [Export("isOnlineLocationSharingEnabled")]
        bool IsOnlineLocationSharingEnabled { get; set; }

        // @property (assign, nonatomic) double positionUploadIntervalSeconds;
        [Export("positionUploadIntervalSeconds")]
        double PositionUploadIntervalSeconds { get; set; }

        // @property (assign, nonatomic) double positionSamplingRateInSeconds;
        [Export("positionSamplingRateInSeconds")]
        double PositionSamplingRateInSeconds { get; set; }

        // @property (assign, nonatomic) int positionUploadThreshold;
        [Export("positionUploadThreshold")]
        int PositionUploadThreshold { get; set; }
    }

    // @interface PTRUserInterfaceConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRUserInterfaceConfiguration
    {
        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);

        // @property (nonatomic, strong) NSArray * _Nonnull enabledMapModes;
        [Export("enabledMapModes", ArgumentSemantic.Strong)]
        NSObject[] EnabledMapModes { get; set; }

        // @property (assign, nonatomic) float mapRotationLimitAngleInDegrees;
        [Export("mapRotationLimitAngleInDegrees")]
        float MapRotationLimitAngleInDegrees { get; set; }

        // @property (assign, nonatomic) float pathWidth;
        [Export("pathWidth")]
        float PathWidth { get; set; }

        // @property (assign, nonatomic) BOOL isPathSimplificationEnabled;
        [Export("isPathSimplificationEnabled")]
        bool IsPathSimplificationEnabled { get; set; }

        // @property (assign, nonatomic) BOOL shouldEnableAccuracyCircle;
        [Export("shouldEnableAccuracyCircle")]
        bool ShouldEnableAccuracyCircle { get; set; }

        // @property (assign, nonatomic) float accuracyCircleMinSizeInMeters;
        [Export("accuracyCircleMinSizeInMeters")]
        float AccuracyCircleMinSizeInMeters { get; set; }

        // @property (assign, nonatomic) float accuracyCircleMaxSizeInMeters;
        [Export("accuracyCircleMaxSizeInMeters")]
        float AccuracyCircleMaxSizeInMeters { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull accuracyCirclePulseColour;
        [Export("accuracyCirclePulseColour", ArgumentSemantic.Strong)]
        UIColor AccuracyCirclePulseColour { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull accuracyCircleStaticColour;
        [Export("accuracyCircleStaticColour", ArgumentSemantic.Strong)]
        UIColor AccuracyCircleStaticColour { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull orientationCircleColor;
        [Export("orientationCircleColor", ArgumentSemantic.Strong)]
        UIColor OrientationCircleColor { get; set; }

        // @property (assign, nonatomic) float pinFadeOutTime;
        [Export("pinFadeOutTime")]
        float PinFadeOutTime { get; set; }

        // @property (assign, nonatomic) float pinDisappearTime;
        [Export("pinDisappearTime")]
        float PinDisappearTime { get; set; }

        // @property (assign, nonatomic) int maximumMapDetailLevel;
        [Export("maximumMapDetailLevel")]
        int MaximumMapDetailLevel { get; set; }

        // @property (assign, nonatomic) float maxZoomScale;
        [Export("maxZoomScale")]
        float MaxZoomScale { get; set; }

        // @property (assign, nonatomic) float minZoomScale;
        [Export("minZoomScale")]
        float MinZoomScale { get; set; }

        // @property (assign, nonatomic) BOOL shouldShowDebuggingPanel;
        [Export("shouldShowDebuggingPanel")]
        bool ShouldShowDebuggingPanel { get; set; }

        // @property (assign, nonatomic) BOOL shouldCheckAnnotationClash;
        [Export("shouldCheckAnnotationClash")]
        bool ShouldCheckAnnotationClash { get; set; }

        // @property (assign, nonatomic) BOOL willShowMapFooter;
        [Export("willShowMapFooter")]
        bool WillShowMapFooter { get; set; }

        // @property (assign, nonatomic) BOOL shouldEnlargeSelectedPoi;
        [Export("shouldEnlargeSelectedPoi")]
        bool ShouldEnlargeSelectedPoi { get; set; }

        // @property (assign, nonatomic) BOOL isDataDownloadPromptEnabled;
        [Export("isDataDownloadPromptEnabled")]
        bool IsDataDownloadPromptEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isAugmentedRealityEnabled;
        [Export("isAugmentedRealityEnabled")]
        bool IsAugmentedRealityEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isOnScreenTranslationEnabled;
        [Export("isOnScreenTranslationEnabled")]
        bool IsOnScreenTranslationEnabled { get; set; }
    }

    // @interface PTRPathManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRPathManagerConfiguration
    {
        // @property (assign, nonatomic) float arrivalThresholdInMetres;
        [Export("arrivalThresholdInMetres")]
        float ArrivalThresholdInMetres { get; set; }

        // @property (assign, nonatomic) float rerouteThresholdInMetres;
        [Export("rerouteThresholdInMetres")]
        float RerouteThresholdInMetres { get; set; }

        // @property (assign, nonatomic) BOOL isTurnByTurnDirectionsEnabled;
        [Export("isTurnByTurnDirectionsEnabled")]
        bool IsTurnByTurnDirectionsEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isSmartReroutingEnabled;
        [Export("isSmartReroutingEnabled")]
        bool IsSmartReroutingEnabled { get; set; }

        // @property (assign, nonatomic) PTRPathfindingDistanceMode distanceMode;
        [Export("distanceMode", ArgumentSemantic.Assign)]
        PTRPathfindingDistanceMode DistanceMode { get; set; }

        // @property (assign, nonatomic) BOOL isVoiceGuidanceEnabled;
        [Export("isVoiceGuidanceEnabled")]
        bool IsVoiceGuidanceEnabled { get; set; }
    }

    // @interface PTRNetworkConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRNetworkConfiguration
    {
        // @property (assign, nonatomic) int cacheDataLimit;
        [Export("cacheDataLimit")]
        int CacheDataLimit { get; set; }

        // @property (assign, nonatomic) int lowerThreshold;
        [Export("lowerThreshold")]
        int LowerThreshold { get; set; }

        // @property (assign, nonatomic) float networkQueueCycleIntervalInSeconds;
        [Export("networkQueueCycleIntervalInSeconds")]
        float NetworkQueueCycleIntervalInSeconds { get; set; }

        // @property (assign, nonatomic) int upperThreshold;
        [Export("upperThreshold")]
        int UpperThreshold { get; set; }
    }

    // @interface PTRFacilityConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRFacilityConfiguration
    {
        // @property (assign, nonatomic) int internalIdentifier;
        [Export("internalIdentifier")]
        int InternalIdentifier { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull externalIdentifier;
        [Export("externalIdentifier", ArgumentSemantic.Retain)]
        string ExternalIdentifier { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull name;
        [Export("name", ArgumentSemantic.Strong)]
        string Name { get; set; }

        // @property (assign, nonatomic) float mapWidthMeters;
        [Export("mapWidthMeters")]
        float MapWidthMeters { get; set; }

        // @property (assign, nonatomic) float mapHeightMeters;
        [Export("mapHeightMeters")]
        float MapHeightMeters { get; set; }

        // @property (assign, nonatomic) int mapMinLevel;
        [Export("mapMinLevel")]
        int MapMinLevel { get; set; }

        // @property (assign, nonatomic) int mapMaxLevel;
        [Export("mapMaxLevel")]
        int MapMaxLevel { get; set; }

        // @property (assign, nonatomic) float headingOffset;
        [Export("headingOffset")]
        float HeadingOffset { get; set; }

        // @property (readonly, nonatomic) BOOL isValid;
        [Export("isValid")]
        bool IsValid { get; }
    }

    // @interface PTRVenueConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRVenueConfiguration
    {
        // @property (assign, nonatomic) int internalIdentifier;
        [Export("internalIdentifier")]
        int InternalIdentifier { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull externalIdentifier;
        [Export("externalIdentifier", ArgumentSemantic.Retain)]
        string ExternalIdentifier { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull name;
        [Export("name", ArgumentSemantic.Strong)]
        string Name { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull beaconType;
        [Export("beaconType", ArgumentSemantic.Strong)]
        string BeaconType { get; set; }
    }

    // @interface PTRLogger : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRLogger
    {
        // +(void)setLoggerLevel:(PTRLoggerLevel)loggerLevel;
        [Static]
        [Export("setLoggerLevel:")]
        void SetLoggerLevel(PTRLoggerLevel loggerLevel);

        // +(NSString *)stringFromLogLevel:(PTRLogLevel)level;
        [Static]
        [Export("stringFromLogLevel:")]
        string StringFromLogLevel(PTRLogLevel level);

        // +(NSString *)stringFromLoggerLevel:(PTRLoggerLevel)level;
        [Static]
        [Export("stringFromLoggerLevel:")]
        string StringFromLoggerLevel(PTRLoggerLevel level);
    }

    // @interface PTRLogManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRLogManagerConfiguration
    {
        // @property (assign, nonatomic) PTRLoggerLevel loggerLevel;
        [Export("loggerLevel", ArgumentSemantic.Assign)]
        PTRLoggerLevel LoggerLevel { get; set; }
    }

    // @interface PTRPushManagerConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRPushManagerConfiguration
    {
        // @property (assign, nonatomic) BOOL isEnabled;
        [Export("isEnabled")]
        bool IsEnabled { get; set; }
    }

    // @interface PTRSimulationConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRSimulationConfiguration
    {
        // @property (assign, nonatomic) BOOL isBluetoothSimulationEnabled;
        [Export("isBluetoothSimulationEnabled")]
        bool IsBluetoothSimulationEnabled { get; set; }

        // @property (assign, nonatomic) BOOL isSensorSimulationEnabled;
        [Export("isSensorSimulationEnabled")]
        bool IsSensorSimulationEnabled { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull bluetoothEventFileName;
        [Export("bluetoothEventFileName", ArgumentSemantic.Retain)]
        string BluetoothEventFileName { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull sensorEventFileName;
        [Export("sensorEventFileName", ArgumentSemantic.Retain)]
        string SensorEventFileName { get; set; }
    }

    // @interface PTRCoreConfiguration : PTRConfigurationInterface
    [BaseType(typeof(PTRConfigurationInterface))]
    interface PTRCoreConfiguration
    {
        // @property (nonatomic, strong) PTRSdkConfiguration * _Nonnull sdkConfiguration;
        [Export("sdkConfiguration", ArgumentSemantic.Strong)]
        PTRSdkConfiguration SdkConfiguration { get; set; }

        // @property (nonatomic, strong) PTRDataManagerConfiguration * _Nonnull dataManagerConfiguration;
        [Export("dataManagerConfiguration", ArgumentSemantic.Strong)]
        PTRDataManagerConfiguration DataManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRFacilityConfiguration * _Nonnull facilityConfiguration;
        [Export("facilityConfiguration", ArgumentSemantic.Strong)]
        PTRFacilityConfiguration FacilityConfiguration { get; set; }

        // @property (nonatomic, strong) PTRVenueConfiguration * _Nonnull venueConfiguration;
        [Export("venueConfiguration", ArgumentSemantic.Strong)]
        PTRVenueConfiguration VenueConfiguration { get; set; }

        // @property (nonatomic, strong) PTRGeofenceManagerConfiguration * _Nonnull geofenceManagerConfiguration;
        [Export("geofenceManagerConfiguration", ArgumentSemantic.Strong)]
        PTRGeofenceManagerConfiguration GeofenceManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRLocationSharingConfiguration * _Nonnull locationSharingConfiguration;
        [Export("locationSharingConfiguration", ArgumentSemantic.Strong)]
        PTRLocationSharingConfiguration LocationSharingConfiguration { get; set; }

        // @property (nonatomic, strong) PTRLogManagerConfiguration * _Nonnull logManagerConfiguration;
        [Export("logManagerConfiguration", ArgumentSemantic.Strong)]
        PTRLogManagerConfiguration LogManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRNetworkConfiguration * _Nonnull networkConfiguration;
        [Export("networkConfiguration", ArgumentSemantic.Strong)]
        PTRNetworkConfiguration NetworkConfiguration { get; set; }

        // @property (nonatomic, strong) PTRPathManagerConfiguration * _Nonnull pathManagerConfiguration;
        [Export("pathManagerConfiguration", ArgumentSemantic.Strong)]
        PTRPathManagerConfiguration PathManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRPoiManagerConfiguration * _Nonnull poiManagerConfiguration;
        [Export("poiManagerConfiguration", ArgumentSemantic.Strong)]
        PTRPoiManagerConfiguration PoiManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRPositionManagerConfiguration * _Nonnull positionManagerConfiguration;
        [Export("positionManagerConfiguration", ArgumentSemantic.Strong)]
        PTRPositionManagerConfiguration PositionManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRUserManagerConfiguration * _Nonnull userManagerConfiguration;
        [Export("userManagerConfiguration", ArgumentSemantic.Strong)]
        PTRUserManagerConfiguration UserManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRUserInterfaceConfiguration * _Nonnull userInterfaceConfiguration;
        [Export("userInterfaceConfiguration", ArgumentSemantic.Strong)]
        PTRUserInterfaceConfiguration UserInterfaceConfiguration { get; set; }

        // @property (nonatomic, strong) PTRPushManagerConfiguration * _Nonnull pushManagerConfiguration;
        [Export("pushManagerConfiguration", ArgumentSemantic.Strong)]
        PTRPushManagerConfiguration PushManagerConfiguration { get; set; }

        // @property (nonatomic, strong) PTRSimulationConfiguration * _Nonnull simulationConfiguration;
        [Export("simulationConfiguration", ArgumentSemantic.Strong)]
        PTRSimulationConfiguration SimulationConfiguration { get; set; }

        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);

        // -(instancetype _Nonnull)updateWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("updateWithDictionary:")]
        PTRCoreConfiguration UpdateWithDictionary(NSDictionary dictionary);
    }

    // @protocol PTRConfigurationManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRConfigurationManagerDelegate
    {
        // @required -(void)onConfigurationManagerUpdate;
        [Abstract]
        [Export("onConfigurationManagerUpdate")]
        void OnConfigurationManagerUpdate();

        // @optional -(void)onConfigurationManagerUpdateFail;
        [Export("onConfigurationManagerUpdateFail")]
        void OnConfigurationManagerUpdateFail();
    }

    // @interface PTRConfigurationManagerInterface : PTRPointrManagerInterface <PTRGeofenceManagerDelegate, PTRDataManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRConfigurationManagerInterface : PTRGeofenceManagerDelegate, PTRDataManagerDelegate
    {
        // -(PTRCoreConfiguration * _Nullable)getCurrentConfiguration;
        [NullAllowed, Export("getCurrentConfiguration")]
        PTRCoreConfiguration CurrentConfiguration { get; }

        // -(void)switchConfigurationToFacility:(int)facilityId;
        [Export("switchConfigurationToFacility:")]
        void SwitchConfigurationToFacility(int facilityId);

        // -(void)switchConfigurationToFacilityString:(NSString * _Nonnull)facilityIdString;
        [Export("switchConfigurationToFacilityString:")]
        void SwitchConfigurationToFacilityString(string facilityIdString);

        // -(PTRCoreConfiguration * _Nullable)getConfigurationForFacility:(int)facilityId;
        [Export("getConfigurationForFacility:")]
        [return: NullAllowed]
        PTRCoreConfiguration GetConfigurationForFacility(int facilityId);

        // -(BOOL)getIsConfiguredToPhysicalFacility;
        [Export("getIsConfiguredToPhysicalFacility")]
        bool IsConfiguredToPhysicalFacility { get; }
    }

    // @interface PTRCoordinateTransformer : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRCoordinateTransformer
    {
        // +(PTRCalculatedLocation * _Nonnull)convertCalculatedLocationToScreenForZoom:(PTRCalculatedLocation * _Nonnull)normalized withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("convertCalculatedLocationToScreenForZoom:withScreenRect:")]
        PTRCalculatedLocation ConvertCalculatedLocationToScreenForZoom(PTRCalculatedLocation normalized, CGRect screenRect);

        // +(CGPoint)convertCornerToScreenPointForZoom:(PTRCorner * _Nonnull)normalized withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("convertCornerToScreenPointForZoom:withScreenRect:")]
        CGPoint ConvertCornerToScreenPointForZoom(PTRCorner normalized, CGRect screenRect);

        // +(CGPoint)convertLocationToScreenPointForZoom:(PTRLocation * _Nonnull)normalized withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("convertLocationToScreenPointForZoom:withScreenRect:")]
        CGPoint ConvertLocationToScreenPointForZoom(PTRLocation normalized, CGRect screenRect);

        // +(PTRPosition)convertNormalizedToScreenForZoom:(PTRPosition)normalized withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("convertNormalizedToScreenForZoom:withScreenRect:")]
        PTRPosition ConvertNormalizedToScreenForZoom(PTRPosition normalized, CGRect screenRect);

        // +(CGPoint)convertNormalizedPointToScreenForZoom:(CGPoint)normalized withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("convertNormalizedPointToScreenForZoom:withScreenRect:")]
        CGPoint ConvertNormalizedPointToScreenForZoom(CGPoint normalized, CGRect screenRect);
    }

    // @interface PTRDataTypes : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRDataTypes
    {
        // +(NSString *)dataTypeToString:(PTRDataType)type;
        [Static]
        [Export("dataTypeToString:")]
        string DataTypeToString(PTRDataType type);
    }

    // @protocol PTRDataManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRDataManagerDelegate
    {
        // @optional -(void)onDataManagerReadyForVenue:(int)venueId;
        [Export("onDataManagerReadyForVenue:")]
        void OnDataManagerReadyForVenue(int venueId);

        // @optional -(void)onDataManagerStartDataManagementForVenue:(int)venueId facility:(int)facilityId dataFromOnline:(BOOL)isOnlineData;
        [Export("onDataManagerStartDataManagementForVenue:facility:dataFromOnline:")]
        void OnDataManagerStartDataManagementForVenue(int venueId, int facilityId, bool isOnlineData);

        // @optional -(void)onDataManagerCompleteAllForVenue:(int)venueId facility:(int)facilityId isSuccessful:(BOOL)isSuccessful dataFromOnline:(BOOL)isOnlineData errorMessages:(NSDictionary<NSNumber *,NSString *> * _Nullable)errorMessages;
        [Export("onDataManagerCompleteAllForVenue:facility:isSuccessful:dataFromOnline:errorMessages:")]
        void OnDataManagerCompleteAllForVenue(int venueId, int facilityId, bool isSuccessful, bool isOnlineData, [NullAllowed] NSDictionary<NSNumber, NSString> errorMessages);

        // @optional -(void)onDataManagerBeginProcessingDataForVenue:(int)venueId facility:(int)facilityId dataType:(PTRDataType)dataType dataFromOnline:(BOOL)isOnlineData;
        [Export("onDataManagerBeginProcessingDataForVenue:facility:dataType:dataFromOnline:")]
        void OnDataManagerBeginProcessingDataForVenue(int venueId, int facilityId, PTRDataType dataType, bool isOnlineData);

        // @optional -(void)onDataManagerEndProcessingDataForVenue:(int)venueId facility:(int)facilityId dataType:(PTRDataType)dataType dataFromOnline:(BOOL)isOnlineData isSuccessful:(BOOL)isSuccessful errorMessages:(NSArray<NSString *> * _Nullable)errorMessages;
        [Export("onDataManagerEndProcessingDataForVenue:facility:dataType:dataFromOnline:isSuccessful:errorMessages:")]
        void OnDataManagerEndProcessingDataForVenue(int venueId, int facilityId, PTRDataType dataType, bool isOnlineData, bool isSuccessful, [NullAllowed] string[] errorMessages);

        // @optional -(void)onDataManagerBeginProcessingMapUpdateForVenue:(int)venueId facility:(int)facilityId level:(int)level mapType:(PTRDataType)mapType dataFromOnline:(BOOL)isOnlineData;
        [Export("onDataManagerBeginProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline:")]
        void OnDataManagerBeginProcessingMapUpdateForVenue(int venueId, int facilityId, int level, PTRDataType mapType, bool isOnlineData);

        // @optional -(void)onDataManagerEndProcessingMapUpdateForVenue:(int)venueId facility:(int)facilityId level:(int)level mapType:(PTRDataType)mapType dataFromOnline:(BOOL)isOnlineData isSuccessful:(BOOL)isSuccessful errorMessages:(NSArray<NSString *> * _Nullable)errorMessages;
        [Export("onDataManagerEndProcessingMapUpdateForVenue:facility:level:mapType:dataFromOnline:isSuccessful:errorMessages:")]
        void OnDataManagerEndProcessingMapUpdateForVenue(int venueId, int facilityId, int level, PTRDataType mapType, bool isOnlineData, bool isSuccessful, [NullAllowed] string[] errorMessages);
    }

    // @interface PTRDataManagerInterface : PTRPointrManagerInterface <PTRConfigurationManagerDelegate, PTRUserManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRDataManagerInterface : PTRConfigurationManagerDelegate, PTRUserManagerDelegate
    {
        // -(void)loadBaseConfiguration;
        [Export("loadBaseConfiguration")]
        void LoadBaseConfiguration();

        // -(void)loadConfigurationForFacility:(int)facilityId;
        [Export("loadConfigurationForFacility:")]
        void LoadConfigurationForFacility(int facilityId);

        // -(BOOL)isContentReadyForVenue:(int)venueId shouldAcceptRasterMapsAlso:(BOOL)shouldAcceptRasterMapsAlso;
        [Export("isContentReadyForVenue:shouldAcceptRasterMapsAlso:")]
        bool IsContentReadyForVenue(int venueId, bool shouldAcceptRasterMapsAlso);

        // -(void)prioritiseMapLevel:(NSNumber * _Nonnull)level;
        [Export("prioritiseMapLevel:")]
        void PrioritiseMapLevel(NSNumber level);

        // -(BOOL)isLoadingMapForLevel:(int)level facility:(int)facilityId venue:(int)venueId;
        [Export("isLoadingMapForLevel:facility:venue:")]
        bool IsLoadingMapForLevel(int level, int facilityId, int venueId);
    }

    // @interface PTRMapDrawablePointView : UIView
    [BaseType(typeof(UIView))]
    interface PTRMapDrawablePointView
    {
        // @property (nonatomic, strong) id<PTRMapDrawable> _Nonnull drawable;
        [Export("drawable", ArgumentSemantic.Strong)]
        PTRMapDrawable Drawable { get; set; }

        // @property (assign, nonatomic) CGPoint position;
        [Export("position", ArgumentSemantic.Assign)]
        CGPoint Position { get; set; }

        // @property (assign, nonatomic) CGPoint centerOffset;
        [Export("centerOffset", ArgumentSemantic.Assign)]
        CGPoint CenterOffset { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull reuseIdentifier;
        [Export("reuseIdentifier", ArgumentSemantic.Strong)]
        string ReuseIdentifier { get; set; }

        // @property (nonatomic, strong) UIImageView * _Nonnull drawableImageView;
        [Export("drawableImageView", ArgumentSemantic.Strong)]
        UIImageView DrawableImageView { get; set; }

        // -(instancetype _Nonnull)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("initWithFrame:forDrawable:")]
        IntPtr Constructor(CGRect frame, PTRMapDrawable drawable);

        // -(instancetype _Nonnull)initWithView:(UIView * _Nonnull)view forDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("initWithView:forDrawable:")]
        IntPtr Constructor(UIView view, PTRMapDrawable drawable);
    }

    // @interface PTRDirectionView : PTRMapDrawablePointView
    [BaseType(typeof(PTRMapDrawablePointView))]
    interface PTRDirectionView
    {
    }

    // @interface PTRDisplayBeacon : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRDisplayBeacon
    {
        // @property (assign, nonatomic) int level;
        [Export("level")]
        int Level { get; set; }

        // @property (assign, nonatomic) float x;
        [Export("x")]
        float X { get; set; }

        // @property (assign, nonatomic) float y;
        [Export("y")]
        float Y { get; set; }

        // @property (assign, nonatomic) float accuracy;
        [Export("accuracy")]
        float Accuracy { get; set; }

        // @property (assign, nonatomic) float distance;
        [Export("distance")]
        float Distance { get; set; }
    }

    // @interface PTRDisplayPeripheral : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRDisplayPeripheral
    {
        // @property (assign, nonatomic) int level;
        [Export("level")]
        int Level { get; set; }

        // @property (assign, nonatomic) float x;
        [Export("x")]
        float X { get; set; }

        // @property (assign, nonatomic) float y;
        [Export("y")]
        float Y { get; set; }

        // @property (assign, nonatomic) float rotation;
        [Export("rotation")]
        float Rotation { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull name;
        [Export("name", ArgumentSemantic.Strong)]
        string Name { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull identifier;
        [Export("identifier", ArgumentSemantic.Strong)]
        string Identifier { get; set; }

        // @property (assign, nonatomic) int rssi;
        [Export("rssi")]
        int Rssi { get; set; }

        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary dictionary);
    }

    // @interface PTRMapVersion : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRMapVersion
    {
        // @property (readonly, nonatomic) int version;
        [Export("version")]
        int Version { get; }

        // @property (readonly, nonatomic) float width;
        [Export("width")]
        float Width { get; }

        // @property (readonly, nonatomic) float height;
        [Export("height")]
        float Height { get; }

        // @property (readonly, nonatomic) int levelOfDetail;
        [Export("levelOfDetail")]
        int LevelOfDetail { get; }

        // @property (readonly, nonatomic) NSString * _Nonnull levelTitle;
        [Export("levelTitle")]
        string LevelTitle { get; }

        // @property (readonly, nonatomic) PTRDataType mapType;
        [Export("mapType")]
        PTRDataType MapType { get; }

        // @property (readonly, nonatomic) NSString * _Nullable urlRasterLowResolution;
        [NullAllowed, Export("urlRasterLowResolution")]
        string UrlRasterLowResolution { get; }

        // @property (readonly, nonatomic) NSString * _Nullable urlRaster;
        [NullAllowed, Export("urlRaster")]
        string UrlRaster { get; }

        // @property (readonly, nonatomic) NSString * _Nullable urlTileArchive;
        [NullAllowed, Export("urlTileArchive")]
        string UrlTileArchive { get; }

        // -(instancetype _Nonnull)initWithVersion:(int)version width:(float)width height:(float)height levelTitle:(NSString * _Nonnull)levelTitle mapType:(PTRDataType)mapType urlRasterLowResolution:(NSString * _Nullable)urlRasterLowResolution urlRaster:(NSString * _Nullable)urlRaster urlTileArchive:(NSString * _Nullable)urlTileArchive;
        [Export("initWithVersion:width:height:levelTitle:mapType:urlRasterLowResolution:urlRaster:urlTileArchive:")]
        IntPtr Constructor(int version, float width, float height, string levelTitle, PTRDataType mapType, [NullAllowed] string urlRasterLowResolution, [NullAllowed] string urlRaster, [NullAllowed] string urlTileArchive);

        // +(NSString * _Nonnull)tileNameForLevel:(int)level scale:(int)scale row:(int)row column:(int)column;
        [Static]
        [Export("tileNameForLevel:scale:row:column:")]
        string TileNameForLevel(int level, int scale, int row, int column);
    }

    partial interface Constants
    {
        // extern NSString *const kPTRKeyDataVersionsFacilityVersions;
        [Field("kPTRKeyDataVersionsFacilityVersions", "__Internal")]
        NSString kPTRKeyDataVersionsFacilityVersions { get; }

        // extern NSString *const kPTRKeyDataVersionsConfigurationVersion;
        [Field("kPTRKeyDataVersionsConfigurationVersion", "__Internal")]
        NSString kPTRKeyDataVersionsConfigurationVersion { get; }

        // extern NSString *const kPTRKeyDataVersionsBeaconVersion;
        [Field("kPTRKeyDataVersionsBeaconVersion", "__Internal")]
        NSString kPTRKeyDataVersionsBeaconVersion { get; }

        // extern NSString *const kPTRKeyDataVersionsPoiVersion;
        [Field("kPTRKeyDataVersionsPoiVersion", "__Internal")]
        NSString kPTRKeyDataVersionsPoiVersion { get; }

        // extern NSString *const kPTRKeyDataVersionsGraphVersion;
        [Field("kPTRKeyDataVersionsGraphVersion", "__Internal")]
        NSString kPTRKeyDataVersionsGraphVersion { get; }

        // extern NSString *const kPTRKeyDataVersionsWallVersion;
        [Field("kPTRKeyDataVersionsWallVersion", "__Internal")]
        NSString kPTRKeyDataVersionsWallVersion { get; }

        // extern NSString *const kPTRKeyDataVersionsMapVersions;
        [Field("kPTRKeyDataVersionsMapVersions", "__Internal")]
        NSString kPTRKeyDataVersionsMapVersions { get; }
    }

    // @interface PTRFacilityDataVersions : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRFacilityDataVersions
    {
        // @property (assign, nonatomic) int facilityId;
        [Export("facilityId")]
        int FacilityId { get; set; }

        // @property (assign, nonatomic) float configurationVersion;
        [Export("configurationVersion")]
        float ConfigurationVersion { get; set; }

        // @property (assign, nonatomic) float beaconVersion;
        [Export("beaconVersion")]
        float BeaconVersion { get; set; }

        // @property (assign, nonatomic) float poiVersion;
        [Export("poiVersion")]
        float PoiVersion { get; set; }

        // @property (assign, nonatomic) float graphVersion;
        [Export("graphVersion")]
        float GraphVersion { get; set; }

        // @property (assign, nonatomic) float wallVersion;
        [Export("wallVersion")]
        float WallVersion { get; set; }

        // @property (nonatomic, strong) NSDictionary<NSNumber *,PTRMapVersion *> * mapVersions;
        [Export("mapVersions", ArgumentSemantic.Strong)]
        NSDictionary MapVersions { get; set; }

        // -(instancetype)initWithConfigurationVersion:(float)configurationVersion beaconVersion:(float)beaconVersion poiVersion:(float)poiVersion graphVersion:(float)graphVersion wallVersion:(float)wallVersion mapVersions:(NSDictionary<NSNumber *,PTRMapVersion *> *)mapVersions facilityId:(int)facilityId;
        [Export("initWithConfigurationVersion:beaconVersion:poiVersion:graphVersion:wallVersion:mapVersions:facilityId:")]
        IntPtr Constructor(float configurationVersion, float beaconVersion, float poiVersion, float graphVersion, float wallVersion, NSDictionary mapVersions, int facilityId);
    }

    // @interface PTRGraphInterface : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRGraphInterface : INSCoding
    {
        // @property (retain, nonatomic) NSDictionary<NSString *,PTRNodeInterface *> * allNodes;
        [Export("allNodes", ArgumentSemantic.Retain)]
        NSDictionary<NSString, PTRNodeInterface> AllNodes { get; set; }

        // @property (assign, nonatomic) float dx;
        [Export("dx")]
        float Dx { get; set; }

        // -(PTRNodeInterface *)getNodeWithIdentifier:(NSString *)nodeUniqueIdentifier;
        [Export("getNodeWithIdentifier:")]
        PTRNodeInterface GetNodeWithIdentifier(string nodeUniqueIdentifier);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }
    }

    // @interface PTRGraphNodeNeighbour : PTRNeighbourInterface <NSCoding, NSCopying>
    [BaseType(typeof(PTRNeighbourInterface))]
    interface PTRGraphNodeNeighbour : INSCoding, INSCopying
    {
        // -(instancetype)initWithOriginalNodeId:(long)originalNodeId speed:(int)speed facilityId:(int)facilityId;
        [Export("initWithOriginalNodeId:speed:facilityId:")]
        IntPtr Constructor(nint originalNodeId, int speed, int facilityId);

        // @property (readonly, nonatomic) int speed;
        [Export("speed")]
        int Speed { get; }
    }

    // @interface PTRGraphNode : PTRNodeInterface <NSCoding, NSCopying>
    [BaseType(typeof(PTRNodeInterface))]
    interface PTRGraphNode : INSCoding, INSCopying
    {
        // -(instancetype)initWithOriginalNodeId:(long)originalNodeId x:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId neighbours:(NSArray<PTRGraphNodeNeighbour *> *)neighbours portalNeighbours:(NSArray<NSNumber *> *)portalNeighbours;
        [Export("initWithOriginalNodeId:x:y:level:venueId:facilityId:neighbours:portalNeighbours:")]
        IntPtr Constructor(nint originalNodeId, float x, float y, int level, int venueId, int facilityId, PTRGraphNodeNeighbour[] neighbours, NSNumber[] portalNeighbours);

        // -(instancetype)initWithOriginalNodeId:(long)originalNodeId location:(PTRLocation *)location neighbours:(NSArray<PTRGraphNodeNeighbour *> *)neighbours strPortalNeighbours:(NSArray<NSString *> *)portalNeighbours;
        [Export("initWithOriginalNodeId:location:neighbours:strPortalNeighbours:")]
        IntPtr Constructor(nint originalNodeId, PTRLocation location, PTRGraphNodeNeighbour[] neighbours, string[] portalNeighbours);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }

        // @property (readonly, nonatomic) long originalNodeId;
        [Export("originalNodeId")]
        nint OriginalNodeId { get; }

        // @property (readonly, nonatomic) NSArray<NSString *> * portalNeighbours;
        [Export("portalNeighbours")]
        string[] PortalNeighbours { get; }

        // @property (readonly, nonatomic) NSString * uniqueIdentifier;
        [Export("uniqueIdentifier")]
        string UniqueIdentifier { get; }
    }

    // @interface PTRLevelGraph : PTRGraphInterface <NSCoding>
    [BaseType(typeof(PTRGraphInterface))]
    interface PTRLevelGraph : INSCoding
    {
        // -(instancetype)initWithFacilityId:(int)facilityId level:(int)level nodes:(NSArray<PTRGraphNode *> *)nodes;
        [Export("initWithFacilityId:level:nodes:")]
        IntPtr Constructor(int facilityId, int level, PTRGraphNode[] nodes);

        // @property (readonly, nonatomic) int level;
        [Export("level")]
        int Level { get; }

        // @property (readonly, nonatomic) int facilityId;
        [Export("facilityId")]
        int FacilityId { get; }
    }

    // @interface PTRPortalNodeChildNode : NSObject <NSCoding, NSCopying>
    [BaseType(typeof(NSObject))]
    interface PTRPortalNodeChildNode : INSCoding, INSCopying
    {
        // -(instancetype)initWithOriginalNodeId:(long)originalNodeId x:(float)x y:(float)y level:(int)level;
        [Export("initWithOriginalNodeId:x:y:level:")]
        IntPtr Constructor(nint originalNodeId, float x, float y, int level);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }

        // @property (readonly, nonatomic) long originalNodeId;
        [Export("originalNodeId")]
        nint OriginalNodeId { get; }

        // @property (readonly, nonatomic) float x;
        [Export("x")]
        float X { get; }

        // @property (readonly, nonatomic) float y;
        [Export("y")]
        float Y { get; }

        // @property (readonly, nonatomic) int level;
        [Export("level")]
        int Level { get; }
    }

    // @interface PTRPortalNode : PTRNodeInterface <NSCoding, NSCopying>
    [BaseType(typeof(PTRNodeInterface))]
    interface PTRPortalNode : INSCoding, INSCopying
    {
        // -(instancetype)initWithStartNode:(PTRPortalNodeChildNode *)startNode endNode:(PTRPortalNodeChildNode *)endNode isStartNode:(BOOL)isStartNode type:(PTRNodeType)type travelTime:(int)travelTime isAccessible:(BOOL)isAccessible isComfortable:(BOOL)isComfortable facilityId:(int)facilityId;
        [Export("initWithStartNode:endNode:isStartNode:type:travelTime:isAccessible:isComfortable:facilityId:")]
        IntPtr Constructor(PTRPortalNodeChildNode startNode, PTRPortalNodeChildNode endNode, bool isStartNode, PTRNodeType type, int travelTime, bool isAccessible, bool isComfortable, int facilityId);

        // -(BOOL)isValid;
        [Export("isValid")]
        bool IsValid { get; }

        // -(void)addNeighbour:(PTRNeighbourInterface *)neighbour;
        [Export("addNeighbour:")]
        void AddNeighbour(PTRNeighbourInterface neighbour);

        // @property (readonly, nonatomic) PTRPortalNodeChildNode * startNode;
        [Export("startNode")]
        PTRPortalNodeChildNode StartNode { get; }

        // @property (readonly, nonatomic) PTRPortalNodeChildNode * endNode;
        [Export("endNode")]
        PTRPortalNodeChildNode EndNode { get; }

        // @property (readonly, nonatomic) BOOL isStartNode;
        [Export("isStartNode")]
        bool IsStartNode { get; }

        // @property (readonly, nonatomic) PTRNodeType type;
        [Export("type")]
        PTRNodeType Type { get; }

        // @property (readonly, nonatomic) int travelTime;
        [Export("travelTime")]
        int TravelTime { get; }

        // @property (readonly, nonatomic) BOOL isAccessible;
        [Export("isAccessible")]
        bool IsAccessible { get; }

        // @property (readonly, nonatomic) BOOL isComfortable;
        [Export("isComfortable")]
        bool IsComfortable { get; }
    }

    // @interface PTRInterFacilityPortalNode : PTRPortalNode <NSCoding, NSCopying>
    [BaseType(typeof(PTRPortalNode))]
    interface PTRInterFacilityPortalNode : INSCoding, INSCopying
    {
        // -(instancetype)initWithStartNode:(PTRPortalNodeChildNode *)startNode endNode:(PTRPortalNodeChildNode *)endNode isStartNode:(BOOL)isStartNode startFacilityId:(int)startFacilityId endFacilityId:(int)endFacilityId type:(PTRNodeType)type travelTime:(int)travelTime isAccessible:(BOOL)isAccessible isComfortable:(BOOL)isComfortable;
        [Export("initWithStartNode:endNode:isStartNode:startFacilityId:endFacilityId:type:travelTime:isAccessible:isComfortable:")]
        IntPtr Constructor(PTRPortalNodeChildNode startNode, PTRPortalNodeChildNode endNode, bool isStartNode, int startFacilityId, int endFacilityId, PTRNodeType type, int travelTime, bool isAccessible, bool isComfortable);

        // @property (readonly, nonatomic) int startFacilityId;
        [Export("startFacilityId")]
        int StartFacilityId { get; }

        // @property (readonly, nonatomic) int endFacilityId;
        [Export("endFacilityId")]
        int EndFacilityId { get; }
    }

    // @interface PTRFacilityGraph : PTRGraphInterface <NSCoding>
    [BaseType(typeof(PTRGraphInterface))]
    interface PTRFacilityGraph : INSCoding
    {
        // -(instancetype)initWithFacilityId:(int)facilityId portalNodes:(NSDictionary<NSString *,PTRPortalNode *> *)portalNodes levelGraphs:(NSDictionary<NSNumber *,PTRLevelGraph *> *)levelGraphs;
        [Export("initWithFacilityId:portalNodes:levelGraphs:")]
        IntPtr Constructor(int facilityId, NSDictionary<NSString, PTRPortalNode> portalNodes, NSDictionary<NSNumber, PTRLevelGraph> levelGraphs);

        // @property (readonly, nonatomic) int facilityId;
        [Export("facilityId")]
        int FacilityId { get; }

        // @property (readonly, nonatomic) NSDictionary<NSString *,PTRPortalNode *> * portalNodes;
        [Export("portalNodes")]
        NSDictionary<NSString, PTRPortalNode> PortalNodes { get; }

        // @property (readonly, nonatomic) NSDictionary<NSNumber *,PTRLevelGraph *> * levelGraphs;
        [Export("levelGraphs")]
        NSDictionary<NSNumber, PTRLevelGraph> LevelGraphs { get; }
    }

    // @interface PTRFusionUtil : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRFusionUtil
    {
        // +(float)calculateHeadingFromQuat:(CMQuaternion)quaternion;
        [Static]
        [Export("calculateHeadingFromQuat:")]
        float CalculateHeadingFromQuat(CMQuaternion quaternion);

        // +(double)normalizeAngle:(double)angle;
        [Static]
        [Export("normalizeAngle:")]
        double NormalizeAngle(double angle);

        // +(double)normalizeAngle:(double)angle withBaseAngle:(double)baseAngle;
        [Static]
        [Export("normalizeAngle:withBaseAngle:")]
        double NormalizeAngle(double angle, double baseAngle);

        // +(double)getAngleChangeFrom:(double)srcAngle to:(double)destAngle;
        [Static]
        [Export("getAngleChangeFrom:to:")]
        double GetAngleChangeFrom(double srcAngle, double destAngle);

        // +(double)getListMean:(NSArray<NSNumber *> * _Nonnull)list;
        [Static]
        [Export("getListMean:")]
        double GetListMean(NSNumber[] list);

        // +(double)phi:(double)x;
        [Static]
        [Export("phi:")]
        double phi(double x);

        // +(double)Phi:(double)z;
        [Static]
        [Export("Phi:")]
        double Phi(double z);

        // +(double)PhiInversePositiveWithY:(double)y andSigma:(double)sigma;
        [Static]
        [Export("PhiInversePositiveWithY:andSigma:")]
        double PhiInversePositiveWithY(double y, double sigma);

        // +(double)PhiInverse:(double)y;
        [Static]
        [Export("PhiInverse:")]
        double PhiInverse(double y);

        // +(double)PhiInverseWithY:(double)y delta:(double)delta low:(double)lo andHigh:(double)hi;
        [Static]
        [Export("PhiInverseWithY:delta:low:andHigh:")]
        double PhiInverseWithY(double y, double delta, double lo, double hi);

        // +(NSArray * _Nonnull)getGaussianPositionsWithNumPositions:(int)numPositions max:(double)max andMaxSigma:(double)maxSigma;
        [Static]
        [Export("getGaussianPositionsWithNumPositions:max:andMaxSigma:")]
        NSObject[] GetGaussianPositionsWithNumPositions(int numPositions, double max, double maxSigma);

        // +(BOOL)equalsDouble1:(double)a double2:(double)b withLimit:(double)limit;
        [Static]
        [Export("equalsDouble1:double2:withLimit:")]
        bool EqualsDouble1(double a, double b, double limit);

        // +(double)distanceWithX1:(double)x1 y1:(double)y1 x2:(double)x2 andY2:(double)y2;
        [Static]
        [Export("distanceWithX1:y1:x2:andY2:")]
        double DistanceWithX1(double x1, double y1, double x2, double y2);

        // +(float)getAltitudeWithP0:(float)p0 p:(float)p;
        [Static]
        [Export("getAltitudeWithP0:p:")]
        float GetAltitudeWithP0(float p0, float p);

        // +(void)print:(float)value base:(float)base;
        [Static]
        [Export("print:base:")]
        void Print(float value, float @base);
    }

    // @protocol PTRGeofenceManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRGeofenceManagerDelegate
    {
        // @optional -(void)onGeofenceManagerDidEnterFacility:(int)facilityId;
        [Export("onGeofenceManagerDidEnterFacility:")]
        void OnGeofenceManagerDidEnterFacility(int facilityId);

        // @optional -(void)onGeofenceManagerDidExitFacility:(int)facilityId;
        [Export("onGeofenceManagerDidExitFacility:")]
        void OnGeofenceManagerDidExitFacility(int facilityId);
    }

    // @interface PTRGeofenceManagerInterface : PTRPointrManagerInterface
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRGeofenceManagerInterface
    {
        // @property (readonly, nonatomic) int currentFacility;
        [Export("currentFacility")]
        int CurrentFacility { get; }

        // @property (readonly, nonatomic) PTRGeofencingState currentState;
        [Export("currentState")]
        PTRGeofencingState CurrentState { get; }
    }

    // @interface PTRVenueGraph : PTRGraphInterface <NSCoding, PTRLineMapDrawable>
    [BaseType(typeof(PTRGraphInterface))]
    interface PTRVenueGraph : INSCoding, PTRLineMapDrawable
    {
        // -(instancetype)initWithVenueId:(int)venueId facilityGraphs:(NSDictionary<NSNumber *,PTRFacilityGraph *> *)facilityGraphs interFacilityPortalNodes:(NSDictionary<NSString *,PTRInterFacilityPortalNode *> *)interFacilityPortalNodes;
        [Export("initWithVenueId:facilityGraphs:interFacilityPortalNodes:")]
        IntPtr Constructor(int venueId, NSDictionary<NSNumber, PTRFacilityGraph> facilityGraphs, NSDictionary<NSString, PTRInterFacilityPortalNode> interFacilityPortalNodes);

        // @property (readonly, nonatomic) int venueId;
        [Export("venueId")]
        int VenueId { get; }

        // @property (readonly, nonatomic) NSDictionary<NSNumber *,PTRFacilityGraph *> * facilityGraphs;
        [Export("facilityGraphs")]
        NSDictionary<NSNumber, PTRFacilityGraph> FacilityGraphs { get; }

        // @property (readonly, nonatomic) NSDictionary<NSString *,PTRInterFacilityPortalNode *> * interFacilityPortalNodes;
        [Export("interFacilityPortalNodes")]
        NSDictionary<NSString, PTRInterFacilityPortalNode> InterFacilityPortalNodes { get; }
    }

    // @protocol PTRGraphManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRGraphManagerDelegate
    {
        // @optional -(void)onGraphManagerGraphUpdated;
        [Export("onGraphManagerGraphUpdated")]
        void OnGraphManagerGraphUpdated();
    }

    // @interface PTRGraphManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRGraphManagerInterface : PTRDataManagerDelegate, PTRConfigurationManagerDelegate
    {
        // -(PTRVenueGraph * _Nullable)getGraph;
        [NullAllowed, Export("getGraph")]
        PTRVenueGraph Graph { get; }

        // -(BOOL)hasContentForVenue:(int)venueId;
        [Export("hasContentForVenue:")]
        bool HasContentForVenue(int venueId);
    }

    // @protocol PTRLevelSelectorVCDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRLevelSelectorVCDelegate
    {
        // @optional -(void)userDidTapToGoLevel:(int)level;
        [Export("userDidTapToGoLevel:")]
        void UserDidTapToGoLevel(int level);
    }

    // @interface PTRLevelSelectorVC : UIViewController
    [BaseType(typeof(UIViewController))]
    interface PTRLevelSelectorVC
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRLevelSelectorVCDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRLevelSelectorVCDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic) int selectedLevel;
        [Export("selectedLevel")]
        int SelectedLevel { get; set; }

        // -(void)tryToOpenWithDelegate:(id _Nonnull)delegate andSelectedLevel:(int)level;
        [Export("tryToOpenWithDelegate:andSelectedLevel:")]
        void TryToOpenWithDelegate(NSObject @delegate, int level);
    }

    // @interface PTRLibraryHelper : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRLibraryHelper
    {
        // +(BOOL)isOldDevice;
        [Static]
        [Export("isOldDevice")]
        bool IsOldDevice { get; }

        // +(NSString * _Nullable)searchFriendlyString:(NSString * _Nonnull)str;
        [Static]
        [Export("searchFriendlyString:")]
        [return: NullAllowed]
        string SearchFriendlyString(string str);

        // +(NSString * _Nonnull)stringForLevel:(int)level;
        [Static]
        [Export("stringForLevel:")]
        string StringForLevel(int level);

        // +(NSString * _Nonnull)alphabetOnlyLowercaseStringFromString:(NSString * _Nonnull)string;
        [Static]
        [Export("alphabetOnlyLowercaseStringFromString:")]
        string AlphabetOnlyLowercaseStringFromString(string @string);

        // +(float)findAngleBetweenTwoPointsWithX1:(float)x1 y1:(float)y1 x2:(float)x2 y2:(float)y2;
        [Static]
        [Export("findAngleBetweenTwoPointsWithX1:y1:x2:y2:")]
        float FindAngleBetweenTwoPointsWithX1(float x1, float y1, float x2, float y2);

        // +(UIApplicationState)applicationState;
        [Static]
        [Export("applicationState")]
        UIApplicationState ApplicationState { get; }
    }

    // @interface PTRLoadingIndicatorView : UIView
    [BaseType(typeof(UIView))]
    interface PTRLoadingIndicatorView
    {
        // @property (assign, nonatomic) NSInteger cornerRadius;
        [Export("cornerRadius")]
        nint CornerRadius { get; set; }

        // @property (assign, nonatomic) NSInteger indicatorBGWidth;
        [Export("indicatorBGWidth")]
        nint IndicatorBGWidth { get; set; }

        // @property (retain, nonatomic) UIColor * _Nonnull indicatorBGColor;
        [Export("indicatorBGColor", ArgumentSemantic.Retain)]
        UIColor IndicatorBGColor { get; set; }

        // @property (assign, nonatomic) uint imageCount;
        [Export("imageCount")]
        uint ImageCount { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull imageSetName;
        [Export("imageSetName", ArgumentSemantic.Retain)]
        string ImageSetName { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull indicatorText;
        [Export("indicatorText", ArgumentSemantic.Retain)]
        string IndicatorText { get; set; }

        // @property (retain, nonatomic) UIColor * _Nonnull indicatorTextColor;
        [Export("indicatorTextColor", ArgumentSemantic.Retain)]
        UIColor IndicatorTextColor { get; set; }

        // @property (readonly, nonatomic) BOOL isAnimating;
        [Export("isAnimating")]
        bool IsAnimating { get; }

        // +(NSString * _Nonnull)defaultFontName;
        // +(void)setDefaultFontName:(NSString * _Nonnull)fontName;
        [Static]
        [Export("defaultFontName")]
        string DefaultFontName { get; set; }

        // +(UIColor * _Nonnull)defaultBackgroundColor;
        [Static]
        [Export("defaultBackgroundColor")]
        UIColor DefaultBackgroundColor();

        // +(void)setDefaultBackgroundColor:(UIColor * _Nonnull)color;
        [Static]
        [Export("setDefaultBackgroundColor:")]
        void SetDefaultBackgroundColor(UIColor color);

        // -(instancetype _Nonnull)initWithText:(NSString * _Nonnull)text;
        [Export("initWithText:")]
        IntPtr Constructor(string text);

        // -(instancetype _Nonnull)initWithText:(NSString * _Nonnull)text imageSetName:(NSString * _Nonnull)name imageCount:(int)count andAnimationDuration:(float)duration;
        [Export("initWithText:imageSetName:imageCount:andAnimationDuration:")]
        IntPtr Constructor(string text, string name, int count, float duration);

        // -(void)startAnimating;
        [Export("startAnimating")]
        void StartAnimating();

        // -(void)stopAnimating;
        [Export("stopAnimating")]
        void StopAnimating();
    }

    // @protocol PTRLocationSharingManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRLocationSharingManagerDelegate
    {
        // @required -(void)onLocationSharingManagerDeviceLocationsUpdated:(NSDictionary * _Nonnull)devices;
        [Abstract]
        [Export("onLocationSharingManagerDeviceLocationsUpdated:")]
        void OnLocationSharingManagerDeviceLocationsUpdated(NSDictionary devices);
    }

    // @interface PTRLocationSharingManagerInterface : PTRPointrManagerInterface <PTRConfigurationManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRLocationSharingManagerInterface : PTRConfigurationManagerDelegate
    {
    }

    // @interface PTRMaintenanceManagerInterface : PTRPointrManagerInterface
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRMaintenanceManagerInterface
    {
    }

    // @interface PTRMapDrawableViewSet : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRMapDrawableViewSet
    {
        // -(void)addView:(UIView *)view forDrawable:(id<PTRMapDrawable>)drawable;
        [Export("addView:forDrawable:")]
        void AddView(UIView view, PTRMapDrawable drawable);

        // -(void)removeViewAndDrawable:(id<PTRMapDrawable>)drawable;
        [Export("removeViewAndDrawable:")]
        void RemoveViewAndDrawable(PTRMapDrawable drawable);

        // -(NSArray<UIView *> *)allViews;
        [Export("allViews")]
        UIView[] AllViews { get; }

        // -(NSArray<id<PTRMapDrawable>> *)allDrawables;
        [Export("allDrawables")]
        PTRMapDrawable[] AllDrawables { get; }

        // -(UIView *)viewForDrawable:(id<PTRMapDrawable>)drawable;
        [Export("viewForDrawable:")]
        UIView ViewForDrawable(PTRMapDrawable drawable);

        // -(UIView *)viewForReuseIdentifier:(NSString *)reuseIdentifier;
        [Export("viewForReuseIdentifier:")]
        UIView ViewForReuseIdentifier(string reuseIdentifier);

        // -(id<PTRMapDrawable>)drawableForView:(UIView *)view;
        [Export("drawableForView:")]
        PTRMapDrawable DrawableForView(UIView view);
    }

    // @protocol PTRMapManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRMapManagerDelegate
    {
        // @optional -(void)onMapManagerMapUpdatedForVenue:(int)venueId facility:(int)facilityId level:(int)level mapType:(PTRDataType)mapType dataFromOnline:(BOOL)isOnlineData;
        [Export("onMapManagerMapUpdatedForVenue:facility:level:mapType:dataFromOnline:")]
        void OnMapManagerMapUpdatedForVenue(int venueId, int facilityId, int level, PTRDataType mapType, bool isOnlineData);

        // @optional -(void)onMapManagerCurrentMapsUpdated;
        [Export("onMapManagerCurrentMapsUpdated")]
        void OnMapManagerCurrentMapsUpdated();
    }

    // @interface PTRMapManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRMapManagerInterface : PTRDataManagerDelegate, PTRConfigurationManagerDelegate
    {
        // -(UIImage * _Nullable)getMapImageForLevel:(int)level forFacility:(int)facilityId;
        [Export("getMapImageForLevel:forFacility:")]
        [return: NullAllowed]
        UIImage GetMapImageForLevel(int level, int facilityId);

        // -(UIImage * _Nullable)getMapTileImageForLevel:(int)level forFacility:(int)facilityId row:(NSInteger)row column:(NSInteger)column scale:(NSInteger)scale;
        [Export("getMapTileImageForLevel:forFacility:row:column:scale:")]
        [return: NullAllowed]
        UIImage GetMapTileImageForLevel(int level, int facilityId, nint row, nint column, nint scale);

        // -(PTRMapVersion * _Nonnull)getMapVersionForFacility:(int)facilityId level:(int)level;
        [Export("getMapVersionForFacility:level:")]
        PTRMapVersion GetMapVersionForFacility(int facilityId, int level);

        // -(NSArray<NSNumber *> * _Nullable)availableLevels;
        [NullAllowed, Export("availableLevels")]
        NSNumber[] AvailableLevels { get; }

        // -(BOOL)hasTilesForFacility:(int)facilityId level:(int)level;
        [Export("hasTilesForFacility:level:")]
        bool HasTilesForFacility(int facilityId, int level);

        // -(BOOL)hasRasterImageForFacility:(int)facilityId level:(int)level;
        [Export("hasRasterImageForFacility:level:")]
        bool HasRasterImageForFacility(int facilityId, int level);

        // -(BOOL)hasContent;
        [Export("hasContent")]
        bool HasContent { get; }

        // -(BOOL)hasContentForLevel:(int)level;
        [Export("hasContentForLevel:")]
        bool HasContentForLevel(int level);

        // -(BOOL)hasContentForVenue:(int)venueId shouldAcceptRasterMapsAlso:(BOOL)shouldAcceptRasterMapsAlso;
        [Export("hasContentForVenue:shouldAcceptRasterMapsAlso:")]
        bool HasContentForVenue(int venueId, bool shouldAcceptRasterMapsAlso);

        // -(NSString * _Nonnull)stringForLevel:(int)level facility:(int)facilityId;
        [Export("stringForLevel:facility:")]
        string StringForLevel(int level, int facilityId);
    }

    // @protocol PTRRegionMapDrawable <PTRMapDrawable>
    [Protocol, Model]
    interface PTRRegionMapDrawable : PTRMapDrawable
    {
        // @required @property (nonatomic, strong) NSArray<PTRCorner *> * _Nullable regionArray;
        [Abstract]
        [NullAllowed, Export("regionArray", ArgumentSemantic.Strong)]
        PTRCorner[] RegionArray { get; set; }
    }

    // @protocol PTRMapViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRMapViewDelegate
    {
        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView onViewTouched:(UIView * _Nonnull)view forDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("mapView:onViewTouched:forDrawable:")]
        void OnViewTouched(PTRMapView mapView, UIView view, PTRMapDrawable drawable);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView onMapLevelChangedTo:(int)level;
        [Export("mapView:onMapLevelChangedTo:")]
        void OnMapLevelChangedTo(PTRMapView mapView, int level);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView onMapRotationModeChangedTo:(PTRMapMode)mapMode;
        [Export("mapView:onMapRotationModeChangedTo:")]
        void OnMapRotationModeChangedTo(PTRMapView mapView, PTRMapMode mapMode);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView didReceiveSingleFingerTap:(UIGestureRecognizer * _Nonnull)gestureRecognizer;
        [Export("mapView:didReceiveSingleFingerTap:")]
        void DidReceiveSingleFingerTap(PTRMapView mapView, UIGestureRecognizer gestureRecognizer);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView didZoomToLevel:(float)zoomLevel;
        [Export("mapView:didZoomToLevel:")]
        void DidZoomToLevel(PTRMapView mapView, float zoomLevel);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView didInitializeSuccessfully:(BOOL)isSuccessful;
        [Export("mapView:didInitializeSuccessfully:")]
        void DidInitializeSuccessfully(PTRMapView mapView, bool isSuccessful);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView onLoadingStateChangedTo:(PTRMapLoadingState)loadingState;
        [Export("mapView:onLoadingStateChangedTo:")]
        void OnLoadingStateChangedTo(PTRMapView mapView, PTRMapLoadingState loadingState);

        // @optional -(void)mapView:(PTRMapView * _Nonnull)mapView onScreenRectChanged:(CGRect)screenRect;
        [Export("mapView:onScreenRectChanged:")]
        void OnScreenRectChanged(PTRMapView mapView, CGRect screenRect);
    }

    // @protocol PTRMapViewDataSource <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRMapViewDataSource
    {
        // @optional -(UIView * _Nullable)mapView:(PTRMapView * _Nonnull)mapView viewForDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("mapView:viewForDrawable:")]
        [return: NullAllowed]
        UIView MapView(PTRMapView mapView, PTRMapDrawable drawable);

        // @optional -(CAShapeLayer * _Nullable)mapView:(PTRMapView * _Nonnull)mapView layerForRegionDrawable:(id<PTRRegionMapDrawable> _Nonnull)drawable;
        [Export("mapView:layerForRegionDrawable:")]
        [return: NullAllowed]
        CAShapeLayer MapView(PTRMapView mapView, PTRRegionMapDrawable drawable);

        // @optional -(CAShapeLayer * _Nullable)mapView:(PTRMapView * _Nonnull)mapView layerForLineMapDrawable:(id<PTRLineMapDrawable> _Nonnull)drawable;
        [Export("mapView:layerForLineMapDrawable:")]
        [return: NullAllowed]
        CAShapeLayer MapView(PTRMapView mapView, PTRLineMapDrawable drawable);
    }

    // @interface PTRMapView : UIView
    [BaseType(typeof(UIView))]
    interface PTRMapView
    {
        // @property (nonatomic, weak) id<PTRMapViewDataSource> _Nullable dataSource;
        [NullAllowed, Export("dataSource", ArgumentSemantic.Weak)]
        PTRMapViewDataSource DataSource { get; set; }

        // @property (assign, nonatomic) float maximumZoomScale;
        [Export("maximumZoomScale")]
        float MaximumZoomScale { get; set; }

        // @property (assign, nonatomic) float minimumZoomScale;
        [Export("minimumZoomScale")]
        float MinimumZoomScale { get; set; }

        // @property (readonly, nonatomic) CGRect screenRect;
        [Export("screenRect")]
        CGRect ScreenRect { get; }

        // @property (nonatomic) CGRect layoutLimits;
        [Export("layoutLimits", ArgumentSemantic.Assign)]
        CGRect LayoutLimits { get; set; }

        // @property (assign, nonatomic) int currentLevel;
        [Export("currentLevel")]
        int CurrentLevel { get; set; }

        // @property (atomic, strong) PTRCalculatedLocation * _Nonnull currentLocation;
        [Export("currentLocation", ArgumentSemantic.Strong)]
        PTRCalculatedLocation CurrentLocation { get; set; }

        // @property (readonly, nonatomic) int currentFacility;
        [Export("currentFacility")]
        int CurrentFacility { get; }

        // @property (assign, nonatomic) PTRMapMode currentMapMode;
        [Export("currentMapMode", ArgumentSemantic.Assign)]
        PTRMapMode CurrentMapMode { get; set; }

        // @property (assign, nonatomic) PTRMapLoadingState loadingState;
        [Export("loadingState", ArgumentSemantic.Assign)]
        PTRMapLoadingState LoadingState { get; set; }

        // @property (assign, nonatomic) BOOL shouldShowJoyStick;
        [Export("shouldShowJoyStick")]
        bool ShouldShowJoyStick { get; set; }

        // @property (nonatomic) int forcedFacilityId;
        [Export("forcedFacilityId")]
        int ForcedFacilityId { get; set; }

        // @property (nonatomic, strong) PTRPath * _Nullable path;
        [NullAllowed, Export("path", ArgumentSemantic.Strong)]
        PTRPath Path { get; set; }

        // @property (nonatomic) BOOL isFirstMapShown;
        [Export("isFirstMapShown")]
        bool IsFirstMapShown { get; set; }

        // -(void)show;
        [Export("show")]
        void Show();

        // -(void)centerMapToPosition:(PTRPosition)position;
        [Export("centerMapToPosition:")]
        void CenterMapToPosition(PTRPosition position);

        // -(void)zoomViewToCurrentPosition;
        [Export("zoomViewToCurrentPosition")]
        void ZoomViewToCurrentPosition();

        // -(void)zoomViewToDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("zoomViewToDrawable:")]
        void ZoomViewToDrawable(PTRMapDrawable drawable);

        // -(void)zoomViewToDrawable:(id<PTRMapDrawable> _Nonnull)drawable zoomLevel:(float)zoomLevel;
        [Export("zoomViewToDrawable:zoomLevel:")]
        void ZoomViewToDrawable(PTRMapDrawable drawable, float zoomLevel);

        // -(void)zoomViewToX:(float)x andY:(float)y;
        [Export("zoomViewToX:andY:")]
        void ZoomViewToX(float x, float y);

        // -(void)zoomViewToX:(float)x andY:(float)y withZoomLevel:(float)zoomLevel;
        [Export("zoomViewToX:andY:withZoomLevel:")]
        void ZoomViewToX(float x, float y, float zoomLevel);

        // -(UIView * _Nonnull)viewWithDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("viewWithDrawable:")]
        UIView ViewWithDrawable(PTRMapDrawable drawable);

        // -(void)tryRotateCanvasWithUserPinCoordinates:(CGPoint)userPinScreenCoordinates;
        [Export("tryRotateCanvasWithUserPinCoordinates:")]
        void TryRotateCanvasWithUserPinCoordinates(CGPoint userPinScreenCoordinates);

        // -(void)setMapContentCenterIfAvailableToCoordinate:(CGPoint)coordinate;
        [Export("setMapContentCenterIfAvailableToCoordinate:")]
        void SetMapContentCenterIfAvailableToCoordinate(CGPoint coordinate);

        // -(float)zoomScale;
        [Export("zoomScale")]
        float ZoomScale { get; }

        // -(CGSize)contentSize;
        [Export("contentSize")]
        CGSize ContentSize { get; }

        // -(BOOL)isScrolling;
        [Export("isScrolling")]
        bool IsScrolling { get; }

        // -(BOOL)isZooming;
        [Export("isZooming")]
        bool IsZooming { get; }

        // -(BOOL)isPointVisibleInMap:(CGPoint)point;
        [Export("isPointVisibleInMap:")]
        bool IsPointVisibleInMap(CGPoint point);

        // -(void)setMinimumZoomScaleWithPredefinedValue:(PTRMapViewMinimumZoomScale)value;
        [Export("setMinimumZoomScaleWithPredefinedValue:")]
        void SetMinimumZoomScaleWithPredefinedValue(PTRMapViewMinimumZoomScale value);

        // -(void)addListener:(id<PTRMapViewDelegate> _Nonnull)listener;
        [Export("addListener:")]
        void AddListener(PTRMapViewDelegate listener);

        // -(void)removeListener:(id<PTRMapViewDelegate> _Nonnull)listener;
        [Export("removeListener:")]
        void RemoveListener(PTRMapViewDelegate listener);

        // -(id<PTRMapDrawable> _Nonnull)drawableWithIdentifier:(NSString * _Nonnull)identifier;
        [Export("drawableWithIdentifier:")]
        PTRMapDrawable DrawableWithIdentifier(string identifier);

        // -(BOOL)isDrawableExist:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("isDrawableExist:")]
        bool IsDrawableExist(PTRMapDrawable drawable);

        // -(void)removeAllDrawables;
        [Export("removeAllDrawables")]
        void RemoveAllDrawables();

        // -(void)removeDrawables:(NSArray<id<PTRMapDrawable>> * _Nonnull)drawables;
        [Export("removeDrawables:")]
        void RemoveDrawables(PTRMapDrawable[] drawables);

        // -(void)removeDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("removeDrawable:")]
        void RemoveDrawable(PTRMapDrawable drawable);

        // -(void)addDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("addDrawable:")]
        void AddDrawable(PTRMapDrawable drawable);

        // -(void)addDrawables:(NSArray<id<PTRMapDrawable>> * _Nonnull)drawables;
        [Export("addDrawables:")]
        void AddDrawables(PTRMapDrawable[] drawables);

        // -(void)refreshAllDrawables;
        [Export("refreshAllDrawables")]
        void RefreshAllDrawables();

        // -(void)refreshDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("refreshDrawable:")]
        void RefreshDrawable(PTRMapDrawable drawable);

        // -(void)realignDrawable:(id<PTRMapDrawable> _Nonnull)drawable;
        [Export("realignDrawable:")]
        void RealignDrawable(PTRMapDrawable drawable);

        // -(void)realignDrawables;
        [Export("realignDrawables")]
        void RealignDrawables();
    }

    // @interface PTRMapMathAlgorithms : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRMapMathAlgorithms
    {
        // +(float)calculateMinimumZoomScaleForMapSize:(CGSize)mapSize scale:(PTRMapViewMinimumZoomScale)scale;
        [Static]
        [Export("calculateMinimumZoomScaleForMapSize:scale:")]
        float CalculateMinimumZoomScaleForMapSize(CGSize mapSize, PTRMapViewMinimumZoomScale scale);

        // +(CGPoint)screenPositionFromLocation:(PTRLocation *)location withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("screenPositionFromLocation:withScreenRect:")]
        CGPoint ScreenPositionFromLocation(PTRLocation location, CGRect screenRect);

        // +(CGPoint)screenPositionFromPoint:(CGPoint)point withScreenRect:(CGRect)screenRect;
        [Static]
        [Export("screenPositionFromPoint:withScreenRect:")]
        CGPoint ScreenPositionFromPoint(CGPoint point, CGRect screenRect);
    }

    // @protocol PTRMapModeViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRMapModeViewDelegate
    {
        // @required -(void)userDidTapOnMapModeView:(PTRMapModeView * _Nonnull)mapModeView;
        [Abstract]
        [Export("userDidTapOnMapModeView:")]
        void UserDidTapOnMapModeView(PTRMapModeView mapModeView);

        // @optional -(void)onMapModeView:(PTRMapModeView * _Nonnull)mapModeView changedMapMode:(PTRMapMode)mapMode;
        [Export("onMapModeView:changedMapMode:")]
        void OnMapModeView(PTRMapModeView mapModeView, PTRMapMode mapMode);
    }

    // @interface PTRMapModeView : UIView
    [BaseType(typeof(UIView))]
    interface PTRMapModeView
    {
        // @property (nonatomic) PTRMapMode currentMapMode;
        [Export("currentMapMode", ArgumentSemantic.Assign)]
        PTRMapMode CurrentMapMode { get; set; }

        // @property (nonatomic) PTRMapMode previousMapMode;
        [Export("previousMapMode", ArgumentSemantic.Assign)]
        PTRMapMode PreviousMapMode { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull imageFreeMode;
        [Export("imageFreeMode", ArgumentSemantic.Strong)]
        UIImage ImageFreeMode { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull imageTrackingMode;
        [Export("imageTrackingMode", ArgumentSemantic.Strong)]
        UIImage ImageTrackingMode { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull imagePathTrackingMode;
        [Export("imagePathTrackingMode", ArgumentSemantic.Strong)]
        UIImage ImagePathTrackingMode { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull imageRotatingMode;
        [Export("imageRotatingMode", ArgumentSemantic.Strong)]
        UIImage ImageRotatingMode { get; set; }

        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRMapModeViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRMapModeViewDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }
    }

    // @protocol PTRNavigationFooterViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRNavigationFooterViewDelegate
    {
        // @optional -(void)footerViewSwipedDown:(PTRNavigationFooterView * _Nonnull)footerView;
        [Export("footerViewSwipedDown:")]
        void FooterViewSwipedDown(PTRNavigationFooterView footerView);
    }

    // @interface PTRNavigationFooterView : UIView
    [BaseType(typeof(UIView))]
    interface PTRNavigationFooterView
    {
        // -(void)updateFooterWithPoi:(PTRPoi * _Nonnull)poi;
        [Export("updateFooterWithPoi:")]
        void UpdateFooterWithPoi(PTRPoi poi);

        // +(void)setDefaultTitleColor:(UIColor * _Nonnull)color;
        [Static]
        [Export("setDefaultTitleColor:")]
        void SetDefaultTitleColor(UIColor color);

        // +(void)setDefaultSubtitleColor:(UIColor * _Nonnull)color;
        [Static]
        [Export("setDefaultSubtitleColor:")]
        void SetDefaultSubtitleColor(UIColor color);

        // +(void)setDefaultButtonTitleColor:(UIColor * _Nonnull)color;
        [Static]
        [Export("setDefaultButtonTitleColor:")]
        void SetDefaultButtonTitleColor(UIColor color);

        // +(void)setDefaultButtonBackgroundColor:(UIColor * _Nonnull)color;
        [Static]
        [Export("setDefaultButtonBackgroundColor:")]
        void SetDefaultButtonBackgroundColor(UIColor color);

        // @property (assign, nonatomic) BOOL hasStartedPathfinding;
        [Export("hasStartedPathfinding")]
        bool HasStartedPathfinding { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull customBackgroundColour;
        [Export("customBackgroundColour", ArgumentSemantic.Strong)]
        UIColor CustomBackgroundColour { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull customLabelTextColour;
        [Export("customLabelTextColour", ArgumentSemantic.Strong)]
        UIColor CustomLabelTextColour { get; set; }

        // @property (nonatomic, strong) UIFont * _Nonnull customLabelFont;
        [Export("customLabelFont", ArgumentSemantic.Strong)]
        UIFont CustomLabelFont { get; set; }

        // @property (nonatomic, strong) UIColor * _Nonnull customButtonTextColour;
        [Export("customButtonTextColour", ArgumentSemantic.Strong)]
        UIColor CustomButtonTextColour { get; set; }

        // @property (nonatomic, strong) UIFont * _Nonnull customButtonFont;
        [Export("customButtonFont", ArgumentSemantic.Strong)]
        UIFont CustomButtonFont { get; set; }

        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRNavigationFooterViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRNavigationFooterViewDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }
    }

    // @protocol PTRNavigationHeaderViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRNavigationHeaderViewDelegate
    {
        // @optional -(void)headerViewSwipedUp:(PTRNavigationHeaderView * _Nonnull)headerView;
        [Export("headerViewSwipedUp:")]
        void HeaderViewSwipedUp(PTRNavigationHeaderView headerView);
    }

    // @interface PTRNavigationHeaderView : UIView
    [BaseType(typeof(UIView))]
    interface PTRNavigationHeaderView
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        PTRNavigationHeaderViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<PTRNavigationHeaderViewDelegate> _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // +(void)setBackgroundColor:(UIColor * _Nonnull)backgroundColor;
        [Static]
        [Export("setBackgroundColor:")]
        void SetBackgroundColor(UIColor backgroundColor);

        // +(void)setMainColorScheme:(UIColor * _Nonnull)colorScheme;
        [Static]
        [Export("setMainColorScheme:")]
        void SetMainColorScheme(UIColor colorScheme);

        // +(void)setFontName:(NSString * _Nonnull)fontName;
        [Static]
        [Export("setFontName:")]
        void SetFontName(string fontName);

        // -(void)setTotalPathTime:(float)time;
        [Export("setTotalPathTime:")]
        void SetTotalPathTime(float time);

        // -(void)updateHeaderForPath:(PTRPath * _Nonnull)path;
        [Export("updateHeaderForPath:")]
        void UpdateHeaderForPath(PTRPath path);

        // -(void)updateHeaderForPathfindingError:(NSString * _Nonnull)errorMessage;
        [Export("updateHeaderForPathfindingError:")]
        void UpdateHeaderForPathfindingError(string errorMessage);
    }

    // @interface PTROnScreenTranslationVC : UIViewController
    [BaseType(typeof(UIViewController))]
    interface PTROnScreenTranslationVC
    {
        // @property (nonatomic, strong) NSString * _Nonnull fromLang;
        [Export("fromLang", ArgumentSemantic.Strong)]
        string FromLang { get; set; }

        // @property (nonatomic, strong) NSString * _Nonnull toLang;
        [Export("toLang", ArgumentSemantic.Strong)]
        string ToLang { get; set; }
    }

    // audit-objc-generics: @interface PTRSortedDictionary<__covariant keyType : NSString *, __covariant valueType> : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRSortedDictionary
    {
        // -(instancetype _Nonnull)initWithDictionary:(NSDictionary<keyType,valueType> * _Nonnull)dictionary;
        [Export("initWithDictionary:")]
        IntPtr Constructor(NSDictionary<NSString, NSObject> dictionary);

        // -(valueType _Nullable)objectForKey:(keyType _Nonnull)key;
        [Export("objectForKey:")]
        [return: NullAllowed]
        NSObject ObjectForKey(string key);

        // -(void)removeObjectForKey:(keyType _Nonnull)key;
        [Export("removeObjectForKey:")]
        void RemoveObjectForKey(string key);

        // -(void)setObject:(valueType _Nonnull)object forKey:(keyType _Nonnull)key;
        [Export("setObject:forKey:")]
        void SetObject(NSObject @object, string key);

        // -(NSArray<keyType> * _Nonnull)allKeys;
        [Export("allKeys")]
        string[] AllKeys { get; }

        // -(NSArray<valueType> * _Nonnull)allValues;
        [Export("allValues")]
        NSObject[] AllValues { get; }

        // -(valueType _Nonnull)objectAtIndex:(NSUInteger)index;
        [Export("objectAtIndex:")]
        NSObject ObjectAtIndex(nuint index);

        // -(void)removeObjectAtIndex:(NSUInteger)index;
        [Export("removeObjectAtIndex:")]
        void RemoveObjectAtIndex(nuint index);

        // -(NSUInteger)count;
        [Export("count")]
        nuint Count { get; }

        // -(void)sortUsingSelector:(SEL _Nonnull)selector;
        [Export("sortUsingSelector:")]
        void SortUsingSelector(Selector selector);
    }

    // @interface PTRPoi : NSObject <NSCoding, PTRMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRPoi : INSCoding, PTRMapDrawable
    {
        // @property (readonly, nonatomic) PTRLocation * _Nonnull position;
        [Export("position")]
        PTRLocation Position { get; }

        // @property (readonly, nonatomic) NSString * _Nonnull name;
        [Export("name")]
        string Name { get; }

        // @property (readonly, nonatomic) NSString * _Nullable longDescription;
        [NullAllowed, Export("longDescription")]
        string LongDescription { get; }

        // @property (readonly, nonatomic) NSArray<NSString *> * _Nullable keywords;
        [NullAllowed, Export("keywords")]
        string[] Keywords { get; }

        // @property (readonly, nonatomic) NSString * _Nonnull type;
        [Export("type")]
        string Type { get; }

        // @property (readonly, nonatomic) BOOL isPortal;
        [Export("isPortal")]
        bool IsPortal { get; }

        // @property (assign, nonatomic) PTRPoiZoomLevel minimumPoiZoomLevel;
        [Export("minimumPoiZoomLevel", ArgumentSemantic.Assign)]
        PTRPoiZoomLevel MinimumPoiZoomLevel { get; set; }

        // @property (assign, nonatomic) PTRPoiZoomLevel maximumPoiZoomLevel;
        [Export("maximumPoiZoomLevel", ArgumentSemantic.Assign)]
        PTRPoiZoomLevel MaximumPoiZoomLevel { get; set; }

        // @property (readonly, nonatomic) NSDictionary<NSString *,NSObject *> * _Nullable extraData;
        [NullAllowed, Export("extraData")]
        NSDictionary<NSString, NSObject> ExtraData { get; }

        // -(instancetype _Nullable)initPoiWithIdentifier:(NSString * _Nonnull)identifier x:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId name:(NSString * _Nonnull)name searchName:(NSString * _Nullable)searchName longDescription:(NSString * _Nullable)longDescription searchLongDescription:(NSString * _Nullable)searchLongDescription keywords:(NSArray<NSString *> * _Nullable)keywords searchKeywords:(NSArray<NSString *> * _Nullable)searchKeywords type:(NSString * _Nonnull)type searchType:(NSString * _Nullable)searchType isPortal:(BOOL)isPortal extraData:(NSDictionary<NSString *,NSObject *> * _Nullable)extraData translations:(NSDictionary<NSString *,NSDictionary<NSString *,NSString *> *> * _Nullable)translations minZoomLevel:(NSString * _Nullable)minZoomLevel andMaxZoomLevel:(NSString * _Nullable)maxZoomLevel;
        [Export("initPoiWithIdentifier:x:y:level:venueId:facilityId:name:searchName:longDescription:searchLongDescription:keywords:searchKeywords:type:searchType:isPortal:extraData:translations:minZoomLevel:andMaxZoomLevel:")]
        IntPtr Constructor(string identifier, float x, float y, int level, int venueId, int facilityId, string name, [NullAllowed] string searchName, [NullAllowed] string longDescription, [NullAllowed] string searchLongDescription, [NullAllowed] string[] keywords, [NullAllowed] string[] searchKeywords, string type, [NullAllowed] string searchType, bool isPortal, [NullAllowed] NSDictionary<NSString, NSObject> extraData, [NullAllowed] NSDictionary<NSString, NSDictionary<NSString, NSString>> translations, [NullAllowed] string minZoomLevel, [NullAllowed] string maxZoomLevel);

        // -(BOOL)containsKeyword:(NSString * _Nonnull)keyword;
        [Export("containsKeyword:")]
        bool ContainsKeyword(string keyword);

        // -(UIImage * _Nullable)getDefaultImage;
        [NullAllowed, Export("getDefaultImage")]
        UIImage DefaultImage { get; }

        // -(void)fillZoomLevelPropertiesWithMapMinimumZoomScale:(float)minimumZoomScale mapMaximumZoomScale:(float)maximumZoomScale;
        [Export("fillZoomLevelPropertiesWithMapMinimumZoomScale:mapMaximumZoomScale:")]
        void FillZoomLevelPropertiesWithMapMinimumZoomScale(float minimumZoomScale, float maximumZoomScale);
    }

    // @interface PTRPoiGroup : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRPoiGroup
    {
        // @property (readonly, nonatomic, strong) NSString * _Nonnull groupName;
        [Export("groupName", ArgumentSemantic.Strong)]
        string GroupName { get; }

        // @property (readonly, nonatomic, strong) NSString * _Nonnull groupType;
        [Export("groupType", ArgumentSemantic.Strong)]
        string GroupType { get; }

        // @property (readonly, nonatomic, strong) NSString * _Nonnull groupDescription;
        [Export("groupDescription", ArgumentSemantic.Strong)]
        string GroupDescription { get; }

        // @property (nonatomic, strong) NSArray<PTRPoi *> * _Nonnull poiList;
        [Export("poiList", ArgumentSemantic.Strong)]
        PTRPoi[] PoiList { get; set; }

        // -(instancetype _Nonnull)initWithPoiList:(NSArray<PTRPoi *> * _Nonnull)poiList;
        [Export("initWithPoiList:")]
        IntPtr Constructor(PTRPoi[] poiList);
    }

    // @interface PTRPoiContainer : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRPoiContainer
    {
        // -(instancetype _Nonnull)initWithPoi:(PTRPoi * _Nonnull)poi;
        [Export("initWithPoi:")]
        IntPtr Constructor(PTRPoi poi);

        // -(instancetype _Nonnull)initWithPoiGroup:(PTRPoiGroup * _Nonnull)poiGroup;
        [Export("initWithPoiGroup:")]
        IntPtr Constructor(PTRPoiGroup poiGroup);

        // -(instancetype _Nonnull)initWithSortedDictionary:(PTRSortedDictionary<NSString *,NSArray<PTRPoi *> *> * _Nonnull)sortedDict;
        [Export("initWithSortedDictionary:")]
        IntPtr Constructor(PTRSortedDictionary sortedDict);

        // -(NSArray<PTRPoi *> * _Nonnull)getPoiList;
        [Export("getPoiList")]
        PTRPoi[] PoiList { get; }

        // -(NSArray<PTRPoiGroup *> * _Nonnull)getPoiGroupList;
        [Export("getPoiGroupList")]
        PTRPoiGroup[] PoiGroupList { get; }
    }

    // typedef void (^PTRPathManagerSuggestionCallback)(BOOL);
    delegate void PTRPathManagerSuggestionCallback(bool arg0);

    // @protocol PTRPathManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRPathManagerDelegate
    {
        // @optional -(void)onPathManagerHasSmartSuggestion:(PTRPathManagerSuggestionCallback _Nonnull)callback;
        [Export("onPathManagerHasSmartSuggestion:")]
        void OnPathManagerHasSmartSuggestion(PTRPathManagerSuggestionCallback callback);

        // @optional -(void)onPathManagerHasArrivedAtDestination;
        [Export("onPathManagerHasArrivedAtDestination")]
        void OnPathManagerHasArrivedAtDestination();

        // @optional -(void)onPathManagerHasCalculatedPath:(PTRPath * _Nullable)path;
        [Export("onPathManagerHasCalculatedPath:")]
        void OnPathManagerHasCalculatedPath([NullAllowed] PTRPath path);

        // @optional -(void)onPathManagerPathCalculationFailedWithErrorMessage:(NSString * _Nullable)errorMsg;
        [Export("onPathManagerPathCalculationFailedWithErrorMessage:")]
        void OnPathManagerPathCalculationFailedWithErrorMessage([NullAllowed] string errorMsg);

        // @optional -(void)onPathManagerPathCalculationAborted;
        [Export("onPathManagerPathCalculationAborted")]
        void OnPathManagerPathCalculationAborted();

        // @optional -(void)onPathManagerStartedPathFindingTo:(PTRPoiContainer * _Nonnull)poiSelection;
        [Export("onPathManagerStartedPathFindingTo:")]
        void OnPathManagerStartedPathFindingTo(PTRPoiContainer poiSelection);
    }

    // @interface PTRPathManagerInterface : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRPathManagerInterface
    {
        // -(void)start;
        [Export("start")]
        void Start();

        // -(void)stop;
        [Export("stop")]
        void Stop();

        // -(void)startPathfinding;
        [Export("startPathfinding")]
        void StartPathfinding();

        // -(void)abortPathfinding;
        [Export("abortPathfinding")]
        void AbortPathfinding();

        // -(void)setCurrentMode:(PTRPathfindingMode)newMode;
        [Export("setCurrentMode:")]
        void SetCurrentMode(PTRPathfindingMode newMode);

        // -(BOOL)isPathFindingStarted;
        [Export("isPathFindingStarted")]
        bool IsPathFindingStarted { get; }

        // -(PTRPath * _Nullable)calculatePath;
        [NullAllowed, Export("calculatePath")]
        PTRPath CalculatePath { get; }

        // -(PTRPath * _Nullable)calculatePathFromLocation:(PTRLocation * _Nonnull)source toLocation:(PTRLocation * _Nonnull)destination;
        [Export("calculatePathFromLocation:toLocation:")]
        [return: NullAllowed]
        PTRPath CalculatePathFromLocation(PTRLocation source, PTRLocation destination);

        // -(PTRPath * _Nullable)calculatePathFromLocation:(PTRLocation * _Nonnull)source toNearestPositionFromArray:(NSArray<PTRLocation *> * _Nonnull)destinations;
        [Export("calculatePathFromLocation:toNearestPositionFromArray:")]
        [return: NullAllowed]
        PTRPath CalculatePathFromLocation(PTRLocation source, PTRLocation[] destinations);

        // -(void)addListener:(id<PTRPathManagerDelegate> _Nonnull)listenerToAdd;
        [Export("addListener:")]
        void AddListener(PTRPathManagerDelegate listenerToAdd);

        // -(void)removeListener:(id<PTRPathManagerDelegate> _Nonnull)listenerToRemove;
        [Export("removeListener:")]
        void RemoveListener(PTRPathManagerDelegate listenerToRemove);

        // -(float)calculateActualDistanceBetweenLocation:(PTRLocation * _Nonnull)first andLocation:(PTRLocation * _Nonnull)second;
        [Export("calculateActualDistanceBetweenLocation:andLocation:")]
        float CalculateActualDistanceBetweenLocation(PTRLocation first, PTRLocation second);

        // -(PTRTravelEstimation * _Nonnull)calculateTravelEstimationBetweenNode:(PTRNodeInterface * _Nonnull)node1 andNode:(PTRNodeInterface * _Nonnull)node2;
        [Export("calculateTravelEstimationBetweenNode:andNode:")]
        PTRTravelEstimation CalculateTravelEstimationBetweenNode(PTRNodeInterface node1, PTRNodeInterface node2);

        // -(PTRTravelEstimation * _Nonnull)calculateTravelEstimationForPath:(PTRPath * _Nonnull)path untilNode:(PTRNodeInterface * _Nonnull)endNode;
        [Export("calculateTravelEstimationForPath:untilNode:")]
        PTRTravelEstimation CalculateTravelEstimationForPath(PTRPath path, PTRNodeInterface endNode);

        // -(NSDictionary<NSString *,PTRNodeInterface *> * _Nonnull)getAllGraphNodes;
        [Export("getAllGraphNodes")]
        NSDictionary<NSString, PTRNodeInterface> AllGraphNodes { get; }
    }

    // @protocol PTRPositionManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRPositionManagerDelegate
    {
        // @optional -(void)onPositionManagerCalculatedLocation:(PTRCalculatedLocation * _Nonnull)calculatedLocation;
        [Export("onPositionManagerCalculatedLocation:")]
        void OnPositionManagerCalculatedLocation(PTRCalculatedLocation calculatedLocation);

        // @optional -(void)onPositionManagerPositioningServiceStateChangedTo:(PTRPositioningServiceState)state;
        [Export("onPositionManagerPositioningServiceStateChangedTo:")]
        void OnPositionManagerPositioningServiceStateChangedTo(PTRPositioningServiceState state);

        // @optional -(void)onPositionManagerDetectedPositionLevelChange:(int)level;
        [Export("onPositionManagerDetectedPositionLevelChange:")]
        void OnPositionManagerDetectedPositionLevelChange(int level);

        // @optional -(void)onPositionManagerPositionIsFading;
        [Export("onPositionManagerPositionIsFading")]
        void OnPositionManagerPositionIsFading();

        // @optional -(void)onPositionManagerPositionIsLost;
        [Export("onPositionManagerPositionIsLost")]
        void OnPositionManagerPositionIsLost();
    }

    // @interface PTRPositionManagerInterface : NSObject
    [BaseType(typeof(NSObject))]
    interface PTRPositionManagerInterface
    {
        // @property (readonly, nonatomic) PTRCalculatedLocation * _Nonnull lastValidCalculatedLocation;
        [Export("lastValidCalculatedLocation")]
        PTRCalculatedLocation LastValidCalculatedLocation { get; }

        // @property (readonly, nonatomic) PTRCalculatedLocation * _Nonnull currentCalculatedLocation;
        [Export("currentCalculatedLocation")]
        PTRCalculatedLocation CurrentCalculatedLocation { get; }

        // @property (readonly, nonatomic) PTRPositioningServiceState serviceState;
        [Export("serviceState")]
        PTRPositioningServiceState ServiceState { get; }

        // @property (readonly, nonatomic) CMAttitude * _Nonnull attitude;
        [Export("attitude")]
        CMAttitude Attitude { get; }

        // -(void)start;
        [Export("start")]
        void Start();

        // -(void)stop;
        [Export("stop")]
        void Stop();

        // -(void)addListener:(id<PTRPositionManagerDelegate> _Nonnull)listenerToAdd;
        [Export("addListener:")]
        void AddListener(PTRPositionManagerDelegate listenerToAdd);

        // -(void)removeListener:(id<PTRPositionManagerDelegate> _Nonnull)listenerToRemove;
        [Export("removeListener:")]
        void RemoveListener(PTRPositionManagerDelegate listenerToRemove);
    }

    // @protocol PTRPoiManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRPoiManagerDelegate
    {
        // @optional -(void)onPoiManagerCurrentPoisUpdated;
        [Export("onPoiManagerCurrentPoisUpdated")]
        void OnPoiManagerCurrentPoisUpdated();

        // @optional -(void)onPoiManagerSelectedPoi:(PTRPoiContainer * _Nonnull)poiSelection;
        [Export("onPoiManagerSelectedPoi:")]
        void OnPoiManagerSelectedPoi(PTRPoiContainer poiSelection);

        // @optional -(void)onPoiManagerEnterTrigger:(PTRPoi * _Nonnull)triggerPoi;
        [Export("onPoiManagerEnterTrigger:")]
        void OnPoiManagerEnterTrigger(PTRPoi triggerPoi);
    }

    // @interface PTRPoiManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRConfigurationManagerDelegate, PTRPositionManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRPoiManagerInterface : PTRDataManagerDelegate, PTRConfigurationManagerDelegate, PTRPositionManagerDelegate
    {
        // -(id<PTRRegionMapDrawable> _Nonnull)getStoreLayoutPoiForLevel:(int)level forFacility:(int)facilityId;
        [Export("getStoreLayoutPoiForLevel:forFacility:")]
        PTRRegionMapDrawable GetStoreLayoutPoiForLevel(int level, int facilityId);

        // -(PTRPoiContainer * _Nullable)getSelectedPoi;
        [NullAllowed, Export("getSelectedPoi")]
        PTRPoiContainer SelectedPoi { get; }

        // -(PTRPoiContainer * _Nullable)getAllPoi;
        [NullAllowed, Export("getAllPoi")]
        PTRPoiContainer AllPoi { get; }

        // -(PTRPoiContainer * _Nonnull)getAllPoisOnLevel:(NSNumber * _Nullable)level withType:(NSString * _Nullable)type inFacility:(NSNumber * _Nullable)facilityId;
        [Export("getAllPoisOnLevel:withType:inFacility:")]
        PTRPoiContainer GetAllPoisOnLevel([NullAllowed] NSNumber level, [NullAllowed] string type, [NullAllowed] NSNumber facilityId);

        // -(PTRPoiContainer * _Nonnull)getPoiWithIdentifier:(NSString * _Nonnull)identifier;
        [Export("getPoiWithIdentifier:")]
        PTRPoiContainer GetPoiWithIdentifier(string identifier);

        // -(PTRPoiContainer * _Nonnull)getPoiByName:(NSString * _Nonnull)name;
        [Export("getPoiByName:")]
        PTRPoiContainer GetPoiByName(string name);

        // -(NSArray<NSString *> * _Nullable)getAllPoiTypes;
        [NullAllowed, Export("getAllPoiTypes")]
        string[] AllPoiTypes { get; }

        // -(BOOL)hasContentForVenue:(int)venueId;
        [Export("hasContentForVenue:")]
        bool HasContentForVenue(int venueId);

        // -(PTRPoiContainer * _Nullable)searchPoi:(NSString * _Nonnull)searchString;
        [Export("searchPoi:")]
        [return: NullAllowed]
        PTRPoiContainer SearchPoi(string searchString);

        // -(PTRPoiContainer * _Nonnull)searchPoi:(NSString * _Nonnull)searchString inFacility:(int)facilityId;
        [Export("searchPoi:inFacility:")]
        PTRPoiContainer SearchPoi(string searchString, int facilityId);

        // -(void)resetSelectedPoiContainer;
        [Export("resetSelectedPoiContainer")]
        void ResetSelectedPoiContainer();

        // -(void)setSelectedPoiContainer:(PTRPoiContainer * _Nonnull)poiSelection;
        [Export("setSelectedPoiContainer:")]
        void SetSelectedPoiContainer(PTRPoiContainer poiSelection);
    }

    // @interface PTRPoiView : PTRMapDrawablePointView
    [BaseType(typeof(PTRMapDrawablePointView))]
    interface PTRPoiView
    {
        // @property (nonatomic, strong) UIImageView * _Nonnull poiImageView;
        [Export("poiImageView", ArgumentSemantic.Strong)]
        UIImageView PoiImageView { get; set; }

        // @property (nonatomic, strong) UILabel * _Nonnull poiNameLabelBottom;
        [Export("poiNameLabelBottom", ArgumentSemantic.Strong)]
        UILabel PoiNameLabelBottom { get; set; }

        // @property (nonatomic, strong) UILabel * _Nonnull poiNameLabelLeft;
        [Export("poiNameLabelLeft", ArgumentSemantic.Strong)]
        UILabel PoiNameLabelLeft { get; set; }

        // @property (nonatomic, strong) UILabel * _Nonnull poiNameLabelRight;
        [Export("poiNameLabelRight", ArgumentSemantic.Strong)]
        UILabel PoiNameLabelRight { get; set; }

        // @property (nonatomic) PTRPoiLabelPlace poiLabelPlace;
        [Export("poiLabelPlace", ArgumentSemantic.Assign)]
        PTRPoiLabelPlace PoiLabelPlace { get; set; }

        // @property (nonatomic) BOOL isEnlarged;
        [Export("isEnlarged")]
        bool IsEnlarged { get; set; }

        // -(instancetype _Nonnull)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable> _Nonnull)drawable withImage:(UIImage * _Nonnull)image;
        [Export("initWithFrame:forDrawable:withImage:")]
        IntPtr Constructor(CGRect frame, PTRMapDrawable drawable, UIImage image);

        // -(instancetype _Nonnull)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable> _Nonnull)drawable withImage:(UIImage * _Nonnull)image shouldShowNameLabel:(BOOL)shouldShowNameLabel;
        [Export("initWithFrame:forDrawable:withImage:shouldShowNameLabel:")]
        IntPtr Constructor(CGRect frame, PTRMapDrawable drawable, UIImage image, bool shouldShowNameLabel);

        // -(instancetype _Nonnull)initWithFrame:(CGRect)frame forDrawable:(id<PTRMapDrawable> _Nonnull)drawable withView:(UIView * _Nonnull)view shouldShowNameLabel:(BOOL)shouldShowNameLabel;
        [Export("initWithFrame:forDrawable:withView:shouldShowNameLabel:")]
        IntPtr Constructor(CGRect frame, PTRMapDrawable drawable, UIView view, bool shouldShowNameLabel);

        // +(void)setPoiImageEnlargingRate:(float)poiImageEnlargingRate;
        [Static]
        [Export("setPoiImageEnlargingRate:")]
        void SetPoiImageEnlargingRate(float poiImageEnlargingRate);

        // -(void)enlargePoiImage;
        [Export("enlargePoiImage")]
        void EnlargePoiImage();

        // -(void)shrinkPoiImage;
        [Export("shrinkPoiImage")]
        void ShrinkPoiImage();

        // -(UILabel * _Nonnull)visibleLabel;
        [Export("visibleLabel")]
        UILabel VisibleLabel { get; }
    }

    // @interface PTRPushManagerInterface : PTRPointrManagerInterface
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRPushManagerInterface
    {
        // -(BOOL)handleNotificationWithUserInfo:(NSDictionary * _Nonnull)userInfo;
        [Export("handleNotificationWithUserInfo:")]
        bool HandleNotificationWithUserInfo(NSDictionary userInfo);

        // -(void)registerPushToken:(NSData * _Nonnull)deviceToken withCallback:(void (^ _Nonnull)(PTRApiResponse * _Nonnull))callback;
        [Export("registerPushToken:withCallback:")]
        void RegisterPushToken(NSData deviceToken, Action<PTRApiResponse> callback);

        // -(void)unregisterUserFromPushwithCallback:(void (^ _Nonnull)(PTRApiResponse * _Nonnull))callback;
        [Export("unregisterUserFromPushwithCallback:")]
        void UnregisterUserFromPushwithCallback(Action<PTRApiResponse> callback);

        // -(void)registerAppForPush;
        [Export("registerAppForPush")]
        void RegisterAppForPush();

        // -(void)playSoundForPush:(int)inSystemSoundId;
        [Export("playSoundForPush:")]
        void PlaySoundForPush(int inSystemSoundId);

        // -(void)setNotificationBadgeToValue:(int)badgeNumber;
        [Export("setNotificationBadgeToValue:")]
        void SetNotificationBadgeToValue(int badgeNumber);
    }

    // @interface PTRRasterMapView : UIScrollView
    [BaseType(typeof(UIScrollView))]
    interface PTRRasterMapView
    {
        // @property (nonatomic) int shownLevel;
        [Export("shownLevel")]
        int ShownLevel { get; set; }

        [Wrap("WeakRasterDelegate")]
        [NullAllowed]
        NSObject RasterDelegate { get; set; }

        // @property (weak) id _Nullable rasterDelegate;
        [NullAllowed, Export("rasterDelegate", ArgumentSemantic.Weak)]
        NSObject WeakRasterDelegate { get; set; }

        // -(void)displayImage:(UIImage * _Nonnull)image;
        [Export("displayImage:")]
        void DisplayImage(UIImage image);

        // @property (nonatomic) CGRect layoutLimits;
        [Export("layoutLimits", ArgumentSemantic.Assign)]
        CGRect LayoutLimits { get; set; }
    }

    // @protocol PTRRasterMapViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRRasterMapViewDelegate
    {
        // @required -(void)rasterMapViewDidZoom:(PTRRasterMapView * _Nonnull)rasterMap;
        [Abstract]
        [Export("rasterMapViewDidZoom:")]
        void RasterMapViewDidZoom(PTRRasterMapView rasterMap);
    }

    // @protocol PTRRouteVCDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRRouteVCDelegate
    {
        // @optional -(void)routeViewUserDidTapRouteStartButton;
        [Export("routeViewUserDidTapRouteStartButton")]
        void RouteViewUserDidTapRouteStartButton();
    }

    // @interface PTRRouteVC : UIViewController
    [BaseType(typeof(UIViewController))]
    interface PTRRouteVC
    {
        [Wrap("WeakDelegate")]
        [NullAllowed]
        NSObject Delegate { get; set; }

        // @property (nonatomic, weak) id _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic, strong) NSArray<PTRPathDirection *> * _Nonnull routeArray;
        [Export("routeArray", ArgumentSemantic.Strong)]
        PTRPathDirection[] RouteArray { get; set; }

        // @property (nonatomic, strong) NSArray<NSNumber *> * _Nonnull minutesArray;
        [Export("minutesArray", ArgumentSemantic.Strong)]
        NSNumber[] MinutesArray { get; set; }

        // @property (nonatomic, strong) PTRPoi * _Nonnull endPoint;
        [Export("endPoint", ArgumentSemantic.Strong)]
        PTRPoi EndPoint { get; set; }

        // @property int totalTime;
        [Export("totalTime")]
        int TotalTime { get; set; }

        // -(void)initialisePropertiesAndTryToPresentWithDelegate:(id _Nonnull)delegate;
        [Export("initialisePropertiesAndTryToPresentWithDelegate:")]
        void InitialisePropertiesAndTryToPresentWithDelegate(NSObject @delegate);

        // +(void)setMainColorScheme:(UIColor * _Nonnull)colorScheme;
        [Static]
        [Export("setMainColorScheme:")]
        void SetMainColorScheme(UIColor colorScheme);

        // +(void)setFontName:(NSString * _Nonnull)fontName;
        [Static]
        [Export("setFontName:")]
        void SetFontName(string fontName);
    }

    // @protocol PTRSearchViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRSearchViewDelegate
    {
        // @optional -(void)searchView:(PTRSearchView * _Nonnull)searchView didCancelSearch:(BOOL)isCancelled;
        [Export("searchView:didCancelSearch:")]
        void SearchView(PTRSearchView searchView, bool isCancelled);

        // @optional -(void)searchView:(PTRSearchView * _Nonnull)searchView didSelectPoi:(PTRPoi * _Nonnull)poi;
        [Export("searchView:didSelectPoi:")]
        void SearchView(PTRSearchView searchView, PTRPoi poi);

        // @optional -(void)searchViewOnUserPressedSearchField;
        [Export("searchViewOnUserPressedSearchField")]
        void SearchViewOnUserPressedSearchField();

        // @optional -(void)searchViewStartedPathFinding;
        [Export("searchViewStartedPathFinding")]
        void SearchViewStartedPathFinding();
    }

    // @interface PTRSearchView : UIView
    [BaseType(typeof(UIView))]
    interface PTRSearchView
    {
        // -(instancetype _Nonnull)initWithFrame:(CGRect)frame searchImage:(UIImage * _Nonnull)searchImage cancelImage:(UIImage * _Nonnull)cancelImage;
        [Export("initWithFrame:searchImage:cancelImage:")]
        IntPtr Constructor(CGRect frame, UIImage searchImage, UIImage cancelImage);

        [Wrap("WeakDelegate")]
        [NullAllowed]
        NSObject Delegate { get; set; }

        // @property (weak) id _Nullable delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (retain, nonatomic) UIColor * _Nonnull customSearchBoxTextColour;
        [Export("customSearchBoxTextColour", ArgumentSemantic.Retain)]
        UIColor CustomSearchBoxTextColour { get; set; }

        // @property (retain, nonatomic) UIColor * _Nonnull customResultTableTextColour;
        [Export("customResultTableTextColour", ArgumentSemantic.Retain)]
        UIColor CustomResultTableTextColour { get; set; }

        // @property (retain, nonatomic) UIColor * _Nonnull customResultTableBackgroundColour;
        [Export("customResultTableBackgroundColour", ArgumentSemantic.Retain)]
        UIColor CustomResultTableBackgroundColour { get; set; }

        // @property (retain, nonatomic) UIFont * _Nonnull customSearchBoxFont;
        [Export("customSearchBoxFont", ArgumentSemantic.Retain)]
        UIFont CustomSearchBoxFont { get; set; }

        // @property (retain, nonatomic) UIFont * _Nonnull customResultTableFont;
        [Export("customResultTableFont", ArgumentSemantic.Retain)]
        UIFont CustomResultTableFont { get; set; }

        // @property (retain, nonatomic) NSString * _Nonnull customSearchPlaceholderText;
        [Export("customSearchPlaceholderText", ArgumentSemantic.Retain)]
        string CustomSearchPlaceholderText { get; set; }

        // -(void)hideSearchView;
        [Export("hideSearchView")]
        void HideSearchView();
    }

    // @interface PTRSimpleLineMapDrawable : NSObject <PTRLineMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRSimpleLineMapDrawable : PTRLineMapDrawable
    {
    }

    // @interface PTRSimpleMapDrawable : NSObject <PTRMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRSimpleMapDrawable : PTRMapDrawable
    {
    }

    // @interface PTRSimpleRegionMapDrawable : NSObject <PTRRegionMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRSimpleRegionMapDrawable : PTRRegionMapDrawable
    {
    }

    // @interface PTRTurnByTurnDirectionManager : NSObject <PTRSingletonProtocol>
    [BaseType(typeof(NSObject))]
    interface PTRTurnByTurnDirectionManager : PTRSingletonProtocol
    {
        // -(BOOL)addDirectionsForPath:(PTRPath * _Nullable)path;
        [Export("addDirectionsForPath:")]
        bool AddDirectionsForPath([NullAllowed] PTRPath path);

        // -(BOOL)updateDirectionsForPath:(PTRPath * _Nullable)path;
        [Export("updateDirectionsForPath:")]
        bool UpdateDirectionsForPath([NullAllowed] PTRPath path);

        // -(void)updateLocation:(PTRCalculatedLocation * _Nonnull)location;
        [Export("updateLocation:")]
        void UpdateLocation(PTRCalculatedLocation location);
    }

    // @interface PTRUserSession : NSObject <NSCoding>
    [BaseType(typeof(NSObject))]
    interface PTRUserSession : INSCoding
    {
        // @property (readonly, nonatomic) NSString * _Nullable authenticationToken;
        [NullAllowed, Export("authenticationToken")]
        string AuthenticationToken { get; }

        // @property (readonly, nonatomic) NSString * _Nullable username;
        [NullAllowed, Export("username")]
        string Username { get; }

        // @property (readonly, nonatomic) NSString * _Nullable deviceIdentifier;
        [NullAllowed, Export("deviceIdentifier")]
        string DeviceIdentifier { get; }

        // @property (nonatomic, strong) NSString * _Nullable preferredLanguage;
        [NullAllowed, Export("preferredLanguage", ArgumentSemantic.Strong)]
        string PreferredLanguage { get; set; }

        // -(instancetype _Nonnull)initWithAuthenticationToken:(NSString * _Nonnull)authenticationToken deviceIdentifier:(NSString * _Nonnull)deviceIdentifier;
        [Export("initWithAuthenticationToken:deviceIdentifier:")]
        IntPtr Constructor(string authenticationToken, string deviceIdentifier);

        // -(BOOL)isEqual:(PTRUserSession * _Nullable)otherSession;
        [Export("isEqual:")]
        bool IsEqual([NullAllowed] PTRUserSession otherSession);
    }

    // @protocol PTRUserManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRUserManagerDelegate
    {
        // @optional -(void)onUserManagerSessionUpdatedTo:(PTRUserSession * _Nonnull)newSession;
        [Export("onUserManagerSessionUpdatedTo:")]
        void OnUserManagerSessionUpdatedTo(PTRUserSession newSession);

        // @optional -(void)onUserManagerPreferredLanguageUpdatedTo:(NSString * _Nonnull)newLangCode;
        [Export("onUserManagerPreferredLanguageUpdatedTo:")]
        void OnUserManagerPreferredLanguageUpdatedTo(string newLangCode);
    }

    // @interface PTRUserManagerInterface : PTRPointrManagerInterface
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRUserManagerInterface
    {
        // -(void)registerDeviceWithCallback:(void (^ _Nonnull)(PTRApiResponse * _Nonnull))callback;
        [Export("registerDeviceWithCallback:")]
        void RegisterDeviceWithCallback(Action<PTRApiResponse> callback);

        // -(void)logoutWithCallback:(void (^ _Nonnull)(PTRApiResponse * _Nonnull))callback;
        [Export("logoutWithCallback:")]
        void LogoutWithCallback(Action<PTRApiResponse> callback);

        // -(void)setPreferredLanguage:(NSString * _Nullable)languageCode;
        [Export("setPreferredLanguage:")]
        void SetPreferredLanguage([NullAllowed] string languageCode);

        // @property (readonly, nonatomic) PTRUserSession * _Nonnull currentUserSession;
        [Export("currentUserSession")]
        PTRUserSession CurrentUserSession { get; }
    }

    // @interface PTRUserPinView : PTRMapDrawablePointView
    [BaseType(typeof(PTRMapDrawablePointView))]
    interface PTRUserPinView
    {
        // @property (nonatomic) CGFloat accuracyRadius;
        [Export("accuracyRadius")]
        nfloat AccuracyRadius { get; set; }

        // @property (nonatomic, strong) UIImage * _Nonnull pinImage;
        [Export("pinImage", ArgumentSemantic.Strong)]
        UIImage PinImage { get; set; }

        // @property (nonatomic) PTROrientationAccuracyClass orientationAccuracyClass;
        [Export("orientationAccuracyClass", ArgumentSemantic.Assign)]
        PTROrientationAccuracyClass OrientationAccuracyClass { get; set; }

        // @property (nonatomic) float rotation;
        [Export("rotation")]
        float Rotation { get; set; }

        // -(void)calculateAndSetAccuracyCircleRadiusWithAccuracy:(float)accuracy mapContentSize:(CGSize)contentSize;
        [Export("calculateAndSetAccuracyCircleRadiusWithAccuracy:mapContentSize:")]
        void CalculateAndSetAccuracyCircleRadiusWithAccuracy(float accuracy, CGSize contentSize);

        // -(void)startAnimatingAccuracy;
        [Export("startAnimatingAccuracy")]
        void StartAnimatingAccuracy();

        // -(void)stopAnimatingAccuracy;
        [Export("stopAnimatingAccuracy")]
        void StopAnimatingAccuracy();

        // -(void)fadeTo:(CGFloat)newAlpha;
        [Export("fadeTo:")]
        void FadeTo(nfloat newAlpha);

        // -(void)animate:(BOOL)animate;
        [Export("animate:")]
        void Animate(bool animate);

        // +(void)setShouldDisableHuggingArms:(BOOL)shouldDisableHuggingArms;
        [Static]
        [Export("setShouldDisableHuggingArms:")]
        void SetShouldDisableHuggingArms(bool shouldDisableHuggingArms);
    }

    // @protocol PTRVenueFacilityManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRVenueFacilityManagerDelegate
    {
        // @optional -(void)onVenueFacilityManagerUpdated;
        [Export("onVenueFacilityManagerUpdated")]
        void OnVenueFacilityManagerUpdated();
    }

    // @interface PTRVenueFacilityManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRVenueFacilityManagerInterface : PTRDataManagerDelegate
    {
        // -(int)resolveVenueFromFacility:(int)facilityInternalIdentifier;
        [Export("resolveVenueFromFacility:")]
        int ResolveVenueFromFacility(int facilityInternalIdentifier);

        // -(int)resolveFacilityFromVenue:(int)venueInternalIdentifier;
        [Export("resolveFacilityFromVenue:")]
        int ResolveFacilityFromVenue(int venueInternalIdentifier);

        // -(int)resolveVenueExternalIdentifier:(NSString *)venueExternalIdentifier;
        [Export("resolveVenueExternalIdentifier:")]
        int ResolveVenueExternalIdentifier(string venueExternalIdentifier);

        // -(int)resolveFacilityExternalIdentifier:(NSString *)facilityExternalIdentifier;
        [Export("resolveFacilityExternalIdentifier:")]
        int ResolveFacilityExternalIdentifier(string facilityExternalIdentifier);
    }

    // @interface PTRWall : NSObject <NSCoding, PTRRegionMapDrawable>
    [BaseType(typeof(NSObject))]
    interface PTRWall : INSCoding, PTRRegionMapDrawable
    {
        // @property (readonly, nonatomic) long wallId;
        [Export("wallId")]
        nint WallId { get; }

        // @property (readonly, nonatomic) int level;
        [Export("level")]
        int Level { get; }

        // @property (readonly, nonatomic) int venueId;
        [Export("venueId")]
        int VenueId { get; }

        // @property (readonly, nonatomic) int facilityId;
        [Export("facilityId")]
        int FacilityId { get; }

        // @property (readonly, nonatomic) NSArray<PTRCorner *> * _Nonnull corners;
        [Export("corners")]
        PTRCorner[] Corners { get; }

        // @property (readonly, nonatomic) PTRWallType type;
        [Export("type")]
        PTRWallType Type { get; }

        // -(instancetype _Nonnull)initWithWallId:(long)wallId level:(int)level venueId:(int)venueId facilityId:(int)facilityId type:(NSString * _Nonnull)type andCorners:(NSArray<PTRCorner *> * _Nonnull)corners;
        [Export("initWithWallId:level:venueId:facilityId:type:andCorners:")]
        IntPtr Constructor(nint wallId, int level, int venueId, int facilityId, string type, PTRCorner[] corners);

        // +(PTRWallType)typeFromString:(NSString * _Nonnull)str;
        [Static]
        [Export("typeFromString:")]
        PTRWallType TypeFromString(string str);

        // +(NSString * _Nonnull)stringFromType:(PTRWallType)type;
        [Static]
        [Export("stringFromType:")]
        string StringFromType(PTRWallType type);
    }

    // @protocol PTRWallManagerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PTRWallManagerDelegate
    {
        // @optional -(void)onWallManagerCurrentWallsUpdated;
        [Export("onWallManagerCurrentWallsUpdated")]
        void OnWallManagerCurrentWallsUpdated();
    }

    // @interface PTRWallManagerInterface : PTRPointrManagerInterface <PTRDataManagerDelegate, PTRConfigurationManagerDelegate>
    [BaseType(typeof(PTRPointrManagerInterface))]
    interface PTRWallManagerInterface : PTRDataManagerDelegate, PTRConfigurationManagerDelegate
    {
        // -(NSArray<PTRWall *> * _Nonnull)getAllWalls;
        [Export("getAllWalls")]
        PTRWall[] AllWalls { get; }

        // -(NSArray<PTRWall *> * _Nonnull)getAllWallsOnLevel:(NSNumber * _Nullable)level inFacility:(NSNumber * _Nullable)facility;
        [Export("getAllWallsOnLevel:inFacility:")]
        PTRWall[] GetAllWallsOnLevel([NullAllowed] NSNumber level, [NullAllowed] NSNumber facility);

        // -(BOOL)hasContentForVenue:(int)venueId;
        [Export("hasContentForVenue:")]
        bool HasContentForVenue(int venueId);
    }

    // @interface PointrMode : NSObject
    [BaseType(typeof(NSObject))]
    [DisableDefaultCtor]
    interface PointrMode
    {
        // +(instancetype)mode;
        [Static]
        [Export("mode")]
        PointrMode Mode();

        // @property (readonly, assign, nonatomic) PTRLoggerLevel defaultLoggerLevel;
        [Export("defaultLoggerLevel", ArgumentSemantic.Assign)]
        PTRLoggerLevel DefaultLoggerLevel { get; }

        // -(BOOL)isLoggerLevelAllowed:(PTRLoggerLevel)level;
        [Export("isLoggerLevelAllowed:")]
        bool IsLoggerLevelAllowed(PTRLoggerLevel level);

        // @property (readonly, assign, nonatomic) BOOL isClassDataLoggingAllowed;
        [Export("isClassDataLoggingAllowed")]
        bool IsClassDataLoggingAllowed { get; }

        // @property (readonly, assign, nonatomic) BOOL shouldAssertionsCrash;
        [Export("shouldAssertionsCrash")]
        bool ShouldAssertionsCrash { get; }

        // @property (readonly, assign, nonatomic) BOOL isSimulationAllowed;
        [Export("isSimulationAllowed")]
        bool IsSimulationAllowed { get; }

        // @property (readonly, assign, nonatomic) BOOL isOnScreenLoggingAllowed;
        [Export("isOnScreenLoggingAllowed")]
        bool IsOnScreenLoggingAllowed { get; }

        // @property (readonly, copy, nonatomic) NSString * bluetoothEventFileName;
        [Export("bluetoothEventFileName")]
        string BluetoothEventFileName { get; }

        // @property (readonly, copy, nonatomic) NSString * sensorEventFileName;
        [Export("sensorEventFileName")]
        string SensorEventFileName { get; }

        // @property (readonly, assign, nonatomic) BOOL isHiddenNotificationsAllowed;
        [Export("isHiddenNotificationsAllowed")]
        bool IsHiddenNotificationsAllowed { get; }

        // @property (readonly, copy, nonatomic) NSString * OCRTextFilePath;
        [Export("OCRTextFilePath")]
        string OCRTextFilePath { get; }
    }

    // @interface PointrDebugMode : PointrMode
    [BaseType(typeof(PointrMode))]
    interface PointrDebugMode
    {
    }

    // @interface PointrReleaseMode : PointrMode
    [BaseType(typeof(PointrMode))]
    interface PointrReleaseMode
    {
    }

    [Static]
    partial interface Constants
    {
        // extern NSString *const _Nonnull POINTR_VERSION_NUMBER;
        [Field("POINTR_VERSION_NUMBER", "__Internal")]
        NSString POINTR_VERSION_NUMBER { get; }

        // extern NSString *const _Nonnull POINTR_VENDOR_NAME;
        [Field("POINTR_VENDOR_NAME", "__Internal")]
        NSString POINTR_VENDOR_NAME { get; }
    }

    // @protocol PointrBaseDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface PointrBaseDelegate
    {
        // @optional -(void)onPointrBaseStop;
        [Export("onPointrBaseStop")]
        void OnPointrBaseStop();

        // @optional -(void)onPointrBaseStateChangedTo:(PointrState)state withMessages:(NSArray<NSString *> * _Nullable)messages;
        [Export("onPointrBaseStateChangedTo:withMessages:")]
        void OnPointrBaseStateChangedTo(PointrState state, [NullAllowed] string[] messages);
    }

    // typedef void (^PointrOnErrorCallback)(NSArray<NSString *> * _Nullable);
    delegate void PointrOnErrorCallback([NullAllowed] string[] arg0);

    // typedef void (^PointrOnStateChangedCallback)(PointrState, NSArray<NSString *> * _Nullable);
    delegate void PointrOnStateChangedCallback(PointrState arg0, [NullAllowed] string[] arg1);

    // @interface PointrBase : PTRAdvertiser <PTRSingletonProtocol>
    [BaseType(typeof(PTRAdvertiser))]
    interface PointrBase : PTRSingletonProtocol
    {
        // @property (assign, nonatomic) BOOL isCrashHandlingEnabled;
        [Export("isCrashHandlingEnabled")]
        bool IsCrashHandlingEnabled { get; set; }

        // @property (assign, nonatomic) PTRLoggerLevel loggerLevel;
        [Export("loggerLevel", ArgumentSemantic.Assign)]
        PTRLoggerLevel LoggerLevel { get; set; }

        // @property (nonatomic, strong) PointrMode * _Nonnull mode;
        [Export("mode", ArgumentSemantic.Strong)]
        PointrMode Mode { get; set; }

        // @property (readonly, nonatomic) PointrState state;
        [Export("state")]
        PointrState State { get; }

        // @property (readonly, nonatomic) NSString * _Nonnull version;
        [Export("version")]
        string Version { get; }

        // -(void)startWithLicenseKey:(NSString * _Nonnull)licenseKey onStateChanged:(PointrOnStateChangedCallback _Nonnull)onStateChanged onError:(PointrOnErrorCallback _Nonnull)onError;
        [Export("startWithLicenseKey:onStateChanged:onError:")]
        void StartWithLicenseKey(string licenseKey, PointrOnStateChangedCallback onStateChanged, PointrOnErrorCallback onError);

        // -(void)stop;
        [Export("stop")]
        void Stop();

        // -(void)resetConfiguration;
        [Export("resetConfiguration")]
        void ResetConfiguration();

        // -(PTRAnalyticsManagerInterface * _Nullable)getAnalyticsManager;
        [NullAllowed, Export("getAnalyticsManager")]
        PTRAnalyticsManagerInterface AnalyticsManager { get; }

        // -(PTRConfigurationManagerInterface * _Nonnull)getConfigurationManager;
        [Export("getConfigurationManager")]
        PTRConfigurationManagerInterface ConfigurationManager { get; }

        // -(PTRDataManagerInterface * _Nullable)getDataManager;
        [NullAllowed, Export("getDataManager")]
        PTRDataManagerInterface DataManager { get; }

        // -(PTRGeofenceManagerInterface * _Nullable)getGeofenceManager;
        [NullAllowed, Export("getGeofenceManager")]
        PTRGeofenceManagerInterface GeofenceManager { get; }

        // -(PTRGraphManagerInterface * _Nullable)getGraphManager;
        [NullAllowed, Export("getGraphManager")]
        PTRGraphManagerInterface GraphManager { get; }

        // -(PTRLocationSharingManagerInterface * _Nullable)getLocationSharingManager;
        [NullAllowed, Export("getLocationSharingManager")]
        PTRLocationSharingManagerInterface LocationSharingManager { get; }

        // -(PTRMaintenanceManagerInterface * _Nullable)getMaintenanceManager;
        [NullAllowed, Export("getMaintenanceManager")]
        PTRMaintenanceManagerInterface MaintenanceManager { get; }

        // -(PTRMapManagerInterface * _Nullable)getMapManager;
        [NullAllowed, Export("getMapManager")]
        PTRMapManagerInterface MapManager { get; }

        // -(PTRPathManagerInterface * _Nullable)getPathManager;
        [NullAllowed, Export("getPathManager")]
        PTRPathManagerInterface PathManager { get; }

        // -(PTRPoiManagerInterface * _Nullable)getPoiManager;
        [NullAllowed, Export("getPoiManager")]
        PTRPoiManagerInterface PoiManager { get; }

        // -(PTRPositionManagerInterface * _Nullable)getPositionManager;
        [NullAllowed, Export("getPositionManager")]
        PTRPositionManagerInterface PositionManager { get; }

        // -(PTRPushManagerInterface * _Nullable)getPushManager;
        [NullAllowed, Export("getPushManager")]
        PTRPushManagerInterface PushManager { get; }

        // -(PTRUserManagerInterface * _Nullable)getUserManager;
        [NullAllowed, Export("getUserManager")]
        PTRUserManagerInterface UserManager { get; }

        // -(PTRWallManagerInterface * _Nullable)getWallManager;
        [NullAllowed, Export("getWallManager")]
        PTRWallManagerInterface WallManager { get; }

        // -(void)initVariables;
        [Export("initVariables")]
        void InitVariables();

        // -(void)resetVariables;
        [Export("resetVariables")]
        void ResetVariables();
    }

    // @interface Pointr : PointrBase
    [BaseType(typeof(PointrBase))]
    interface Pointr
    {
    }

    // @interface Pointr (UIColor)
    [Category]
    [BaseType(typeof(UIColor))]
    interface UIColor_Pointr
    {
        // +(UIColor *)colorWithHexString:(NSString *)hexString;
        [Static]
        [Export("colorWithHexString:")]
        UIColor ColorWithHexString(string hexString);

        // +(CGFloat)colorComponentFrom:(NSString *)string start:(NSUInteger)start length:(NSUInteger)length;
        [Static]
        [Export("colorComponentFrom:start:length:")]
        nfloat ColorComponentFrom(string @string, nuint start, nuint length);

        // +(UIColor *)ptrDarkBlue;
        [Static]
        [Export("ptrDarkBlue")]
        UIColor PtrDarkBlue();

        // +(UIColor *)ptrLightBlue;
        [Static]
        [Export("ptrLightBlue")]
        UIColor PtrLightBlue();

        // +(UIColor *)ptrRed;
        [Static]
        [Export("ptrRed")]
        UIColor PtrRed();

        // +(UIColor *)ptrGray;
        [Static]
        [Export("ptrGray")]
        UIColor PtrGray();

        // +(UIColor *)ptrGreen;
        [Static]
        [Export("ptrGreen")]
        UIColor PtrGreen();

        // +(UIColor *)ptrOrange;
        [Static]
        [Export("ptrOrange")]
        UIColor PtrOrange();

        // +(UIColor *)ptrPurple;
        [Static]
        [Export("ptrPurple")]
        UIColor PtrPurple();

        // +(UIColor *)ptrYellow;
        [Static]
        [Export("ptrYellow")]
        UIColor PtrYellow();

        // +(UIColor *)ptrFlatGreen;
        [Static]
        [Export("ptrFlatGreen")]
        UIColor PtrFlatGreen();

        // +(UIColor *)ptrFlatBlue;
        [Static]
        [Export("ptrFlatBlue")]
        UIColor PtrFlatBlue();

        // +(UIColor *)ptrFlatOrange;
        [Static]
        [Export("ptrFlatOrange")]
        UIColor PtrFlatOrange();

        // +(UIColor *)ptrFlatRed;
        [Static]
        [Export("ptrFlatRed")]
        UIColor PtrFlatRed();
    }

    // @interface Pointr (UIImageView)
    [Category]
    [BaseType(typeof(UIImageView))]
    interface UIImageView_Pointr
    {
        // -(void)setImageFromUrlString:(NSString * _Nonnull)urlString withPlaceHolderImage:(UIImage * _Nonnull)placeholder;
        [Export("setImageFromUrlString:withPlaceHolderImage:")]
        void SetImageFromUrlString(string urlString, UIImage placeholder);

        // -(void)setImageFromUrlString:(NSString * _Nonnull)urlString;
        [Export("setImageFromUrlString:")]
        void SetImageFromUrlString(string urlString);
    }

    // @interface Pointr (UIView)
    [Category]
    [BaseType(typeof(UIView))]
    interface UIView_Pointr
    {
        // -(NSMutableAttributedString *)_beautifyText:(NSString *)string withSpacing:(float)spacing;
        [Export("_beautifyText:withSpacing:")]
        NSMutableAttributedString _beautifyText(string @string, float spacing);
    }

    // @interface Pointr (UIViewController)
    [Category]
    [BaseType(typeof(UIViewController))]
    interface UIViewController_Pointr
    {
        // -(void)_transitionTo:(UIViewController *)vc withCompletion:(void (^)(void))block;
        [Export("_transitionTo:withCompletion:")]
        void _transitionTo(UIViewController vc, Action block);

        // -(void)_popBackWithCompletion:(void (^)(void))block;
        [Export("_popBackWithCompletion:")]
        void _popBackWithCompletion(Action block);
    }

    // @interface PTRRegionPoi : PTRPoi <PTRRegionMapDrawable>
    [BaseType(typeof(PTRPoi))]
    interface PTRRegionPoi : PTRRegionMapDrawable
    {
        // -(instancetype _Nullable)initPoiWithIdentifier:(NSString * _Nonnull)identifier x:(float)x y:(float)y level:(int)level venueId:(int)venueId facilityId:(int)facilityId name:(NSString * _Nonnull)name searchName:(NSString * _Nonnull)searchName longDescription:(NSString * _Nullable)longDescription searchLongDescription:(NSString * _Nullable)searchLongDescription keywords:(NSArray<NSString *> * _Nullable)keywords searchKeywords:(NSArray<NSString *> * _Nullable)searchKeywords type:(NSString * _Nonnull)type searchType:(NSString * _Nonnull)searchType isPortal:(BOOL)isPortal regionArray:(NSArray * _Nullable)regionArray extraData:(NSDictionary<NSString *,NSObject *> * _Nullable)extraData translations:(NSDictionary<NSString *,NSDictionary<NSString *,NSString *> *> * _Nullable)translations minZoomLevel:(NSString * _Nullable)minZoomLevel andMaxZoomLevel:(NSString * _Nullable)maxZoomLevel;
        [Export("initPoiWithIdentifier:x:y:level:venueId:facilityId:name:searchName:longDescription:searchLongDescription:keywords:searchKeywords:type:searchType:isPortal:regionArray:extraData:translations:minZoomLevel:andMaxZoomLevel:")]

        IntPtr Constructor(string identifier, float x, float y, int level, int venueId, int facilityId, string name, string searchName, [NullAllowed] string longDescription, [NullAllowed] string searchLongDescription, [NullAllowed] string[] keywords, [NullAllowed] string[] searchKeywords, string type, string searchType, bool isPortal, [NullAllowed] NSObject[] regionArray, [NullAllowed] NSDictionary<NSString, NSObject> extraData, [NullAllowed] NSDictionary<NSString, NSDictionary<NSString, NSString>> translations, [NullAllowed] string minZoomLevel, [NullAllowed] string maxZoomLevel);

        // @property (nonatomic, strong) NSArray<PTRCorner *> * _Nullable regionArray;
        [NullAllowed, Export("regionArray", ArgumentSemantic.Strong)]
        PTRCorner[] RegionArray { get; set; }
    }
}
