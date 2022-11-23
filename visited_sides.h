#pragma once
class VisitedSides {
private:
	bool _sides[4] = { false, false, false, false };
public:
	void addVisitedSide(int side);
	bool isSideVisited(int side);
	bool allVisited();
};