//
//  ZSUserInfoResultModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/8.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSUserInfoResultModel : NSObject

//@property (nonatomic, copy) NSString *openId;
//@property (nonatomic, copy) NSString *unionId;
//@property (nonatomic, copy) NSString *playerAccount;
@property (nonatomic, copy) NSString *nickname;
@property(nonatomic,assign)int playerId;
//@property (nonatomic, copy) NSString *realName;
@property (nonatomic, copy) NSString *mobile;
/** true：正式账户；false：游客 */
@property(nonatomic,assign)BOOL isFormal;
@property (nonatomic, copy) NSString *picture;
/** 账号状态：1-正常，2-零时冻结，3-永久冻结 */
//@property(nonatomic,assign)int state;
//@property (nonatomic, copy) NSString *channelNO;
//@property (nonatomic, copy) NSString *packageNo;

/** 实名状态：1.未实名；2.已实名未第三方认证；3.已实名第三方认证通过 */
@property(nonatomic,assign)int RealNameState;
/** 是否绑定微信    true：绑定；false：没有绑定 */
@property(nonatomic,assign)BOOL isBindWechat;
@end

NS_ASSUME_NONNULL_END
