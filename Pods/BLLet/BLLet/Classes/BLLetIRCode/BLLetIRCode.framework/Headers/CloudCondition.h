//
//  CloudCondition.h
//  CloudCondition
//
//  Created by yzm157 on 14/11/12.
//  Copyright (c) 2014年 Broadlink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/*空调开关状态*/
typedef NS_ENUM(NSUInteger, AC_SWITCH_STATE_E) {
    AC_STATE_CLOSE, /*关闭*/
    AC_STATE_OPEN   /*开启*/
};

/*空调模式*/
typedef NS_ENUM(NSUInteger, AC_MODE_TYPE_E) {
    AC_MODE_AUTO,       /*自动*/
    AC_MODE_COOL,       /*制冷*/
    AC_MODE_HUMIDITY,   /*除湿*/
    AC_MODE_WIND,       /*通风*/
    AC_MODE_HEAT        /*加热*/
};

/*空调风速*/
typedef NS_ENUM(NSUInteger, AC_WIND_SPEED_E) {
    AC_SPEED_AUTO,      /*自动*/
    AC_SPEED_LOW,       /*低速*/
    AC_SPEED_MID,       /*中速*/
    AC_SPEED_HIGH       /*高速*/
};

/*按键类型*/
typedef NS_ENUM(NSUInteger, AC_KEY_E) {
    AC_KEY_SWITCH,      /*开关键*/
    AC_KEY_MODE,        /*模式键*/
    AC_KEY_TEMP_ADD,    /*温度加键*/
    AC_KEY_TEMP_SUB,    /*温度减键*/
    AC_KEY_WIND_SPPED   /*风速键*/
};

@interface CloudCondition : NSObject

//26007600620001271031101010101010101010101010101010101031101010101031101010101010103110311031103110101010103110311031101010101010101010101010101010101010101010101031101010101031103110101031103110101010101010101010101010101010103110311031103110C5
/*云空调匹配,匹配到数据之后根据返回的url下载文件至本地*/
/*Return:
 {
    "code"  :   "0",
    "msg"   :   "success",
    "match" :   [
                    {
                        "name"          :   "海尔空调_1000",
                        "download_url"  :   "http://www.broadlink.com.cn"
                    },
                    {
                        "name"          :   "格力空调_001",
                        "download_url"  :   "http://www.broadlink.com.cn"
                    }
                ]
 
 }
 */
- (NSDictionary *)matchCode:(NSString *)code;

/*传入文件的保存地址，并获取空调信息*/
/*Return:
 {
    "code"  :   "0",
    "msg"   :   "success",
    "info"  :
                {
                    "name"          :   "海尔空调_1000",        //空调名称及云代码
                    "temperature"   :   [16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30],   //支持的温度值
                    "status"        :   [0, 1],                 //支持的状态值
                    "mode"          :   [0, 1, 2, 3, 4],        //支持的模式值
                    "windspeed"     :   [1, 2, 3]               //支持的风速值
                }
 }
 */
- (NSDictionary *)getACInfoWithFilePath:(NSString *)path;

/*传入文件的保存地址,获取指定开关状态，模式，风速，温度值下的数据*/
/*Return:
 {
    "code"  :   "0",
    "msg"   :   "success",
    "data"  :   "*******************************"
 }
 */
- (NSDictionary *)getCodeWithFilePath:(NSString *)path state:(AC_SWITCH_STATE_E)state mode:(AC_MODE_TYPE_E)mode speed:(AC_WIND_SPEED_E)speed key:(AC_KEY_E)key temperature:(int)temp;

@end
