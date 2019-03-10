#include "Package\build\native\include\congame.h"

#include <Windows.h>
#include <time.h>
#include <math.h>

namespace Congame {
	void InitRnd(unsigned int seed) {
		srand(seed);
		int trash = rand() % 10;
		for (int i = 0; i < trash; i++) {
			rand();
		}
	}
	void InitRnd() {
		time_t timer;
		InitRnd((unsigned int)time(&timer));
	}

	int RndInt(int max) {
		return RndInt(max, 0);
	}
	int RndInt(int max, int min) {
		return (int)(floorf(RndFloat()*(float)(max + 1 - min)) + (float)min);
	}

	float RndFloat() {
		return (float)rand() / 32768.0f;
	}
	double RndDouble() {
		return (double)rand() / 32768.0;
	}
}