//
//  BRPtouchPrinter.h
//  BRPtouchPrinterKit
//
//  Created by BIL on 12/02/03.
//  Copyright (c) 2012 Brother Industries, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#include "BRPtouchPrintInfo.h"
#include "BRPtouchPrinterData.h"

#import "PTDData.h"
#import "BrPtPJ673_def.h"

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

//  Timeout Error
#define ERROR_TIMEOUT		-3		//	通信タイムアウト
#define ERROR_BADPAPERRES	-4		//	用紙情報（PTD）が不正、読み込めない、または用紙指定がおかしい
#define ERROR_BADENCRYPT	-5		//	暗号化指定なのに暗号化キーが指定されていない
#define ERROR_IMAGELARGE	-6		//	イメージが用紙サイズよりも大きい
#define ERROR_CREATESTREAM	-7		//	ストリームの作成に失敗
#define ERROR_OPENSTREAM	-8		//	ストリームのオープンに失敗
#define ERROR_FILENOTEXIST  -9      //  印刷対象のファイルが存在しない
#define ERROR_PAGERANGEERROR  -10      //  指定するページが正しくない

//  Return value
#define RET_FALSE       0
#define RET_TRUE        1

//
typedef struct _PTSTATUSINFO {
	Byte	byHead;						// ヘッドマーク
	Byte	bySize;						// サイズ
	Byte	byBrotherCode;				// ブラザーコード
	Byte	bySeriesCode;				// シリーズコード
	Byte	byModelCode;				// 機種コード
	Byte	byNationCode;				// 国別コード
	Byte	byFiller;					// カバー情報
	Byte	byFiller2;					// 未使用
	Byte	byErrorInf;					// エラー情報
	Byte	byErrorInf2;				// エラー情報２
	Byte	byMediaWidth;				// メディア幅
	Byte	byMediaType;				// メディア種類
	Byte	byColorNum;					// 色数
	Byte	byFont;						// フォント
	Byte	byJapanesFont;				// 日本語フォント
	Byte	byMode;						// モード
	Byte	byDensity;					// 濃度
	Byte	byMediaLength;				// メディア長さ
	Byte	byStatusType;				// ステータス種類
	Byte	byPhaseType;				// フェーズ種類
	Byte	byPhaseNoHi;				// フェーズ番号上位バイト
	Byte	byPhaseNoLow;				// フェーズ番号下位バイト
	Byte	byNoticeNo;					// 通知番号
	Byte	byExtByteNum;				// 拡張部バイト数
    Byte	byLabelColor;				// テープ色情報
	Byte	byFontColor;				// 文字色情報
	Byte	byHardWareSetting[4];		// ハードウェア設定
    Byte	byNoUse[2];                 // 未使用
} PTSTATUSINFO, *LPPTSTATUSINFO;

typedef enum {
    DEFAULT_SERIES,
    PT_SERIES,
    QL_SERIES
} PRINTER_SERIES;

typedef enum {
    TYPE_DEFAULT,
    TYPE_G,
    TYPE_g
} RASTER_GRAPHIC_TYPE;
PRINTER_SERIES      printerSeries;
RASTER_GRAPHIC_TYPE rasterGraphicType;
@interface BRPtouchPrinter : NSObject <NSNetServiceBrowserDelegate,NSNetServiceDelegate>
{	
	NSMutableString*		strIPAddress;

	NSMutableString*		strPrinterName;
	
	NSMutableString*		strEncryptKey;
	NSMutableString*		strEncryptKeyEx;
	
	BOOL					bPrintInfo;
	BOOL					bCustom;
	
	BRPtouchPrintInfo*		ppi;				//	印刷情報クラス
	
    NSMutableArray*			aryPaperMM;					//  すべてを含む全用紙リスト(mm)
    NSMutableArray*			aryPaperNoSplitMM;			//  スプリットを省いた用紙リスト(mm)
	NSMutableArray*			aryPaperNoDiaMM;			//	Diaを省いた用紙リスト(mm)
	NSMutableArray*			aryPaperNoSplitNoDiaMM;		//	スプリットとDiaを省いた用紙リスト(mm)
    NSMutableArray*			aryPaperIN;					//  スプリットを含む全用紙リスト(inch)
    NSMutableArray*			aryPaperNoSplitIN;			//  スプリットを省いた用紙リスト(inch)
	NSMutableArray*			aryPaperNoDiaIN;			//	Diaを省いた用紙リスト(inch)
	NSMutableArray*			aryPaperNoSplitNoDiaIN;		//	スプリットとDiaを省いた用紙リスト(inch)
    NSDictionary*			dictPrinterInfo;			//  プリンタ名とPTDファイル名

    LPPTDHEADER				pptdHeader;
    LPPTDMODELINFO			pptdModelInfo;
    LPPTDPAPERINFO			pptdPaperInfo;
    LPPTDPAPERINFO2			pptdPaperInfo2;
    LPPTDPAPERADDINFO		pptdPaperAddInfo;

    int                 nPrintDataSize;
    void*               pPrintData;
	
	SENSINFO_1			sinfo;
	
    NSInputStream*		iStreamEz;
    NSOutputStream*		oStreamEz;
	BOOL				bStreamEz;

    int                 modelInfo;

}

- (void)setIPAddress:(NSString*)strIP;
- (int)sendFile:(NSString*)filePath timeout:(int)nTimeout;
- (int)sendData:(NSData*)data timeout:(int)nTimeout;

- (int)sendFileEx:(NSString*)strFile timeout:(int)nTimeout;
- (int)sendDataEx:(NSData*)dataData timeout:(int)nTimeout;
- (id)initWithPrinterName:(NSString*)strPrinterName;
- (BOOL)setPrinterName:(NSString*)strPrinterName;
- (BOOL)isPrinterReady;
- (int)getPTStatus:(PTSTATUSINFO*)status;
- (int)printImage:(CGImageRef)imageRef copy:(int)nCopy timeout:(int)nTimeout;
- (int)printPDFAtPath:(NSString *)pdfPath pages:(NSUInteger [])indexes length:(NSUInteger)length copy:(int)nCopy timeout:(int)nTimeout;
- (int)setPrintInfo:(BRPtouchPrintInfo*)printInfo;
- (BOOL)setCustomPaperFile:(NSString*)strFilePath;
- (BOOL)setEncryptKey:(NSString*)strKey keyEx:(NSString*)strKeyEx;

- (int)startPrint;
- (void)endPrint;

@end
