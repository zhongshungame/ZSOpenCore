//
//  ZSPayService.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/14.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZSOrderParamsModel, ZSBaseModel;
NS_ASSUME_NONNULL_BEGIN

@interface ZSPayService : NSObject

+ (instancetype)service;

/// 获取充值列表入口
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+(void)getPayWay:(void (^)(long code,NSString *_Nullable result))onSuccess
       onFailure:(void (^)(long code,NSString *errMessage))onFailure;

/// 下单
/// @param payInfo 支付参数json字符串
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+(void)recharge:(NSString *)payInfo
       onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
       onFailure:(void (^)(long code,NSString *errMessage))onFailure;
            
@end

NS_ASSUME_NONNULL_END
