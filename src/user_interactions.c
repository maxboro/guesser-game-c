#include <stdio.h>
#include <stdbool.h>

int get_guess(bool* is_error_ptr){
    int user_guess;
    printf("Write your guess\n");
    int elements_written = scanf("%d", &user_guess);
    if (elements_written == 0){
        fprintf(stderr, "Error: elements_written %d\n", elements_written);
        *is_error_ptr = true;
        return -1;
    }
    printf("User guess: %d\n", user_guess);
    return user_guess;
}

void final_message(bool is_win, bool is_error){
    if (is_error) {
        printf("Error occurred, game is interrupted\n");
    } else {
        printf("Game over: You ");
        if (is_win){
            printf("won\n");
        } else {
            printf("lost\n");
        }
    }
}
