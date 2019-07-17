//
//  BLNetworkImp.h
//  Let
//
//  Created by junjie.zhu on 2016/11/17.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BLNetworkImp : NSObject

/**
 获取当前连接WiFi列表信息

 @return WiFi列表信息
 */
+ (NSArray *)getCurrentWifiList;

/**
 *  获取当前连接的Wi-Fi的SSID
 *
 *  @return SSID
 */
+ (NSString *)getCurrentSSIDInfo;

/**
 *  域名解析
 *
 *  @param host 域名
 *
 *  @return ip地址
 */
+ (NSString *)getIpAddrFromHost:(NSString *)host;


/**
 *  获取当前网关地址
 *
 *  @return address
 */
+ (NSString *)getCurrentGatewayAddress;

/**
 获取当前设备网络服务商
 
 @return 网络服务商
 */
+ (NSString *)getCurrentNetworkCarriername;


/**
 获取本机IPv4地址

 @param preferIPv4 获取IPv4地址
 @return IPv4地址
 */
+ (NSString *)getIPAddress:(BOOL)preferIPv4;

/**
 获取本机IP地址
 
 @return IP地址列表
 */
+ (NSDictionary *)getIPAddresses;

@end
