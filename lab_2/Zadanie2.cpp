#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <cmath>

#define WIDTH 5000
#define DEPTH 4000
#define MIN_HEIGHT 1200
#define MAX_HEIGHT 3500

static double euclidean_distance(short x1, short y1, short z1, short x2, short y2, short z2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

static double two_triangles_area(short h1, short h2, short h3, short h4) {
    // Wysokoœci: h1 - punkt g³ówny; h2 - punkt wy¿ej; h3 - punkt na skos; h4 - punkt po lewej
    double dist1_2 = euclidean_distance(0, 0, h1, 0, 1, h2);
    double dist1_3 = euclidean_distance(0, 0, h1, 1, 1, h3);
    double dist1_4 = euclidean_distance(0, 0, h1, 1, 0, h4);
    double dist2_3 = euclidean_distance(0, 1, h2, 1, 1, h3);
    double dist3_4 = euclidean_distance(1, 1, h2, 1, 0, h4);

    double p1 = dist1_2 + dist1_3 + dist2_3;
    double a1 = sqrt(p1 * (p1 - dist1_2) * (p1 - dist1_3) * (p1 - dist2_3));

    double p2 = dist1_4 + dist1_3 + dist3_4;
    double a2 = sqrt(p2 * (p2 - dist1_4) * (p2 - dist1_3) * (p2 - dist3_4));

    return a1 + a2;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Przypisanie pamiêci dla tablicy
    short** terrain = (short**) new short[WIDTH * sizeof(short*)];

    if (terrain == NULL) {
        std::cout << u8"B³¹d alokacji pamiêci!\n";
        return 1;
    }

    for (short i = 0; i < WIDTH; i++) {
        terrain[i] = (short*) new short[DEPTH * sizeof(short)];
        if (terrain[i] == NULL) {
            std::cout << u8"B³¹d alokacji pamiêci dla wiersza " << i;
            return 1;
        }
    }

    // Generowanie danych oraz obliczenia
    srand(time(nullptr));
    double area = 0.0;

    for (short x = 0; x < WIDTH; x++) {
        for (short y = 0; y < DEPTH; y++) {
            terrain[x][y] = rand() % (MAX_HEIGHT - MIN_HEIGHT + 1) + MIN_HEIGHT;

            if (x > 0 && y > 0) {
                area += two_triangles_area(terrain[x][y], terrain[x][y - 1], terrain[x - 1][y - 1], terrain[x - 1][y]);
            }
        }
    }

    // Zwolnienie pamiêci
    for (int i = 0; i < WIDTH; i++) {
        delete[] terrain[i];
    }
    delete[] terrain;

    std::cout << "Pole powierzchni terenu wynosi " << area << " m^2\n";
}