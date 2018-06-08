//
//  SYUserModel.h
//  SY185SDK
//
//  Created by 燚 on 2018/6/8.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "SY185GeneralModel.h"
#import "SYNetWorkManager.h"

/** type 1 注册 2绑定 3解绑 4 修改密码 */
typedef enum : NSUInteger {
    CodeRegister = 1,
    CodeBinding = 2,
    COdeUnbind,
    CodeResetPassword
} CodeMessage;


@interface SYUserModel : SY185GeneralModel

@property (nonatomic, strong, readonly) NSString *uid;
@property (nonatomic, strong, readonly) NSString *token;
@property (nonatomic, strong, readonly) NSString *username;
@property (nonatomic, strong, readonly) NSString *mobile;
@property (nonatomic, strong, readonly) NSString *platform_money;
@property (nonatomic, strong, readonly) NSString *id_name;
@property (nonatomic, strong, readonly) NSString *id_card;
@property (nonatomic, strong, readonly) NSString *icon_url;
@property (nonatomic, strong, readonly) NSString *question_contract_enabled;
@property (nonatomic, assign, readonly) NSInteger maxSpped;


/** 当前用户 */
+ (SYUserModel *)currentUser;

/** 请求手机验证码 */
+ (void)requestCodeWithType:(CodeMessage)codeType
            WithPhoneNumber:(NSString *)phoneNumber
                 completion:(SYRequestCompletionBlock)completion;








@end


















