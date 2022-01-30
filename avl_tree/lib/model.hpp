
using namespace std;

typedef struct node node;

typedef struct node {
    node *left, *right;
    int val;
    int ht;
} node;

node *new_node(int val) {
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->left = n->right = nullptr;
    n->ht = 0;

    return n;

}