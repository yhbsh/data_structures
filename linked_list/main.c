#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    struct node *next;
    int value;
};

void list_insert(struct node **head, int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
        return;
    }

    struct node *temp;
    for (temp = *head; temp->next != NULL; temp = temp->next)
        ;

    temp->next = node;
}

void list_print(struct node *head) {
    if (head != NULL) {
        printf("%d ", head->value);
    }

    for (struct node *temp = head->next; temp != NULL; temp = temp->next) {
        printf("-> %d ", temp->value);
    }
    printf("\n");
}

void list_free(struct node *head) {
    if (head == NULL)
        return;

    for (struct node *temp = head->next, *prev = head; temp != NULL; prev = temp, temp = temp->next)
        free(prev);
}

int main(void) {

    srand(time(0));
    struct node *head = NULL;

    for (int i = 0; i < 100; i++) {
        list_insert(&head, rand() % 200);
    }

    list_print(head);

    list_free(head);

    return 0;
}
