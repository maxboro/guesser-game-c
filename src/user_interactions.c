#include <stdio.h>
#include <stdbool.h>

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

void final_message(bool is_win){
    printf("Game over: You ");
    if (is_win){
        printf("won\n");
    } else {
        printf("lost\n");
    }
}

void game_cycle(int random_number, bool* is_win_ptr){
    int user_guess = get_guess();

    printf("Guess is ");
    if (random_number == user_guess){
        printf("correct\n");
        *is_win_ptr = true;
    } else {
        printf("not correct\n");
    }
}
