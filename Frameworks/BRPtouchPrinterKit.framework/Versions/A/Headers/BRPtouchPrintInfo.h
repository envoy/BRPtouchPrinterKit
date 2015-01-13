//
//  BRPtouchPrintInfo.h
//  BRPtouchPrinterKit
//
//  Created by BIL on 12/06/26.
//  Copyright (c) 2012 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#define OPTION_AUTOCUT		0x00000001
#define OPTION_CUTATEND		0x00000002

#define PRINT_ORIGINAL		0x00
#define PRINT_FIT			0x01

#define ORI_LANDSCAPE		0x00
#define ORI_PORTRATE		0x01

//  二値化形式フラグ
#define HALFTONE_BINARY    0x00
#define HALFTONE_DITHER    0x01
#define HALFTONE_ERRDIF    0x02

#define ALIGN_LEFT			0x00
#define ALIGN_CENTER		0x01
#define ALIGN_RIGHT			0x02

#define ALIGN_TOP			0x00
#define ALIGN_MIDDLE		0x01
#define ALIGN_BOTTOM		0x02

#define PAPERALIGN_LEFT		0x00
#define PAPERALIGN_CENTER	0x01

#define RET_ERR_PAPERNAME		-1
#define RET_ERR_OPTION			-2
#define RET_ERR_DENSITY			-3
#define RET_ERR_PRINTMODE		-4
#define RET_ERR_ORIENTATION		-5
#define RET_ERR_HALFTONE		-6
#define RET_ERR_HORIZONTAL		-7
#define RET_ERR_VERTICAL		-8
#define RET_ERR_PAPERALIGN		-9
#define RET_ERR_EXTFLAG			-10


//  各種モード設定フラグ
#define FLAG_M_AUTOCUT  0x40
#define FLAG_M_MIRROR   0x80

//  拡張モード設定フラグ
#define FLAG_K_DRAFT    0x01
#define FLAG_K_HALFCUT  0x04
#define FLAG_K_NOCHAIN  0x08
#define FLAG_K_SPTAPE   0x10
#define FLAG_K_AFTERCUT 0x20
#define FLAG_K_HGPRINT  0x40
#define FLAG_K_COPY     0x80

//  印刷情報指令フラグ
#define FLAG_PI_KIND    0x02
#define FLAG_PI_WIDTH   0x04
#define FLAG_PI_LENGTH  0x08
#define FLAU_PI_RECOVER 0x80

//  二値化形式フラグ
#define HALFTONE_BINARY    0x00
#define HALFTONE_DITHER    0x01
#define HALFTONE_ERRDIF    0x02

//　圧縮モードフラグ
#define COMPRESS_ID         0x4D
#define COMPRESS_DISABLED   0x00
#define COMPRESS_PRESERVED  0x01
#define COMPRESS_ENABLED    0x02

@interface BRPtouchPrintInfo : NSObject
{
	NSString*		strPaperName;
	unsigned long	ulOption;
	int				nPrintMode;
	int				nDensity;
	int				nOrientation;
	int				nHalftone;
	int				nHorizontalAlign;
	int				nVerticalAlign;
	int				nPaperAlign;
	int				nExtFlag;
	int				nAutoCutFlag;
	int				nAutoCutCopies;
    int             nExMode;
}

@property	(retain,nonatomic)NSString*			strPaperName;
@property	(assign,nonatomic)unsigned long		ulOption;
@property	(assign,nonatomic)int				nPrintMode;
@property	(assign,nonatomic)int				nDensity;
@property	(assign,nonatomic)int				nOrientation;
@property	(assign,nonatomic)int				nHalftone;
@property	(assign,nonatomic)int				nHorizontalAlign;
@property	(assign,nonatomic)int				nVerticalAlign;
@property	(assign,nonatomic)int				nPaperAlign;
@property	(assign,nonatomic)int				nExtFlag;
@property	(assign,nonatomic)int				nAutoCutFlag;
@property	(assign,nonatomic)int				nAutoCutCopies;
@property	(assign,nonatomic)int				nExMode;

@end
