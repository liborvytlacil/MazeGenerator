/**
* Defines code for processing command line input and printing the result to the standard output.
*/

#include "MazeGenerator.h"
#include <iostream>
#include <string>

using namespace std;

/**
* Prints a given maze to the standard output. The caller must ensure, that the passed int array indeed
* represents a maze of the given width and height.
*/
void printMaze(const int* maze, int width, int height) {
	const char wall = 'X';
	const char space = ' ';

	// print the first wall row
	cout << wall;
	for (int x = 0; x < width; x++) {
		cout << wall;
		cout << wall;
	}
	cout << endl;

	// alternate between printing rows with cells and wall rows.
	// each maze row is analyzed twice. First, we are interested in eastern neighbours of each cell in the row,
	// then we are insterested in southern neighbours of each cell in the row.
	for (int y = 0; y < height; y++) {
		// print the next row with cells
		// start with the left-most wall
		cout << wall;
		for (int x = 0; x < width; x++) {
			// print the next cell
			cout << space;

			// based on whether a cell is connected to its eastern neighbour, print either a space (connection) or a wall
			if ((maze[linearize(x, y, width)] & CELL_PATH_E) != 0) {
				cout << space;
			}
			else {
				cout << wall;
			}
		}
		cout << endl;

		// print the next wall row
		// start with the left-most wall
		cout << wall;
		for (int x = 0; x < width; x++) {
			// based on whether a cell is connected to its southern neighbour, print either a space (connection) or a wall
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
}

int main(int argc, char* argv[])
{
	const int maxWidth = 60;
	const int maxHeight = 60;

	// process input
	int width = 1;
	int height = 1;
	if (argc != 3) {
		cout << "Usage: <executable-name> width height" << endl;
	}
	else {
		try {
			width = stoi(argv[1]);
			height = stoi(argv[2]);
		}
		catch (invalid_argument const& ex) {
			cerr << "ERROR: Both width and height must be valid integers." << endl;
			return 1;
		}
		catch (out_of_range const& ex) {
			cerr << "ERROR: One of the dimensions was outside of the integer range." << endl;
			return 1;
		}

		if (width < 1 || height < 1) {
			cerr << "ERROR: both width and height must be positive integers." << endl;
			return 1;
		}

		if (width > maxWidth || height > maxHeight) {
			cerr << "ERROR: Dimensions outside of the range [1.." << maxWidth << "] x [1.." << maxHeight << "]" << endl;
			return 1;
		}
	}

	// generate and print the maze
	StandardRandomGenerator randomGenerator;
	const int* maze = generateMaze(width, height, 0, 0, randomGenerator);
	printMaze(maze, width, height);
	delete[] maze;
	return 0;
}