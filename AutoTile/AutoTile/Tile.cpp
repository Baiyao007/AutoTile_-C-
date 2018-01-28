// 作成日：2016.12.12
// 作成者：柏
// 作成内容：タイルの分割情報保存
// 最後修正：2016.12.12

#include "Tile.h"

Tile::Tile() {
	for (int i = 0; i < tileData.size(); i++) {
		tileData[i] = 0;
	}
}

Tile::~Tile() {}

std::array<int, 4> Tile::GetTileData() const {
	return tileData;
}

int Tile::GetTileData(eTile e) const{
	return tileData[(int)e];
}

void Tile::ReSetTile() {
	for (int i = 0; i < tileData.size(); i++) {
		tileData[i] = 0;
	}
}

void Tile::SetTile(eTile e, int imageHandle){
	tileData[(int)e] = imageHandle;
}




