#ifndef gameh
#define gameh
#include<windows.h>
#include"InputHandle.h"
#include<thread>
//#define GAME_X 50
//#define GAME_Y 100
class State;
class Resource;
class InputHandle;
using namespace std;
class Game {
private:
	volatile bool running;
public:
	Resource* resource;
	InputHandle* inputhandle;
	State* currentState;
	thread* gameThread;
	Game();
	void run();
	void setCurrentState(State* state);
	void updateAndRender();
	void gameRun(State* *currentState);
	void over();
	~Game();
};
#endif // !gameh





