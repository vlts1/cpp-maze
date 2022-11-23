#pragma once
class SideSquare {
private:
	void _setLocation(int currentRow, int currentCol);
	int _row;
	int _col;
	int _relativeLocation;
public:
	SideSquare(int relativeLocation, int currentRow, int currentCol);
	int getRow();
	int getCol();
};