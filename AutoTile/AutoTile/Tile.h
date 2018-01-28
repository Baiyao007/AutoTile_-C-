// 作成日：2016.12.12
// 作成者：柏
// 作成内容：タイルの分割情報保存
// 最後修正：2016.12.12


#pragma once
#include <array>
#include "Vector2.h"
#include "eTile.h"

class Tile {
public:
	Tile();
	~Tile();

	std::array<int, 4> GetTileData() const;
	int GetTileData(eTile e) const;
	void SetTile(eTile e, int imageHandle);
	void ReSetTile();

	Vector2<int> position;
	std::array<int, 4>tileData;
};
