#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

void list_dump(struct node *head) {
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
