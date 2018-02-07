//
//  BRPtouchPrinterData.h
//  BRPtouchPrinterKit
//
//  Copyright (c) 2017 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRPtouchPrinterData : NSObject
{
	NSArray*	aryPrinterList;
}

- (NSArray*)getPrinterList;

@end
