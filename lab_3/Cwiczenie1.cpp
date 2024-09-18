#include <iostream>

int main()
{
    int x;
    // std::cout << x << "\n";

    x = 10;
    std::cout << x << "\n";

    int* adres = &x;
    std::cout << adres << "\n";

    int* y;
    // std::cout << y << "\n";

    y = new int;
    std::cout << y << "\n";

    *y = 20;
    std::cout << *y << "\n";

    delete y;
    std::cout << y << "\n";
}
