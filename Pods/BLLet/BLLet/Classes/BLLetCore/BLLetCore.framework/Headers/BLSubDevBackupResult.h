//
//  BLSubDevBackupResult.h
//  BLLetCore
//
//  Created by admin on 2019/4/15.
//  Copyright © 2019 朱俊杰. All rights reserved.
//

#import <BLLetBase/BLLetBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface BLSubSevBackupInfo : NSObject

@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, copy) NSString *session;
@property (nonatomic, copy) NSString *sharedkey;

@end

@interface BLSubDevBackupResult : BLBaseResult

@property (nonatomic, assign) NSInteger total;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, copy) NSArray *list;

@end

NS_ASSUME_NONNULL_END
