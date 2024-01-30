#include "Enemy.h"

EnemyClass::EnemyClass(float posX, float posY,float radius) {
	enemy.position = {posX, posY};
	enemy.velocity = {5.0f, 0.0f};
	enemy.radius = radius;

	isAlive = 1;
}

void EnemyClass::EnemyUpdate(char* keys) {
	if (keys[DIK_R]) {
		isAlive = 1;
	}
	if (isAlive) {
		enemy.position.x += enemy.velocity.x;
		if (enemy.position.x > 1280 - enemy.radius) {
			enemy.velocity.x = -5.0f;
		}
		if (enemy.position.x < 0 + enemy.radius) {
			enemy.velocity.x = 5.0f;
		}
	}
}

void EnemyClass::EnemyDraw() {
	if (isAlive) {
		Novice::DrawEllipse(
		    (int)enemy.position.x, (int)enemy.position.y, (int)enemy.radius,
		    (int)enemy.radius, 0.0f, WHITE, kFillModeSolid);
	}
}

void EnemyClass::CheckEnemyCollision(Bullet bullet[], EnemyClass* otherEnemy) {
	for (int i = 0; i < 7; i++) {
		float a = static_cast<float>(bullet[i].position.x - enemy.position.x);
		float b = static_cast<float>(bullet[i].position.y - enemy.position.y);
		float distance = sqrtf(a * a + b * b);

		if (distance <= bullet[i].radius + enemy.radius) {
			isAlive = 0;

			if (otherEnemy != nullptr) {
				otherEnemy->isAlive = 0;
			}
		}
	}
}

