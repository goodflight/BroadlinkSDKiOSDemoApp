//
//  BLQueryDeviceConnectServerResult.h
//  BLLetCore
//
//  Created by admin on 2019/4/15.
//  Copyright © 2019 朱俊杰. All rights reserved.
//

#import <BLLetBase/BLLetBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface BLServerBean : NSObject

@property (nonatomic, copy) NSString *host;
@property (nonatomic, copy) NSString *ip;

@end

@interface BLQueryDeviceConnectServerResult : BLBaseResult

@property (nonatomic, copy) NSArray<BLServerBean *> *serverlist;

@end

NS_ASSUME_NONNULL_END
