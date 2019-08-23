#pragma once
#include"Random.h"
#include<graphics.h>
#include<vector>
class Cloud {
private:
	double x, y;
	double velX;
	int height, width;
	IMAGE *img1, *img2;
public:
	Cloud(double x, double y, int width, int height,IMAGE* img1,IMAGE* img2) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		velX = 0.3;
		this->img1 = img1;
		this->img2 = img2;
	}
	void update() {
		x += velX;
		if (x >= 80) {
			reset();
		}
	}
	void reset() {
		x = 0;
		y = Random::between(0, 80);
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	int getHeight() {
		return height;
	}
	int getWidth() {
		return width;
	}
	pair<IMAGE*, IMAGE*> getImage() {
		return make_pair(img1, img2);
	}
};