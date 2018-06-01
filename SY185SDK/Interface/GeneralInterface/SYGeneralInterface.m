//
//  SYGeneralInterface.m
//  SY185SDK
//
//  Created by 燚 on 2018/5/31.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "SYGeneralInterface.h"
#import <Foundation/Foundation.h>


///<<<<<<<<<<<<<<<<<<<<<<<<<<<< Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * SDK 初始化接口
 * @param AppID             App 的 id
 * @param AppKey            App 的 key
 * @param callBackPointer     初始化成功后的回调block
 */
void GeneralInit(const char * AppID, const char * AppKey, bool useWindow, GeneralInitCallBack callBackPointer) {
    NSLog(@"general init == appid -> %s appkey -> %s",AppID,AppKey);
    if (callBackPointer) {
        callBackPointer(true,"general init call back");
    }
}
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
void General185SignOut(void);
///<<<<<<<<<<<<<<<<<<<<<<<<<<<< GM init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
/**
 * GM 功能初始化
 * @param server_id         服务器 id
 * @param server_name       服务器名称
 * @param role_id           角色 id
 * @param role_name         角色名称
 */
void GeneralGMFunctionInit(const char * server_id, const char * server_name, const char * role_id, const char * role_name);









