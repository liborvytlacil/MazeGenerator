// MazeGenerator.cpp : Defines the entry point for the application.
//

#include "MazeGenerator.h"
#include <iostream>
#include <stack>
#include <set>
#include <vector>

using namespace std;



int linearize(int x, int y, int mazeWidth) {
	return x + y * mazeWidth;
}

int getOppositeDirection(int direction) {
	switch (direction)
	{
	case CELL_PATH_N:
		return CELL_PATH_S;
	case CELL_PATH_S:
		return CELL_PATH_N;
	case CELL_PATH_W:
		return CELL_PATH_E;
	case CELL_PATH_E:
		return CELL_PATH_W;
	default:
		return direction;
	}
}

int* generateMaze(int width, int height, int startX, int startY, RandomGenerator &randomGenerator) {
	stack<pair<int, int>> stack;
	set<pair<int, int>> visited;

	const size_t mazeSize = (size_t)width * height;
	int* maze = new int[mazeSize];
	for (int i = 0; i < mazeSize; ++i) {
		maze[i] = 0;
	}

	stack.push(make_pair(startX, startY));
	while (visited.size() < mazeSize) {
		const pair<int, int> currentCell = stack.top();

		// mark as visited
		visited.insert(currentCell);

		// Create a vector of available neigbours
		vector<pair<int, pair<int, int>>> neighbours;
		const int x = currentCell.first;
		const int y = currentCell.second;

		if (y > 0 && visited.find(make_pair(x, y - 1)) == visited.cend()) { // north
			neighbours.push_back(make_pair(CELL_PATH_N, make_pair(x, y - 1)));
		}

		if (x > 0 && visited.find(make_pair(x - 1, y)) == visited.cend()) { // west
			neighbours.push_back(make_pair(CELL_PATH_W, make_pair(x - 1, y)));
		}

		if (y < height - 1 && visited.find(make_pair(x, y + 1)) == visited.cend()) { // south
			neighbours.push_back(make_pair(CELL_PATH_S, make_pair(x, y + 1)));
		}

		if (x < width - 1 && visited.find(make_pair(x + 1, y)) == visited.cend()) { // east
			neighbours.push_back(make_pair(CELL_PATH_E, make_pair(x + 1, y)));
		}

		if (!neighbours.empty()) {
			// pick a random available neighbour, connect it to the current cell and push it to the stack
			// to be visited in the next iteration
			const pair<int, pair<int, int>> neighbourData = neighbours[randomGenerator.next(neighbours.size())];
			const int direction = neighbourData.first;
			const pair<int, int> neighbour = neighbourData.second;

			maze[linearize(x, y, width)] |= direction;
			maze[linearize(neighbour.first, neighbour.second, width)] |= getOppositeDirection(direction);
			stack.push(neighbour);
		}
		else {
			// backtrack
			stack.pop();
		}
	}
	return maze;
}

