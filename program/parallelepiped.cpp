// Parallelepiped.cpp contains definition of functions for Parallelepiped creation, calculating and output

#include "parallelepiped.h"


void Parallelepiped::input(FILE *file) {
    fscanf(file, "%d", &edgeA);
    fscanf(file, "%d", &edgeB);
    fscanf(file, "%d", &edgeC);
}

void Parallelepiped::randomize() {
    edgeA = Shape::random20.get();
    edgeB = Shape::random20.get();
    edgeC = Shape::random20.get();
}

void Parallelepiped::output(FILE *file) {
    fprintf(file, "Rectangular parallelepiped. a = %d, b = %d, c = %d.  Volume = %f.  Density = %f\n",
            edgeA, edgeB, edgeC, calculateVolume(), density);
}

double Parallelepiped::calculateVolume() {
    return edgeA * edgeB * edgeC;
}
