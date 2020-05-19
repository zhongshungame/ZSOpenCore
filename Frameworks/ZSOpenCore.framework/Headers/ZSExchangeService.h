//
//  ZSExchangeService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/11.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSGoodsListResultModel.h"

@class ZSBaseModel,ZSGoodsListResultModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZSExchangeService : NSObject

+ (instancetype)service;


/// 兑换商城获取商品列表（分页）
/// @param pageSize 页数量
/// @param pageIndex 页面（从1开始）
/// @param currencyId 兑换货币Id(int可选参数,示例参数：@1或nil)
/// @param completeBlock 完成回调（list即商品列表）
-(void)GetGoodsListWithPageSize:(int)pageSize
                      pageIndex:(int)pageIndex
                     currencyId:(nullable id)currencyId
                  completeBlock:(void (^)(ZSBaseModel *model,NSMutableArray<ZSGoodsListResultModel *> *_Nullable list))completeBlock;
@end

NS_ASSUME_NONNULL_END
