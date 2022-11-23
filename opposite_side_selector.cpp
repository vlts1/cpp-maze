#include "opposite_side_selector.h"
#include <square.h>
#include <iostream>

// Used to perform an action both on the selected square
// and on the specified neighbor square

int OppositeSideSelector::getOppositeSide(int side) {
	Square s = Square();
	if (side == s.top) {
		return s.bottom;
	}
	if (side == s.bottom) {
		return s.top;
	}
	if (side == s.right) {
		return s.left;
	}
	if (side == s.left) {
		return s.right;
	}
	std::cout << "--------- Get opposite side ERROR \n";
	return -1;
}