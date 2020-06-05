//
//  ZSSMSOpenService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/5/27.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSSMSOpenService : NSObject

+ (instancetype)service;

/// 发送短信
/// @param mobile 手机号
/// @param type 业务类型 0-注册验证码；1-登陆验证码；2-密码修改验证码；3-异常登陆验证码;
/// @param smsProvider 短信服务提供商（0-默认，1-尚通，2-北京微网通联，3-赛邮，  默认北京微网通联）
/// @param smsKey 相当于cookie用于做区分
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
-(void)sendSMS:(NSString *)mobile
          type:(int)type
   smsProvider:(int)smsProvider
       smsKey:(NSString *)smsKey
     onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
     onFailure:(void (^)(long code,NSString *errMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
