#include <square.h>
#include <maze_drawer.h>
#include <square_stack.h>
#include <rand_num_generator.h>
#include <path_marker.h>
#include <side_square.h>
#include <opposite_side_selector.h>
#include "maze_solver.h"
void MazeSolver::solve(Square squareGrid[31][31]) {
	SquareStack stack = SquareStack();
	PathMarker marker = PathMarker();
	RandNumGenerator random = RandNumGenerator();

	_markSquaresUnvisited(squareGrid);

	int r = 0;
	int c = 0;

	Square iter = squareGrid[r][c];
	iter.setVisited();
	marker.markSquare(iter.getRow() + 1, iter.getCol());
	stack.push(iter);

	while (r != 29 || c != 29) {
		
		Square neighborSq = _getUnvisitedNeighbor(iter, squareGrid);

		// If no unvisited squares available
		if (neighborSq.getRow() == -3 && neighborSq.getCol() == -3) {
			Square popped = stack.pop();
			marker.removeSquareMark(popped.getRow() + 1, popped.getCol());

			Square previousSquare = stack.pop();
			r = previousSquare.getRow();
			c = previousSquare.getCol();
			previousSquare.setVisited();
			squareGrid[previousSquare.getRow()][previousSquare.getCol()].setVisited();
			squareGrid[neighborSq.getRow()][neighborSq.getCol()].setVisited();
			stack.push(previousSquare);

		}
		else {

			r = neighborSq.getRow();
			c = neighborSq.getCol();

			neighborSq.setVisited();
			marker.markSquare(neighborSq.getRow() + 1, neighborSq.getCol());
			stack.push(neighborSq);
			squareGrid[neighborSq.getRow()][neighborSq.getCol()].setVisited();

		}
		iter = squareGrid[r][c];
	}
	cout << "r = 29, c = 29";

}

void MazeSolver::_markSquaresUnvisited(Square squareGrid[31][31]) {
	for (int r = 0; r < 30; r++) {
		for (int c = 0; c < 30; c++) {
			squareGrid[r][c].setNotVisited();
		}
	}
}

Square MazeSolver::_getUnvisitedNeighbor(Square sq, Square squareGrid[31][31]) {
	OppositeSideSelector oppositeSideSelector = OppositeSideSelector();
	for (int i = 0; i < 4; i++) {
		

		SideSquare sideSq = SideSquare(i, sq.getRow(), sq.getCol());
		
		bool isInNeighborOppositeSideAvailable = 
			squareGrid[sideSq.getRow()][sideSq.getCol()]
				.isSideAvailable(oppositeSideSelector.getOppositeSide(i));

		// If there is no wall in between two squares
		if (!sq.isSideAvailable(i) || !isInNeighborOppositeSideAvailable) {

			// If the side square has never been visited
			if (squareGrid[sideSq.getRow()][sideSq.getCol()].isVisited() == false) {

				// Check if square is in range
				if (sideSq.getRow() < 30 && sideSq.getRow() >= 0) {
					if (sideSq.getCol() < 30 && sideSq.getCol() >= 0) {

						return squareGrid[sideSq.getRow()][sideSq.getCol()];
					}
				}
			}
		}
	}

	return Square(-3, -3);
}