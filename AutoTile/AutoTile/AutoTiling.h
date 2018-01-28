// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�FAutoTile
// �Ō�C���F2016.12.12

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

	//tile�`��̍��W�Ǘ��p
	Vector2<float> offset[4];

	//�}�b�v�`�b�v�摜�̃n���h���i�[�p
	std::array<int, 24>tileRectMap;

	//mapData���Ǘ�����p
	std::array<std::array<bool, Parameter::MapTipWidth>, Parameter::MapTipHeight>mapData;

	//TileData���Ǘ�����p(1�̃^�C�����l����)
	std::array<std::array<Tile, Parameter::MapTipWidth>, Parameter::MapTipHeight>tilesData;

};