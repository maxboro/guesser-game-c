#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// to be implemented
int get_random_number(int min_bound, int max_bound){

    // Setting seed for the rand() function
    srand(time(0));

    int random_number = rand() % (max_bound - min_bound + 1) + min_bound;
    return random_number;
}

int get_guess(){
    int user_guess;
    printf("Write your guess\n");
    int elements_written = scanf("%d", &user_guess);
    if (elements_written == 0){
        fprintf(stderr, "Error: elements_written %d\n", elements_written);
        return 1;
    }
    printf("User guess: %d\n", user_guess);
    return user_guess;
}
