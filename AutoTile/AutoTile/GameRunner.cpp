// 作成日：2016.12.12
// 作成者：柏
// 作成内容：Game管理
// 最後修正：2016.12.12

#include "GameRunner.h"
#include <DXLib.h>
#include "Parameter.h"


GameRunner::GameRunner() :endFlag(false) {}
GameRunner::~GameRunner() {}

void GameRunner::Run() {
	Initialize();
	while (!EndCheck()) {
		Update();
		Draw();
	}

	Finalize();
}

void GameRunner::Initialize() {
	ChangeWindowMode(TRUE);
	SetGraphMode(Parameter::ScreenWidth, Parameter::ScreenHeight, 32);
	SetMainWindowText("AutoTile");

	DxLib_Init();
	autoT.Initialize();
}

void GameRunner::Update() {
	autoT.Update();
}

void GameRunner::Draw() {
	autoT.Draw();
}

void GameRunner::Finalize() {
	DxLib_End();
}

bool GameRunner::EndCheck() {
	endFlag = CheckHitKey(KEY_INPUT_ESCAPE);
	return endFlag;
}