/**
* A test file used for veryfing the maze generation algorithm.
*/
#include "../MazeGenerator.h"
#include "../RandomGenerator.h"
#include <vector>
#include <iostream>

int* generateMaze(int width, int height, int startX, int startY, RandomGenerator &randomGenerator);

using namespace std;

/**
* Implementation of RandomGenerator that simply returns values from a given vector, one by one.
* Each call returns the next value. Once all values have been returned, the counter is reset
* and numbers are returned from the beginning again.
*/
class PredictibleRandomGenerator : public RandomGenerator {
private:
	vector<int> values;
	int current;

public:
	PredictibleRandomGenerator(vector<int> values) :
		values(values), current(0) { }

	int next(size_t bound) override {
		if (current >= values.size()) {
			current = 0;
		}
		return values[current++];
	}
};

/**
* A white-box test that relies on the implementation of the maze generation algorithm,
* especially on how neighbours are selected using the pseudo-random generator.
*/
void testMazeGenerator() {
	// see test-maze.png that shows how this looks like
	// and in which direction this is generated
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
	
	PredictibleRandomGenerator randomGenerator = PredictibleRandomGenerator(randomVector);
	int* actual = generateMaze(4, 4, 1, 0, randomGenerator);
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
