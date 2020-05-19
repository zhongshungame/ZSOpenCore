//
//  ZSGoodsListResultModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/11.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSGoodsListResultModel : NSObject

/** Id */
@property(nonatomic,copy)NSString *productId;
/** 商品名称 */
@property(nonatomic,copy)NSString *productName;
/** 价格 */
@property(nonatomic,assign)double *price;
/** 商品类型 */
@property(nonatomic,assign)int productType;
/** 商品简介 */
@property(nonatomic,copy)NSString *descriptions;
/** 图片 */
@property(nonatomic,copy)NSString *productImg;
@end

NS_ASSUME_NONNULL_END
