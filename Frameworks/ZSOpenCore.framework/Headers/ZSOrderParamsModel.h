//
//  ZSOrderParamsModel.h
//  ZSOpenCore
//
//  Created by qkagame on 2019/8/14.
//  Copyright © 2019 QKAGame. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ZSOrderPlatformTypePlatform = 1,
    ZSOrderPlatformTypeU3D,
    ZSOrderPlatformTypePC,
    ZSOrderPlatformTypeBlockchain,
    ZSOrderPlatformTypeElectronicGames
} ZSOrderPlatformType;

typedef enum : NSUInteger {
    ZSOrderDeviceTypeAndroid = 1,
    ZSOrderDeviceTypeiOS = 2,
    ZSOrderDeviceTypeH5 = 4,
    ZSOrderDeviceTypePC = 8,
} ZSOrderDeviceType;

typedef enum : NSUInteger {
    ZSOrderMachineTypeAndroid = 1,
    ZSOrderMachineTypeiOS = 2,
    ZSOrderMachineTypeH5 = 3,
    ZSOrderMachineOther = 4,
} ZSOrderMachineType;

typedef enum : NSUInteger {
    ZSOrderMethodAlipayH5 = 1,
    ZSOrderMethodWechatH5,
    ZSOrderMethodUnionPayH5,
    ZSOrderMethodAlipayQRCode,
    ZSOrderMethodWechatQRCode,
    ZSOrderMethodUnionPayQRCode,
    ZSOrderMethodWechat,
    ZSOrderMethodAlipay
} ZSOrderMethod;

@interface ZSOrderParamsModel : NSObject

@property (nonatomic, assign) int isPloy;
@property (nonatomic, assign) int platformType;
@property (nonatomic, copy) NSString *orderNO;
@property (nonatomic, assign) int amount;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, assign) int quantity;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *desc;

/// 默认为ios 无需设置
@property (nonatomic, assign,readonly) ZSOrderDeviceType device;
@property (nonatomic, copy) NSString *typeCode;
@property (nonatomic, copy) NSString *extData;
@property (nonatomic, copy) NSString *extInfo;
@property (nonatomic, copy) NSString *openId;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *notifyUrl;
@property (nonatomic, copy) NSString *sign;
@property (nonatomic, copy) NSString *signType;

/// 分包号 sdk自动设置无需设置
@property (nonatomic, copy,readonly) NSString *channelSubCode;

/// app版本号
@property (nonatomic, copy) NSString *appVersion;
@property (nonatomic, copy) NSString *version;

@end
