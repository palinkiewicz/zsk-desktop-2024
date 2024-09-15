#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(nullptr));

    double temps[50][40][27];

    uint8_t maxIndex = 0;
    double maxAvg = 0.0;

    for (uint8_t i = 0; i < 50; i++) {
        double avg = 0.0;

        for (uint8_t j = 0; j < 40; j++) {
            for (uint8_t k = 0; k < 27; k++) {
                temps[i][j][k] = (double)(rand() % 701 + 1800) / 100.0;
                avg += temps[i][j][k];
            }
        }

        avg /= 40 * 27;

        if (avg > maxAvg) {
            maxIndex = i;
            maxAvg = avg;
        }
    }

    SetConsoleOutputCP(CP_UTF8);
    std::cout << u8"Największa średnia temperatura (" << maxAvg << "^C) odnaleziona w przekroju " << (short) maxIndex << ".\n";
}
