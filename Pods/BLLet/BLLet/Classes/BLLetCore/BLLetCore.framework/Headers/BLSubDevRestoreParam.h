//
//  BLSubDevRestoreParam.h
//  BLLetCore
//
//  Created by admin on 2019/4/15.
//  Copyright © 2019 朱俊杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLSubDevBackupResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface BLSubDevRestoreParam : NSObject

/**
 * 待还原的子设备总数目
 **/
@property (nonatomic, assign) NSInteger total;
/**
 * 当前分页请求的子设备开始序号
 **/
@property (nonatomic, assign) NSInteger index;
/**
 * 还原操作事务ID
 **/
@property (nonatomic, assign) NSInteger msgid;
/**
 * 子设备信息列表
 **/
@property (nonatomic, copy) NSArray *list;

@end

NS_ASSUME_NONNULL_END
