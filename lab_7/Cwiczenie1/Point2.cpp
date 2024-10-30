#include "Point2.h"

Point2::Point2() {
	x = 0.0f;
	y = 0.0f;
}

Point2::Point2(float _x, float _y) {
	x = _x;
	y = _y;
}

void Point2::setX(float _x) {
	x = _x;
}

void Point2::setY(float _y) {
	y = _y;
}

float Point2::getX() {
	return x;
}

float Point2::getY() {
	return y;
}