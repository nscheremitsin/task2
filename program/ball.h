#ifndef TASK_BALL_H
#define TASK_BALL_H

// Ball.h contains Ball description

#include "shape.h"
#include "random.h"
#include <cmath>
#include <cstdio>


class Ball : public Shape {
public:
    // Freeing memory
    ~Ball() override {};

    // Read parameters from file
    void input(FILE* file) override;

    // Randomize parameters
    void randomize() override;

    // Output parameters in file
    void output(FILE* file) override;

    // Calculate volume
    double calculateVolume() override;
private:
    int radius;
};

#endif
