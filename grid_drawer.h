#pragma once
#include <square_queue.h>
#include <square.h>
class GridDrawer {
private:
	void _drawSquareLine(int rowWidth, int currentRow);
public: 
	void drawSquaresGrid(int rowWidth, int rowCount);
};