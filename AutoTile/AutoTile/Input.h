// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�F���͊Ǘ�
// �Ō�C���F2016.12.12

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