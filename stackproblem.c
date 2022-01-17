// stackproblem.c – Lab 02 – Matthew, Mamelak

#include <stdio.h>
#include <stdlib.h>
#define max_input 80

struct node {
    struct node *next;
    char val;
};
typedef struct node node1, *pnode;

//Creates nodes with a specified value
pnode create_node(char value) {
    pnode new_node = (pnode) malloc(sizeof(node1));
    new_node->next = NULL;
    new_node->val = value;
    return new_node;
}

//Adds a value the user entered to the stack
void add_stack(pnode *head, char value) {
    //Checks to see if stack is empty
    if (*head == NULL) {
        *head = create_node(value);
    } else {
        //Else statement if stack is not empty
        pnode New_Node = create_node(value);
        New_Node->next = *head;
        *head = New_Node;
    }
}

//Gets an array of up to 80 numbers by the user
int main() {
    char user_input[max_input];
    pnode head = NULL;
    for (int i = 0; i < max_input; i++) {
        scanf("%c", &user_input[i]);
        if (user_input[i] == '\n') {
            break;
        }
        else {
            add_stack(&head, user_input[i]);
        }
    }
    pnode current_val = head;
    //Prints the values in reverse order the user typed them in
    while (current_val != NULL) {
        printf("%c", current_val->val);
        current_val = current_val->next;
    }
    return 0;
}
