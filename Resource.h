#ifndef resourceh
#define resourceh
#include<fstream>
#include<vector>
#include<string>
#include<graphics.h>
using namespace std;
#define plane_size 50
#define bullet_size 20
#define cloud_size 70
class Resource {
public:
	IMAGE plane_img1;
	IMAGE plane_img2;
	IMAGE enemy_img1;
	IMAGE enemy_img2;
	IMAGE plane_img3;
	IMAGE plane_img4;
	IMAGE enemy_img3;
	IMAGE enemy_img4;
	IMAGE enemy_bullet1;
	IMAGE plane_bullet1;
	IMAGE enemy_bullet2;
	IMAGE plane_bullet2;
	IMAGE over_img;
	IMAGE start_img;
	IMAGE bg_img;
	IMAGE cloud1_img1, cloud1_img2;
	IMAGE cloud2_img1, cloud2_img2;
	void load() {
		loadimage(&start_img, _T("bin/welcome.png"), 800, 1000, true);
		loadimage(&enemy_bullet1, _T("bin/enemyBullet1.png"), bullet_size, bullet_size, true);
		loadimage(&plane_bullet1, _T("bin/Bullet1.png"), bullet_size, bullet_size, true);
		loadimage(&enemy_img1, _T("bin/enemy1.png"), plane_size, plane_size, true);
		loadimage(&enemy_img2, _T("bin/enemy2.png"), plane_size, plane_size, true);
		loadimage(&enemy_img3, _T("bin/enemy1r.png"), plane_size, plane_size, true);
		loadimage(&enemy_img4, _T("bin/enemy2r.png"), plane_size, plane_size, true);
		loadimage(&plane_img1, _T("bin/huaji1.png"), plane_size, plane_size, true);
		loadimage(&plane_img2, _T("bin/huaji2.png"), plane_size, plane_size, true);
		loadimage(&plane_img3, _T("bin/huaji1r.png"), plane_size, plane_size, true);
		loadimage(&plane_img4, _T("bin/huaji2r.png"), plane_size, plane_size, true);
		loadimage(&enemy_bullet2, _T("bin/enemyBullet2.png"), bullet_size, bullet_size, true);
		loadimage(&plane_bullet2, _T("bin/Bullet2.png"), bullet_size, bullet_size, true);
		loadimage(&over_img, _T("bin/over.png"), 800, 1000, true);
		loadimage(&bg_img, _T("bin/bg.png"), 800, 1000, true);
		loadimage(&cloud1_img1, _T("cloud1a.png"));
		loadimage(&cloud1_img2, _T("cloud1b.png"));
		loadimage(&cloud2_img1, _T("cloud2a.png"));
		loadimage(&cloud2_img2, _T("cloud2b.png"));
	}
	/*
	vector<string> loadImg(string fileName) {
		fstream img(fileName, ios::in);
		vector<string> tmpImg;
		string tmp;
		while (img >> tmp) {
			tmpImg.push_back(tmp);
		}
		return tmpImg;
	}*/
};
#endif