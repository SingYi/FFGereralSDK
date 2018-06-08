//
//  SYUserModel.m
//  SY185SDK
//
//  Created by 燚 on 2018/6/8.
//  Copyright © 2018年 Sans. All rights reserved.
//



#import "SYUserModel.h"


#define SYUserUtil [SYUserModel sharedUtil]
typedef struct _util {
    void (*requestCode)(CodeMessage codeType, NSString *phoneNumber, SYRequestCompletion completion);
} SYUserUtil_t ;


static void _requestCode(CodeMessage codeType, NSString *phoneNumber, SYRequestCompletion completion) {
    postRquesest(nil, nil, completion);
}

static SYRequestCompletionBlock _requesCodeCallBackBlock;
static void _requestCodeCallBack(Call_back) {
    _requesCodeCallBackBlock ? _requestCodeCallBack(Call_back_messsage) : 0;
}


@interface SYUserModel ()

@property (nonatomic, strong) NSString *uid;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *mobile;
@property (nonatomic, strong) NSString *platform_money;
@property (nonatomic, strong) NSString *id_name;
@property (nonatomic, strong) NSString *id_card;
@property (nonatomic, strong) NSString *icon_url;
@property (nonatomic, strong) NSString *question_contract_enabled;
@property (nonatomic, assign) NSInteger maxSpped;


+ (SYUserUtil_t *)sharedUtil;



@end


static SYUserUtil_t *_util = NULL;
static SYUserModel *_userModel = nil;

@implementation SYUserModel

+ (SYUserModel *)currentUser {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (!_userModel) {
            _userModel = [[SYUserModel alloc] init];
        }
    });
    return _userModel;
}

+ (SYUserUtil_t *)sharedUtil {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _util = malloc(sizeof(SYUserUtil_t));
        _util -> requestCode = _requestCode;
    });
    return _util;
}

#pragma makr -
+ (void)requestCodeWithType:(CodeMessage)codeType WithPhoneNumber:(NSString *)phoneNumber completion:(SYRequestCompletionBlock)completion {
    _requesCodeCallBackBlock = completion ?: nil;
    SYUserUtil -> requestCode(codeType, phoneNumber ,_requestCodeCallBack);
}













@end










