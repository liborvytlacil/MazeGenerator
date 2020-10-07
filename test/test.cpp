#include "../MazeGenerator.h"
#include "../RandomGenerator.h"
#include <vector>
#include <iostream>

int* generateMaze(int width, int height, int startX, int startY, RandomGenerator &randomGenerator);

extern enum Direction;

using namespace std;

class PredictibleRandomGenerator : public RandomGenerator {
private:
	vector<int> values;
	int current;

public:
	PredictibleRandomGenerator(vector<int> values) :
		values(values), current(0) { }

	int next(int bound) override {
		if (current >= values.size()) {
			current = 0;
		}
		return values[current++];
	}
};

void testMazeGenerator() {
	int* expected = new int[16]{
		CELL_PATH_S | CELL_PATH_E,
		CELL_PATH_W,
		CELL_PATH_S | CELL_PATH_E,
		CELL_PATH_W,

		CELL_PATH_N | CELL_PATH_S,
		CELL_PATH_E,
		CELL_PATH_N | CELL_PATH_W | CELL_PATH_E,
		CELL_PATH_W | CELL_PATH_S,

		CELL_PATH_N | CELL_PATH_E,
		CELL_PATH_W | CELL_PATH_S,
		CELL_PATH_S | CELL_PATH_E,
		CELL_PATH_N | CELL_PATH_W |  CELL_PATH_S,

		CELL_PATH_E,
		CELL_PATH_N | CELL_PATH_W | CELL_PATH_E,
		CELL_PATH_N | CELL_PATH_W ,
		CELL_PATH_N
	};

	vector<int> randomVector = {
		0, 0, 0, 1, 1, 0,
		0, 0, 1, 1,
		0, 1, 1,
		0, 0
	};
	
	int* actual = generateMaze(4, 4, 1, 0, PredictibleRandomGenerator(randomVector));
	bool success = true;
	for (int i = 0; i < 16; ++i) {
		if (actual[i] != expected[i]) {
			cout << "Mismatch index " << i << ". Expected " << expected[i] << ", actual " << actual[i] << ".\n";
			success = false;
		}
	}

	if (success) {
		cout << "Test SUCCEEDED\n";
	}
	else {
		cout << "Test FAILED\n";
	}

	delete[] expected;
	if (actual != nullptr) {
		delete[] actual;
	}
}

int main() {
	cout << "Maze Generator Test" << endl;
	testMazeGenerator();
}
