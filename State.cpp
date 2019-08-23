#include "State.h"

#define COLX 20
#define COLY 10
#define COL 10
void putimage_transparent(int x, int y, IMAGE* img1, IMAGE* img2) {
	putimage(x, y, img2, SRCAND);
	putimage(x, y, img1, SRCPAINT);
}
void putimage_transparent(int x, int y, pair<IMAGE*,IMAGE*> imgs) {
	putimage(x, y, imgs.second, SRCAND);
	putimage(x, y, imgs.first, SRCPAINT);
}

State::State()
{
}

void State::init(Resource* r) {
	this->r = r;
}

 void State::render() {
	
}

 void State::update() {

}

 void State::keyInput(int key)
 {
	 
 }


 void State::setCurrentState(State* newState) {
	GameMain::game.setCurrentState(newState);
}
 State::~State()
 {
 }
 void LoadState::init(Resource *r) {
	 this->r = r;
	 r->load();
	 setCurrentState(new MenuState);
 }

 void LoadState::render() {
	 
 }

 void LoadState::update() {

 }

 void LoadState::keyInput(int key) {
 }

 void PlayState::init(Resource* r) {
	 this->r = r;
	 settextstyle(30, 16, _T("Courier"));
	 setbkmode(TRANSPARENT);
	 settextcolor(BLACK);
	 lastscore = 0;
	 score = 0;
	 count_time = 0;
	 count_time2 = 0;
	 up = new userPlane(GAME_X - 3, GAME_Y -3 ,
		 r->plane_img1.getwidth() / COL, r->plane_img1.getheight() / COLX, "liuguotao",
		 &r->plane_img1, &r->plane_img2, &r->plane_img3, &r->plane_img4);
	 for (int i = 0; i < 6; i++) {
		 eps.push_back(new enemyPlane(Random::between(0, 3), Random::between(0, GAME_Y), 
			 r->enemy_img1.getwidth() / COLY, r->enemy_img1.getheight() / COLX,
			 &r->enemy_img1, &r->enemy_img2, &r->enemy_img3, &r->enemy_img4));
	 }
	 enemy_bulletmap = new BulletMap(1);
	 user_bulletmap = new BulletMap(0);
	 cloud1 = new Cloud(0.0, 20.0,
		 r->cloud1_img1.getwidth() / COL, r->cloud1_img1.getheight() / COL,
		 &r->cloud1_img1, &r->cloud1_img2);
	 cloud2 = new Cloud(30.0, 40.0,
		 r->cloud1_img1.getwidth() / COL, r->cloud1_img1.getheight() / COL,
		 &r->cloud2_img1, &r->cloud2_img2);
 }

 void PlayState::render() {
	 BeginBatchDraw();
	 putimage(0, 0, &r->bg_img);
	 putimage_transparent(cloud1->getY()*COL, cloud1->getX()*COL, cloud1->getImage());
	 putimage_transparent(cloud2->getY()*COL, cloud2->getX()*COL, cloud2->getImage());
	 putimage_transparent(up->getY()*COLY, up->getX()*COLX, up->getImage());
	 for (auto& ep : eps) {
		 putimage_transparent(ep->getY()*COLY, ep->getX()*COLX, ep->getImage());
	 }
	 bulletMapRender();
	 
	 char ch[50];
	 sprintf_s(ch, "score:%d life:%d", score, up->getLife());
	 int num = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);
	 wchar_t *wide = new wchar_t[num];
	 MultiByteToWideChar(0, 0, ch, -1, wide, num); 
	 RECT r = { 500, 0, 800, 40 };
	 drawtext(wide, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	 FlushBatchDraw();
	 EndBatchDraw();

 }
 void PlayState::bulletMapRender() {
	 for (int i = 0; i < GAME_X; i++) {
		 for (int j = 0; j < GAME_Y; j++) {
			 if (enemy_bulletmap->bullet_map[i][j]) {
				 putimage_transparent(j*COLY, i*COLX, &r->enemy_bullet1, &r->enemy_bullet2);
			 }
			 if (user_bulletmap->bullet_map[i][j]) {
				 putimage_transparent(j*COLY, i*COLX, &r->plane_bullet1, &r->plane_bullet2);
			 }
		 }
	 }
 }
 void PlayState::update() {
	 cloud1->update();
	 cloud2->update();
	 user_bulletmap->fire(*up);
	 for (auto& ep : eps) {
		 enemy_bulletmap->fire(*ep);
	 }
	 enemy_bulletmap->attack(*up);
	 up->update();
	 for (auto& ep : eps) {
		 user_bulletmap->attack(*ep);
		 ep->update();
		 if (ep->getLife() <= 0) {
			 score++;
			 ep->reset();
		 }
	 } 
	 static int count = 0;
	 if (++count > 3) {
		 user_bulletmap->update();
		 enemy_bulletmap->update();
		 count = 0;
	 }
	 if (score-lastscore>20) {
		 lastscore = score;
		 eps.push_back(new enemyPlane(Random::between(0, 3), Random::between(0, GAME_Y),
			 r->enemy_img1.getwidth() / COLY, r->enemy_img1.getheight() / COLX,
			 &r->enemy_img1, &r->enemy_img2, &r->enemy_img3, &r->enemy_img4));
	 }
	 
	 if (up->getLife() <= 0) {
		 //draw->gotoxy(31, 0);
		 //cout << "score:" << score << " life:" << setw(2) << up->getLife();
		 setCurrentState(new OverState(score));
	 }	 
 }

 void PlayState::keyInput(int key) {
	 up->move(key);
 }

 PlayState::~PlayState()
 {
	 delete user_bulletmap;
	 delete enemy_bulletmap;
 }

 OverState::OverState(int score)
 {
	 this->score = score;
 }

 void OverState::init(Resource * r)
 {

	 this->r = r;
	 putimage(0, 0, &r->over_img);
	 settextstyle(100, 50, _T("Courier"), 0, 0, 1000, false, false, false);
	 setbkmode(TRANSPARENT);
	 RECT rect = { 0,0,800,1000 };
	 char ch[50];
	 sprintf_s(ch, "YOUR SCORE: %d", score);
	 int num = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);	 
	 wchar_t *wide = new wchar_t[num];
	 MultiByteToWideChar(0, 0, ch, -1, wide, num);
	 drawtext(wide, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
 }

 void OverState::render()
 {
	 /*
	 BeginBatchDraw();
	
	 FlushBatchDraw();
	 EndBatchDraw();*/
 }

 void OverState::update()
 {
 }

 void OverState::keyInput(int key)
 {
	 if(key == InputHandle::KEY_ENTER)
		setCurrentState(new MenuState);
 }

 void MenuState::init(Resource * r)
 {
	 this->r = r;
	 putimage(0, 0, &r->start_img);
	 
 }

 void MenuState::render()
 {
	 /*
	 BeginBatchDraw();
	 
	 FlushBatchDraw();
	 EndBatchDraw();*/
 }

 void MenuState::update()
 {
 }

 void MenuState::keyInput(int key)
 {
	 if (key == InputHandle::ESC)GameMain::game.over();
	 if (key == InputHandle::KEY_ENTER)setCurrentState(new PlayState);
 }
