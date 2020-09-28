//
//  ZSQuickLoginManager.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/7/29.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSQuickLoginManager : NSObject
/// businessID
@property (nonatomic, copy) NSString *businessID;

+(instancetype)sharedZSQuickLoginManager;

/// 在使用一键登录之前，请先调用shouldQuickLogin方法，判断当前上网卡的网络环境和运营商是否可以一键登录，若可以一键登录，继续执行下面的步骤；否则，建议后续直接走降级方案（例如短信）
-(BOOL)shouldQuickLogin;

/// 预准备一键登录
/// @param timeout 超时时间（单位：毫秒）
/// @param customParam 授权窗口自定义参数：@{@"logoImg":@"logo图片",@"logoWidth":logo宽度,@"logoHeight"://logo高度}
/// @param completion 完成回调
-(void)prepareQuickLoginWithTimeout:(NSTimeInterval)timeout customParam:(NSDictionary *_Nullable)customParam completion:(void (^)(long code ,NSString *errorMsg))completion;

/// 拉取授权页并登录
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)CUCMCTAuthorizeLogin:(void (^)(long code,NSString *result))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure;


/// 拉取授权页
/// @param onSuccess 完成回调(返回易盾token和运营商的accessToken、脱敏手机号securityPhone)
/// @param onFailure 失败回调
/// @param authViewWillShow 授权窗口即将展示回调
-(void)CUCMCTAuthorize:(void (^)(long code,NSString *ydToken,NSString *yysAccessToken,NSString *_Nullable securityPhone))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure authViewWillShow:(void (^_Nullable)(void))authViewWillShow;
@end

NS_ASSUME_NONNULL_END
