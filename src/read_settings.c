#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 128

void trim_newline(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[len-1] = '\0';
        len--;
    }
}

bool load_settings(int* min_bound_ptr, int* max_bound_ptr, int* n_guesses_allowed_ptr){

    // Opening file in reading mode
    FILE* file_ptr = fopen("settings.txt", "r");

    if (file_ptr == NULL) {
        fprintf(stderr, "file can't be opened \n");
        return false;
    }
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file_ptr)) {
        trim_newline(line);

        // Split key and value
        char *equals = strchr(line, '=');
        if (!equals) continue;

        *equals = '\0';
        char *key = line;
        char *value = equals + 1;

        // printf("Setting: '%s'  Value: '%s'\n", key, value);
        if (strcmp(key, "min_bound") == 0) {
            *min_bound_ptr = atoi(value);
        } else if (strcmp(key, "max_bound") == 0) {
            *max_bound_ptr = atoi(value);
        } else if (strcmp(key, "n_guesses_allowed") == 0) {
            *n_guesses_allowed_ptr = atoi(value);
        }
    }

    // Closing the file
    fclose(file_ptr);

    // Check
    printf("min_bound is set to %d\n", *min_bound_ptr);
    printf("max_bound is set to %d\n", *max_bound_ptr);
    printf("n_guesses_allowed is set to %d\n", *n_guesses_allowed_ptr);
    return true;
}
