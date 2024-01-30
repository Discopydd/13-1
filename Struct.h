#pragma once
struct Vector2 {
	float x;
	float y;
};
struct Player {
	Vector2 position;
	Vector2 velocity;
	float radius;
};
struct Bullet {
	Vector2 position;
	Vector2 velocity;
	float radius=8.0f;
	int isShot;
};
struct Enemy {
	Vector2 position;
	Vector2 velocity;
	float radius;

};