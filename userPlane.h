#ifndef userplaneh
#define userplaneh
#include "Plane.h"
#include<string>
using namespace std;
class userPlane :
	public Plane
{
private:
	string username;
public:
	userPlane(float x, float y, int width, int height, 
		string name, IMAGE* img1, IMAGE* img2, IMAGE* img3, IMAGE* img4) 
		:Plane(x, y, width, height, img1, img2, img3, img4), username(name) {
		life = 10;
		vel_x = 0.3;
		vel_y = 0.5;
		BULLET_COUNT = 2;
	}
	void move(int dir) {
		if (dir == 0) {//up
			x -= vel_x;
		}
		else if (dir == 1) {//down
			x += vel_x;
		}
		else if (dir == 2) {//left
			this->dir = 0;
			y -= vel_y;
		}
		else if (dir == 3) {//right
			this->dir = 2;
			y += vel_y;
		}
	}
	void update() {
		if (x < 0)x = 0;
		if (x >= GAME_X - height)x = GAME_X - 1 - height;
		if (y < 0)y = 0;
		if (y >= GAME_Y - width)y = GAME_Y - 1 - width;
	}
	
};
#endif

