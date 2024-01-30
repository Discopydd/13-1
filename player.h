#pragma once
#include "Novice.h"
#include "Struct.h"

class PlayerClass {
public:
	PlayerClass();
	~PlayerClass();

	void PlayerUpdate(char* keys);
	void PlayerDraw();

	Player player;
	Bullet* GetBulletPos();
	static int BulletTime;

private:
	Bullet bullet[7];
	void BulletUpdate(char* keys);
	void BulletDraw();
};