#pragma once
#include <square.h>

class SquareQueue {
private:
	int capacity = 2000;
	Square squares[2000] = {};
	int size = 0;
	int front = -1;
	int rear = -1;
public:
	SquareQueue();
	bool isFull();

	bool isEmpty();

	void enq(Square s);

	Square deq();
};