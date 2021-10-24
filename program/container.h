#ifndef __container__
#define __container__

// Container.h contains Container description

#include "shape.h"


class Container {
public:
    // Initialization
    Container();

    // Freeing memory
    ~Container();

    // Read parameters from file for all shapes
    void input(FILE* file);

    // Randomize parameters for all shapes
    void randomize(int size);

    // Output parameters in file for all shapes
    void output(FILE* file, const char* message);

    // Calculate volume sum for all shapes
    double calculateAverageVolume();

    // Sorting depending on volume
    void sort();
private:
    int length; // текущая длина
    Shape* shapes[10000];
};

#endif
