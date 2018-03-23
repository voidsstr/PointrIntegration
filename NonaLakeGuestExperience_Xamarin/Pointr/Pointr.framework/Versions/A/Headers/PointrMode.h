//
//  PointrMode.h
//  Pods
//
//  Created by Yavuz Nuzumlali on 12/05/2017.
//
//

#import "Foundation/Foundation.h"
#import "PTRLogger.h"

@interface PointrMode : NSObject

+ (instancetype)mode;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

@property (nonatomic, assign, readonly) PTRLoggerLevel defaultLoggerLevel;
- (BOOL)isLoggerLevelAllowed:(PTRLoggerLevel)level;
@property (nonatomic, assign, readonly) BOOL isClassDataLoggingAllowed;

@property (nonatomic, assign, readonly) BOOL shouldAssertionsCrash;
@property (nonatomic, assign, readonly) BOOL isSimulationAllowed;
@property (nonatomic, assign, readonly) BOOL isOnScreenLoggingAllowed;
@property (nonatomic, copy, readonly) NSString *bluetoothEventFileName;
@property (nonatomic, copy, readonly) NSString *sensorEventFileName;
@property (nonatomic, assign, readonly) BOOL isHiddenNotificationsAllowed;
@property (nonatomic, copy, readonly) NSString *OCRTextFilePath;

@end
