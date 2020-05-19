//
//  ZSServerErrorCode.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/15.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 1-100  common服务错误
 100-499玩家服务错误
 500-800为充值服务错误
 0. 成功操作
 1. 上传文件的Content-Type错误
 2. 图片验证码过期
 3. 图片验证码错误
 4. 短信验证码发送失败
 5. 手机验证码过期
 10. 手机验证码错误
 98. 业务处理失败
 99. 无效参数
 100. 参数不能为空
 100. 参数不能为空
 101. 玩家不存在
 102. 玩家处于冻结状态
 103. 异常登录验证错误次数已超过五次，无法继续验证
 104. 密码不合规
 105. 异常登录之手机验证码验证
 106. 异常登录之问题验证
 107. 账号已临时冻结
 */
typedef enum : NSUInteger {
    /// 未登录
    ZSServerErrorUnlogin = 401, 
    /// 成功操作
    ZSServerErrorCodeLegal = 0,
    /// 上传文件的Content-Type错误
    ZSServerErrorCodeContentType = 1,
    /// 图片验证码过期
    ZSServerErrorCodePicVerificationCodeExpired = 2,
    /// 图片验证码错误
    ZSServerErrorCodePicVerificationCodeError = 3,
    /// 短信验证码发送失败
    ZSServerErrorCodeSendSMSFailed = 4,
    /// 手机验证码过期
    ZSServerErrorCodeSMSExpired = 5,
    /// 手机验证码错误
    ZSServerErrorCodeSMSError = 10,
    /// 业务处理失败
    ZSServerErrorCodeBusinessProcessingFailed = 98,
    /// 无效参数
    ZSServerErrorCodeInvalidParams = 99,
    /// 参数不能为空
    ZSServerErrorCodeParamsNull = 100,
    /// 玩家不存在
    ZSServerErrorCodeUserNoeExist = 101,
    /// 玩家处于冻结状态
    ZSServerErrorCodeUserFrozen = 102,
    /// 异常登录验证错误次数已超过五次，无法继续验证
    ZSServerErrorCodeLoginException = 103,
    /// 密码不合规
    ZSServerErrorCodePasswordIllegal = 104,
    /// 异常登录之手机验证码验证
    ZSServerErrorCodeLoginExceptionVertify = 105,
    /// 异常登录之问题验证
    ZSServerErrorCodeInsufficientBalance = 106,
    /// 登陆校验失败
    ZSServerErrorCodeLoginFailure = 107,
} ZSServerErrorCode;
