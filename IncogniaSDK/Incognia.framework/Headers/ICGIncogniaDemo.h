//
//  ICGIncogniaDemo.h
//  Incognia
//
//  Created by Douglas Soares on 01/12/20.
//  Copyright © 2020 Incognia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IncogniaCore/ICGUserAddress.h>
#import <IncogniaCore/ICGTransactionAddress.h>

NS_ASSUME_NONNULL_BEGIN

@interface ICGIncogniaDemo : NSObject

/**
 * Records a login.
 */
+ (void)trackLogin:(NSString *)accountId __deprecated_msg("Use trackLoginWithAccountId:loginId: instead");

/**
 * Records a login.
 */
+ (void)trackLoginWithAccountId:(NSString *)accountId loginId:(NSString *_Nullable)loginId;

/**
 * Records a sign up.
 */
+ (void)trackSignUp:(NSString *_Nullable)signUpId address:(ICGUserAddress *_Nullable)userAddress;

/**
 * Records a transaction.
 */
+ (void)trackTransactionWithAccountId:(NSString *)accountId
                        transactionId:(NSString *_Nullable)transactionId
                 transactionAddresses:(NSSet <ICGTransactionAddress *> *_Nullable)addresses;

@end

NS_ASSUME_NONNULL_END
