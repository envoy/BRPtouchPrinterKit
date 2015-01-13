//*************************************************************************
//
//
//  ptdif.h ( P-Touch Data InterFace )
//
//
//*************************************************************************

#define CCHFORMNAME     32
#define CCHDEVICENAME   32

//
//	多重 include 防止
//
#ifndef __PTDIF__
#define __PTDIF__


//
//	C++ アプリから利用するための定義
//
#ifdef __cplusplus
extern "C"{
#endif

//
//	数値定義マクロ
//

#define SIZEDSPNUM			16			//

    
//
//	Paper Ability
//
#define PTPAPER_ABILITY_FREELENGTH			0x00000001	// 自由長用紙であることを示す。nTypeにより決められるものはこのフラグよりタイプの属性を重んじる。（読み込みモジュール側で調整する。）
#define PTPAPER_ABILITY_OUTPUTROTATE90		0x00000002	// 出力時に９０度回転する。
#define PTPAPER_ABILITY_FEEDCOMMAND			0x00000004	// フィードコマンド使用可能。nTypeにより決められるものはこのフラグよりタイプの属性を重んじる。（読み込みモジュール側で調整する。）
#define PTPAPER_ABILITY_MARU				0x00000008	// 丸い用紙・印字領域である
#define PTPAPER_ABILITY_WEARMASK			0x00000010	// マスクがある。
#define PTPAPER_ABILITY_SAMEWIDTHNOERROR	0x00000020	// 同じ幅ならエラーにならず出力できる。ＬＭでは、ピンオフセットも同じかを確認する。
#define PTPAPER_ABILITY_RDCPAPER			0x00000040	// 縮小用紙である。
#define PTPAPER_ABILITY_IGNORE_PAPER_TYPE		0x00000080	// 異なる用紙種類も互換性有りとする。//061208追加
#define PTPAPER_ABILITY_WIDTH_REVALUE			0x00000100	// 用紙幅のmmを常に切り上げる。3.4mm →4 (LMと本体でやり取りする数値に使用される)。//070122追加
#define PTPAPER_ABILITY_WIDTH_DEVALUE			0x00000200	// 用紙幅のmmを常に切り下げる。105.6mm → 105 (LMと本体でやり取りする数値に使用される)。//080717追加


////////////////////////////////////////////////////////////////////
//
//	F情報構造体定義
//
////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////
//	BKPOSATR
//////////////////////////////////////////////////
typedef union
{
	UCHAR byte;
	struct
	{
		UCHAR centering	: 1;			//
		UCHAR alignment	: 2;			//
		UCHAR dummy		: 5;			// dummy
	} bits;
} BKPOSATR;


//////////////////////////////////////////////////
//	MEDIAATRINFO
//////////////////////////////////////////////////
typedef union
{
	WORD word;
	struct
	{
		WORD rotate				: 4;	//
		WORD halfChar			: 1;	//
		WORD holeFreeLenMedia	: 1;	//
		WORD dummy				: 10;	// dummy
	} bits;
} MEDIAATRINFO;


//////////////////////////////////////////////////
//	PRESETBLKPOS
//////////////////////////////////////////////////
typedef struct
{
	BKPOSATR	posAtr;					//
	WORD		left;					//
	WORD		bottom;					//
	WORD		length;					//
	WORD		height;					//
} PRESETBLKPOS;


#pragma pack(1)	//090616:add//

//////////////////////////////////////////////////
//	PRESETBLKPOS1
//////////////////////////////////////////////////

typedef struct
{
	BKPOSATR	posAtr;					//
	WORD		left;					//
	WORD		bottom;					//
	WORD		length;					//
	WORD		height;					//
} PRESETBLKPOS1;

// SENSINFO構造体
typedef struct
{
	BYTE			sensorID;						//	センサ番号 0〜64
	unsigned char	energyRank;						//	エネルギーランク
	unsigned char	tapeWidMm;						//　テープ幅情報。単位ｍｍ（ＰＣ送信用）
	unsigned short	tapeLenMn;						//　ダイカットラベルテープ長。単位ｍｍ（ＰＣ送信用）
	unsigned char	rollWidMm;						//	ロール全幅情報。単位ｍｍ（モーター制御用）
	unsigned short	headDot;						//　印字可能領域の開始位置。単位dot(0-719)
	unsigned short	prtWidth;						//　印字領域幅。単位dot
	unsigned short	prtLength;						//　印字領域長さ。dot
	unsigned char	headDivide;						//	強制分割設定。0:なし、1:あり
	short			dieStartPlus;					//	ダイカットマーク検出から印刷開始までのパルス数 更にプラス分。マイナス方向の補正もあり
	short			dieStartRevPlus;				//	ダイカット 印刷前の逆転ドット数 補正量
	unsigned short	dieStartFwdPlus;				//	ダイカット 印刷前の正転から送りドット数 補正量
	short			afterFeedPlus;					//	印刷後後フィード量補正
	unsigned short	pafMediaID;						//	Pafデータでの媒体種類ＩＤ  (エディタ上でのＩＤ番号)
	PRESETBLKPOS1	blockPos1[1];					//	プリセットテンプレート ブロック配置情報 ブロックが１つのパターン
	PRESETBLKPOS1	blockPos2[2];					//	プリセットテンプレート ブロック配置情報 ブロックが２つのパターン
	PRESETBLKPOS1	blockPos3[3];					//	プリセットテンプレート ブロック配置情報 ブロックが３つのパターン
	unsigned char	sizeMM[SIZEDSPNUM];				//	プリセットテンプレート表示媒体名文字 mm
	unsigned char	sizeIN[SIZEDSPNUM];				//	プリセットテンプレート表示媒体名文字 in
	MEDIAATRINFO	charAtrInfo;					//	メディアに付随する属性指定情報(ローテート/半角/特殊メディア)
	unsigned short	lblPitchDot;					//　ラベルピッチ距離(ラベル先端から、次のラベルの先端までの距離)
	unsigned short	markNoChkValu;					//	ダイカット 印刷開始から黒マーク検出しない距離 補正値
	unsigned char	reserved[12];					//	予約領域

} SENSINFO_1;

////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
	}
#endif

#endif // __PTDIF__

