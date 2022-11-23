#pragma once
#include <square.h>

class GlobalVisitedSides {
private:
	bool squareExists(Square square);
	void markSide(Square square, Square neighborSquare, int neighborPosition);
public:
	void markVisitedSides(Square square, Square squareArray[31][31]);
};