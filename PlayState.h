#pragma once
#include"State.h"
class State;
class PlayState :public State {
private:

public:
	void init();
	void render();
	void update();
	void keyInput(int key);

};