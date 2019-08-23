#ifndef gamemainh
#define gamemainh
#include"Game.h"
class Game;
class GameMain {
public:
	static Game game;
	GameMain();
	void run();
};
#endif