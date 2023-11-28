#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    struct node *head = NULL;

    for (int i = 0; i < 100; i++) {
        list_insert(&head, rand() % 200);
    }

    list_dump(head);

    list_free(head);

    return 0;
}
