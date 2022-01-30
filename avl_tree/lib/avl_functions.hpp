using namespace std;

int height(node *root);
int balance(node *root);

node *right_rotation(node *current, node* parent);
node *left_rotation(node *current, node *parent);

bool insert_bst(node *root, node *n, stack<node*> &st);
node *insert_avl(node *root, int val, int *sortie);