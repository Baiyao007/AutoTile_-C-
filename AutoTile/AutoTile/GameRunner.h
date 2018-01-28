// 作成日：2016.12.12
// 作成者：柏
// 作成内容：Game管理
// 最後修正：2016.12.12

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