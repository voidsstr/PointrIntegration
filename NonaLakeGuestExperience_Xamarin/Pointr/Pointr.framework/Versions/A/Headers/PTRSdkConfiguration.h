//
//  PTRSdkConfiguration.h
//  Pointr
//
//  Created by Pointr on 20/04/2017.
//  Copyright © 2017 Pointr. All rights reserved.
//

// Apple
#import "Foundation/Foundation.h"

// Config
#import "PTRConfigurationInterface.h"

NS_ASSUME_NONNULL_BEGIN

@interface PTRSdkConfiguration : PTRConfigurationInterface

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public properties
/////////////////////////////////////////////////////////////////////////

/**
 * The set method for the base url sets the property. Addition to the property all the related, download, upload and
 * query URL's are automatically set according to the base url. If any of these properties are required to be they can
 * be set explicitly.
 */
@property (nonatomic, strong) NSString *baseUrl;

/**
 * The list of all the UUID's for all the venues of the customer
 */
@property (nonatomic, strong) NSArray<NSDictionary<NSNumber *, NSString *> *> *uuidList;

/**
 * Brand of the beacons used in venue
 * @brief default (@"kontakt")
 */
@property (nonatomic, strong) NSString *beaconBrandName;

/////////////////////////////////////////////////////////////////////////
#pragma mark - Public methods
/////////////////////////////////////////////////////////////////////////

/**
 * Returns YES if all required fields are populated
 * NO otherwise
 */
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
