//
//  ZSExchangeService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/11.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZSBaseModel,ZSGoodsListResultModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZSExchangeService : NSObject

+ (instancetype)service;


/// 兑换商城获取商品列表（分页）
/// @param pageSize 页数量
/// @param pageIndex 页面（从1开始）
/// @param currencyId 兑换货币Id(int可选参数,示例参数：@1或nil)
/// @param onSuccess 成功回调函数
/// @param onFailure 失败回调函数
+(void)getGoodsList:(int)pageSize
          pageIndex:(int)pageIndex
         currencyId:(NSString *_Nullable)currencyId
          onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
          onFailure:(void (^)(long code,NSString *errMessage))onFailure;
@end

NS_ASSUME_NONNULL_END
