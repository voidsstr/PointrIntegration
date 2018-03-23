using System;
using System.Runtime.InteropServices;
using Foundation;
using ObjCRuntime;
using Pointr;

namespace Pointr
{
    public enum PTRAlertViewType
    {
        None,
        Error,
        Warning,
        Success,
        Info,
        YesNo,
        VisitPage,
        Rating,
        WithoutButton
    }

    public enum PTRAnalyticsType
    {
        StartedLibrary,
        StartedPathfinding,
        SearchedPoi,
        CancelledPoiSearch,
        CancelledPathfinding,
        ArrivedDestination,
        PathDistanceChanged
    }

    [Native]
    public enum PTROrientationAccuracyClass : ulong
    {
        Low,
        High
    }

    [Native]
    public enum PTRLocationState : ulong
    {
        Lost,
        Faded,
        Active,
        Unknown
    }

    [Native]
    public enum PTRPositioningServiceState : ulong
    {
        Unknown,
        NotAuthorised,
        NoBluetooth,
        UnsupportedHardware,
        NotStarted,
        Error,
        Ok
    }

    [StructLayout (LayoutKind.Sequential)]
    public struct PTRPosition
    {
        public float x;

        public float y;

        public float accuracy;

        public int level;

        public float orientation;

        public float orientationAccuracy;

        public PTROrientationAccuracyClass orientationAccuracyClass;

        public double timestamp;
    }

    [StructLayout (LayoutKind.Sequential)]
    public struct PTRGeoPosition
    {
        public double lat;

        public double lon;

        public float accuracy;

        public int level;

        public float orientation;

        public float orientationAccuracy;

        public PTROrientationAccuracyClass orientationAccuracyClass;

        public double timestamp;
    }

    static class CFunctions
    {
        // extern PTRPosition PTRPositionMakeFull (float x, float y, float accuracy, int level, float orientation, float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);
        [DllImport ("__Internal")]
        static extern PTRPosition PTRPositionMakeFull (float x, float y, float accuracy, int level, float orientation, float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);

        // extern PTRGeoPosition PTRGeoPositionMakeFromPosition (double lat, double lon, PTRPosition pos);
        [DllImport ("__Internal")]
        static extern PTRGeoPosition PTRGeoPositionMakeFromPosition (double lat, double lon, PTRPosition pos);

        // extern PTRPosition PTRPositionMake (float x, float y, int level);
        [DllImport ("__Internal")]
        static extern PTRPosition PTRPositionMake (float x, float y, int level);

        // extern PTRPosition PTRPositionMakeInvalid ();
        [DllImport ("__Internal")]
        static extern PTRPosition PTRPositionMakeInvalid ();

        // extern void PTRDispatchAsyncOnMainQueue (void (^ _Nonnull)(void) block);
        [DllImport ("__Internal")]
        static extern void PTRDispatchAsyncOnMainQueue (Action block);

        // extern void PTRDispatchSyncOnMainQueue (void (^ _Nonnull)(void) block);
        [DllImport ("__Internal")]
        static extern void PTRDispatchSyncOnMainQueue (Action block);

        // extern NSString * _Nonnull PTRPointrStateToString (PointrState state);
        [DllImport ("__Internal")]
        static extern NSString PTRPointrStateToString (PointrState state);
    }

    public enum PTRNodeType
    {
        Unknown,
        Regular,
        Rotation,
        Turn,
        Lift,
        Escalator,
        Travelator,
        AngularStairs,
        RotationalStairs,
        ServiceLift,
        SecurityControl,
        BorderControl,
        Ramp,
        Steps,
        ServiceStairs,
        Train,
        Shuttle,
        Metro
    }

    [Native]
    public enum PTRPathDirectionType : ulong
    {
        GoStraight,
        TurnSlightLeftAndKeepStraight,
        TurnLeft,
        TurnSlightRightAndKeepStraight,
        TurnRight,
        ChangeLevel,
        RotateBack,
        RotateLeft,
        RotateRight,
        PrepareToTurnRight,
        PrepareToTurnLeft,
        ChangeFacility,
        Security,
        BorderControl
    }

    public enum PTRHeadingMode
    {
        Quaternion = 0,
        ComplementaryFilter = 1,
        NotAvailable = -1
    }

    [Native]
    public enum PTRMapMode : ulong
    {
        Free = 0,
        Tracking = 1,
        RotationalTracking = 2,
        PathTracking = 3
    }

    [Native]
    public enum PTRPathfindingDistanceMode : ulong
    {
        Normal,
        Exhibition
    }

    public enum PTRLogLevel
    {
        Verbose = 0,
        Debug = 1,
        Info = 2,
        Warning = 3,
        Error = 4
    }

    public enum PTRLoggerLevel
    {
        All = -999,
        Verbose = 0,
        Info = 2,
        Warning = 3,
        Error = 4,
        Off = 999
    }

    [Native]
    public enum PTRDataType : ulong
    {
        None,
        BaseConfiguration,
        VenueConfiguration,
        FacilityConfiguration,
        VenueDataVersions,
        FacilityDataVersions,
        VenueGraph,
        FacilityGraph,
        RasterMap,
        TiledMap,
        VenuePois,
        FacilityPois,
        VenueWalls,
        FacilityWalls,
        UserSession,
        VenueBeacons,
        All
    }

    [Native]
    public enum PTRGeofencingState : ulong
    {
        Unknown,
        In,
        Out
    }

    [Native]
    public enum PTRMapLoadingState : ulong
    {
        Off,
        Loading,
        Ready,
        Error
    }

    public enum PTRMapViewMinimumZoomScale
    {
        t,
        ll
    }

    public enum PTRPoiZoomLevel
    {
        InvalidZoomLevel,
        OuterZoomLevel,
        MediumZoomLevel,
        InnerZoomLevel
    }

    public enum PTRPathfindingMode
    {
        Normal,
        Easy,
        Accessible
    }

    public enum PTRPoiLabelPlace
    {
        Bottom = 0,
        Left,
        Right,
        None
    }

    public enum PTRWallType
    {
        Unknown,
        Wall,
        TransparentWall
    }

    public enum PointrState
    {
        Off,
        Configuring,
        Validating,
        Registering,
        Running
    }
}
