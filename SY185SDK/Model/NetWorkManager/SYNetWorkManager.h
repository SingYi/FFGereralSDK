//
//  SYNetWorkManager.h
//  SY185SDK
//
//  Created by 燚 on 2018/6/8.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Call_back NSDictionary *content, BOOL success
#define Call_back_messsage content,success

typedef void(^SYRequestCompletionBlock)(NSDictionary *dcit, BOOL success);
typedef void(*SYRequestCompletion)(NSDictionary *dict, BOOL success);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wundefined-internal"
static void postRquesest(NSString *url, NSDictionary *params, SYRequestCompletion completion);
#pragma clang diagnostic pop







