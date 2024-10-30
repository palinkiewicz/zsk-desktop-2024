#pragma once

class Point2 {
private:
	float x;
	float y;

public:
	Point2();
	Point2(float _x, float _y);

	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
};