// 作成日：2016.12.12
// 作成者：柏
// 作成内容：タイルの周り9マス情報保存
// 最後修正：2016.12.12

#pragma once
#include <bitset>
#include "eGirth.h"

//周囲9マスの情報を格納
class GirthState {
public:
	GirthState();
	GirthState(
		bool isTileLT, bool isTileT, bool isTileRT,
		bool isTileL , bool isTileC, bool isTileR ,
		bool isTileLB, bool isTileB, bool isTileRB
	);
	~GirthState();

	//現在地がタイルかどうか
	bool IsTile() const;

	//指定地はタイルかどうか
	bool GetAdjacentState(eGirth girthState) const;

	//周囲９マスの情報を格納
	std::bitset<9> girth;
};
