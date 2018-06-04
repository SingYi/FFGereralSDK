//
//  ViewController.m
//  SDKTest
//
//  Created by 燚 on 2018/5/31.
//  Copyright © 2018年 Sans. All rights reserved.
//

#import "ViewController.h"
#import "SY185SDK.h"

@interface ViewController ()

@end

@implementation ViewController

void initCallBack(bool success, const char * message) {
    NSLog(@"init call back pointer -> %s",message);
}

void payCallBack(BOOL success, const char * rold_id) {
    NSLog(@"pay call back pointer -> %s",rold_id);
}



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    /** 初始化 */
    SY185SDKInitSDKWithPointer("123", "321", true, initCallBack);
    SY185SDKInitSDKWithBlock("123", "321", true, ^(bool success, const char *message) {
        NSLog(@"init call back block -> %s", message);
    });

    /** 发起支付 */
    SY185SDKPayStart("1", "1", "1", "1", "1", "1", "1", "1", payCallBack);



}





@end













