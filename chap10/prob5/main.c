#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void addq(struct node *head, struct node *tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
        tail->next = newNode;
    } else {
        tail->next->next = newNode;
        tail->next = newNode;
    }
}

int delete(struct node *head, struct node *tail) {
    if (head->next == NULL) {
        printf("empty queue\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = head->next;
    int data = temp->data;
    head->next = temp->next;
    free(temp);

    if (head->next == NULL) {
        tail->next = NULL;
    }

    return data;
}

void printQueue(struct node *head) {
    if (head->next == NULL) {
        printf("empty queue\n");
        return;
    }

    printf("print queue\n");
    struct node *current = head->next;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tail = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    tail->next = NULL;

    while (1) {
        int inputValue;
        if (scanf("%d", &inputValue) != 1) {
            break;
        }
        addq(head, tail, inputValue);
    }
    printQueue(head);

    free(head);
    free(tail);

    return 0;
}

