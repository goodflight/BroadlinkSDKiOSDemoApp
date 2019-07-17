//
//  BLCaptchaInfo.h
//  AFNetworking
//
//  Created by hongkun.bai on 2019/6/5.
//

#import <Foundation/Foundation.h>
#import <BLLetBase/BLLetBase.h>
NS_ASSUME_NONNULL_BEGIN

@interface BLCaptchaInfoResult : BLBaseResult
@property (nonatomic, strong) NSString *captchaid;
@property (nonatomic, strong) NSString *captchaPNG;
@end

NS_ASSUME_NONNULL_END
