#include "grid_drawer.h"
#include <square.h>
#include <iostream>
#include <square_queue.h>
using namespace std;

void GridDrawer::_drawSquareLine(int rowWidth, int currentRow) {
	int column = 0;
	while (column < rowWidth) {
		Square sq = Square(currentRow, column);
		sq.draw();
		column++;
	}
}

void GridDrawer::drawSquaresGrid(int rowWidth, int rowCount) {
	cout << "Drawing a 30x30 grid..." << endl;

	for (int row = 0; row < rowCount; row++) {
		_drawSquareLine(rowWidth, row);
	}
}

