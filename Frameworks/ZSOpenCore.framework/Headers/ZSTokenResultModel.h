//
//  ZSTokenResultModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/4/21.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSTokenResultModel : NSObject

@property(nonatomic,assign)BOOL success;
@property(nonatomic,assign)long code;
@property(nonatomic,copy)NSString *responseTime;
@property(nonatomic,copy)NSString *token_type;
@property(nonatomic,copy)NSString *scope;
@property(nonatomic,copy)NSString *refresh_token;
@property(nonatomic,copy)NSString *access_token;
@property(nonatomic,copy)NSString *error;
/** 错误详细描述 */
@property(nonatomic,copy)NSString *error_description;
@property(nonatomic,assign)long expires_in;
/** 请求任务标识 */
@property(nonatomic,copy)NSString *requestTaskId;
@end

NS_ASSUME_NONNULL_END
