//
//  ICGIncognia.h
//  Incognia
//
//  Created by Pedro Atanasio on 05/06/20.
//  Copyright © 2020 Incognia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IncogniaCore/ICGOptions.h>
#import <IncogniaCore/ICGConsentResult.h>
#import <IncogniaCore/ICGConsentDialogOptions.h>
#import <IncogniaCore/ICGUserAddress.h>
#import <IncogniaCore/ICGCheckIn.h>

typedef void (^ICGFetchResultBlock)(UIBackgroundFetchResult);
typedef void (^ICGConsentBlock)(ICGConsentResult *_Nullable);
typedef void (^ICGStringBlock)(NSString *_Nullable);

NS_ASSUME_NONNULL_BEGIN

@interface ICGIncognia : NSObject

/**
 Initializes the Incognia SDK with the options parameters.
 */
+ (void)initSdkWithOptions:(ICGOptions *)options;

/**
 Initializes the Incognia SDK with the IncogniaOptions.plist properties file. To know more, please refer to the Incognia documentation.
 */
+ (void)initSdk;

/**
 Allows background operations.

 Should be called inside [-application:performFetchWithCompletionHandler:].
 */
+ (void)performFetchWithCompletionBlock:(nullable ICGFetchResultBlock)fetchResultBlock;

/**
Allows consents for the functionality types specified in consentTypes parametes (using ICG_CONSENT_TYPE_. constants).
If denyRemainingTypes is YES, other consent types not present in consentTypes are denied.
If denyRemainingTypes is NO, other consent types not present in consentTypes stay unmodified.
*/
+ (void)allowConsentTypes:(NSSet <NSString *> *)consentTypes denyRemainingTypes:(BOOL)denyRemainingTypes;

/**
Denies consents for the functionality types specified in consentTypes parametes (using ICG_CONSENT_TYPE_. constants).
A call to this method does not modify other consent types not present in consentTypes.
*/
+ (void)denyConsentTypes:(NSSet <NSString *> *)consentTypes;

/**
 Presents to the user a Dialog for consent request. If the user allows it, it will give the privacy consent for the consentTypes
 present on the given ICGConsentDialogOptions. Otherwise, it will deny consent for the given consentTypes.

 Returns through a block a NSDictionary containing the consent status for each consentType present on the consentTypes field ot the
 given ICGConsentDialogOptions.
 */
+ (void)requestPrivacyConsentWithOptions:(ICGConsentDialogOptions *)options andConsentBlock:(nullable ICGConsentBlock)block;

/**
 Presents to the user a Dialog for consent request. If the user allows it, it will give the privacy consent for the consentTypes
 present on the given ICGConsentDialogOptions. Otherwise, it will deny consent for the given consentTypes.
 */
+ (void)requestPrivacyConsentWithOptions:(ICGConsentDialogOptions *)options;

/**
Returns through a block a NSDictionary containing the consent status for each consentType present on the given set.
*/
+ (void)checkConsentForTypes:(NSSet <NSString *> *)consentTypes withBlock:(nullable ICGConsentBlock)block;

/**
 Sets the current user id. This information will be used on the Incognia services (i.e., for events).
 This value is persisted.
 */
+ (void)setUserId:(NSString *)userId;

/**
 Clears the current persisted user id.
 */
+ (void)clearUserId;

/**
 Sets the user address.
 This value is persisted locally.
*/
+ (void)setUserAddress:(ICGUserAddress *)userAddress;

/**
 Clears the current persisted user address.
*/
+ (void)clearUserAddress;

/**
Asynchronously retrieves the current installation id.
*/
+ (void)getInstallationId:(ICGStringBlock)block;

+ (void)setVisitsEnabled:(BOOL)enabled;

/**
 Registers a check-in event.
*/
+ (void)registerCheckIn:(ICGCheckIn *)checkIn;

/**
 Registers an in-app event.
 Note that custom properties must have key-value pairs of NSStrings.
 */
+ (void)trackEvent:(NSString *)eventName;
+ (void)trackEvent:(NSString *)eventName properties:(NSDictionary <NSString *, NSString *> *)properties;

/**
 Registers an app event and its localization.
 */
+ (void)trackLocalizedEvent:(NSString *)eventName;

/**
 Registers an app event and its localization.
*/
+ (void)trackLocalizedEvent:(NSString *)eventName properties:(NSDictionary <NSString *, NSString *> *)properties;

@end

NS_ASSUME_NONNULL_END
