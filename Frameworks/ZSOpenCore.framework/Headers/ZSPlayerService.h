//
//  ZSPlayerService.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/7.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZSUserInfoResultModel;
@class ZSBaseModel, ZSPromoteResultModel;
@class ZSRegistParamsModel, ZSRegistResultModel;
@class ZSLoginParamsModel;
@class ZSResetPasswordResultModel;
@class ZSTokenResultModel;

@interface ZSPlayerService : NSObject

+ (instancetype)service;

#pragma mark - 注册/登录

@property (nonatomic, assign) BOOL isLogin;
@property (nonatomic, copy) NSString *accessToken;

/**
 游客注册
 
 @param completeBlock 完成回调
 */
- (void)touristRegistWithCompleteBlock:(void (^ _Nullable)(ZSBaseModel *model, ZSRegistResultModel *  _Nullable content))completeBlock;

/**
 手机号注册
 
 @param mobile 手机号
 @param smsKey 验证码key，发送验证码接口回调获得
 @param smsCode 验证码
 @param password 密码（可选）
 @param completeBlock 完成回调
 */
- (void)registWithMobile:(NSString *)mobile
                  smsKey:(NSString *)smsKey
                 smsCode:(NSString *)smsCode
                password:(NSString *_Nullable)password
           completeBlock:(void (^ _Nullable)(ZSBaseModel *model, ZSRegistResultModel * _Nullable content))completeBlock;

/// 账号注册
/// @param account 账号
/// @param password 密码
/// @param completeBlock 完成回调
- (void)registWithAccount:(NSString *)account
                 password:(NSString *)password
            completeBlock:(void (^ _Nullable)(ZSBaseModel *model, ZSRegistResultModel * _Nullable content))completeBlock;

/**
 手机号登录
 
 @param mobile 手机号码
 @param smsKey 验证码key，发送验证码接口回调获得
 @param smsCode 验证码
 @param completeBlock 完成回调
 */
- (void)loginWithMobile:(NSString *)mobile
                 smsKey:(NSString *)smsKey
                smsCode:(NSString *)smsCode
          completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;
/**
 手机号登录
 
 @param mobile 手机号码
 @param smsKey 验证码key，发送验证码接口回调获得
 @param smsCode 验证码
 @param requestTaskId 透传参数，原样返回ZSBaseModel.requestTaskId
 @param completeBlock 完成回调
 */
- (void)loginWithMobile:(NSString *)mobile
                 smsKey:(NSString *)smsKey
                smsCode:(NSString *)smsCode
          requestTaskId:(NSString *_Nullable)requestTaskId
          completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;

/**
 账号登录
 
 @param account 账号
 @param password 密码
 @param isTourist 是否是游客登录
 @param completeBlock 完成回调
 */
- (void)loginWithAccount:(NSString *)account
                password:(NSString *)password
               isTourist:(BOOL)isTourist
           completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;
/**
 账号登录
 
 @param account 账号
 @param password 密码
 @param requestTaskId 透传参数，原样返回ZSBaseModel.requestTaskId
 @param isTourist 是否是游客登录
 @param completeBlock 完成回调
 */
- (void)loginWithAccount:(NSString *)account
                password:(NSString *)password
           requestTaskId:(NSString *_Nullable)requestTaskId
               isTourist:(BOOL)isTourist
           completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;
/**
 客户端授权登录
 
 @param clientAuthAccessToken 授权应用的accessToken
 @param completeBlock 完成回调
 */
- (void)clientLoginClientAuthAccessToken:(NSString *)clientAuthAccessToken
                           completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;
/**
 客户端授权登录
 
 @param clientAuthAccessToken 授权应用的accessToken
 @param requestTaskId 透传参数，原样返回ZSBaseModel.requestTaskId
 @param completeBlock 完成回调
 */
- (void)clientLoginClientAuthAccessToken:(NSString *)clientAuthAccessToken
                           requestTaskId:(NSString *_Nullable)requestTaskId
                           completeBlock:(void (^ _Nullable)(ZSTokenResultModel *model))completeBlock;
/**
 微信登录/注册
 @param code 微信授权码
 @param completeBlock 完成回调
 */
- (void)wechatLoginWithWechatCode:(NSString *)code completeBlock:(void (^)(ZSTokenResultModel *model))completeBlock;
/**
 微信登录/注册
 @param code 微信授权码
 @param requestTaskId 透传参数，原样返回ZSBaseModel.requestTaskId
 @param completeBlock 完成回调
 */
- (void)wechatLoginWithWechatCode:(NSString *)code
                    requestTaskId:(NSString *_Nullable)requestTaskId
                    completeBlock:(void (^)(ZSTokenResultModel *model))completeBlock;

/// 刷新当前账号token，刷新成功后会重新覆盖本地的旧token
/// @param complete completeBlock
- (void)refreshTokenCompleteBlock:(void (^)(ZSTokenResultModel *model))complete;

/// 刷新指定refreshToken
/// @param refreshToken 旧refreshToken
/// @param complete 刷新完成回调
- (void)refreshTokenWithRefreshToken:(NSString *)refreshToken completeBlock:(void (^)(ZSTokenResultModel *model))complete;

/// 验证Token
/// @param token token
/// @param complete 验证回调active（token是否有效）
-(void)introspectWithToken:(NSString *)token complete:(void (^)(ZSBaseModel *model,BOOL active))complete;

/// 退出登录
/// @param complete 退出完成回调：logout清除当前用户本地token成功标识
- (void)logoutWithComplete:(void (^)(BOOL logout))complete;

#pragma mark - 用户接口

/**
 获取当前登录用户信息
 
 @param completeBlock 完成回调
 */
- (void)getUserInfoWithCompleteBlock:(void (^ _Nullable)(ZSBaseModel *model, ZSUserInfoResultModel * _Nullable content))completeBlock;

/**
 财富充值
 
 @param itemId itemId
 @param orderNo orderNo
 @param amount amount
 @param signature signature
 @param completeBlock 完成回调
 */
//- (void)rechargeWithItemId:(NSString *)itemId
//                   orderNo:(NSString *)orderNo
//                    amount:(NSInteger)amount
//                 signature:(NSString *)signature
//             completeBlock:(void (^ _Nullable)(ZSBaseModel *model))completeBlock;

/**
 财富消费
 
 @param itemId itemId
 @param orderNo orderNo
 @param amount amount
 @param signature signature
 @param completeBlock 完成回调
 */
//- (void)expenditureWithItemId:(NSString *)itemId
//                      orderNo:(NSString *)orderNo
//                       amount:(NSInteger)amount
//                    signature:(NSString *)signature
//                completeBlock:(void (^ _Nullable)(ZSBaseModel *model))completeBlock;

/**
 绑定手机（或手机转正）
 
 @param smsKey smsKey
 @param smsCode smsCode
 @param mobile 手机号码
 @param password 密码（可空）
 @param completeBlock 完成回调
 */
- (void)bindMobileWithSmsKey:(NSString *)smsKey
                     smsCode:(NSString *)smsCode
                      mobile:(NSString *)mobile
                    password:(NSString *_Nullable)password
               completeBlock:(void (^)(ZSBaseModel *model))completeBlock;

/// 绑定微信（或微信转正）
/// @param code 微信授权码
/// @param completeBlock 完成回调
- (void)bindWechatWithCode:(NSString *)code
             completeBlock:(void (^)(ZSBaseModel *model))completeBlock;


/// 实名认证
/// @param realName 真实姓名
/// @param IdCard 身份证号码
/// @param complete 完成回调
- (void)RealNameAuthenticationWithRealName:(NSString *)realName
                                    IdCard:(NSString *)IdCard
                             completeBlock:(void (^)(ZSBaseModel *model))complete;
#pragma mark - 异常流程

/**
 重置密码
 方法内部会首先查询当前手机号是否绑定了账号
 @param mobile 手机号码
 @param smsKey 验证码key，发送验证码接口回调获得
 @param smsCode 验证码
 @param password 密码
 @param completeBlock 完成回调
 */
- (void)resetPasswordWithMobile:(NSString *)mobile
                         smsKey:(NSString *)smsKey
                        smsCode:(NSString *)smsCode
                       password:(NSString *)password
                  completeBlock:(void (^ _Nullable)(ZSBaseModel *model, ZSResetPasswordResultModel * _Nullable content))completeBlock;

/**
 查询手机是否注册
 
 @param mobile 手机号码
 @param completeBlock 完成回调
 */
- (void)checkPhoneRegistedWithMobile:(NSString *)mobile
                       completeBlock:(void (^ _Nullable)(ZSBaseModel *model, BOOL isRegisted))completeBlock;

/**
 登录异常验证
 
 @param mobile 手机号码
 @param smsKey 验证码key，发送验证码接口回调获得
 @param smsCode 验证码
 @param completeBlock 完成回调
 */
//- (void)loginExceptionVertifyWithMobile:(NSString *)mobile
//                                 smsKey:(NSString *)smsKey
//                                smsCode:(NSString *)smsCode
//                          completeBlock:(void (^ _Nullable)(ZSBaseModel *model))completeBlock;

@end

NS_ASSUME_NONNULL_END
