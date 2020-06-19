//
//  ZSAdvertisingService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/19.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSOpenCoreDefines.h"
#import <UIKit/UIKit.h>
#import "ZSBaseModel.h"

typedef enum : NSUInteger {
    ZSAdvertisingTypeBanner=1, //Banner
    ZSAdvertisingTypeInterstitial,//插屏广告
    ZSAdvertisingTypeRewardedVideo//激励视频
} ZSAdvertisingType;

NS_ASSUME_NONNULL_BEGIN

@interface ZSAdvertisingManager : NSObject

/// 初始化设置appId
/// @param GDTAppId 优量汇appId
/// @param BUAppId 穿山甲appId
+(void)setupWithGDTAppId:(NSString *)GDTAppId BUAppId:(NSString *)BUAppId;
///单例
+(instancetype)sharedZSAdvertisingManager;

/// 加载激励视频广告
/// @rewardName 奖励名称（道具ID），此参数将会透传给后端的回调接口
/// @rewardAmount 奖励的数量，此参数将会透传给后端的回调接口
/// @viewController 广告展示所在的控制器，传入nil(空)值则默认是application.keyWindow.rootViewController
/// @param successLoadAdHandler 广告加载成功回调 回调参数为广告的key标识，请保存好此key，用于页面即将消失（viewWillDisappear）并且用户没有关闭广告时删除广告使用，
/// 注意：广告即将展示时系统会回调viewWillDisappear（App应用），请控制好删除广告逻辑
/// @param adWillShowHandler 广告即将显示回调
/// @param failLoadAdHandler 视频广告各种错误信息回调
/// @param adDidCloseHandler 用户手动关闭广告回调
/// @param serverRewardedHandler 调用服务器接口回调
- (void)loadRewardedVideoAdWithRewardName:(NSString *)rewardName
                             rewardAmount:(NSUInteger)rewardAmount
                           viewController:(UIViewController *_Nullable)viewController
                     successLoadAdHandler:(void (^)(NSString *key))successLoadAdHandler
                        failLoadAdHandler:(void (^_Nullable)(NSError *error))failLoadAdHandler
                        adWillShowHandler:(void(^_Nullable)(void))adWillShowHandler
                        adDidCloseHandler:(void (^_Nullable)(void))adDidCloseHandler
                    serverRewardedHandler:(void (^)(ZSBaseModel *model))serverRewardedHandler;

/// 加载banner广告
/// @param locationType 广告位置（顶部、中部、底部)，其中广告的边距是20，高度是100
/// @param successLoadAdHandler 广告加载成功回调 回调参数为广告的key标识，请保存好此key，用于页面即将消失（viewWillDisappear）并且用户没有关闭广告时删除广告使用
/// @param failLoadAdHandler 广告加载失败回调
/// @param adDidCloseHandler 用户手动关闭广告回调
/// @param isAnimationOn Banner展现和轮播时的动画效果开关，传入nil或@(YES)为打开，@(NO)为关闭
/// @param interval 广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选]
/// @param viewController 广告展示所在的控制器，传入nil(空)值则默认是application.keyWindow.rootViewController
- (void)loadBannerWithLocationType:(ZSBannerLocationType)locationType
                      successLoadAdHandler:(void (^)(NSString *key))successLoadAdHandler
                         failLoadAdHandler:(void (^_Nullable)(NSError *error))failLoadAdHandler
                         adDidCloseHandler:(void (^_Nullable)(void))adDidCloseHandler
                             isAnimationOn:(id _Nullable)isAnimationOn
                                  interval:(NSNumber *_Nullable)interval
                            viewController:(UIViewController *_Nullable)viewController;


/// 加载插屏广告
/// @param viewController 广告展示所在的控制器，传入nil(空)值则默认是application.keyWindow.rootViewController
/// @param successLoadAdHandler 广告加载成功回调 回调参数为广告的key标识，请保存好此key，用于页面即将消失（viewWillDisappear）并且用户没有关闭广告时删除广告使用
/// @param failLoadAdHandler 广告加载失败回调
/// @param adWillShowHandler 广告即将显示回调
/// @param adDidCloseHandler 用户手动关闭广告回调
- (void)loadInterstitialAdWithViewController:(UIViewController *)viewController
                        successLoadAdHandler:(void (^)(NSString *key))successLoadAdHandler
                           FailLoadAdHandler:(void(^_Nullable)(NSError *error))failLoadAdHandler
                           adWillShowHandler:(void(^_Nullable)(void))adWillShowHandler
                           adDidCloseHandler:(void (^_Nullable)(void))adDidCloseHandler;

/// 移除广告（若App页面或游戏界面即将要销毁，并且发现用户并没有关闭广告时需手动调用该方法将广告移除，
/// 避免页面被销毁而广告对象依然留着内存中造成内存紧张)
/// @param key 下标，该下标由调起广告的方法返回
-(void)removeAdvertisingWithKey:(NSString *)key;

/// 移除所有广告
-(void)removeAllAdvertising;


/// 校验广告是否存在
/// @param key 下标，该下标由调起广告的方法返回
-(BOOL)checkAdvertisingWithKey:(NSString *)key;
@end

NS_ASSUME_NONNULL_END
