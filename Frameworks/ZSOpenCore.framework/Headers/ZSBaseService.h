//
//  ZSBaseService.h
//  ZSOpenCore
//
//  Created by qkagame on 2020/5/27.
//  Copyright © 2020 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZSBaseModel.h"
#import "ZSTokenResultModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSBaseService : NSObject

+(void)handleApiWithBaseModel:(ZSBaseModel *)model
                    onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess
                    onFailure:(void (^)(long code,NSString *errMessage))onFailure;

+(void)handleApiWithTokenModel:(ZSTokenResultModel *)model onSuccess:(void (^)(long code,NSString *_Nullable result))onSuccess onFailure:(void (^)(long code,NSString *errMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
