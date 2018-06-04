//
//  SYCInterface.m
//  SY185SDK
//
//  Created by 燚 on 2018/6/1.
//  Copyright © 2018年 Sans. All rights reserved.
//

#include "SYCInterface.h"
#include "SYGeneralInterface.h"


#pragma mark - notice
/**
 * SDK debug 模式控制台开启打印信息(在初始化方法之前调用这个函数会开启在控制台打印相关信息,不调用此函数不会有打印信息.这个函数不会影响 SDK 接入,只是为了方便调试)
 */
void Game185ShowDebugMessage(void) {
    General185ShowDebugMessage();
}

#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> call back with Function block
static GInitCallBackBlock _initCallBackBlock = NULL;
void Game185InitCallBack(bool success, const char * message) {
    if (_initCallBackBlock) {
        _initCallBackBlock(success, message);
    }
}

static GPayCallBackBlock _payCallBackBlock = NULL;
void Game185PayStartCallBack(bool success, const char * order_id) {
    if (_payCallBackBlock) {
        _payCallBackBlock(success, order_id);
    }
}

static GLoginCallBackBlock _loginCallBackBlock = NULL;
void Game185LoginCallBack(bool success, const char * message, const char * username, const char * token) {
    if (_loginCallBackBlock) {
        _loginCallBackBlock(success, message ,username, token);
    }
}

///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function with block >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化接口
 */
void SY185SDKInitSDKWithBlock(const char * AppID, const char * AppKey, bool useWindow, GInitCallBackBlock callBackBlock) {
    if (callBackBlock) {
        _initCallBackBlock = callBackBlock;
    } else {
        errorMessage("init call back block not exist");
    }
    GeneralInit(AppID, AppKey, useWindow, Game185InitCallBack);
}
/**
 * SDK 发起支付接口
 */
void SY185SDKPayStartWithBlock(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, GPayCallBackBlock callBackBlock) {
    if (callBackBlock) {
        _payCallBackBlock = callBackBlock;
    } else {
        errorMessage("pay call back block not exist");
    }
    GeneralPayStart(server_id, server_name, role_id, role_name, product_id, product_name, amount, extension, Game185PayStartCallBack);
}
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 */
void SY185SDKShowLoginViewWithBlock(GLoginCallBackBlock callBackBlock) {
    if (callBackBlock) {
        _loginCallBackBlock = callBackBlock;
    } else {
        errorMessage("login call back block not exist");
    }
    GeneralShowLoginView(Game185LoginCallBack);
}


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> call back with Function Pointer
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function with pointer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化接口
 */
void SY185SDKInitSDKWithPointer(const char * AppID, const char * AppKey, bool useWindow, InitCallBackFunction callBackPointer) {
    GeneralInit(AppID, AppKey, useWindow, callBackPointer);
}
/**
 * SDK 发起支付接口
 */
void SY185SDKPayStart(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, PayCallBackFunction callBackPointer) {
    GeneralPayStart(server_id, server_name, role_id, role_name, product_id, product_name, amount, extension, callBackPointer);
}
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 * @param callBackPointer     登录后的回调
 */
void SY185SDKShowLoginView(LoginCallBackFunction callBackPointer) {
    GeneralShowLoginView(callBackPointer);
}

#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> no call back function
/**
 * SDK 退出登录接口(游戏中玩家点击退出游戏的时候请调用这个方法)
 */
void SY185SDKSignOut(void) {
    GeneralSignOut();
}
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< GM init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * GM 功能初始化
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 */
void SY185SDKGMFunctionInit(const char * server_id, const char * server_name, const char * role_id, const char * role_name) {
    GeneralGMFunctionInit(server_id, server_name, role_id, role_name);
}



