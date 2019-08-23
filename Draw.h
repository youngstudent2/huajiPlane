#ifndef Draw_H
#define Draw_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<graphics.h>
#include"Game.h"
class BulletMap;
using namespace std;
typedef vector<string> Image;
class Draw {
private:
	TCHAR** s;
	
public:
	Draw();
	~Draw();
	void clear();
	void draw_out();
	void gotoxy(int x, int y);
	void draw_rect(int x, int y, int width, int height);
	void prepareImg(int x, int y, Image& img);
	void prepareBulletMap(BulletMap* bp, Image& img);
};

#endif // !Draw_H

