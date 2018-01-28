// 作成日：2016.12.12
// 作成者：柏
// 作成内容：入力管理
// 最後修正：2016.12.12

#pragma once
#include "Vector2.h"


class Input {
public:
	Input();
	~Input();

	static Vector2<int> GetMousePosition();

	static bool IsLeftClick();

	static bool IsRightClick();

};