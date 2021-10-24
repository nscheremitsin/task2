// Ball.cpp contains definition of functions for Ball creation, calculating and output

#include "ball.h"


void Ball::input(FILE *file) {
    fscanf(file, "%d", &radius);
}

void Ball::randomize() {
    radius = Shape::random20.get();
}

void Ball::output(FILE *file) {
    fprintf(file, "Ball.                       r = %d.                Volume = %f.  Density = %f\n",
            radius, calculateVolume(), density);
}

double Ball::calculateVolume() {
    return M_PI * 4 / 3 * pow(radius, 3);
}
