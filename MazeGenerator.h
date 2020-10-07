#pragma once
#include "RandomGenerator.h"

enum Directions {
	CELL_PATH_N = 0x01,
	CELL_PATH_W = 0x02,
	CELL_PATH_E = 0x04,
	CELL_PATH_S = 0x08,
};

int linearize(int x, int y, int mazeWidth);

int getOppositeDirection(int direction);

int* generateMaze(int width, int height, int startX, int startY, RandomGenerator& randomGenerator);