//
//  IRCodeModel.m
//  BLAPPSDKDemo
//
//  Created by admin on 2019/3/26.
//  Copyright © 2019 BroadLink. All rights reserved.
//

#import "IRCodeModel.h"

@implementation IRCodeModel

+ (NSDictionary *)BLS_modelCustomPropertyMapper {
    
    return @{
             @"name": @"version",
             @"modelId": @"versionid",
             };
}


@end
