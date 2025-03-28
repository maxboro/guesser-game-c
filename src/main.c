#include <stdio.h>
#include "utils.c"

int main(){
    int min_bound = 0;
    int max_bound = 9;
    int rand = get_random_number(min_bound, max_bound);

    int user_guess;
    printf("Write your guess\n");
    scanf("%d", &user_guess);
    printf("User guess: %d\n", user_guess);

    printf("Guess is ");
    if (rand == user_guess){
        printf("correct\n");
    } else {
        printf("not correct\n");
    }

    return 0;
}
