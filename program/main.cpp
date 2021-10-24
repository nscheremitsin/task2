
// main.cpp contains main function

#include <cstring>
#include <ctime>
#include "container.h"


// Informing about errors
void printErrorMessage() {
    printf("Incorrect command line or qualifier value!\n"
           "Waited:\n"
           "\tcommand -f input_file output_file_1 output_file_2\n"
           "Or:\n"
           "\tcommand -n number output_file_1 output_file_2\n");
}

// Testing program
int main(int argc, char* argv[]) {
    if(argc != 5) {
        printErrorMessage();
        return 1;
    }

//    clock_t start_time = clock();
    printf("Start\n");
    Container container;

    // Populating container with 1 of 2 methods
    if (!strcmp(argv[1], "-f")) {
        FILE* input_file = fopen(argv[2], "r");
        container.input(input_file);
    }
    else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("Incorrect number of figures = %n. Set 0 < number <= 10000\n", &size);
            return 3;
        }
        srand(static_cast<unsigned int>(time(nullptr)));
        container.randomize(size);
    }
    else {
        printErrorMessage();
        return 2;
    }

    // Outputting populated container in file 1.
    FILE* output_file_one = fopen(argv[3], "w");
    container.output(output_file_one, "Container has %d elements:\n");

    // Outputting result of calculations in file 2.
    FILE* output_file_two = fopen(argv[4], "w");
    container.sort();
    container.output(output_file_two, "Container has %d elements after sorting in the following order:\n");

    printf("Stop");
//    printf("\nRuntime: %lf sec", (double)(clock() - start_time) / CLOCKS_PER_SEC);
    return 0;
}
