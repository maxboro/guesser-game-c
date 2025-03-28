#include <stdlib.h>
#include <time.h>

int get_random_number(int min_bound, int max_bound){

    // Setting seed for the rand() function
    srand((unsigned int) time(0));

    int random_number = rand() % (max_bound - min_bound + 1) + min_bound;
    return random_number;
}
