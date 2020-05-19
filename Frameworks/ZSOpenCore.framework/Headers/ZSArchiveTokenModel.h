//
//  ZSArchiveTokenModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/3/8.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSOpenCoreDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSArchiveTokenModel : NSObject

/** token */
@property(nonatomic,copy)NSString *token;
/** refreshToken */
@property(nonatomic,copy)NSString *refreshToken;
/** token类型 */
@property(nonatomic,assign)ZSTokenType tokenType;
/** 手机号：tokenType=ZSTokenTypeSMS时不为空 */
@property(nonatomic,copy)NSString *mobile;
/** 昵称： tokenType !=ZSTokenTypeSMS时不为空*/
@property(nonatomic,copy)NSString *nickName;
/** 登录时间戳 */
@property(nonatomic,assign)long loginTime;
/** 解密token的sub:获取 */
@property(nonatomic,copy)NSString *openId;
/** 用户账号 tokenType=游客时不为空*/
@property(nonatomic,copy,nullable)NSString *account;
/** 用户密码 tokenType=游客时不为空*/
@property(nonatomic,copy,nullable)NSString *password;
@end

NS_ASSUME_NONNULL_END
