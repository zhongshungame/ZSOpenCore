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

/**
 获取支付订单
 
 @param params 支付参数
 @param complateBlock 完成回调
 */
- (void)payWithParam:(ZSOrderParamsModel *)params complateBlock:(void(^)(ZSBaseModel *model, NSString *url))complateBlock;
            
@end

NS_ASSUME_NONNULL_END
