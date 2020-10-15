#pragma once

#include<cmath>
#include<ctime>

class RandomGenerator {
public:
	virtual int next(int bound) = 0;
};

class StandardRandomGenerator : public RandomGenerator {
public:

	StandardRandomGenerator() {
		srand(time(NULL));
	}

	int next(int bound) override {
		if (bound > 0) {
			return rand() % bound;
		}
		return rand();
	}
};