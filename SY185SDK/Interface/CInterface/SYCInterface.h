//
//  SYCInterface.h
//  SY185SDK
//
//  Created by 燚 on 2018/6/1.
//  Copyright © 2018年 Sans. All rights reserved.
//

#ifndef SYCInterface_h
#define SYCInterface_h

#include <stdio.h>
#include <stdbool.h>


/**
 * 注 : 这些方法在自定义类的实例中调用时候,
 *      请确保实例的内存常驻没有释放.
 *      否则可能会因为ARC机制自动释放内存而无法接收到回调
 *
 *      该头文件中封装了两中方式调用 SDK 获取回调方式,
 *      只需调用一种法法即可
 */

#pragma mark - notice
/**
 * SDK debug 模式控制台开启打印信息(在初始化方法之前调用这个函数会开启在控制台打印相关信息,不调用此函数不会有打印信息.这个函数不会影响 SDK 接入,只是为了方便调试)
 */
void Game185ShowDebugMessage(void);


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> call back with Block
////////////////////////////////////////////////////////////////////////////////
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< call back Block >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
////////////////////////////////////////////////////////////////////////////////
/**
 * SDK 初始化回调 block
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 */
typedef void(^GInitCallBackBlock)(bool success, const char * message);
/**
 * SDK 支付回调 block
 * @param success           是否成功
 * @param order_id          订单 id
 */
typedef void(^GPayCallBackBlock)(bool success, const char *order_id);
/**
 * SDK 登录回调 block
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 * @param username          用户账号
 * @param token             账号 token
 */
typedef void(^GLoginCallBackBlock)(bool success, const char * message, const char * username, const char * token);
////////////////////////////////////////////////////////////////////////////////////
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function with block >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
////////////////////////////////////////////////////////////////////////////////////
/**
 * SDK 初始化接口
 * @param AppID             App 的 id
 * @param AppKey            App 的 key
 * @param callBackBlock     初始化成功后的回调block
 */
void SY185SDKInitSDKWithBlock(const char * AppID, const char * AppKey, bool useWindow, GInitCallBackBlock callBackBlock);
/**
 * SDK 发起支付接口
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 * @param product_id        产品 id
 * @param product_name      产品名称
 * @param amount            金额 -> 单位 RMB(元) <最小充值金额 1 元 -> amount >= 1>
 * @param extension         拓展字段
 * @param callBackBlock     支付的回调 block
 */
void SY185SDKPayStartWithBlock(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, GPayCallBackBlock callBackBlock);
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 * @param callBackBlock     登录后的回调
 */
void SY185SDKShowLoginViewWithBlock(GLoginCallBackBlock callBackBlock);


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> call back with Function Pointer
/////////////////////////////////////////////////////////////////////////////////
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function Pointer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/////////////////////////////////////////////////////////////////////////////////
/**
 * SDK 初始化回调 Function Pointer
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 */
typedef void(*InitCallBackFunction)(bool success, const char * message);
/**
 * SDK 支付回调 Function Pointer
 * @param success           是否成功
 * @param order_id          订单 id
 */
typedef void(*PayCallBackFunction)(bool success, const char *order_id);
/**
 * SDK 登录回调 Function Pointer
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 * @param username          用户账号
 * @param token             账号 token
 */
typedef void(*LoginCallBackFunction)(bool success, const char * message, const char * username, const char * token);
//////////////////////////////////////////////////////////////////////////////////////
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function with pointer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
//////////////////////////////////////////////////////////////////////////////////////
/**
 * SDK 初始化接口
 * @param AppID             App 的 id
 * @param AppKey            App 的 key
 * @param callBackPointer   初始化成功后的回调block
 */
void SY185SDKInitSDKWithPointer(const char * AppID, const char * AppKey, bool useWindow, InitCallBackFunction callBackPointer);
/**
 * SDK 发起支付接口
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 * @param product_id        产品 id
 * @param product_name      产品名称
 * @param amount            金额 -> 单位 RMB(元) <最小充值金额 1 元 -> amount >= 1>
 * @param extension         拓展字段
 * @param callBackPointer     支付的回调 block
 */
void SY185SDKPayStart(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, PayCallBackFunction callBackPointer);
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 * @param callBackPointer     登录后的回调
 */
void SY185SDKShowLoginView(LoginCallBackFunction callBackPointer);


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> no call back function
/**
 * SDK 退出登录接口(游戏中玩家点击退出游戏的时候请调用这个方法)
 */
void SY185SDKSignOut(void);
/**
 * GM 功能初始化
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 */
void SY185SDKGMFunctionInit(const char * server_id, const char * server_name, const char * role_id, const char * role_name);



#endif /* SYGeneralInterface */





