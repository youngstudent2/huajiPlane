#pragma once
#include"Plane.h"
#include"Random.h"
class enemyPlane:public Plane {
private:
	int left;
	int right;
	int last_x;
public:
	enemyPlane(float x, float y, int width, int height, 
		IMAGE* img1, IMAGE* img2, IMAGE* img3, IMAGE* img4) 
		:Plane(x, y, width, height, img1, img2, img3, img4) {
		life = 1;
		left = Random::between(0, 2);
		right = Random::between(0, 2);
		vel_x = 0.14*Random::between(1, 2);
		vel_y = 0.4*Random::between(1, 3);
		last_x = 0;
		BULLET_COUNT = Random::between(20, 70);
	}
	void update() {
		this->dir = (right - left) > 0 ? 2 : 0;
		y += (right - left)*vel_y;
		x += vel_x;
		if (x < 0)x = 0;
		if (x - last_x > 10) {
			last_x = x;
			int tmp = left;
			left = right;
			right = tmp;
		}
		
		if (x >= GAME_X - height)reset();
		if (y < 0)y = 0;
		if (y >= GAME_Y - width)y = GAME_Y - 1 - width;

	}
	void reset() {
		left = Random::between(0, 2);
		right = Random::between(0, 2);
		if (left == right) {
			int x = Random::between(0, 3);
			if (x==1) {
				++left;
			}
			else if (x == 2) {
				++right;
			}
			else {

			}
		}

		vel_x = 0.14*Random::between(1, 2);
		vel_y = 0.4*Random::between(1, 3);
		x = 0;
		y = Random::between(0, GAME_Y);
		life = 1;
		last_x = 0;
		BULLET_COUNT = Random::between(20, 70);
	}
};