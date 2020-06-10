//
//  ZSPlayerOpenService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/5/27.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSBaseService.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSPlayerOpenService : ZSBaseService

+ (instancetype)service;

/// 游客注册
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doRegistVisitor:(void (^)(long code,NSString *_Nullable result))onSuccess
             onFailure:(void (^)(long code,NSString *errMessage))onFailure;


/// 手机注册
/// @param mobile 手机号
/// @param smsCode 短信验证码
/// @param smsKey smsKey(调用发送短信验证码接口时的sesskey)
/// @param password 密码(可空)
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doRegistMobile:(NSString *)mobile
              smsCode:(NSString *)smsCode
              smsKey:(NSString *)smsKey
             password:(NSString *_Nullable)password
            onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 账号注册
/// @param account 账号
/// @param password 密码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doRegistAccount:(NSString *)account
              password:(NSString *)password
             onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
             onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 手机登录
/// @param mobile 手机号
/// @param smsCode 短信验证码
/// @param smsKey smsKey(调用发送短信验证码接口时的sesskey)
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doLoginMobile:(NSString *)mobile
             smsCode:(NSString *)smsCode
              smsKey:(NSString *)smsKey
           onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
           onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 账号登录
/// @param username 账号
/// @param password 密码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doLoginUsername:(NSString *)username
              password:(NSString *)password
             onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
             onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 微信登录
/// @param code 微信授权码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doWXLogin:(NSString *)code
       onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
       onFailure:(void (^)(long code,NSString *errMessage))onFailure;


/// 苹果登录
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)sigInWithApple:(void (^)(long code,NSString *_Nullable result))onSuccess
            onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 启动时监听苹果登录的状态
/// @param complete 完成回调(若当前用户是苹果登录，并且用户在设置注销了AppleID，则APP启动时needLogin为YES)
-(void)checkSignInAppleStateWhenLaunchWithComplete:(void (^)(BOOL needLogin))complete;

/// 刷新当前登录账号的token
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)refreshToken:(void (^)(long code,NSString *_Nullable result))onSuccess
          onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 退出登录
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doExit:(void (^)(long code,NSString *_Nullable result))onSuccess
    onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 获取当前登录账号的信息
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)getAccountInfo:(void (^)(long code,NSString *_Nullable result))onSuccess
            onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 手机转正（绑定）
/// @param mobile 手机号
/// @param smsCode 短信验证码
/// @param smsKey smsKey(调用发送短信验证码接口时的sesskey)
/// @param password 密码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doPromoteByMobile:(NSString *)mobile
                 smsCode:(NSString *)smsCode
                  smsKey:(NSString *)smsKey
                password:(NSString *)password
               onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
               onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 微信转正（绑定）
/// @param code 微信授权码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doPromoteByWX:(NSString *)code
           onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
           onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 查询手机号是否已注册
/// @param mobile 手机号
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)queryMobile:(NSString *)mobile
         onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
         onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 实名验证
/// @param realName 姓名
/// @param ID 身份证号码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)bindIDCard:(NSString *)realName
               ID:(NSString *)ID
        onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
        onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 找回密码
/// @param mobile 手机
/// @param smsCode 短信验证码
/// @param smsKey smsKey(调用发送短信验证码接口时的sesskey)
/// @param password 新密码
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)doResetPassword:(NSString *)mobile
               smsCode:(NSString *)smsCode
                smsKey:(NSString *)smsKey
              password:(NSString *)password
             onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
             onFailure:(void (^)(long code,NSString *errMessage))onFailure;


/// 获取分包号
-(NSString *)getPackageCode;

/// 获取当前token
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)getAccessToken:(void (^)(long code,NSString *_Nullable result))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure;
@end

NS_ASSUME_NONNULL_END
