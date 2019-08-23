#pragma once
#include"State.h"
class LoadState :public State {
private:

public:
	void init();
	void render();
	void update();
	void keyInput(int key);
};