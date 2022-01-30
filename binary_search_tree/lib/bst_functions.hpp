using namespace std;

// functions declarations
nodeptr new_node(int val);
nodeptr insert_node(nodeptr root, int val);
void insert_node_iterative(nodeptr &root, int val);
nodeptr new_tree(int n);

// different traversing algorithms
void preordre(nodeptr root);
void preorder_iterative(nodeptr root);
void preorder_iterative2(nodeptr root);
void inorder_iterative(nodeptr root);
void postorder_iterative_onestack(nodeptr root);
void postorder_iterative_twostacks(nodeptr root);
void level_order_iterative(nodeptr root);

// construct a full binary tree from the preorder traversal of its nodes
// and additional information in each node :
// -- true if it is an internal node -- false otherwise (i.e a leaf node)
// reminder : a full binary tree is a binary tree
// with the propery that each node can either be a "leaf" or an "internal node"
nodeptr tree_from_preorder(vector<pair<int, bool>> preorder);

// special function that return true if a path from root to leaf that adds up to a value
// "target_sum" exists and false if it does not exist!
bool pathsum(nodeptr root, int ts);

