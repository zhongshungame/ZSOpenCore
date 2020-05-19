//
//  ZSSmsService.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/15.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class ZSBaseModel;
@interface ZSSMSService : NSObject

+ (instancetype)service;

/**
 短信发送(默认短信服务提供商)
 
 @param mobile 手机号
 @param type 业务类型 0-注册验证码；1-登陆验证码；2-密码修改验证码；3-异常登陆验证码;
 @param completeBlock 完成回调
 */
- (void)sendSMSWithMobile:(NSString *)mobile
                     type:(int)type
            completeBlock:(void(^)(ZSBaseModel *model, NSString *smsKey))completeBlock;


/// 短信发送
/// @param mobile 手机号
/// @param type 业务类型 0-注册验证码；1-登陆验证码；2-密码修改验证码；3-异常登陆验证码;
/// @param smsProvider 短信服务提供商（0-默认，1-尚通，2-北京微网通联，3-赛邮，  默认北京微网通联）
/// @param completeBlock 完成回调
- (void)sendSMSWithMobile:(NSString *)mobile
                     type:(int)type
              smsProvider:(int)smsProvider
            completeBlock:(void (^)(ZSBaseModel *model, NSString *))completeBlock;

@end


NS_ASSUME_NONNULL_END
