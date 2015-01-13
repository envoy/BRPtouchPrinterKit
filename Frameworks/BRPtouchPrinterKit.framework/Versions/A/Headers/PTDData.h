//////////////////////////////////////////////////////////////////////////
//
//	PTDData.h
//
//////////////////////////////////////////////////////////////////////////


//	Windows互換定義
#ifdef __LP64__
#define DWORD   unsigned int
#else
#define DWORD   unsigned long
#endif

#define BYTE    unsigned char
#define WORD    unsigned short
#define WCHAR   unichar
#define UCHAR   unsigned char

#include "ptdif.h"

#pragma pack (1)

/// ヘッダー構造体 ///
typedef struct
{
	DWORD		dwMark;					/* ファイルマーク				*/
	DWORD		dwPTDVersion;			/* PTD形式のバージョン			*/
	DWORD		dwPTDSize;				/* データ全体のサイズ			*/
	DWORD		dwPTDPaperInfoNum;		/* 用紙数						*/
	DWORD		dwModelInfoOffset;		/* ModelInfoのオフセット		*/
	DWORD		dwPaperInfoTopOffset;	/* 最初のPaperInfoのオフセット	*/
	DWORD		dwSourcePaperBlockSize;	/* PaperInfoのサイズ			*/
	DWORD		dwReserve;				/* 予備						*/
}PTDHEADER,* LPPTDHEADER;

/// 機種情報構造体 ///
#define PTD_MAX_RESOLUTION_PAIRS			5		// 最大解像度組数

typedef struct
{
	BYTE		bySeriesCode;					/* シリーズコード			*/
	BYTE		byModelCode;					/* モデルコード			*/
	WCHAR		dmDeviceName[CCHDEVICENAME];	/* 	デバイス名				*/
	DWORD		dwModelVersion;					/* プロダクトバージョン		*/
	DWORD		dwDeviceAbility01;				/* 機種のアビリティその１	*/
	DWORD		dwDeviceAbility02;				/* 機種のアビリティその２	*/
	DWORD		dwHeadPinNum;					/* ヘッドピン数			*/
	WORD		wMinCopies;						/* 最小コピー数			*/
	WORD		wMaxCopies;						/* 最大コピー数			*/
	WORD		wMinCutEveryNum;				/* 最小カットエブリー数		*/
	WORD		wMaxCutEveryNum;				/* 最大カットエブリー数		*/
	short		nDefaultPaperSize;				/* デフォルトの用紙ID		*/
	short		nDefaultPaperLength;			/* デフォルト用紙長さ1/10mm（デフォルトが自由長のときに使用する） */
	short		nDefaultPaperLengthRes;			/* デフォルト用紙長さdot（デフォルトが自由長のときに使用する） */
	WORD		wResolutionNum;					/* 解像度数				*/
	WORD		wResolutions[PTD_MAX_RESOLUTION_PAIRS * 2];	/* 解像度配列 */
    short       nDefaultResolution;             /* デフォルトの解像度 */
	short       nPTPaperResolution;             /* PTPAPER_INFOの解像度 */
	short       nDefaultPaperMargin;            /* デフォルトのマージン 1/10mm */
	short       nDefaultPaperMarginRes;         /* デフォルトのマージンdot（単位：dot） */
	short       nDefaultOrientation;            /* デフォルトの用紙方向 */
}PTDMODELINFO,* LPPTDMODELINFO;

/// 用紙情報構造体 ///
#define	PTD_MAX_COMPATIBLE_PAPER_SIZES		4		// 印刷を許可する他の用紙IDの最大登録数

typedef struct
{
	WCHAR		szPaperName_mm[CCHFORMNAME];				/* 用紙名:mm			*/
	WCHAR		szPaperName_inch[CCHFORMNAME];				/* 用紙名:インチ		*/
	WCHAR		szPaperWidthString_inch[CCHFORMNAME/2];		/* 用紙幅名:インチ		*/
	WCHAR		szPaperLengthString_inch[CCHFORMNAME/2];	/* 用紙長さ名:インチ	*/
	short		nType;					/* 用紙の種類						*/
	short		nPaperSize;				/* dmPaperSize					*/
	short		nPaperWidth;			/* dmPaperWidth					*/
	short		nImageAreaWidth;		/* 印字領域幅[1/10mm]				*/
	short		nPaperWidthRes;			/* 用紙幅[マスターユニット]			*/
	short		nImageAreaWidthRes;		/* 印字領域幅[マスターユニット]		*/
	short		nPaperLength;			/* 用紙長さ[1/10mm]				*/
	short		nImageAreaLength;		/* 印字領域長さ[マスターユニット]		*/
	short		nPaperLengthRes;		/* 用紙長さ[1/10mm]				*/
	short		nImageAreaLengthRes;	/* 印字領域長さ[マスターユニット]		*/
	short		nPhysicalOffsetX;		/* X方向オフセット[マスターユニット]	*/
	short		nPhysicalOffsetY;		/* Y方向オフセット[マスターユニット]	*/
	WORD		wPinOffsetLeft;			/* 左ピンオフセット					*/
	WORD		wPinOffsetRight;		/* 右ピンオフセット					*/
	short		nMaxFeed;				/* 最大フィード量					*/
	short		nMaxLength;				/* 最大長[1/10mm]					*/
	short		nMinLength;				/* 最小長[1/10mm]					*/
	WORD		wSplit;					/* スプリット数					*/
	short		nClipInfoLeft;			/* クリップマージン左				*/
	short		nClipInfoTop;			/* クリップマージン上				*/
	short		nClipInfoRight;			/* クリップマージン右				*/
	short		nClipInfoBottom;		/* クリップマージン下				*/
	short		nCompatiblePaperSizes[PTD_MAX_COMPATIBLE_PAPER_SIZES];	/* 他の用紙に印刷可能な用紙サイズを指定する */
	DWORD		dwPaperAbility01;		/* 用紙能力０１					*/
	DWORD		dwPaperAbility02;		/* 用紙能力０２					*/
	// ここから本体設定専用情報 //
	short		nSensorID;				/* センサID						*/
	BYTE		byEnergyRank;			/* エネルギーランク					*/
	BYTE		byRollWidMm;			/* ロール全幅情報。単位ｍｍ（モーター制御用）					*/
	BYTE		byHeadDivide;			/* 強制分割設定。0:なし、1:あり								*/
	short		nDieStartPlus;			/* ダイカットマーク検出から印刷開始までのパルス数 更にプラス分。マイナス方向の補正もあり */
	short		nDieStartRevPlus;		/* ダイカット 印刷前の逆転ドット数 補正量						*/
	WORD		wDieStartFwdPlus;		/* ダイカット 印刷前の正転から送りドット数 補正量					*/
	short		nAfterFeedPlus;			/* 印刷後後フィード量補正									*/
	WORD		wPafMediaID;			/* Pafデータでの媒体種類ＩＤ  (エディタ上でのＩＤ番号)			*/
	PRESETBLKPOS	PresetBlkPos1[1];	/* プリセットテンプレート ブロック配置情報 ブロックが１つのパターン	*/
	PRESETBLKPOS	PresetBlkPos2[2];	/* プリセットテンプレート ブロック配置情報 ブロックが２つのパターン	*/
	PRESETBLKPOS	PresetBlkPos3[3];	/* プリセットテンプレート ブロック配置情報 ブロックが３つのパターン	*/
	char		szSizeMM[SIZEDSPNUM];	/* プリセットテンプレート表示媒体名文字 mm						*/
	char		szSizeIN[SIZEDSPNUM];	/* プリセットテンプレート表示媒体名文字 in						*/
	MEDIAATRINFO	MediaAtrInfo;		/* メディアに付随する属性指定情報(ローテート/半角/特殊メディア)		*/

}PTDPAPERINFO,* LPPTDPAPERINFO;

/// 用紙追加情報構造体 ///  [070125]新規作成
typedef struct
{
	WORD			wLblPitchDot;							/* ラベルピッチ距離(ラベル先端から、次のラベルの先端までの距離) */
	WORD			wMarkNoChkValu;							/* ダイカット 印刷開始から黒マーク検出しない距離 補正値 */
	BYTE			byReserved[12];							/* 予約領域 */
}PTDPAPERADDINFO,* LPPTDPAPERADDINFO;

/// 用紙情報V11構造体 ///  [070125]新規作成
typedef struct
{	
	PTDPAPERINFO	Papers;				//	用紙
	PTDPAPERADDINFO	PapersAdd;			//	用紙追加情報
}PTDPAPERV11INFO,* LPPTDPAPERV11INFO;

/// [090610] PTDPAPERINFO の途中にいくつかのフィールドを追加：
typedef struct
{
	WCHAR		szPaperName_mm[CCHFORMNAME];				/* 用紙名:mm			*/
	WCHAR		szPaperName_inch[CCHFORMNAME];				/* 用紙名:インチ		*/
	WCHAR		szPaperWidthString_inch[CCHFORMNAME/2];		/* 用紙幅名:インチ		*/
	WCHAR		szPaperLengthString_inch[CCHFORMNAME/2];	/* 用紙長さ名:インチ	*/
	short		nType;					/* 用紙の種類						*/
	short		nPaperSize;				/* dmPaperSize					*/
	short		nPaperWidth;			/* dmPaperWidth					*/
	short		nImageAreaWidth;		/* 印字領域幅[1/10mm]				*/
	short		nPaperWidthRes;			/* 用紙幅[マスターユニット]			*/
	short		nImageAreaWidthRes;		/* 印字領域幅[マスターユニット]		*/
	short		nPaperLength;			/* 用紙長さ[1/10mm]				*/
	short		nImageAreaLength;		/* 印字領域長さ[マスターユニット]		*/
	short		nPaperLengthRes;		/* 用紙長さ[1/10mm]				*/
	short		nImageAreaLengthRes;	/* 印字領域長さ[マスターユニット]		*/
	short		nPhysicalOffsetX;		/* X方向オフセット[マスターユニット]	*/
	short		nPhysicalOffsetY;		/* Y方向オフセット[マスターユニット]	*/
	WORD		wPinOffsetLeft;			/* 左ピンオフセット					*/
	WORD		wPinOffsetRight;		/* 右ピンオフセット					*/
	short		nMaxFeed;				/* 最大フィード量					*/
	short		nMaxLength;				/* 最大長[1/10mm]					*/
	short		nMinLength;				/* 最小長[1/10mm]					*/
	WORD		wSplit;					/* スプリット数					*/
	short		nClipInfoLeft;			/* クリップマージン左				*/
	short		nClipInfoTop;			/* クリップマージン上				*/
	short		nClipInfoRight;			/* クリップマージン右				*/
	short		nClipInfoBottom;		/* クリップマージン下				*/
	short		nVirtualOffsetX;		// アプリ上仮想X方向オフセット[マスターユニット]
	short		nVirtualOffsetY;		// アプリ上仮想Y方向オフセット[マスターユニット]
	short		nCompatiblePaperSizes[PTD_MAX_COMPATIBLE_PAPER_SIZES];	/* 他の用紙に印刷可能な用紙サイズを指定する */
	DWORD		dwPaperAbility01;		/* 用紙能力０１					*/
	DWORD		dwPaperAbility02;		/* 用紙能力０２					*/
	BYTE		byReserved001[16];		// 予約領域
	// ここから本体設定専用情報 //
	short		nSensorID;				/* センサID										*/
	BYTE		byEnergyRank;			/* エネルギーランク									*/
	BYTE		byRollWidMm;			/* ロール全幅情報。単位ｍｍ（モーター制御用）			*/
	BYTE		byHeadDivide;			/* 強制分割設定。0:なし、1:あり						*/
	short		nDieStartPlus;			/* ダイカットマーク検出から印刷開始までのパルス数 更にプラス分。マイナス方向の補正もあり */
	short		nDieStartRevPlus;		/* ダイカット 印刷前の逆転ドット数 補正量				*/
	WORD		wDieStartFwdPlus;		/* ダイカット 印刷前の正転から送りドット数 補正量			*/
	short		nAfterFeedPlus;			/* 印刷後後フィード量補正							*/
	WORD		wPafMediaID;			/* Pafデータでの媒体種類ＩＤ  (エディタ上でのＩＤ番号)	*/
	PRESETBLKPOS	PresetBlkPos1[1];	/* プリセットテンプレート ブロック配置情報 ブロックが１つのパターン */
	PRESETBLKPOS	PresetBlkPos2[2];	/* プリセットテンプレート ブロック配置情報 ブロックが２つのパターン */
	PRESETBLKPOS	PresetBlkPos3[3];	/* プリセットテンプレート ブロック配置情報 ブロックが３つのパターン */
	char		szSizeMM[SIZEDSPNUM];	/* プリセットテンプレート表示媒体名文字 mm				*/
	char		szSizeIN[SIZEDSPNUM];	/* プリセットテンプレート表示媒体名文字 in				*/
	MEDIAATRINFO	MediaAtrInfo;		/* メディアに付随する属性指定情報(ローテート/半角/特殊メディア) */

}PTDPAPERINFO2,* LPPTDPAPERINFO2;

/// 用紙情報V12構造体 ///
typedef struct
{	
	PTDPAPERINFO2	Papers;				//	用紙
	PTDPAPERADDINFO	PapersAdd;			//	用紙追加情報
}PTDPAPERV12INFO,* LPPTDPAPERV12INFO;

#pragma pack ()
