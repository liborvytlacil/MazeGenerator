#include "MazeGenerator.h"
#include <iostream>

using namespace std;

int main()
{
	const char wall = 'X';
	const char space = ' ';
	const int width = 24;
	const int height = 10;
	StandardRandomGenerator randomGenerator;

	const int* maze = generateMaze(width, height, 0, 0, randomGenerator);

	cout << wall;
	for (int x = 0; x < width; x++) {
		cout << wall;
		cout << wall;
	}
	cout << endl;

	for (int y = 0; y < height; y++) {
		cout << wall;
		for (int x = 0; x < width; x++) {
			cout << space;
			if ((maze[linearize(x, y, width)] & CELL_PATH_E) != 0) {
				cout << space;
			}
			else {
				cout << wall;
			}
		}
		cout << endl;

		cout << wall;
		for (int x = 0; x < width; x++) {
			if ((maze[linearize(x, y, width)] & CELL_PATH_S) != 0) {
				cout << space;
			}
			else {
				cout << wall;
			}
			cout << wall;
		}
		cout << endl;
	}

	delete[] maze;
	return 0;
}