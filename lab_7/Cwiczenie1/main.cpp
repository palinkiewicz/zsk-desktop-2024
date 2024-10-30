#include "Point2.h"
#include <iostream>

void printPointInfo(Point2 pt) {
    std::cout << "X: " << pt.getX() << ", Y: " << pt.getY() << "\n";
}

int main()
{
    Point2 pt = Point2(5.0f, 1.0f);
    printPointInfo(pt);

    pt.setX(1.0f);
    printPointInfo(pt);

    pt.setY(1.5f);
    printPointInfo(pt);
}
