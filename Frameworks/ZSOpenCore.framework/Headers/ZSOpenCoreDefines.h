//
//  ZSOpenCoreDefines.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/11/14.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#ifndef ZSOpenCoreDefines_h
#define ZSOpenCoreDefines_h
/** 环境 */
typedef enum : NSUInteger {
    /// 开发环境，默认打印 ZSLogLevelAll
    ZSEnvironmentTypeDev,
    /// 测试环境，默认打印 ZSLogLevelSimple
    ZSEnvironmentTypeTest,
    /// 开发环境，默认打印 ZSLogLevelNone
    ZSEnvironmentTypeRelease,
} ZSEnvironmentType;

/** 打印级别 */
typedef enum : NSUInteger {
    /// 全部log
    ZSLogLevelAll,
    /// 部分log
    ZSLogLevelSimple,
    /// 关闭log
    ZSLogLevelNone,
} ZSLogLevel;

typedef enum : NSUInteger {
    ZSTokenTypeSMS = 1,//手机
    ZSTokenTypeAccount,//账号
    ZSTokenTypeWechat,//微信
    ZSTokenTypeClient,//官方应用
    ZSTokenTypeTourist, //游客
    ZSTokenTypeApple
} ZSTokenType;

typedef enum : NSUInteger {
    ZSPushProviderJPush=1 //极光推送
} ZSPushProvider;

//广告商
typedef enum : NSUInteger {
    ZSAdvertisingProviderGDT=1, //腾讯优量汇
    ZSAdvertisingProviderBU, //穿山甲
    ZSAdvertisingProviderInside //内部广告
} ZSAdvertisingProvider;

//banner广告位置类别
typedef enum : NSUInteger {
    /// banner广告位置:顶部
    ZSBannerLocationTypeTop,
    /// banner广告位置:中间
    ZSBannerLocationTypeMiddle,
    /// banner广告位置:底部
    ZSBannerLocationTypeBottom,
} ZSBannerLocationType;

#endif /* ZSOpenCoreDefines_h */


