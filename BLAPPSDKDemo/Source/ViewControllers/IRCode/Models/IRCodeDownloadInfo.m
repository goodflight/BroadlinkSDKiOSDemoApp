//
//  IRCodeDownloadInfo.m
//  BLAPPSDKDemo
//
//  Created by admin on 2019/3/26.
//  Copyright © 2019 BroadLink. All rights reserved.
//

#import "IRCodeDownloadInfo.h"

@implementation IRCodeDownloadInfo

+ (NSDictionary *)BLS_modelCustomPropertyMapper {
    
    return @{
             @"key": @[@"randkey", @"fixkey"],
             @"ircodeid": @[@"ircodeid", @"fixedId"],
             };
}



@end
