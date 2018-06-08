//
//  SYGeneralInterface.h
//  SY185SDK
//
//  Created by 燚 on 2018/5/31.
//  Copyright © 2018年 Sans. All rights reserved.
//




#ifndef SYGeneralInterface_h
#define SYGeneralInterface_h

#include <stdio.h>
#include <stdbool.h>

#pragma mark - notice
/**
 * SDK debug 模式控制台开启打印信息(在初始化方法之前调用这个函数会开启在控制台打印相关信息,不调用此函数不会有打印信息.这个函数不会影响 SDK 接入,只是为了方便调试)
 */
void General185ShowDebugMessage(void);

///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function Pointer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化回调 Function Pointer
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 */
typedef void(*GeneralInitCallBack)(bool success, const char * message);
/**
 * SDK 支付回调 Function Pointer
 * @param success           是否成功
 * @param order_id          订单 id
 */
typedef void(*GeneralPayCallBack)(bool success, const char *order_id);
/**
 * SDK 登录回调 Function Pointer
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 * @param username          用户账号
 * @param token             账号 token
 */
typedef void(*GeneralLoginCallBack)(bool success, const char * message, const char * username, const char * token);
/**
 * SDK 登出回调 Function Pointer
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 */
typedef void(*GeneralLogoutCallBack)(const char * message);
/**
 * SDK GM发送道具回调 Function Pointer
 * @param success           是否成功
 * @param message           如果成功返回 NUll 失败则返回失败的信息
 * @param username          用户账号
 * @param token             账号 token
 */
typedef void(*GeneralLoginCallBack)(bool success, const char * message, const char * username, const char * token);


///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化接口
 * @param AppID             App 的 id
 * @param AppKey            App 的 key
 * @param callBackPointer     初始化成功后的回调block
 */
void GeneralInit(const char * AppID, const char * AppKey, bool useWindow, GeneralInitCallBack callBackPointer);
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
void GeneralPayStart(const char * server_id, const char * server_name, const char * role_id, const char * role_name, const char * product_id, const char * product_name, const char * amount, const char *extension, GeneralPayCallBack callBackPointer);
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 * @param callBackPointer     登录后的回调
 */
void GeneralShowLoginView(GeneralLoginCallBack callBackPointer);


#pragma mark - >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> no call back function
/**
 * SDK 退出登录接口(游戏中玩家点击退出游戏的时候请调用这个方法)
 */
void GeneralSignOut(void);
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< GM init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * GM 功能初始化
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 */
void GeneralGMFunctionInit(const char * server_id, const char * server_name, const char * role_id, const char * role_name);




#endif /* SYGeneralInterface */











