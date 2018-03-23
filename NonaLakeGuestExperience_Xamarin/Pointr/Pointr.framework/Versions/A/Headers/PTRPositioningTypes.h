//
//  PTRPositioning.h
//
//
//  Created by Pointr on 07/12/14.
//  Copyright (c) 2014 Pointr. All rights reserved.
//

#ifndef PTRPositiningTypes_h
#define PTRPositiningTypes_h

#import "limits.h"
#import "Foundation/Foundation.h"
#import "CoreGraphics/CoreGraphics.h"

#define IS_VALID_MAJOR_MINOR(m) \
    ((m.major >= 0 && m.major <= 65535) && (m.minor >= 0 && m.minor <= 65535) && (m.major != 0 || m.minor != 0))
#define IS_VALID_NORMALISED_POSITION(p) \
    ((p.x >= 0.0F && p.x <= 1.0F) && (p.y >= 0.0F && p.y <= 1.0F) && (p.level != PTRPositioningTypes.invalidLevel))
#define IS_VALID_NORMALISED_NODE(p)                                                                      \
    ((p.location.x >= 0.0F && p.location.x <= 1.0F) && (p.location.y >= 0.0F && p.location.y <= 1.0F) && \
     (p.location.level != PTRPositioningTypes.invalidLevel))

#define IS_VALID_RSSI(r) (r < 0 && r != -127)

#define IS_VALID_LEVEL(l)                                                             \
    (l >= [[[Pointr sharedInstance] getConfigurationManager] getCurrentConfiguration] \
              .facilityConfiguration.mapMinLevel &&                                   \
     l <= [[[Pointr sharedInstance] getConfigurationManager] getCurrentConfiguration] \
              .facilityConfiguration.mapMaxLevel)

#define SQUARE(x) ((x) * (x))

/**
 * Class that contains positioning related constants and types
 */
@interface PTRPositioningTypes : NSObject

+ (float)invalidPosition;
+ (double)invalidGeoPosition;
+ (float)invalidAccuracy;
+ (int)invalidLevel;
+ (float)invalidOrientation;
+ (float)defaultOrientation;
+ (float)defaultOrientationAccuracy;

+ (unsigned short)invalidMajor;
+ (unsigned short)invalidMinor;
+ (int)invalidFacility;
+ (int)invalidVenue;

@end

typedef NS_ENUM(NSUInteger, PTROrientationAccuracyClass) {
    PTROrientationAccuracyClassLow,
    PTROrientationAccuracyClassHigh
};

typedef NS_ENUM(NSUInteger, PTRLocationState) {
    PTRLocationStateLost,
    PTRLocationStateFaded,
    PTRLocationStateActive,
    PTRLocationStateUnknown
};

typedef NS_ENUM(NSUInteger, PTRPositioningServiceState) {
    PTRPositioningServiceUnknown,  // Unknown yet (e.g. BT is powering up, or user is just presented a location
                                   // authorisation dialog) DEFAULT
    PTRPositioningServiceNotAuthorised,
    PTRPositioningServiceNoBluetooth,
    PTRPositioningServiceUnsupportedHardware,
    PTRPositioningServiceNotStarted,
    PTRPositioningServiceError,  // callback given when an error in CB appears
    // it is due to Apple's bug failing updating CB state when a peripheral falsely disconnected
    // no programmatic solution for this issue only closing and openning BT fixes issue
    //[please check: https://forums.developer.apple.com/thread/83852]
    PTRPositioningServiceOK
};

typedef struct PTRPosition {
    float x;                                               // Relative [0, 1)
    float y;                                               // Relative [0, 1)
    float accuracy;                                        // Confidence radius, in metres
    int level;                                             // Real level (Ground level -> 0, 1st level -> 1)
    float orientation;                                     // Orientation in radians
    float orientationAccuracy;                             // Orientation spread in radians
    PTROrientationAccuracyClass orientationAccuracyClass;  // Low or High
    double timestamp;
} PTRPosition;

typedef struct PTRGeoPosition {
    double lat;                                            // Latitude
    double lon;                                            // Longitude
    float accuracy;                                        // Confidence radius, in metres
    int level;                                             // Real level (Ground level -> 0, 1st level -> 1)
    float orientation;                                     // Orientation in radians
    float orientationAccuracy;                             // Orientation spread in radians
    PTROrientationAccuracyClass orientationAccuracyClass;  // Low or High
    double timestamp;
} PTRGeoPosition;

// Directive to treat as a C file, when included from an Objective-C++ file
#ifdef __cplusplus
extern "C" {
#endif

/**
 Helper to create a PTRPosition
 */
extern PTRPosition PTRPositionMakeFull(float x, float y, float accuracy, int level, float orientation,
                                       float orientationAccuracy, PTROrientationAccuracyClass orientationAccuracyClass);

/**
 Helper to create PTRGeoPosition from a PTRPosition struct
 */
extern PTRGeoPosition PTRGeoPositionMakeFromPosition(double lat, double lon, PTRPosition pos);

/**
 Helper to create a PTRPosition with the main components
 */
extern PTRPosition PTRPositionMake(float x, float y, int level);

/**
 Helper to create an invalid PTRPosition.
 Primarily useful for initialising.
 */
extern PTRPosition PTRPositionMakeInvalid(void);

#ifdef __cplusplus
}
#endif

#endif
