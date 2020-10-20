/**
* Provides declarations of functions used to generate a maze.
*/
#pragma once
#include "RandomGenerator.h"

/**
* Represents a connection bewteen two rooms in a maze. Values of the enumerations are chosen, so
* that they can be combined and analysed using bit-wise operators.
*/
enum Directions {
	CELL_PATH_N = 0x01,
	CELL_PATH_W = 0x02,
	CELL_PATH_E = 0x04,
	CELL_PATH_S = 0x08,
};

/**
* Transforms the cell location [x, y] into x + y * mazeWidth, so that it can be used as an index
* in one-dimensional array representing a maze, indexed row-wise.
* @param x x-coordinate of a cell.
* @param y y-coordinate of a cell.
* @param mazeWidth Number of cells in each row of the maze.
* @return x + y * mazeWidth.
*/
int linearize(int x, int y, int mazeWidth);

/**
* @param Direction.
* @return The direction opposite to the given direction. North is the opposite of South, East is the
* opposite of West and vice-versa. If a number representing no valid direction is given, the result is
* undefined.
* @see Direction.
*/
int getOppositeDirection(int direction);

/**
* Generates a rectangular, four-directional maze, where each cell can be connected to up to four
* neighbours (north, south, east, west).
* The function uses a given pseudo random number generator to randomize the actual connection
* between cells, while ensuring that there will always exist a path bewteen any two cells.
* @param width Width of the maze. (number of columns)
* @param height Height of the maze. (number of rows)
* @param startX X-coordinate of a cell in which the generation will begin.
* @param startY Y-coordinate of a cell in which the generation will begin.
* @param randomGenerator pseudo random number generator to use when deciding which cells are
* to be connected.
* @return A one dimensional array of width*height elements, laid row-wise, where each element represents
* a cell. Each cell is number, whose bits represents open directions from this cell.
* @see Direction
*/
int* generateMaze(int width, int height, int startX, int startY, RandomGenerator& randomGenerator);