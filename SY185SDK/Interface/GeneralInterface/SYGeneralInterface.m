//
//  SYGeneralInterface.m
//  SY185SDK
//
//  Created by 燚 on 2018/5/31.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "SYGeneralInterface.h"
#import <Foundation/Foundation.h>

/**
 * SDK debug 模式控制台开启打印信息(在初始化方法之前调用这个函数会开启在控制台打印相关信息,不调用此函数不会有打印信息.这个函数不会影响 SDK 接入,只是为了方便调试)
 */
void General185ShowDebugMessage(void) {
//    showMessage("显示信息");
    syLog(@"显示信息");
}

///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化接口
 */
void GeneralInit(const char * AppID, const char * AppKey, bool useWindow, GeneralInitCallBack callBackPointer) {
    syLog(@"general -> SDK 初始化");
    if (callBackPointer) {
        callBackPointer(true,"general init call back");
    }
}
/**
 * SDK 发起支付接口
 */
void GeneralPayStart(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, GeneralPayCallBack callBackPointer) {
    syLog(@"general -> 发起支付");
    if (callBackPointer) {
        callBackPointer(true,"general pay call back");
    }
}

/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 */
void GeneralShowLoginView(GeneralLoginCallBack callBackPointer) {
    syLog(@"general -> 显示登录页面");
}


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> no call back function
/**
 * SDK 退出登录接口(游戏中玩家点击退出游戏的时候请调用这个方法)
 */
void GeneralSignOut(void) {
    syLog(@"general -> 退出登录");
}

/**
 * GM 功能初始化
 */
void GeneralGMFunctionInit(const char * server_id, const char * server_name, const char * role_id, const char * role_name) {
    syLog(@"general -> 初始化 GM");
}









