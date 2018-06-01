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

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    Game185InitSDKWithBlock("123", "234", true, ^(bool success, const char *message) {
        NSLog(@"%s -> %s",message,__func__);
    });

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
