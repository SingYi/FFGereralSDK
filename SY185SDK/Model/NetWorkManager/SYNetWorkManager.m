//
//  SYNetWorkManager.m
//  SY185SDK
//
//  Created by 燚 on 2018/6/8.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "SYNetWorkManager.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
static void postRquesest(NSString *url, NSDictionary *params, SYRequestCompletion completion) {
    NSURLSession *session = [NSURLSession sharedSession];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]];
    if (params && params.count) {
        NSArray *arrKey = [params allKeys];
        NSMutableArray *pValues = [NSMutableArray array];
        for (id key in arrKey) {
            [pValues addObject:[NSString stringWithFormat:@"%@=%@",key,params[key]]];
        }
        NSString *strP = [pValues componentsJoinedByString:@"&"];
        [request setHTTPBody:[strP dataUsingEncoding:NSUTF8StringEncoding]];
    }
    request.timeoutInterval = 10.f;
    [request setHTTPMethod:@"POST"];
    NSURLSessionTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (error == nil) {
            NSError * fail = nil;
            id obj = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&fail];
            if (fail) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (completion) {
                        completion(@{@"msg":fail.localizedDescription},false);
                    }
                });
            } else {
                if (obj && [obj isKindOfClass:[NSDictionary class]]) {
                    dispatch_async(dispatch_get_main_queue(), ^{

                        NSString *status = obj[@"status"];
                        if (status.integerValue == 1) {
                            completion(obj,true);
                        } else {
                            completion(@{@"msg":obj[@"msg"]},false);
                        }
                    });
                } else {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        if (completion) {
                            completion(obj,false);
                        }
                    });
                }
            }
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (completion) {
                    completion(@{@"msg":error.localizedDescription},false);
                }
            });
        }
    }];
    [task resume];
}
#pragma clang diagnostic pop
