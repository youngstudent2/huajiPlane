#ifndef inputhandleh
#define inputhandleh
#include"State.h"
#include"conio.h"
class State;
class InputHandle {
private:
	State *currrentState;
	int getKeyInput();
public:
	static const int ESC = -1;
	static const int KEY_UP = 0;
	static const int KEY_DOWN = 1;
	static const int KEY_LEFT = 2;
	static const int KEY_RIGHT = 3;
	static const int KEY_ENTER = 4;
	static const int KEY_W = 5;
	static const int KEY_S = 6;
	static const int KEY_E = 7;
	static const int KEY_Q = 8;
	static const int CTRL_Z = 9;
	static const int CTRL_T = 10;
	static const int CTRL_D = 11;
	static const int CTRL_N = 12;
	static const int CTRL_F = 13;
	static const int CTRL_S = 14;
	void setCurrentState(State *state);
	void keyInput();
	~InputHandle();
};

#endif