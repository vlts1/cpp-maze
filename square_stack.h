#pragma once
#include <square.h>
#include <iostream>
using namespace std;

class SquareStack
{
private:
	Square array[1000] = {};
	int index = 0;

	void _setIndexFirstEmpty();
public:
	SquareStack();

	bool isFull();

	bool isEmpty();

	void push(Square sq);

	Square pop();
};