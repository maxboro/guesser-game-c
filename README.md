# Description
Number guessing game

# Example
Typical games session looks like this:
```terminal
min_bound is set to 1
max_bound is set to 10
n_guesses_allowed is set to 3
Write your guess
1
User guess: 1
Guess is not correct
Write your guess
2
User guess: 2
Guess is not correct
Write your guess
3
User guess: 3
Guess is not correct
Game over: You won
```

# Settings
Can be updated in settings.txt
- `min_bound` (default 1) - min possible value
- `max_bound` (default 10) - max possible value
- `n_guesses_allowed` (default 3) - # guesses player has

# How to run:
```bash
make          # Builds the project
./exec        # Runs the executable
make clean    # Cleans up build files
```