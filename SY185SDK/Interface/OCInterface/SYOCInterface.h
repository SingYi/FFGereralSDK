//
//  SYOCInterface.h
//  SY185SDK
//
//  Created by 燚 on 2018/6/1.
//  Copyright © 2018年 Sans. All rights reserved.
//


/**
 * 注 : 这些方法在自定义类的实例中调用时候,
 *      请确保实例的内存常驻没有释放.
 *      否则可能会因为ARC机制自动释放内存而无法接收到回调
 *
 *      该头文件中封装了两中方式调用 SDK 获取回调方式,
 *      只需调用一种法法即可
 */


#import <Foundation/Foundation.h>

#pragma mark - call back delegate
@protocol SY185SDKDelegate <NSObject>
/**
 *  SDK初始化回调:
 *  初始化成功后可以掉起登录页面,否则无法掉起登录页面;
 */
- (void)m185SDKInitCallBackWithSuccess:(BOOL)success
                       withInformation:(NSDictionary *_Nonnull)dict;
/**
 *  登录的回调:
 *  成功: success 返回 true,dict 里返回 username 和 userToken
 *  失败: success 返回 false,dict 里返回 error message
 */
- (void)m185SDKLoginCallBackWithSuccess:(BOOL)success
                        withInformation:(NSDictionary * _Nonnull )dict;
/**
 *  登出的回调:
 *  这个回调是从 SDK 登出的回调
 */
- (void)m185SDKLogOutCallBackWithSuccess:(BOOL)success
                         withInformation:(NSDictionary * _Nullable )dict;
/**
 *  充值回调
 */
- (void)m185SDKRechargeCallBackWithSuccess:(BOOL)success
                           withInformation:(NSDictionary * _Nonnull )dict;
/**
 *  GM 权限发送道具成功回调
 */
- (void)m185SDKGMSendPropsCallBackWithSuccess:(BOOL)success
                              withInformation:(NSDictionary * _Nonnull )dict;
@end


#pragma mark - call back block
/** 初始化回调 block */
typedef void(^SDKInitCallBackBlock)(BOOL success, NSDictionary * _Nullable content);
/** 支付回调 block */
typedef void(^SDKPayCallBackBLock)(BOOL success, NSDictionary * _Nullable content);
/** 登录回调 block */
typedef void(^SDKLoginCallBackBlock)(BOOL success, NSDictionary * _Nullable content);
/** GM 权限发送道具回调 */
typedef void(^SDKGMSendPropsCallBackBlock)(BOOL success, NSDictionary * _Nullable content);


@interface SY185SDK : NSObject

#pragma mark - notice
/**
 * SDK debug 模式控制台开启打印信息(在初始化方法之前调用这个函数会开启在控制台打印相关信息,不调用此函数不会有打印信息.这个函数不会影响 SDK 接入,只是为了方便调试)
 */
+ (void)SY185SDKShowMessage;

#pragma mark - block method
/**
 * SDK 初始化接口
 * @param appID             App 的 id
 * @param appKey            App 的 key
 * @param callBackBlock     初始化成功后的回调block
 */
+ (void)InitWithAppID:(NSString * _Nonnull )appID
               AppKey:(NSString * _Nonnull )appKey
            UseWindow:(BOOL)useWindow
        CallBackBlock:(SDKInitCallBackBlock _Nonnull)callBackBlock;
/**
 * SDK 发起支付接口
 * @param serverID          服务器 id
 * @param serverName        服务器名称
 * @param roleID            角色 id
 * @param roleName          角色名称
 * @param productID         产品 id
 * @param productName       产品名称
 * @param amount            金额 -> 单位 RMB(元) <最小充值金额 1 元 -> amount >= 1>
 * @param extension         拓展字段
 * @param callBackBlock     支付的回调 block
 */
+ (void)payStartWithServerID:(NSString * _Nonnull )serverID
                  ServerName:(NSString * _Nonnull )serverName
                      RoleID:(NSString * _Nonnull )roleID
                    RoleName:(NSString * _Nonnull )roleName
                   ProductID:(NSString * _Nonnull )productID
                 ProductName:(NSString * _Nonnull )productName
                      Amount:(NSString * _Nonnull )amount
                   Extension:(NSString * _Nullable )extension
               CallBackBlock:(SDKPayCallBackBLock _Nonnull )callBackBlock;
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 * @param callBackBlock     登录后的回调
 */
+ (BOOL)showLoginViewWithCallBackBlock:(SDKLoginCallBackBlock _Nonnull )callBackBlock;
/**
 * GM 功能初始化
 * @param serverID          服务器 id
 * @param serverName        服务器名称
 * @param roleID            角色 id
 * @param roleName          角色名称
 * @param callBackBlock     发送道具回调
 */
+ (void)initGMFunctionWithServerid:(NSString * _Nonnull )serverID
                        ServerName:(NSString * _Nonnull )serverName
                            RoleID:(NSString * _Nonnull )roleID
                          RoleName:(NSString * _Nonnull )roleName
                     CallBackBlock:(SDKGMSendPropsCallBackBlock _Nonnull )callBackBlock;

#pragma mark - delegate method
/**
 * SDK 初始化接口
 * @param appID             App 的 id
 * @param appKey            App 的 key
 * @param delegate          回调的 delegate, 如果使用 delegate, delegate 只需要在初始化的时候设置一次
 */
+ (void)InitWithAppID:(NSString * _Nonnull )appID
               AppKey:(NSString * _Nonnull )appKey
            UseWindow:(BOOL)useWindow
             Delegate:(id<SY185SDKDelegate> _Nonnull)delegate;
/**
 * SDK 发起支付接口
 * @param serverID          服务器 id
 * @param serverName        服务器名称
 * @param roleID            角色 id
 * @param roleName          角色名称
 * @param productID         产品 id
 * @param productName       产品名称
 * @param amount            金额 -> 单位 RMB(元) <最小充值金额 1 元 -> amount >= 1>
 * @param extension         拓展字段
 */
+ (void)payStartWithServerID:(NSString * _Nonnull )serverID
                  ServerName:(NSString * _Nonnull )serverName
                      RoleID:(NSString * _Nonnull )roleID
                    RoleName:(NSString * _Nonnull )roleName
                   ProductID:(NSString * _Nonnull )productID
                 ProductName:(NSString * _Nonnull )productName
                      Amount:(NSString * _Nonnull )amount
                   Extension:(NSString * _Nullable )extension;
/**
 * SDK 加载登录页面接口(请在初始化成功之后调用这个函数)
 */
+ (BOOL)showLoginView;
/**
 * GM 功能初始化
 * @param serverID          服务器 id
 * @param serverName        服务器名称
 * @param roleID            角色 id
 * @param roleName          角色名称
 */
+ (void)initGMFunctionWithServerid:(NSString * _Nonnull )serverID
                        ServerName:(NSString * _Nonnull )serverName
                            RoleID:(NSString * _Nonnull )roleID
                          RoleName:(NSString * _Nonnull )roleName;

#pragma mark - NO call back method
/** 登出 */
+ (void)signOut;







@end
