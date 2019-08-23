#include "Random.h"
int Random::seed = 0;
int Random::between(int x, int y) { //random num in [x,y)
	if (seed == 0) {
		seed = 1027;
		srand(seed);
	}
	return rand() % (y - x) + x;
}
