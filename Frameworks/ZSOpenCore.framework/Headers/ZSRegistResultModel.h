//
//  ZSRegistResultModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/7.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSRegistResultModel : NSObject

@property (nonatomic, copy) NSString *openId;
@property (nonatomic, copy) NSString *unionId;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, copy) NSString *account;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *picture;

@end

NS_ASSUME_NONNULL_END
