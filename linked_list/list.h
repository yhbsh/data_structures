struct node {
    struct node *next;
    int value;
};

void list_insert(struct node **head, int value);
void list_dump(struct node *head);
void list_free(struct node *head);
