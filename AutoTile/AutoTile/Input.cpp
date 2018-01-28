// 作成日：2016.12.12
// 作成者：柏
// 作成内容：入力管理
// 最後修正：2016.12.12

#include "input.h"
#include <DxLib.h>

Input::Input() {}

Input::~Input() {}

Vector2<int> Input::GetMousePosition() {
	int X, Y;
	GetMousePoint(&X, &Y);
	return Vector2<int>(X, Y);
}

bool Input::IsLeftClick() {
	return GetMouseInput() & MOUSE_INPUT_LEFT;
}

bool Input::IsRightClick() {
	return GetMouseInput() & MOUSE_INPUT_RIGHT;
}


