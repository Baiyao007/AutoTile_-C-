// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�F�^�C���̕������ۑ�
// �Ō�C���F2016.12.12


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
