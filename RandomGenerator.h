#pragma once

#include<cmath>

class RandomGenerator {
public:
	virtual int next(int bound) = 0;
};

class StandardRandomGenerator : public RandomGenerator {
	int next(int bound) override {
		if (bound > 0) {
			return rand() % bound;
		}
		return rand();
	}
};