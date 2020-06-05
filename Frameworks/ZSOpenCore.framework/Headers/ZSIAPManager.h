//
//  ZSIAPManager.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/5/23.
//  Copyright © 2020 xf. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSIAPManager : NSObject

/// 单例
+ (instancetype)sharedZSIAPManager;

-(void)requestWhenInUseAuthorization;
/// 苹果内购下单
/// @param productId 产品ID
/// @param orderId 订单号
/// @param complete 完成回调
-(void)addPaymentWithProductId:(NSString *)productId
                       orderId:(NSString *)orderId
                      complete:(void (^)(BOOL success,long code ,NSString *_Nullable errMessage))complete;
@end

NS_ASSUME_NONNULL_END
