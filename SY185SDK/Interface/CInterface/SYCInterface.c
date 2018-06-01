//
//  SYCInterface.m
//  SY185SDK
//
//  Created by 燚 on 2018/6/1.
//  Copyright © 2018年 Sans. All rights reserved.
//

#include "SYCInterface.h"
#include "SYGeneralInterface.h"

static InitCallBackBlock _callBackBlock = NULL;

void Game185InitCallBack(bool success, const char * message) {
    if (_callBackBlock) {
        _callBackBlock(success, message);
    }
}

void Game185InitSDKWithBlock(const char * AppID, const char * AppKey, bool useWindow, InitCallBackBlock callBackBlock) {
    void *p = Game185InitCallBack;
    if (callBackBlock) {
        _callBackBlock = callBackBlock;
    }
    GeneralInit(AppID, AppKey, useWindow, p);
}
