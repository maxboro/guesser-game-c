#include <stdbool.h>
#include "utils.c"
#include "user_interactions.c"

int main(){
    int min_bound = 0;
    int max_bound = 9;
    int n_guesses_allowed = 3;
    bool is_win = false;
    bool is_error = false;

    int random_number = get_random_number(min_bound, max_bound);

    for (int n_guess = 0; n_guess < n_guesses_allowed; n_guess++){
        game_cycle(random_number, &is_win, &is_error);
        if (is_win || is_error)
            break;
    }

    final_message(is_win, is_error);
    return 0;
}
