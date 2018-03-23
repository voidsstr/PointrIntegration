//
//  PTRVenueFacilityManagerInterface.h
//  Pods
//
//  Created by Ege AKPINAR on 02/06/2017.
//
//

#import "Foundation/Foundation.h"

// Management
#import "PTRPointrManagerInterface.h"

// Config
#import "PTRVenueConfiguration.h"
#import "PTRFacilityConfiguration.h"

// Forward declare dependencies
@protocol PTRDataManagerDelegate;

@protocol PTRVenueFacilityManagerDelegate <NSObject>

@optional

/**
 * Gets triggered when venue-facility information is updated
 */
- (void)onVenueFacilityManagerUpdated;

@end

/**
 * (Private) Manager for resolving venue <> facility conversions, using internal/external identifiers
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored \
    "-Weverything"  // To get rid of 'No protocol definition found' warnings which are not accurate
@interface PTRVenueFacilityManagerInterface
    : PTRPointrManagerInterface <id<PTRVenueFacilityManagerDelegate>> <PTRDataManagerDelegate>
#pragma clang diagnostic pop

/////////////////////////////////////////////////////////////////////////
#pragma mark - Venue <> Facility conversions
/////////////////////////////////////////////////////////////////////////

/**
 * Tries to resolve venueInternalIdentifier for venue which contains facility with specified
 * @paramfacilityInternalIdentifier
 * @return venueInternalIdentifier if venue is found. INVALID_VENUE otherwise.
 */
- (int)resolveVenueFromFacility:(int)facilityInternalIdentifier;

/**
 * Tries to resolve facilityInternalIdentifier for facility which is contained in venue with specified
 * @paramvenueInternalIdentifier
 * @return facilityInternalIdentifier if facility is found. INVALID_FACILITY otherwise.
 */
- (int)resolveFacilityFromVenue:(int)venueInternalIdentifier;

/////////////////////////////////////////////////////////////////////////
#pragma mark - External <> Internal conversions
/////////////////////////////////////////////////////////////////////////

/**
 * Tries to convert given @param venueExternalIdentifier to 'venueInternalIdentifier'
 * @return venueInternalIdentifier for specified @paramvenueExternalIdentifier. INVALID_VENUE if failure.
 */
- (int)resolveVenueExternalIdentifier:(NSString *)venueExternalIdentifier;

/**
 * Tries to convert given @param facilityExternalIdentifier to 'facilityInternalIdentifier'
 * @return facilityInternalIdentifier for specified @paramfacilityExternalIdentifier. INVALID_FACILITY if failure.
 */
- (int)resolveFacilityExternalIdentifier:(NSString *)facilityExternalIdentifier;

@end
