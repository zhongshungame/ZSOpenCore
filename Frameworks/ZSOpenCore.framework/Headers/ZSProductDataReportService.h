//
//  ZSProductDataReportService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/8/4.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSProductDataReportService : NSObject

/// 产品日志上报埋点
/// @param jsonParams json参数
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+(void)reportProduct:(NSString *)jsonParams onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
