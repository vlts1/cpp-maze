
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "square.h"
#include <stdio.h>
#include <math.h>
#include <random>
#include <grid_drawer.h>
#include <square_queue.h>
#include <maze_drawer.h>
#include "path_marker.h"

using namespace cv;
using namespace std;
#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define QUEUE_SIZE 50

char wndname[] = "TurtleWindow";
Mat image = Mat::zeros(1000, 1000, CV_8UC3);
Scalar WHITE(255, 255, 255);
const int DELAY = 1;
Point _curPosition(250, 250);
int _direction = 0;



void init()
{
	imshow(wndname, image);
	waitKey(DELAY);
}

void changePosition(int x, int y)
{
	_curPosition.x = x;
	_curPosition.y = y;
}

void changeDirection(int direction)
{
	_direction = direction;
}

void moveForward(int nPixels, cv::Scalar color, bool repaint = true)
{
	int x = static_cast<int>(round(nPixels * cos(degToRad(_direction))));
	int y = static_cast<int>(round(nPixels * sin(degToRad(_direction))));
	Point newPoint = Point(x + _curPosition.x, y + _curPosition.y);
	line(image, _curPosition, newPoint, color);
	_curPosition = newPoint;

	if (repaint) {
		imshow(wndname, image);
		waitKey(DELAY);
	}

}

// Definitions for the square and path marker are defined in the 
// main file because depend on the drawing functions


void PathMarker::markSquare(int row, int col) {
	putText(image, "o", Point(col * 25, row * 25 - 3), FONT_HERSHEY_DUPLEX, 0.5, WHITE);
	imshow(wndname, image);
	waitKey(DELAY);
}

void PathMarker::removeSquareMark(int row, int col) {
	putText(image, "o", Point(col * 25, row * 25 - 3), FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0, 0));
	imshow(wndname, image);
	waitKey(DELAY);
}


Square::Square(int row, int col) {
	_row = row;
	_col = col;
}
Square::Square()  {
	_row = 0;
	_col = 0;
}

bool Square::isSideAvailable(int side) {
	return _sides[side];
}

void Square::setNotVisited() {
	_isVisited = false;
}

void Square::removeSide(int sideIndex) {
	_sides[sideIndex] = false;
	// Draws/redraws the square on side removal. 
	draw();
}
void Square::setVisited() {
	_isVisited = true;
}
bool Square::isVisited() {
	return _isVisited;
}

int Square::getRow() {
	return _row;
}
int Square::getCol() {
	return _col;
}
void Square::draw() {
	int myDirection = 0;
	changePosition(_col * 25, _row * 25);

	for (int i = 0; i < 4; i++) {
		if (_sides[i] == false) {
			moveForward(25, cv::Scalar(0, 0, 0));
		}
		else {
			moveForward(25, cv::Scalar(255, 255, 255));
		}
		myDirection += 90;
		changeDirection(myDirection);
	}
	changeDirection(0);
}



int main()
{
	init();


	MazeDrawer mazeDr = MazeDrawer();
	mazeDr.drawMaze();


	waitKey();
	return 0;
}
