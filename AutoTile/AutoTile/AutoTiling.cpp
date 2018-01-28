// 作成日：2016.12.12
// 作成者：柏
// 作成内容：AutoTile
// 最後修正：2016.12.22
// 修正内容：SourceMonitorによる改善

#include "AutoTiling.h"
#include "Parameter.h"
#include "Input.h"
#include <DxLib.h>
#include "eTile.h"

//コンストラクタ、四分割されたタイルカットを指定用offset初期化
AutoTiling::AutoTiling():tileSize(Parameter::TileSize) {
	offset[0] = Vector2<float>(0.0f	, 0.0f);	//TopLeft
	offset[1] = Vector2<float>(0.5f , 0.0f);	//TopRight
	offset[2] = Vector2<float>(0.0f	, 0.5f);	//BottomLeft
	offset[3] = Vector2<float>(0.5f	, 0.5f);	//BottomRight
}

AutoTiling::~AutoTiling() {
}

//初期化
void AutoTiling::Initialize() {
	LoadDivGraph("MapChip2.png", 24, 2, 12, Parameter::TileSize / 2, Parameter::TileSize / 2, &tileRectMap[0]);
	InitiliazeMapData();
}

//更新
void AutoTiling::Update() {
	WriteTerrain();
	SetMapData();
}

// 描画
void AutoTiling::Draw() {
	for (int y = 0; y < mapData.size(); y++) {
		for (int x = 0; x < mapData[0].size(); x++) {
			DrawTiles(x, y);
		}
	}
}

// タイルずつ描画
// <param name="x">マップチップのＸ座標</param>
// <param name="y">マップチップのＹ座標</param>
void AutoTiling::DrawTiles(int x, int y) {
	if (!IsTile(x, y)) { return; }
	int tSize = Parameter::TileSize;

	for (int i = 0; i < 4; i++) {
		DrawGraph((x + offset[i].X) * tSize, (y + offset[i].Y) * tSize, tilesData[y][x].GetTileData((eTile)i), TRUE);
	}
}

// クリック操作によってタイルを描画
void AutoTiling::WriteTerrain() {
	Vector2<int> mouseCoord = Input::GetMousePosition() / Vector2<int>(Parameter::TileSize, Parameter::TileSize);
	int mouseY = mouseCoord.Y;
	int mouseX = mouseCoord.X;
	if (!IsInField(mouseX, mouseY)) { return; }
	if (Input::IsLeftClick()) {
		if (IsTile(mouseX, mouseY)) { return; }
		mapData[mouseY][mouseX] = true;
	}
	if (Input::IsRightClick()) {
		if (!IsTile(mouseX, mouseY)) { return; }
		mapData[mouseY][mouseX] = false;
		ClearDrawScreen();
	}
}


// マップに計算済みのタイルを設置
void AutoTiling::SetMapData() {
	for (int y = 0; y < mapData.size(); y++) {
		for (int x = 0; x < mapData[0].size(); x++) {
			GirthState gs = GetGirthState(x, y);
			SetTile(gs, x, y);
		}
	}
}

/* <summary>
タイルの情報をチェックし、設定
<param name="gs">周りマスの情報</param>
<param name="x">マップチップのＸ座標</param>
<param name="y">マップチップのＹ座標</param>*/
void AutoTiling::SetTile(GirthState gs, int x, int y) {
	eImageType l_top = CheckTileType(gs, eGirth::TOP, eGirth::LEFT);
	eImageType r_top = CheckTileType(gs, eGirth::TOP, eGirth::RIGHT);
	eImageType l_bottom = CheckTileType(gs, eGirth::BOTTOM, eGirth::LEFT);
	eImageType r_bottom = CheckTileType(gs, eGirth::BOTTOM, eGirth::RIGHT);

	tilesData[y][x].SetTile(eTile::LEFT_TOP, GetImageHandle(eTile::LEFT_TOP, l_top));
	tilesData[y][x].SetTile(eTile::RIGHT_TOP, GetImageHandle(eTile::RIGHT_TOP, r_top));
	tilesData[y][x].SetTile(eTile::LEFT_BOTTOM, GetImageHandle(eTile::LEFT_BOTTOM, l_bottom));
	tilesData[y][x].SetTile(eTile::RIGHT_BOTTOM, GetImageHandle(eTile::RIGHT_BOTTOM, r_bottom));
}


int AutoTiling::GetImageHandle(eTile eT, eImageType eI) {
	return tileRectMap[4 * (int)eI + (int)eT];
}


/* タイルの地形チェック
<param name="gs">周囲マスの情報</param>
<param name="eVertical">垂直ターゲットのマス</param>
<param name="eHorizontal">水平ターゲットのマス</param>
<returns>地形種類</returns>*/
eImageType AutoTiling::CheckTileType(GirthState gs, eGirth eVertical, eGirth eHorizontal) {
	if (!gs.IsTile()) { return eImageType::NONE; }

	eImageType type = LAND;  //「周囲タイルあり」で初期化
	eGirth eDiagonal = (eGirth)((int)eVertical + (int)eHorizontal - 4);     //斜め位置の番号を計算

	//垂直方向チェック
	if (!gs.GetAdjacentState(eVertical)) {
		type = TOP_BOTTOM;
	}
	//水平方向チェック
	if (!gs.GetAdjacentState(eHorizontal)) {
		type = (type == eImageType::LAND) ? eImageType::LEFT_RIGHT : eImageType::CROSS;
	}
	//斜め方向チェック
	if (!gs.GetAdjacentState(eDiagonal)) {
		type = (type == eImageType::LAND) ? eImageType::SALTIRE : type;
	}
	return type;
}


void AutoTiling::InitiliazeMapData() {
	for (int y = 0; y < mapData.size(); y++) {
		for (int x = 0; x < mapData[0].size(); x++) {
			mapData[y][x] = false;
		}
	}
}


GirthState AutoTiling::GetGirthState(int x, int y) {
	GirthState result;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			int targetX = x + i - 1;
			int targetY = y + j - 1;
			result.girth[j * 3 + i] = IsInField(targetX, targetY) ? mapData[targetY][targetX] : false;
		}
	}
	return result;
}

bool AutoTiling::IsInField(int x, int y) const {
	bool horizontal = (x >= 0 && x < Parameter::MapTipWidth);
	bool vertical = (y >= 0 && y < Parameter::MapTipHeight);
	return  horizontal && vertical;
}

bool AutoTiling::IsTile(int x, int y) const {
	return mapData[y][x];
}
