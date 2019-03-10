#ifndef _CONGAME_RANDOM	// include guard
#define _CONGAME_RANDOM

namespace Congame {
	// randomize by seed
	void InitRnd(unsigned int seed);
	// randomize by msec
	void InitRnd();

	// returns random integer max to 'max'
	int RndInt(int max);
	// returns random integer from 'min' to 'max'
	int RndInt(int max, int min);

	// returns random float which 0 <= n < 1
	float RndFloat();
	// returns random double which 0 <= n < 1
	double RndDouble();
}
#endif // !_CONGAME_RANDOM
