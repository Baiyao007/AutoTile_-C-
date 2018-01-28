// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�FGame�Ǘ�
// �Ō�C���F2016.12.12

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