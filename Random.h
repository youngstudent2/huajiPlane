#ifndef random_H
#define random_H
#include<cstdlib>
class Random {
private:
	static int seed;
public:
	static int between(int x, int y);

};

#endif // !random_H

