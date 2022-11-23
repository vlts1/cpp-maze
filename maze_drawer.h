#pragma once
#include <square.h>
class MazeDrawer {
private:
	Square _pickNearSquare(int currentRow, int currentCol, Square squares[31][31], bool removeWall = false);
public:
	void drawMaze();
};