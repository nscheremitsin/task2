// Shape.cpp contains definition of functions for Shape creation, calculating and output

#include "ball.h"
#include "parallelepiped.h"
#include "tetrahedron.h"


Random Shape::random20(1, 20);
Random Shape::random3(1, 3);


Shape* Shape::staticInput(FILE* file) {
    int key;
    fscanf(file, "%d", &key);
    double density;
    switch (key) {
        case 1:
        case 2:
        case 3:
            fscanf(file, "%lf", &density);
            break;
        default:
            density = 0.0;
            break;
    }
    Shape* shape;
    switch(key) {
        case 1:
            shape = new Ball;
            break;
        case 2:
            shape = new Tetrahedron;
            break;
        case 3:
            shape = new Parallelepiped;
            break;
        default:
            return nullptr;
    }
    shape->density = density;
    shape->input(file);
    return shape;
}

Shape *Shape::staticRandomize() {
    auto key = Shape::random3.get();
    double density = Shape::random3.get() % 10
                     + Shape::random3.get() % 10 / 10.0
                     + Shape::random3.get() % 100 / 100.0
                     + Shape::random3.get() % 1000 / 1000.0;
    Shape* shape;
    switch(key) {
        case 1:
            shape = new Ball;
            break;
        case 2:
            shape = new Tetrahedron;
            break;
        case 3:
            shape = new Parallelepiped;
            break;
        default:
            return nullptr;
    }
    shape->density = density;
    shape->randomize();
    return shape;
}
