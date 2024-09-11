#include <iostream>
#include <cmath>

double* quadratic_function(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    double* pt;

    if (delta < 0) {
        pt = nullptr;
    }
    else if (delta == 0) {
        pt = new double[1];
        pt[0] = (-1.0 * b) / (2.0 * a);
    }
    else {
        pt = new double[2];
        pt[0] = (-1.0 * b - sqrt(delta)) / (2.0 * a);
        pt[1] = (-1.0 * b + sqrt(delta)) / (2.0 * a);
    }

    return pt;
}

int main()
{
    double* res = quadratic_function(1.0, -4.0, -5.0);

    std::cout << res[0] << " " << res[1];
}
