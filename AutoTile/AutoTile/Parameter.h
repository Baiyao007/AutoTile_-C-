// 作成日：2016.12.12
// 作成者：柏
// 作成内容：常数管理
// 最後修正：2016.12.12

#pragma once
#include "Vector2.h"


class Parameter {
public:
	static const int MapTipWidth = 15;
	static const int MapTipHeight = 10;
	static const int TileSize = 64;

	static const int ScreenWidth = MapTipWidth * TileSize;
	static const int ScreenHeight = MapTipHeight * TileSize;
};
