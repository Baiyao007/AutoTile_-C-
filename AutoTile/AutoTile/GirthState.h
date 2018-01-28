// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�F�^�C���̎���9�}�X���ۑ�
// �Ō�C���F2016.12.12

#pragma once
#include <bitset>
#include "eGirth.h"

//����9�}�X�̏����i�[
class GirthState {
public:
	GirthState();
	GirthState(
		bool isTileLT, bool isTileT, bool isTileRT,
		bool isTileL , bool isTileC, bool isTileR ,
		bool isTileLB, bool isTileB, bool isTileRB
	);
	~GirthState();

	//���ݒn���^�C�����ǂ���
	bool IsTile() const;

	//�w��n�̓^�C�����ǂ���
	bool GetAdjacentState(eGirth girthState) const;

	//���͂X�}�X�̏����i�[
	std::bitset<9> girth;
};
