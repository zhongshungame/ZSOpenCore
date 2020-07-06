//
//  ZSOpenCoreSDK.h
//  ZSOpenCore
//
//  Created by Hunter on 2019/7/30.
//  Copyright © 2019 sng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSOpenCoreDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSOpenCoreSDK: NSObject

/// 初始化SDK，调用其他接口前必须先初始化
/// @param appId appId
/// @param appSecret appSecret
/// @param scope api scope
/// @param publicKey 公钥(下单签名使用)
/// @param channelNo 渠道号
/// @param packageNo 分包号
+ (void)initializeSDKWithAppId:(NSString *)appId
                     appSecret:(NSString *)appSecret
                         scope:(NSString *)scope
                     publicKey:(NSString *)publicKey
                     channelNo:(NSString *)channelNo
                     packageNo:(NSString *)packageNo,...NS_REQUIRES_NIL_TERMINATION;

/// 关闭日志打印
+(void)setLogOFF;
/**
 打开url
 
 @param urlString urlString
 */
+ (void)openUrl:(NSString *)urlString;
@end

NS_ASSUME_NONNULL_END
