//
//  BRPtouchNetworkInfo.h
//  BRPtouchPrinterKit
//
//  Created by BIL on 12/02/23.
//  Copyright (c) 2012 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRPtouchNetworkInfo : NSObject
{
	NSString*	strIPAddress;
	NSString*	strLocation;
	NSString*	strModelName;
	NSString*	strSerialNumber;
	NSString*	strNodeName;
	NSString*	strMACAddress;
}

@property	(copy,nonatomic)NSString*	strIPAddress;
@property	(copy,nonatomic)NSString*	strLocation;
@property	(copy,nonatomic)NSString*	strModelName;
@property	(copy,nonatomic)NSString*	strSerialNumber;
@property	(copy,nonatomic)NSString*	strNodeName;
@property	(copy,nonatomic)NSString*	strMACAddress;

@end
