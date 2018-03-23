//
//  PTRSimulationConfiguration.h
//  Pointr
//
//  Created by Pointr Labs on 08/01/17.
//  Copyright © 2017 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Configuration for Bluetooth and Sensor simulation. Very useful in debugging.
 */
@interface PTRSimulationConfiguration : PTRConfigurationInterface

/**
 *  Indicates if bluetooth simulation is enabled.
 *  NO by default
 */
@property (nonatomic, assign) BOOL isBluetoothSimulationEnabled;

/**
 *  Indicates if sensor simulation is enabled.
 *  NO by default
 */
@property (nonatomic, assign) BOOL isSensorSimulationEnabled;

/**
 *  Name of bluetooth event file, to feed into simulation
 *  "BeaconEvent.json" by default
 *  @warning File names are case sensitive
 */
@property (nonatomic, retain) NSString *bluetoothEventFileName;

/**
 *  Name of sensor event file, to feed into simulation
 *  "SensorEvent.json" by default
 *  @warning File names are case sensitive
 */
@property (nonatomic, retain) NSString *sensorEventFileName;

@end

NS_ASSUME_NONNULL_END
