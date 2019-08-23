#ifndef stateh
#define stateh
#include<iostream>
#include"GameMain.h"
#include"InputHandle.h"
#include"Resource.h"
#include"userPlane.h"
#include"enemyPlane.h"
#include"BulletMap.h"
#include"Cloud.h"
class Draw;
class Game;
class GameMain;
class InputHandle;
class State {
protected:
	Resource* r;
public:
	State();
	virtual void init(Resource* r);
	virtual void render();
	virtual void update();
	virtual void keyInput(int key);
	void setCurrentState(State* newState);
	~State();
};
class LoadState : public State {
private:

public:
	void init(Resource* r);
	void render();
	void update();
	virtual void keyInput(int key) override;
};
class PlayState :public State {
private:
	userPlane* up;
	BulletMap* enemy_bulletmap;
	BulletMap* user_bulletmap;
	Cloud *cloud1, *cloud2;
	vector<enemyPlane*> eps;
	int count_time, count_time2;
	int score, lastscore;
public:
	void init(Resource* r);
	void render();
	void bulletMapRender();
	void update();
	void keyInput(int key) override;
	~PlayState();
};

class OverState :public State {
private:
	int score;
public:
	OverState(int score);
	void init(Resource* r);
	void render();
	void update();
	void keyInput(int key) override;
};
class MenuState :public State {
private:
	Resource *r;
public:
	void init(Resource* r);
	void render();
	void update();
	void keyInput(int key) override;
};
#endif