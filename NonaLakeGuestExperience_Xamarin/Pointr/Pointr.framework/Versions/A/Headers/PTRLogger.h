//
//  PTRLogger.hpp
//  Pointr
//
//  Created by Ismail Ege AKPINAR on 11/11/2017.
//

#import "Foundation/Foundation.h"

//#define PTRAssert(e, m) [[PTRLogManager sharedInstance] assert:e function:__PRETTY_FUNCTION__ line:__LINE__ message:m]
#define PTRAssert(e, m)       \
    {                         \
        if (!(e))             \
            loge(@"%@", (m)); \
    }

#define logv(s, ...) \
    [PTRLogger logWithLevel:PTRLogLevelVerbose function:__PRETTY_FUNCTION__ line:__LINE__ format:s, ##__VA_ARGS__]
#define logd(s, ...) \
    [PTRLogger logWithLevel:PTRLogLevelDebug function:__PRETTY_FUNCTION__ line:__LINE__ format:s, ##__VA_ARGS__]
#define logi(s, ...) \
    [PTRLogger logWithLevel:PTRLogLevelInfo function:__PRETTY_FUNCTION__ line:__LINE__ format:s, ##__VA_ARGS__]
#define logw(s, ...) \
    [PTRLogger logWithLevel:PTRLogLevelWarning function:__PRETTY_FUNCTION__ line:__LINE__ format:s, ##__VA_ARGS__]
#define loge(s, ...) \
    [PTRLogger logWithLevel:PTRLogLevelError function:__PRETTY_FUNCTION__ line:__LINE__ format:s, ##__VA_ARGS__]

typedef NS_ENUM(int, PTRLogLevel) {
    PTRLogLevelVerbose = 0,
    PTRLogLevelDebug = 1,
    PTRLogLevelInfo = 2,
    PTRLogLevelWarning = 3,
    PTRLogLevelError = 4
};

typedef NS_ENUM(int, PTRLoggerLevel) {
    PTRLoggerLevelAll = -999,  // Equivalent to Verbose
    PTRLoggerLevelVerbose = 0,
    // NOTE- Logger level cannot be Debug. Debug's are always printed.
    PTRLoggerLevelInfo = 2,
    PTRLoggerLevelWarning = 3,
    PTRLoggerLevelError = 4,
    PTRLoggerLevelOff = 999
};

@interface PTRLogger : NSObject

/**
 *  Determine minimum level of logs to be printed
 *  @warn Default level is PTRLoggerLevelAll
 */
+ (void)setLoggerLevel:(PTRLoggerLevel)loggerLevel;

/**
 *  Main logging method
 *  NOTE- This method passes log to cpp
 */
+ (void)logWithLevel:(PTRLogLevel)logLevel
            function:(const char *)function
                line:(NSUInteger)line
              format:(NSString *)format, ... NS_FORMAT_FUNCTION(4, 5);

//+ (void)log:(NSString *)message withLevel:(PTRLogLevel)level;

// Helper methods
+ (NSString *)stringFromLogLevel:(PTRLogLevel)level;
+ (NSString *)stringFromLoggerLevel:(PTRLoggerLevel)level;

@end
