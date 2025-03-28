#include <stdio.h>
#include "utils.c"

int main(){
    int min_bound = 0;
    int max_bound = 9;
    int random_number = get_random_number(min_bound, max_bound);

    int user_guess = get_guess();

    printf("Guess is ");
    if (random_number == user_guess){
        printf("correct\n");
    } else {
        printf("not correct\n");
    }

    return 0;
}
