#pragma once
#include"Plane.h"

class BulletMap {
private:
	bool bullet_map[GAME_X][GAME_Y];
	int dir;
public:
	friend class Draw;
	friend class PlayState;
	BulletMap(int dir) {
		this->dir = dir;
		for (int i = 0; i < GAME_X; i++) {
			for (int j = 0; j < GAME_Y; j++) {
				bullet_map[i][j] = 0;
			}
		}	
	}
	void update() {
		if (dir == 0) {
			for (int i = 0; i < GAME_X - 1; i++) {
				for (int j = 0; j < GAME_Y; j++) {
					bullet_map[i][j] = bullet_map[i + 1][j];
					bullet_map[i + 1][j] = 0;
				}
			}
		}
		else {
			for (int i = GAME_X - 1; i > 0; i--) {
				for (int j = 0; j < GAME_Y; j++) {
					bullet_map[i][j] = bullet_map[i - 1][j];
					bullet_map[i - 1][j] = 0;
				}
			}
		}
		for (int j = 0; j < GAME_Y; j++) {
			bullet_map[dir ? 0 : GAME_X - 1][j] = 0;
		}
	}
	bool attack(Plane& p) {
		bool attacked = 0;
		for (int i = p.getX(); i <= p.getX() + p.getHeight(); i++) {
			if(i>GAME_X)break;
			for (int j = p.getY(); j <= p.getY() + p.getWidth(); j++) {
				if (j >= GAME_Y)break;
				if (bullet_map[i][j]) {
					bullet_map[i][j] = 0;
					attacked = 1;
				}
			}
		}
		if (attacked)p.attacked();
		return attacked;
	}
	void fire(Plane& p) {
		if (!p.fire())return;
		if (dir == 0) {
			if (!outside((int)p.getX() - 1, (int)p.getY() + p.getWidth() - 1))
				bullet_map[(int)p.getX() - 1][(int)p.getY() + p.getWidth() - 1] = 1;
		//	bullet_map[(int)p.getX() - 1][(int)p.getY() + p.getWidth() - 2] = 1;
		}
		if (dir == 1) {
			if (!outside((int)p.getX() + p.getHeight() + 1, (int)p.getY() + p.getWidth() - 1))
				bullet_map[(int)p.getX() + p.getHeight() + 1][(int)p.getY() + p.getWidth() - 1] = 1;
			//bullet_map[(int)p.getX() + p.getHeight() + 2][(int)p.getY() + p.getWidth() - 1] = 1;
			//bullet_map[(int)p.getX() + p.getHeight() + 3][(int)p.getY() + p.getWidth() - 1] = 1;
		}
	}
	bool outside(int x, int y) {
		return x < 0 || y < 0 || x >= GAME_X || y >= GAME_Y;
	}
};