#include <iostream>
#include <cmath>

struct point {
    double x;
    double y;
};

double triange_area(point a, point b, point c) {
    return 0.5 * abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

int main() {
    struct point a = {1.0, 3.0};
    struct point b = {4.0, 0.0};
    struct point c = {-2.0, 1.0};

    std::cout << "Pole: " << triange_area(a, b, c) << "\n";
}