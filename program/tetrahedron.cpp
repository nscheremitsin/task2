// Tetrahedron.cpp contains definition of functions for Tetrahedron creation, calculating and output

#include "tetrahedron.h"


void Tetrahedron::input(FILE *file) {
    fscanf(file, "%d", &edge);
}

void Tetrahedron::randomize() {
    edge = Shape::random20.get();
}

void Tetrahedron::output(FILE *file) {
    fprintf(file, "Regular tetrahedron.        a = %d.                Volume = %f.  Density = %f\n",
            edge, calculateVolume(), density);
}

double Tetrahedron::calculateVolume() {
    return pow(edge, 3) * sqrt(2) / 12;
}
