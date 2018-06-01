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
    if (callBackBlock) {
        _callBackBlock = callBackBlock;
    } else {
        errorMessage("init call block not exist");
    }
    GeneralInit(AppID, AppKey, useWindow, Game185InitCallBack);
}










