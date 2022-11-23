#include "square_queue.h"
#include <square.h>
#include <iostream>
using namespace std;

	SquareQueue::SquareQueue() {}
	bool SquareQueue::isFull() {
		return size == capacity;
	}

	bool SquareQueue::isEmpty() {
		return size == 0;
	}

	void SquareQueue::enq(Square s) {
		if (isFull()) {
			cout << "square queue overflow";
			exit(1);
		}
		rear = (rear + 1) % capacity;
		squares[rear] = s;
		size++;
	}

	Square SquareQueue::deq() {
		if (isEmpty()) {
			cout << "square queue underflow";
			exit(1);
		}
		front += 1;
		front = front % capacity;
		Square sq = squares[front];
		size--;
		return sq;
	}