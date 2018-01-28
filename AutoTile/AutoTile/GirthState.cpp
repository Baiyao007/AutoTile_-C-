// 作成日：2016.12.12
// 作成者：柏
// 作成内容：タイルの周り9マス情報保存
// 最後修正：2016.12.12

#include "GirthState.h"

GirthState::GirthState() {
	GirthState(
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	);
}

GirthState::GirthState(
	bool isTileLT, bool isTileT, bool isTileRT,
	bool isTileL , bool isTileC, bool isTileR,
	bool isTileLB, bool isTileB, bool isTileRB) 
{
	girth.reset();
	if (isTileLT) { girth.set(0); }
	if (isTileT ) { girth.set(1); }
	if (isTileRT) { girth.set(2); }

	if (isTileL ) { girth.set(3); }
	if (isTileC ) { girth.set(4); }
	if (isTileR ) { girth.set(5); }

	if (isTileLB) { girth.set(6); }
	if (isTileB ) { girth.set(7); }
	if (isTileLB) { girth.set(8); }
}

GirthState::~GirthState() {}

bool GirthState::IsTile() const{
	return girth.test(4);
}

bool GirthState::GetAdjacentState(eGirth girthState) const {
	return girth.test((int)girthState);
}