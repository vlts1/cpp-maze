#pragma once
#include <visited_sides.h>
class Square {
private:
	bool _sides[4] = {true, true, true, true};
	int _row;
	int _col;
	bool _isVisited = false;
public:
	// Physical sides needed for drawing the maze
	// and checking visited squares
	VisitedSides visitedPhysicalSides = VisitedSides();
	static const int top = 0;
	static const int bottom = 2;
	static const int left = 3;
	static const int right = 1;

	Square(int row, int col);
	Square();
	
	// Visible sides needed for finding the exit and
	// removing the walls
	bool isSideAvailable(int side);
	int getRow();
	int getCol();
	void setNotVisited();
	void setVisited();
	// Set to true if it has been visited at least once
	bool isVisited();
	void removeSide(int sideIndex);
	void draw();
};

