#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <cmath>
#include <set>
#include <stack>

#define WIDTH 5000
#define DEPTH 4000
#define MIN_HEIGHT 1200
#define MAX_HEIGHT 3500
#define PI 3.1415

struct Point {
    short x;
    short y;

    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));

    // Przypisanie pamięci dla tablicy oraz generowanie danych
    short** terrain = (short**) new short* [WIDTH];

    if (terrain == NULL) {
        std::cout << u8"Błąd alokacji pamięci!\n";
        return 1;
    }

    for (short x = 0; x < WIDTH; x++) {
        terrain[x] = new short[DEPTH];

        if (terrain[x] == NULL) {
            std::cout << u8"Błąd alokacji pamięci dla wiersza " << x;
            return 1;
        }

        for (short y = 0; y < DEPTH; y++) {
            terrain[x][y] = rand() % (MAX_HEIGHT - MIN_HEIGHT + 1) + MIN_HEIGHT;
        }
    }

    // Wybranie losowych punktów
    short currentX = rand() % WIDTH;
    short currentY = rand() % DEPTH;
    short targetX = rand() % WIDTH;
    short targetY = rand() % DEPTH;

    std::cout << "Wybrane punkty:\n\tStart = (" << currentX << ", " << currentY << ")\n\tKoniec = (" << targetX << ", " << targetY << ")\n";

    // Losowe poszukiwanie drogi
    short dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    short dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    int steps = 0;

    std::set<Point> banned;
    std::stack<Point> pathStack;
    std::set<Point> stackSet;
    std::stack<double> anglesStack;

    Point currentPoint = { currentX, currentY };
    pathStack.push(currentPoint);
    stackSet.insert(currentPoint);

    while (!pathStack.empty()) {
        currentPoint = pathStack.top();
        currentX = currentPoint.x;
        currentY = currentPoint.y;

        if (currentX == targetX && currentY == targetY) {
            break;
        }

        bool foundNextMove = false;

        // Maksymalnie 100 prób odnalezienia odcinka
        for (int i = 0; i < 100; i++) {
            short nextMove = rand() % 8;
            short newX = currentX + dx[nextMove];
            short newY = currentY + dy[nextMove];

            Point newPoint = { newX, newY };

            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < DEPTH &&
                stackSet.find(newPoint) == stackSet.end() && banned.find(newPoint) == banned.end()) {

                // Obliczanie kąta
                double d_xy = sqrt(abs(dx[nextMove]) + abs(dy[nextMove]));
                double d_z = abs(terrain[newX][newY] - terrain[currentX][currentY]);

                anglesStack.push(abs(atan2(d_z, d_xy) * 180 / PI));
                steps++;

                // Aktualizacja ścieżki
                currentX = newX;
                currentY = newY;
                currentPoint = newPoint;

                pathStack.push(currentPoint);
                stackSet.insert(currentPoint);

                foundNextMove = true;
                break;
            }
        }

        if (!foundNextMove) {
            banned.insert(currentPoint);
            stackSet.erase(currentPoint);
            pathStack.pop();
            anglesStack.pop();
        }

        if (steps % 10000 == 0) {
            std::cout << "Aktualny krok: " << steps << "\n";
        }
    }

    // Zwolnienie pamięci
    for (short x = 0; x < WIDTH; x++) {
        delete[] terrain[x];
    }
    delete[] terrain;

    // Obliczenia końcowe
    if (steps > 0) {
        double totalSlope = 0.0;

        while (!anglesStack.empty()) {
            totalSlope += anglesStack.top();
            anglesStack.pop();
        }

        double averageSlope = totalSlope / pathStack.size();
        std::cout << u8"\nŚrednie nachylenie drogi: " << averageSlope << " stopni\n";
    }
    else {
        std::cout << u8"\nNie udało się przejść drogi.\n";
    }

    return 0;
}