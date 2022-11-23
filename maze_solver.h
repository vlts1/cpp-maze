#pragma once
class MazeSolver {

public:
	void solve(Square squareGrid[31][31]);
	void _markSquaresUnvisited(Square squareGrid[31][31]);
	Square _getUnvisitedNeighbor(Square sq, Square squareGrid[31][31]);
};