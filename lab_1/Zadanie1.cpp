#include <iostream>
#include <cmath>

double* quadratic_function(double a, double b, double c, int &size) {
    double delta = b * b - 4 * a * c;
    double* pt;

    if (delta < 0) {
        pt = nullptr;
        size = 0;
    }
    else if (delta == 0) {
        pt = new double[1];
        pt[0] = (-1.0 * b) / (2.0 * a);
        size = 1;
    }
    else {
        pt = new double[2];
        pt[0] = (-1.0 * b - sqrt(delta)) / (2.0 * a);
        pt[1] = (-1.0 * b + sqrt(delta)) / (2.0 * a);
        size = 2;
    }

    return pt;
}

int main()
{
    int size;
    double* res = quadratic_function(-1.0, 4.0, -4.0, size);

    if (size == 0) {
        std::cout << "Brak pierwiastka\n";
    } else if (size == 1) {
        std::cout << "Jeden pierwiastek: " << res[0] << "\n";
    } else if (size == 2) {
        std::cout << "Dwa pierwiastki: " << res[0] << ", " << res[1] << "\n";
    }

    delete[] res;
}
