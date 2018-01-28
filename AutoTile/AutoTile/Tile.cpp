// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�F�^�C���̕������ۑ�
// �Ō�C���F2016.12.12

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




