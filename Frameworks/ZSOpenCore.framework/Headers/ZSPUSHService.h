//
//  ZSPUSHService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/17.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSPUSHRegisterEntity.h"
#import <UserNotifications/UserNotifications.h>
#import "ZSOpenCoreDefines.h"

@class ZSBaseModel;
//@class UNUserNotificationCenter,UNNotification,UNNotificationResponse;

@protocol ZSPUSHRegisterDelegate <NSObject>

/*
 * @brief handle UserNotifications.framework [willPresentNotification:withCompletionHandler:]
 * @param center [UNUserNotificationCenter currentNotificationCenter] 新特性用户通知中心
 * @param notification 前台得到的的通知对象
 * @param completionHandler 该callback中的options 请使用UNNotificationPresentationOptions
 */
- (void)ZSPushNotificationCenter:(UNUserNotificationCenter *_Nonnull)center willPresentNotification:(UNNotification *_Nonnull)notification withCompletionHandler:(void (^_Nonnull)(NSInteger options))completionHandler API_AVAILABLE(ios(10.0));
/*
 * @brief handle UserNotifications.framework [didReceiveNotificationResponse:withCompletionHandler:]
 * @param center [UNUserNotificationCenter currentNotificationCenter] 新特性用户通知中心
 * @param response 通知响应对象
 * @param completionHandler
 */
- (void)ZSPushNotificationCenter:(UNUserNotificationCenter *_Nonnull)center didReceiveNotificationResponse:(UNNotificationResponse *_Nonnull)response withCompletionHandler:(void(^_Nonnull)(void))completionHandler API_AVAILABLE(ios(10.0));

/*
 * @brief handle UserNotifications.framework [openSettingsForNotification:]
 * @param center [UNUserNotificationCenter currentNotificationCenter] 新特性用户通知中心
 * @param notification 当前管理的通知对象
 */
- (void)ZSPushNotificationCenter:(UNUserNotificationCenter *_Nonnull)center openSettingsForNotification:(UNNotification *_Nullable)notification NS_AVAILABLE_IOS(12.0);

/**
 * 监测通知授权状态返回的结果
 * @param status 授权通知状态，详见ZSAuthorizationStatus
 * @param info 更多信息，预留参数
 */
- (void)ZSPushNotificationAuthorization:(ZSAuthorizationStatus)status withInfo:(NSDictionary *_Nonnull)info;

@end
NS_ASSUME_NONNULL_BEGIN


@interface ZSPUSHService : NSObject

#pragma mark -init 初始化部分
/*!
 * @abstract 新版本的注册方法（兼容iOS10）
 *
 * @param config 注册通知配置
 * @param pushProvider 推送提供商
 * @param delegate 代理
 *
 */
+ (void)registerForRemoteNotificationConfig:(ZSPUSHRegisterEntity *)config
                               pushProvider:(ZSPushProvider)pushProvider
                                   delegate:(id<ZSPUSHRegisterDelegate>)delegate;

/*!
 * @abstract 启动SDK
 *
 * @param launchingOption 启动参数.d
 * @param appKey 一个Push 应用必须的,唯一的标识. 请参考 Push 相关说明文档来获取这个标识.
 * @param isProduction 是否生产环境. 如果为开发状态,设置为 NO; 如果为生产状态,应改为 YES.
 *                     App 证书环境取决于profile provision的配置，此处建议与证书环境保持一致.
 * @param advertisingId 广告标识符（IDFA） 如果不需要使用IDFA，传nil.
 * @param pushProvider 推送提供商
 * @discussion 提供SDK启动必须的参数, 来启动 SDK.
 * 此接口必须在 App 启动时调用，并且调用此方法前先调用调用前请先调用[ZSOpenCoreSDK initializeSDKWithEnvironment:appId:appSecret:scope:channelNo:packageNo]方法初始化环境, 否则 Push SDK 将无法正常工作.此方法内部会自动打上channelNo和packageNo这两个tag
 */
+ (void)setupWithOption:(NSDictionary *_Nullable)launchingOption
                 appKey:(NSString *)appKey
       apsForProduction:(BOOL)isProduction
  advertisingIdentifier:(NSString *_Nullable)advertisingId
           pushProvider:(ZSPushProvider)pushProvider;


/// 上传deviceToken到服务器
/// @param deviceToken deviceToken
+(void)registerDeviceToken:(NSData *)deviceToken;

#pragma mark -API 部分

/// 添加渠道号和分标号tag
/// @param completion 完成回调：iResCode==0为添加成功
+(void)addChannelNoAndPackageNoTagCompletion:(void (^)(NSInteger iResCode, NSSet *iTags, NSInteger seq))completion seq:(NSInteger)seq;
/*!
 * @abstract 处理收到的 APNs 消息
 */
+ (void)handleRemoteNotification:(NSDictionary *)remoteInfo;

/*!
 * @abstract 设置角标(到服务器)
 *
 * @param value 新的值. 会覆盖服务器上保存的值(这个用户)
 *
 * @discussion 本接口不会改变应用本地的角标值.
 * 本地仍须调用 UIApplication:setApplicationIconBadgeNumber 函数来设置脚标.
 *
 * 本接口用于配合 ZSPush 提供的服务器端角标功能.
 * 该功能解决的问题是, 服务器端推送 APNs 时, 并不知道客户端原来已经存在的角标是多少, 指定一个固定的数字不太合理.
 *
 * ZSPush 服务器端脚标功能提供:
 *
 * - 通过本 API 把当前客户端(当前这个用户的) 的实际 badge 设置到服务器端保存起来;
 * - 调用服务器端 API 发 APNs 时(通常这个调用是批量针对大量用户),
 *   使用 "+1" 的语义, 来表达需要基于目标用户实际的 badge 值(保存的) +1 来下发通知时带上新的 badge 值;
 */
+ (BOOL)setBadge:(NSInteger)value;

/*!
 * @abstract 重置脚标(为0)
 *
 * @discussion 相当于 [setBadge:0] 的效果.
 * 参考 [JPUSHService setBadge:] 说明来理解其作用.
 */
+ (void)resetBadge;

/**
 增加tags

 @param tags 需要增加的tags集合
 @param completion 响应回调
 @param seq 请求序列号
 */
+ (void)addTags:(NSSet<NSString *> *)tags
     completion:(void (^)(NSInteger iResCode, NSSet *iTags, NSInteger seq))completion
            seq:(NSInteger)seq;

/**
 覆盖tags
 调用该接口会覆盖用户所有的tags

 @param tags 需要设置的tags集合
 @param completion 响应回调
 @param seq 请求序列号
 */
+ (void)setTags:(NSSet<NSString *> *)tags
     completion:(void (^)(NSInteger iResCode, NSSet *iTags, NSInteger seq))completion
            seq:(NSInteger)seq;

/**
 设置Alias

 @param alias 需要设置的alias
 @param completion 响应回调
 @param seq 请求序列号
 */
+ (void)setAlias:(NSString *)alias
      completion:(void (^)(NSInteger iResCode, NSString *iAlias, NSInteger seq))completion
             seq:(NSInteger)seq;

/**
 删除alias

 @param completion 响应回调
 @param seq 请求序列号
 */
+ (void)deleteAlias:(void (^)(NSInteger iResCode, NSString *iAlias, NSInteger seq))completion
                seq:(NSInteger)seq;

/*!
 * @abstract 打开日志级别到 Debug
 *
 * @discussion JMessage iOS 的日志系统参考 Android 设计了级别.
 * 从低到高是: Verbose, Debug, Info, Warning, Error.
 * 对日志级别的进一步理解, 请参考 Android 相关的说明.
 *
 * SDK 默认开启的日志级别为: Info. 只显示必要的信息, 不打印调试日志.
 *
 * 请在SDK启动后调用本接口，调用本接口可打开日志级别为: Debug, 打印调试日志.
 */
+ (void)setDebugMode;

/*!
 * @abstract 关闭日志
 *
 * @discussion 关于日志级别的说明, 参考 [JPUSHService setDebugMode]
 *
 * 虽说是关闭日志, 但还是会打印 Warning, Error 日志. 这二种日志级别, 在程序运行正常时, 不应有打印输出.
 *
 * 建议在发布的版本里, 调用此接口, 关闭掉日志打印.
 */
+ (void)setLogOFF;
@end

NS_ASSUME_NONNULL_END
