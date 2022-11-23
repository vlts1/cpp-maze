#include "global_visited_sides.h"
#include <square.h>
#include <side_square.h>
#include <opposite_side_selector.h>
bool GlobalVisitedSides::squareExists(Square square) {
	if (square.getCol() > 29 || square.getCol() < 0) {
		return false;
	}
	if (square.getRow() > 29 || square.getRow() < 0) {
		return false;
	}
	return true;
}

void GlobalVisitedSides::markSide(Square square, Square neighborSquare, int neighborPosition) {
	OppositeSideSelector oppositeSideSelector = OppositeSideSelector();
	int oppositeNeighborSide = oppositeSideSelector.getOppositeSide(neighborPosition);

	if (squareExists(neighborSquare)) {
		if (neighborSquare.isVisited()) {
			square.visitedPhysicalSides.addVisitedSide(neighborPosition);
		}
	}
	else {
		// If side is a wall, mark as visited
		square.visitedPhysicalSides.addVisitedSide(neighborPosition);
	}
}

void GlobalVisitedSides::markVisitedSides(Square square, Square squareArray[31][31]) {

	SideSquare squareAbove	  = SideSquare(square.top,	  square.getRow(), square.getCol());
	SideSquare squareBelow	  = SideSquare(square.bottom, square.getRow(), square.getCol());
	SideSquare squareToRight  = SideSquare(square.right,  square.getRow(), square.getCol());
	SideSquare squareToLeft   = SideSquare(square.left,	  square.getRow(), square.getCol());
	
	markSide(square, Square(squareAbove  .getRow(), squareAbove  .getCol()), square.top   );
	markSide(square, Square(squareBelow  .getRow(), squareBelow  .getCol()), square.bottom);
	markSide(square, Square(squareToRight.getRow(), squareToRight.getCol()), square.right );
	markSide(square, Square(squareToLeft .getRow(), squareToLeft .getCol()), square.left  );
	
	squareArray[square.getRow()][square.getCol()] = square;
}
