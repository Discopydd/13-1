#pragma once
#include "Novice.h"
#include "Struct.h"
#include <math.h>

class EnemyClass {
public:
	EnemyClass(float posX, float posY,float radius);

	void EnemyUpdate(char* keys);
	void EnemyDraw();
	void CheckEnemyCollision(Bullet bullet[], EnemyClass* otherEnemy);
	int isAlive;
	Enemy enemy;

};