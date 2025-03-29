#include <stdbool.h>
#include "prev_guesses.c"
#include "read_settings.c"
#include "utils.c"
#include "user_interactions.c"

void game_cycle(int random_number, bool* is_win_ptr, bool* is_error_ptr, struct Set* guesses_set_ptr){
    int user_guess = get_guess(is_error_ptr);
    add_guess(guesses_set_ptr, user_guess);
    if (*is_error_ptr){
        return;
    }

    printf("Guess is ");
    if (random_number == user_guess){
        printf("correct\n");
        *is_win_ptr = true;
    } else {
        printf("not correct\n");
    }
}

int main(){
    int min_bound;
    int max_bound;
    int n_guesses_allowed;
    bool is_win = false;
    bool is_error = false;

    // user's guesses made
    struct Set guesses_set = init_guesses_set();

    // loading settings
    bool load_successful = load_settings(&min_bound, &max_bound, &n_guesses_allowed);
    if (!load_successful){
        fprintf(stderr, "Settings weren't loaded\n");
        return 1;
    }

    // number guessed
    int random_number = get_random_number(min_bound, max_bound);
    
    for (int n_guess = 0; n_guess < n_guesses_allowed; n_guess++){
        game_cycle(random_number, &is_win, &is_error, &guesses_set);
        if (is_win || is_error)
            break;
    }

    final_message(is_win, is_error);
    free_set(&guesses_set);
    return 0;
}
