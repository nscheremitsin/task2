// Container.cpp contains definition of functions for Container creation, calculating and output

#include "container.h"


Container::Container(): length{0} { }

Container::~Container() {
    for (int i = 0; i < length; i++) {
        delete shapes[i];
    }
    length = 0;
}

void Container::input(FILE* file) {
    int size;
    fscanf(file, "%d", &size);
    for (int i = 0; i < size; ++i) {
        if ((shapes[length] = Shape::staticInput(file)) != nullptr) {
            length++;
        }
    }
}

void Container::randomize(int size) {
    for (int i = 0; i < size; ++i) {
        if ((shapes[length] = Shape::staticRandomize()) != nullptr) {
            length++;
        }
    }
}

void Container::output(FILE* file, const char* message) {
    fprintf(file, message, length);
    for (int i = 0; i < length; ++i) {
        shapes[i]->output(file);
    }
}

double Container::calculateAverageVolume() {
    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += shapes[i]->calculateVolume();
    }
    return sum / length;
}

void Container::sort() {
    double averageVolume = calculateAverageVolume();
    Container* container_sorted = new Container;
    for (int i = 0; i < this->length; ++i) {
        if (this->shapes[i]->calculateVolume() > averageVolume) {
            if ((container_sorted->shapes[container_sorted->length] = this->shapes[i]) != nullptr) {
                container_sorted->length++;
            }
        }
    }
    for (int i = 0; i < this->length; ++i) {
        if (this->shapes[i]->calculateVolume() <= averageVolume) {
            if ((container_sorted->shapes[container_sorted->length] = this->shapes[i]) != nullptr) {
                container_sorted->length++;
            }
        }
    }
    *this = *container_sorted;
}
