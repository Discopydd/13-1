#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1C_28_リ_ヨン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	PlayerClass* player = new PlayerClass();
	EnemyClass* enemyA = new EnemyClass(200.0f,200.0f,15.0f);
	EnemyClass* enemyB = new EnemyClass(300.0f, 300.0f, 20.0f);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->PlayerUpdate(keys);
		enemyA->EnemyUpdate(keys);
		enemyB->EnemyUpdate(keys);
		enemyA->CheckEnemyCollision(player->GetBulletPos(), enemyB);
		enemyB->CheckEnemyCollision(player->GetBulletPos(), enemyA);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->PlayerDraw();
		enemyA->EnemyDraw();
		enemyB->EnemyDraw();
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemyA->isAlive);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemyB->isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemyA;
	delete enemyB;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
