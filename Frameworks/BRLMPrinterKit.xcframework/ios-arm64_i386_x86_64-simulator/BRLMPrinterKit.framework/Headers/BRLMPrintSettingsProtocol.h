//
//  BRLMPrintSettings.h
//  BRLMPrinterKit
//
//  Copyright © 2020 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRLMPrinterDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BRLMPrintSettingsProtocol <NSObject>

+ (instancetype)new  __unavailable;
- (instancetype)init __unavailable;
- (instancetype)copy __unavailable;

@required
- (nullable instancetype)initDefaultPrintSettingsWithPrinterModel:(BRLMPrinterModel)model;

@end

NS_ASSUME_NONNULL_END
