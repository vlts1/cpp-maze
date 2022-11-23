#include "visited_sides.h"
#include <iostream>

using namespace std;
// Makes each square remember its visited sides
void VisitedSides::addVisitedSide(int side) {
	_sides[side] = true;
}

bool VisitedSides::isSideVisited(int side) {
	return _sides[side];
}

bool VisitedSides::allVisited() {
	for (int i = 0; i < 4; i++) {
		if (_sides[i] == false) {
			return false;
		}
	}
	return true;
}