#include <stdbool.h>
#include "read_settings.c"
#include "utils.c"
#include "user_interactions.c"

int main(){
    int min_bound;
    int max_bound;
    int n_guesses_allowed;
    bool is_win = false;
    bool is_error = false;

    // loading settings
    bool load_successful = load_settings(&min_bound, &max_bound, &n_guesses_allowed);
    if (!load_successful){
        fprintf(stderr, "Settings weren't loaded\n");
        return 1;
    }

    // number guessed
    int random_number = get_random_number(min_bound, max_bound);
    
    for (int n_guess = 0; n_guess < n_guesses_allowed; n_guess++){
        game_cycle(random_number, &is_win, &is_error);
        if (is_win || is_error)
            break;
    }

    final_message(is_win, is_error);
    return 0;
}
