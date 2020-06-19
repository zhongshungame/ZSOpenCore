//
//  ZSPUSHRegisterEntity.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/17.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, ZSAuthorizationOptions) {
    ZSAuthorizationOptionNone    = 0,   // the application may not present any UI upon a notification being received
    ZSAuthorizationOptionBadge   = (1 << 0),    // the application may badge its icon upon a notification being received
    ZSAuthorizationOptionSound   = (1 << 1),    // the application may play a sound upon a notification being received
    ZSAuthorizationOptionAlert   = (1 << 2),    // the application may display an alert upon a notification being received
    ZSAuthorizationOptionCarPlay = (1 << 3),    // The ability to display notifications in a CarPlay environment.
    ZSAuthorizationOptionCriticalAlert NS_AVAILABLE_IOS(12.0) = (1 << 4) ,   //The ability to play sounds for critical alerts.
    ZSAuthorizationOptionProvidesAppNotificationSettings NS_AVAILABLE_IOS(12.0) = (1 << 5) ,      //An option indicating the system should display a button for in-app notification settings.
    ZSAuthorizationOptionProvisional NS_AVAILABLE_IOS(12.0) = (1 << 6) ,     //The ability to post noninterrupting notifications provisionally to the Notification Center.
    ZSAuthorizationOptionAnnouncement NS_AVAILABLE_IOS(13.0) = (1 << 7) , //The ability for Siri to automatically read out messages over AirPods.
};

typedef NS_ENUM(NSUInteger, ZSAuthorizationStatus) {
    ZSAuthorizationNotDetermined    = 0,   // The user has not yet made a choice regarding whether the application may post user notifications.
    ZSAuthorizationStatusDenied,    // The application is not authorized to post user notifications.
    ZSAuthorizationStatusAuthorized,    // The application is authorized to post user notifications.
    ZSAuthorizationStatusProvisional NS_AVAILABLE_IOS(12.0),    // The application is authorized to post non-interruptive user notifications.
};

NS_ASSUME_NONNULL_BEGIN

@interface ZSPUSHRegisterEntity : NSObject
/*!
 * 支持的类型
 * badge,sound,alert
 */
@property (nonatomic, assign) NSInteger types;
/*!
 * 注入的类别
 * iOS10 UNNotificationCategory
 * iOS8-iOS9 UIUserNotificationCategory
 */
@property (nonatomic, strong) NSSet *categories;

@end

NS_ASSUME_NONNULL_END
