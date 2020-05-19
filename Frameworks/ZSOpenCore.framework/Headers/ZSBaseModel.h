//
//  ZSBaseModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/6.
//  Copyright © 2019 QKAGame. All rights reserved.
//  基础接口类

#import <Foundation/Foundation.h>
#import "ZSServerErrorCode.h"

@interface ZSBaseModel : NSObject
/// 是否成功
@property (nonatomic, assign) BOOL success;
/// 错误码
@property (nonatomic, assign) long code;
/// 错误描述
@property (nonatomic, copy) NSString *error;
/** 错误详细描述 */
@property(nonatomic,copy)NSString *error_description;
/// 时间
@property (nonatomic, copy) NSString *responseTime;
@property (nonatomic, strong) NSDictionary *data;
/** 请求任务标识 */
@property(nonatomic,copy)NSString *requestTaskId;
@end
