// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�FAutoTile
// �Ō�C���F2016.12.22
// �C�����e�FSourceMonitor�ɂ����P

#include "AutoTiling.h"
#include "Parameter.h"
#include "Input.h"
#include <DxLib.h>
#include "eTile.h"

//�R���X�g���N�^�A�l�������ꂽ�^�C���J�b�g���w��poffset������
AutoTiling::AutoTiling():tileSize(Parameter::TileSize) {
	offset[0] = Vector2<float>(0.0f	, 0.0f);	//TopLeft
	offset[1] = Vector2<float>(0.5f , 0.0f);	//TopRight
	offset[2] = Vector2<float>(0.0f	, 0.5f);	//BottomLeft
	offset[3] = Vector2<float>(0.5f	, 0.5f);	//BottomRight
}

AutoTiling::~AutoTiling() {
}

//������
void AutoTiling::Initialize() {
	LoadDivGraph("MapChip2.png", 24, 2, 12, Parameter::TileSize / 2, Parameter::TileSize / 2, &tileRectMap[0]);
	InitiliazeMapData();
}

//�X�V
void AutoTiling::Update() {
	WriteTerrain();
	SetMapData();
}

// �`��
void AutoTiling::Draw() {
	for (int y = 0; y < mapData.size(); y++) {
		for (int x = 0; x < mapData[0].size(); x++) {
			DrawTiles(x, y);
		}
	}
}

// �^�C�����`��
// <param name="x">�}�b�v�`�b�v�̂w���W</param>
// <param name="y">�}�b�v�`�b�v�̂x���W</param>
void AutoTiling::DrawTiles(int x, int y) {
	if (!IsTile(x, y)) { return; }
	int tSize = Parameter::TileSize;

	for (int i = 0; i < 4; i++) {
		DrawGraph((x + offset[i].X) * tSize, (y + offset[i].Y) * tSize, tilesData[y][x].GetTileData((eTile)i), TRUE);
	}
}

// �N���b�N����ɂ���ă^�C����`��
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


// �}�b�v�Ɍv�Z�ς݂̃^�C����ݒu
void AutoTiling::SetMapData() {
	for (int y = 0; y < mapData.size(); y++) {
		for (int x = 0; x < mapData[0].size(); x++) {
			GirthState gs = GetGirthState(x, y);
			SetTile(gs, x, y);
		}
	}
}

/* <summary>
�^�C���̏����`�F�b�N���A�ݒ�
<param name="gs">����}�X�̏��</param>
<param name="x">�}�b�v�`�b�v�̂w���W</param>
<param name="y">�}�b�v�`�b�v�̂x���W</param>*/
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


/* �^�C���̒n�`�`�F�b�N
<param name="gs">���̓}�X�̏��</param>
<param name="eVertical">�����^�[�Q�b�g�̃}�X</param>
<param name="eHorizontal">�����^�[�Q�b�g�̃}�X</param>
<returns>�n�`���</returns>*/
eImageType AutoTiling::CheckTileType(GirthState gs, eGirth eVertical, eGirth eHorizontal) {
	if (!gs.IsTile()) { return eImageType::NONE; }

	eImageType type = LAND;  //�u���̓^�C������v�ŏ�����
	eGirth eDiagonal = (eGirth)((int)eVertical + (int)eHorizontal - 4);     //�΂߈ʒu�̔ԍ����v�Z

	//���������`�F�b�N
	if (!gs.GetAdjacentState(eVertical)) {
		type = TOP_BOTTOM;
	}
	//���������`�F�b�N
	if (!gs.GetAdjacentState(eHorizontal)) {
		type = (type == eImageType::LAND) ? eImageType::LEFT_RIGHT : eImageType::CROSS;
	}
	//�΂ߕ����`�F�b�N
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
