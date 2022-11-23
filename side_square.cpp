#include "side_square.h"
#include <square.h>

// Represents the square behind the specified relativeLocation
SideSquare::SideSquare(int relativeLocation, int currentRow, int currentCol) {
	_relativeLocation = relativeLocation;
	_setLocation(currentRow, currentCol);
}

void SideSquare::_setLocation(int currentRow, int currentCol) {
	_row = currentRow;
	_col = currentCol;

	Square sqValues = Square();

	switch (_relativeLocation) {
	case sqValues.top:
		_row -= 1;
		break;

	case sqValues.bottom:
		_row += 1;
		break;

	case sqValues.right:
		_col += 1;
		break;

	case sqValues.left:
		_col -= 1;
		break;
	}
}

int SideSquare::getRow() {
	return _row;
}
int SideSquare::getCol() {
	return _col;
}