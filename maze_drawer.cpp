#include "maze_drawer.h"
#include <grid_drawer.h>
#include <square.h>
#include <iostream>
#include <rand_num_generator.h>
#include <opposite_side_selector.h>
#include <visited_sides.h>
#include <side_square.h>
#include <global_visited_sides.h>
#include <maze_solver.h>
#
using namespace std;

// Main algorithm for turning a grid into a maze
Square MazeDrawer::_pickNearSquare(int currentRow, int currentCol, Square squares[31][31], bool removeWall) {
	RandNumGenerator rand = RandNumGenerator();
	OppositeSideSelector oppositeSideSelector = OppositeSideSelector();
	int triesTimeout = 0;
	while (true) {

		int currentSquareRandSide = rand.getRandNum(0, 3);
		//cout << currentSquareRandSide << endl;
		// Creating a square behind the random side
		SideSquare squareBehindRandomSide = SideSquare(currentSquareRandSide, currentRow, currentCol);

		// Checks whether the coordinates are in range of the maze
		// To pick only the adjoining square
		if (squareBehindRandomSide.getCol() < 30 && squareBehindRandomSide.getCol() >= 0) {
			if (squareBehindRandomSide.getRow() < 30 && squareBehindRandomSide.getRow() >= 0) {

				// Implementing the square from the side square
				Square nearSquare = squares[squareBehindRandomSide.getRow()][squareBehindRandomSide.getCol()];
				Square currentSquare = squares[currentRow][currentCol];
				// Mark as visited right after object creation
				currentSquare.setVisited();


				GlobalVisitedSides().markVisitedSides(currentSquare, squares);

				if (currentSquare.visitedPhysicalSides.isSideVisited(currentSquareRandSide)) {
					// If all adjoining squares have been visited, go back until 
					// a square with unchecked sides is found
					triesTimeout++;

					if (currentSquare.visitedPhysicalSides.allVisited() || triesTimeout == 40) {
						//cout << "All visited" << endl;
						triesTimeout = 0;
						return Square(-1, -1);
					}
				}
				else if (nearSquare.isVisited() == false) {
					triesTimeout = 0;
					// Mark the square as the one that has been visited at least once
					nearSquare.setVisited();
					
					// Mark only the SIDE as visited, not the entire square 
					// for both the current square, and square behind the wall
					currentSquare.visitedPhysicalSides.addVisitedSide(currentSquareRandSide);
					nearSquare.visitedPhysicalSides.addVisitedSide(oppositeSideSelector.getOppositeSide(currentSquareRandSide));
					

					if (removeWall) {
						// Since both the starting square, and the connecting
						// square have a side in common, this code removes the 
						// side from both squares
						currentSquare.removeSide(currentSquareRandSide);
						nearSquare.removeSide(oppositeSideSelector.getOppositeSide(currentSquareRandSide));
					}


					squares[nearSquare.getRow()][nearSquare.getCol()] = nearSquare;
					squares[currentSquare.getRow()][currentSquare.getCol()] = currentSquare;
					return nearSquare;
				}
			}
		}
	}
}




void MazeDrawer::drawMaze() {
	GridDrawer gridDrawer = GridDrawer();
	gridDrawer.drawSquaresGrid(30, 30);

	SquareQueue queue = SquareQueue();


	// Initialize array
	Square squares[31][31];
	for (int row = 0; row < 30; row++) {
		for (int col = 0; col < 30; col++) {
			squares[row][col] = Square(row, col);
		}
	}

	Square squareIter = squares[0][0];

	int r = 0;
	int c = 0;

	do {
		// If all sides have been visited, go back
		if (squareIter.getRow() == -1 && squareIter.getCol() == -1) {
			squareIter = queue.deq();
		}
		else {
			queue.enq(squareIter);
		}
		// Set location of the current square
		r = squareIter.getRow();
		c = squareIter.getCol();

		// Assign a random neighbor square to the current one
		squareIter = _pickNearSquare(r, c, squares, true);
	} 
	while (queue.isEmpty() == false);

	cout << "Maze is finished\n";

	MazeSolver solver = MazeSolver();
	solver.solve(squares);

	squares[0][0].removeSide(3);
	squares[29][29].removeSide(1);
}

