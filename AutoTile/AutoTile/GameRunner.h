// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�FGame�Ǘ�
// �Ō�C���F2016.12.12

#pragma once
#include "AutoTiling.h"

class GameRunner {
public:
	GameRunner();
	~GameRunner();

	void Run();

private:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
	bool EndCheck();

	AutoTiling autoT;
	bool endFlag;
};