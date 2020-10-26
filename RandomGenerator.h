/**
* Declares very simple interface for random generators and a very simple implementation.
* The idea here is to be able to define a test implementation with deterministic results
* that can be used for testing the maze generation algorithm.
*/
#pragma once

#include<cmath>
#include<ctime>

class RandomGenerator {
public:
	virtual int next(size_t bound) = 0;
	virtual ~RandomGenerator() { }
};

class StandardRandomGenerator : public RandomGenerator {
public:

	StandardRandomGenerator() {
		srand(static_cast<unsigned>(time(NULL)));
	}

	int next(size_t bound) override {
		if (bound > 0) {
			return rand() % bound;
		}
		return rand();
	}
};