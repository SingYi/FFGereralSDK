//
//  SYLogModel.m
//  SY185SDK
//
//  Created by 燚 on 2018/6/1.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "SYLogModel.h"
#import "SDKModel.h"
#import <Foundation/Foundation.h>

NSString *gameDateString(void);

void errorMessage(char * message) {
    NSString *messageString = [NSString stringWithFormat:@"SY_185_SDK|%@|: %s",gameDateString(),message];
    printf("%s \n",[messageString UTF8String]);
}

void showMessage(void * message) {
    if (![SDKModel sharedModel].showMessage) {
        return;
    }
    NSString *messageString = [NSString stringWithFormat:@"SY_185_SDK|%@|: %s",gameDateString(),message];
    printf("%s \n",[messageString UTF8String]);
}


NSString *gameDateString(void) {
    NSDateFormatter *formatter = [NSDateFormatter new];
    formatter.dateFormat = @"YYYY-MM-dd hh:mm ss.SSS";
    NSString *timeString = [formatter stringFromDate:[NSDate date]];
    return timeString;
}







