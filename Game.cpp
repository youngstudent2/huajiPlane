#include "Game.h"
Game::Game() {
	inputhandle = new InputHandle();
	resource = new Resource;
	currentState = nullptr;
	running = true;
	//定义窗口大小
	initgraph(800, 1000);
	setCurrentState(new LoadState);
}
void Game::run() {
	gameThread = new thread(&Game::gameRun, this, &currentState);
	gameThread->detach();
	while (running) {
		inputhandle->keyInput();
		Sleep(5);
	}
}

void Game::setCurrentState(State * state) {
	if(this->currentState!=nullptr)
		delete this->currentState;
	this->currentState = state;
	inputhandle->setCurrentState(state);
	currentState->init(resource);

}

void Game::gameRun(State* *currentState)
{
	while (running) {
		(*currentState)->update();
		(*currentState)->render();
		Sleep(11);
	}
}

void Game::over() {
	running = false;
	//exit(0);
}

Game::~Game()
{
	delete resource;
	delete inputhandle;
	delete gameThread;
}
