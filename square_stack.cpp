#include "square_stack.h"
#include <iostream>
#include <square.h>

using namespace std;

void SquareStack::_setIndexFirstEmpty() {
	for (int i = 0; i < 1000; i++) {
		if (array[i].getCol() == -2 && array[i].getRow() == -2) {
			index = i;
			break;
		}
	}
}

SquareStack::SquareStack() {
	for (int i = 0; i < 1000; i++) {
		array[i] = Square(-2, -2);
	}
}

bool SquareStack::isFull()
{
	if (array[999].getCol() != -2 && array[999].getRow() != -2) {
		return true;
	}
	return false;
}
bool SquareStack::isEmpty()
{
	for (int i = 0; i < 1000; i++) {
		if (array[i].getCol() != -2 && array[i].getRow() != -2) {
			return false;
		}
	}
	return true;
}

void SquareStack::push(Square sq)
{
	if (isFull())
	{
		cout << "Stack overrrun" << endl;
		exit(1);
		return;
	}
	_setIndexFirstEmpty();
	array[index] = sq;
	cout << "I:pushed \n";
}

Square SquareStack::pop()
{
	if (isEmpty())
	{
		cout << "Integer Stack underrun" << endl;
		exit(2);
		return Square(-4, -4);
	}
	_setIndexFirstEmpty();
	Square sq = array[index - 1];
	cout << "I:popped " << endl;
	array[index - 1] = Square(-2, -2);
	return sq;
}
