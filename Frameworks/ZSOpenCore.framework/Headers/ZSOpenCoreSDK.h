//
//  ZSOpenCoreSDK.h
//  ZSOpenCore
//
//  Created by Hunter on 2019/7/30.
//  Copyright © 2019 sng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSOpenCoreDefines.h"

@class ZSBaseModel, ZSRegistResultModel, ZSLoginResultModel, ZSPromoteResultModel, ZSUserInfoResultModel, ZSResetPasswordResultModel, ZSOrderParamsModel, ZSQuestionListResultModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZSOpenCoreSDK: NSObject

/**
 初始化SDK，调用其他接口前必须先初始化
 
 @param environmentType 环境
 @param channelNo 渠道id
 @param packageNo 分包id
 @param scope scope
 @param appId appId
 @param appSecret appSecret
 */
+ (void)initializeSDKWithEnvironment:(ZSEnvironmentType)environmentType
                               appId:(NSString *)appId
                           appSecret:(NSString *)appSecret
                               scope:(NSString *)scope
                           channelNo:(NSString *)channelNo
                           packageNo:(NSString *)packageNo;

/// 关闭日志打印
+(void)setLogOFF;
/**
 打开url
 
 @param urlString urlString
 */
+ (void)openUrl:(NSString *)urlString;
@end

NS_ASSUME_NONNULL_END
