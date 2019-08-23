#include "InputHandle.h"

int InputHandle::getKeyInput() {
	if (GetAsyncKeyState(VK_LEFT)) {
		return KEY_LEFT;
	}
	if (GetAsyncKeyState(VK_UP)) {
		return KEY_UP;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		return KEY_RIGHT;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		return KEY_DOWN;
	}
	if (GetAsyncKeyState(VK_RETURN)) {
		return KEY_ENTER;
	}
	return -94;
/*
	int ch = _getch();
	if (ch == 224) {
		ch = _getch();
		switch (ch)
		{
		case 72:return KEY_UP;
		case 80:return KEY_DOWN;
		case 75:return KEY_LEFT;
		case 77:return KEY_RIGHT;
		}
	}
	else {
		//Debug:
		//_getch();
		//release:

		switch (ch)
		{
		case 'w':return KEY_W;
		case 's':return KEY_S;
		case 'q':return KEY_Q;
		case 'e':return KEY_E;
		case '\r':return KEY_ENTER;
		case 27:return ESC;
		case 26:return CTRL_Z;
		case 20:return CTRL_T;
		case 19:return CTRL_S;
		case 14:return CTRL_N;
		case 6:return CTRL_F;
		case 4:return CTRL_D;
		}
	}
	return -94;*/
}

void InputHandle::setCurrentState(State * state) {
	this->currrentState = state;
}

void InputHandle::keyInput() {
	currrentState->keyInput(getKeyInput());
}
InputHandle::~InputHandle() {
	delete this->currrentState;
}