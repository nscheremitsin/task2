#ifndef TASK_SHAPE_H
#define TASK_SHAPE_H

// Shape.h contains Shape description

#include "random.h"
#include <cstdio>


class Shape {
protected:
    static Random random20;
    static Random random3;
    double density;
public:
    // Freeing memory
    virtual ~Shape() {};

    // Read parameters from file
    static Shape* staticInput(FILE* file);

    // Read parameters from file (virtual)
    virtual void input(FILE* file) = 0;

    // Randomize parameters
    static Shape* staticRandomize();

    // Randomize parameters (virtual)
    virtual void randomize() = 0;

    // Output parameters in file (virtual)
    virtual void output(FILE* file) = 0;

    // Calculate volume (virtual)
    virtual double calculateVolume() = 0;
};

#endif //TASK_SHAPE_H
