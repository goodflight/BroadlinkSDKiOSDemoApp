//
//  BLLocateInfo.h
//  AFNetworking
//
//  Created by hongkun.bai on 2019/6/5.
//

#import <Foundation/Foundation.h>
#import <BLLetBase/BLLetBase.h>
NS_ASSUME_NONNULL_BEGIN
@interface BLSubchild : NSObject
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *code;
@end

@interface BLChild : NSObject
@property (nonatomic, copy)           NSString *province;
@property (nonatomic, copy)           NSString *code;
@property (nonatomic, copy) NSArray<BLSubchild *> *subchildren;
@end

@interface BLDatum : NSObject
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *code;
@property (nonatomic, copy) NSArray<BLChild *> *children;
@end

@interface BLLocateInfoResult : BLBaseResult
@property (nonatomic, copy) NSArray<BLDatum *> *data;
@end


NS_ASSUME_NONNULL_END
