//
//  BRPtouchDevice.h
//  BRSearchModule
//
//  Copyright (c) 2017 Brother. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRPtouchDeviceInfo : NSObject

@property	(copy,nonatomic)NSString*	strIPAddress;
@property	(copy,nonatomic)NSString*	strLocation;
@property	(copy,nonatomic)NSString*	strModelName;
@property	(copy,nonatomic)NSString*	strPrinterName;
@property	(copy,nonatomic)NSString*	strSerialNumber;
@property	(copy,nonatomic)NSString*	strNodeName;
@property	(copy,nonatomic)NSString*	strMACAddress;

- (NSString *)description;

@end
