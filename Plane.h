#ifndef planeh
#define planeh
#include<vector>
#include<graphics.h>
#define GAME_X 50
#define GAME_Y 80
class Plane{
protected:
	float x, y;//坐标
	int width, height;//长宽
	float vel_y, vel_x;//速度
	int life;
	int bullet_count;
	int BULLET_COUNT;
	int dir;
	vector<IMAGE*> imgs;
public:
	Plane(float x,float y,int width,int height, IMAGE* img1, IMAGE* img2, IMAGE* img3, IMAGE* img4) {
		dir = 0;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->vel_x = 0.0;
		this->vel_y = 0.0;
		bullet_count = 0;
		BULLET_COUNT = 0xffffff;
		imgs.push_back(img1);
		imgs.push_back(img2);
		imgs.push_back(img3);
		imgs.push_back(img4);
	}
	virtual void update() {

	}
	virtual void render() {

	}
	void attacked() {
		life--;
	}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	int getLife() {
		return life;
	}
	bool fire() {
		if (++bullet_count >= BULLET_COUNT) {
			bullet_count = 0;
			return true;
		}
		return false;
	}
	pair<IMAGE*, IMAGE*> getImage() {
		return make_pair(imgs[dir], imgs[dir + 1]);
	}
};
#endif