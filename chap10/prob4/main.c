#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node *top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top->next;
    top->next = newNode;
}

int pop(struct node *top) {
    if (top->next == NULL) {
        printf("empty stack.\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = top->next;
    int data = temp->data;

    top->next = temp->next;
    free(temp);

    return data;
}

void printStack(struct node *top) {
    if (top->next == NULL) {
        printf("empty stack.\n");
        return;
    }

    printf("print stack\n");
    struct node *current = top->next;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *top = (struct node *)malloc(sizeof(struct node));
    top->next = NULL;

    while (1) {
        int inputValue;
        if (scanf("%d", &inputValue) != 1) {
            break;
        }
        push(top, inputValue);
    }

    printStack(top);
    free(top);

    return 0;
}
