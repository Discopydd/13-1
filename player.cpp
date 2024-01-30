#include "Player.h"
#include <iostream>
using namespace std;

int PlayerClass::BulletTime;
PlayerClass::PlayerClass() {
	player.position = {600.0f, 600.0f};
	player.velocity = {5.0f, 5.0f};
	player.radius = 30.0f;

	for (int i = 0; i < 7; i++) {
	bullet[i].position = {0.0f, 0.0f};
	bullet[i].velocity = {0.0f, 10.0f};
	bullet[i].isShot = 0;
	}
	
	
}
PlayerClass::~PlayerClass() {}

void PlayerClass::PlayerUpdate(char* keys) {
	if (keys[DIK_A]) {
		player.position.x -= player.velocity.x;
	}

	if (keys[DIK_D]) {
		player.position.x += player.velocity.x;
	}

	if (keys[DIK_W]) {
		player.position.y -= player.velocity.y;
	}

	if (keys[DIK_S]) {
		player.position.y += player.velocity.y;
	}
	BulletUpdate(keys);
}

void PlayerClass::PlayerDraw() {
	Novice::DrawEllipse(
	    (int)player.position.x, (int)player.position.y, (int)player.radius, (int)player.radius,
	    0.0f,
	    WHITE,
	    kFillModeSolid);
	BulletDraw();
}
Bullet* PlayerClass::GetBulletPos() { return bullet; }
void PlayerClass::BulletUpdate(char* keys) {
	for (int i = 0; i < 7; i++) {
		if (BulletTime == 0) {
			if (keys[DIK_SPACE]) {
				if (bullet[i].isShot == 0) {
					bullet[i].isShot = 1;
					bullet[i].position.x = player.position.x;
					bullet[i].position.y = player.position.y;
					BulletTime = 10;
				}
			}
		}
		if (bullet[i].isShot == 1) {
			bullet[i].position.y -= bullet[i].velocity.y;
			if (bullet[i].position.y <= 0.0f) {
				bullet[i].isShot = 0;
			}
		}
	}
	if (BulletTime > 0) {
		BulletTime--;
	}
}
void PlayerClass::BulletDraw() {
	for (int i = 0; i < 7; i++) {
		if (bullet[i].isShot) {
			Novice::DrawEllipse(
			    (int)bullet[i].position.x, (int)bullet[i].position.y, (int)bullet[i].radius,
			    (int)bullet[i].radius, 0.0f, WHITE, kFillModeSolid);
		}
	}
}


