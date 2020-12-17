//
//  ICGIncogniaDemo.h
//  Incognia
//
//  Created by Douglas Soares on 01/12/20.
//  Copyright © 2020 Incognia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IncogniaCore/ICGUserAddress.h>

NS_ASSUME_NONNULL_BEGIN

@interface ICGIncogniaDemo : NSObject

/**
 Records a login.
*/
+ (void)trackLogin:(NSString *)accountId;

/**
 Records a sign up.
*/
+ (void)trackSignUp:(NSString * _Nullable)signUpId address:(ICGUserAddress * _Nullable)userAddress;

@end

NS_ASSUME_NONNULL_END
