#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int guess;
    struct Node* next_ptr;
};

struct Set {
    struct Node* head_ptr;
};

struct Set init_set(){
    struct Set guesses_set;
    guesses_set.head_ptr = NULL;
    return guesses_set;
}

struct Node* create_node(int guess_val){
    struct Node* new_node_ptr = (struct Node*)malloc(sizeof(struct Node));
    if (new_node_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node_ptr->guess = guess_val;
    new_node_ptr->next_ptr = NULL;
    return new_node_ptr;
}

void add_guess(struct Set* guesses_ptr, int guess_val){
    if (guesses_ptr->head_ptr == NULL){
        guesses_ptr->head_ptr = create_node(guess_val);
    } else {
        bool is_found = false;
        struct Node* head_ptr_temp = guesses_ptr->head_ptr;
        while (true){
            if (head_ptr_temp->guess == guess_val){
                is_found = true;
                printf("You have already tried %d\n", guess_val);
                break;
            }
            
            if (head_ptr_temp->next_ptr == NULL){
                break;
            }
            head_ptr_temp = head_ptr_temp->next_ptr;
        }
        
        if (!is_found){
            head_ptr_temp->next_ptr = create_node(guess_val);
        }
    }
}


void free_set(struct Set* guesses_ptr){
    struct Node* head_ptr_temp = guesses_ptr->head_ptr;
    struct Node* to_delete_ptr;
    while (head_ptr_temp != NULL){
        to_delete_ptr = head_ptr_temp;
        head_ptr_temp = head_ptr_temp->next_ptr;
        free(to_delete_ptr);
    }
    
}

int test_prev_guesses() {
    struct Set guesses_set = init_set();
    add_guess(&guesses_set, 8);
    add_guess(&guesses_set, 9);
    add_guess(&guesses_set, 10);
    add_guess(&guesses_set, 8);
    add_guess(&guesses_set, 8);
    add_guess(&guesses_set, 9);
    add_guess(&guesses_set, 10);
    add_guess(&guesses_set, 11);
    
    
    free_set(&guesses_set);

    return 0;
}
