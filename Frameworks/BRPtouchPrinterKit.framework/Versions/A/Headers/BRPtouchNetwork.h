//
//  BRPtouchNetwork.h
//  BRPtouchPrinterKit
//
//  Created by BIL on 12/02/23.
//  Copyright (c) 2012 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "BRPtouchNetworkInfo.h"

//  Timeout Error
#define ERROR_TIMEOUT   -3

//  Return value
#define RET_FALSE       0
#define RET_TRUE        1

@protocol BRPtouchNetworkDelegate;

@class PLNetworkModule;

@interface BRPtouchNetwork : NSObject <NSNetServiceBrowserDelegate,NSNetServiceDelegate>
{
	id <BRPtouchNetworkDelegate> delegate;

	NSMutableArray*             _registeredPrinterNames;
	NSMutableArray*				aryListData;
    PLNetworkModule*            mPLNetworkModule;
    
    int                         nInfoIndex;     //  index of printer info
    NSTimer*                    tm;
	BOOL						bSearching;
	
	NSMutableArray*				aryBRPNetInfo;
}

@property(retain, nonatomic) NSMutableArray* registeredPrinterNames;


- (int)startSearch: (int)searchTime;
- (NSArray*)getPrinterNetInfo;

- (BOOL)setPrinterNames:(NSArray*)strPrinterNames;
- (BOOL)setPrinterName:(NSString*)strPrinterName;

- (id)initWithPrinterNames:(NSArray*)strPrinterNames;
- (id)initWithPrinterName:(NSString*)strPrinterName;

@property (nonatomic, assign) id <BRPtouchNetworkDelegate> delegate;

@end

@protocol BRPtouchNetworkDelegate <NSObject>

-(void) didFinishedSearch:(id)sender;

@end
