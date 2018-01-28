// 作成日：2016.12.12
// 作成者：柏
// 作成内容：AutoTile
// 最後修正：2016.12.12

#pragma once
#include <array>
#include "Parameter.h"
#include "Girthstate.h"
#include "Tile.h"
#include "eImageType.h"


class AutoTiling {
public:
	AutoTiling();
	~AutoTiling();

	void Initialize();
	void Update();
	void Draw();
	void DrawTiles(int x, int y);

	void WriteTerrain();
	void InitiliazeMapData();
	void SetMapData();
	GirthState GetGirthState(int x, int y);
	eImageType CheckTileType(GirthState gs, eGirth eVertical, eGirth eHorizontal);
	int GetImageHandle(eTile eT, eImageType eI);

	void SetTile(GirthState gs, int x, int y);
	
	bool IsInField(int x, int y) const;
	bool IsTile(int x, int y) const;

private:
	int tileSize;

	//tile描画の座標管理用
	Vector2<float> offset[4];

	//マップチップ画像のハンドル格納用
	std::array<int, 24>tileRectMap;

	//mapDataを管理する用
	std::array<std::array<bool, Parameter::MapTipWidth>, Parameter::MapTipHeight>mapData;

	//TileDataを管理する用(1つのタイルを四分割)
	std::array<std::array<Tile, Parameter::MapTipWidth>, Parameter::MapTipHeight>tilesData;

};