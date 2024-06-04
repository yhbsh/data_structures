#ifndef BST_H
#define BST_H

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* bst_create_node(int key);
Node* bst_insert(Node* node, int key);
void bst_dump_dot(Node* node, FILE* stream);
void bst_export_file(Node* tree, FILE *stream);

#endif // BST_H
