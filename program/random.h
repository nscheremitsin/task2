#ifndef __rnd__
#define __rnd__

// random.h contains function for getting random int

#include <cstdlib>
#include <ctime>


class Random {
public:
    // Initialization
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        srand(static_cast<unsigned int>(time(0)));
    }

    // Generating random number in range
    int get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};

#endif
