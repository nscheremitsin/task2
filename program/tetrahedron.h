#ifndef TASK_TETRAHEDRON_H
#define TASK_TETRAHEDRON_H

// Tetrahedron.h contains Tetrahedron description

#include "shape.h"
#include "random.h"
#include <cmath>
#include <cstdio>


class Tetrahedron : public Shape {
public:
    // Freeing memory
    ~Tetrahedron() override {};

    // Read parameters from file
    void input(FILE* file) override;

    // Randomize parameters
    void randomize() override;

    // Output parameters in file
    void output(FILE* file) override;

    // Calculate volume
    double calculateVolume() override;
private:
    int edge;
};

#endif
