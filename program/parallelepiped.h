#ifndef TASK_PARALLELIPIPED_H
#define TASK_PARALLELIPIPED_H

// Parallelepiped.h contains Parallelepiped description

#include "shape.h"
#include "random.h"
#include <cstdio>
#include <cstdio>


class Parallelepiped : public Shape {
public:
    // Freeing memory
    ~Parallelepiped() override {};

    // Read parameters from file
    void input(FILE* file) override;

    // Randomize parameters
    void randomize() override;

    // Output parameters in file
    void output(FILE* file) override;

    // Calculate volume
    double calculateVolume() override;
private:
    int edgeA, edgeB, edgeC;
};

#endif
