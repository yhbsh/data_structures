#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "./draw_avl.cpp"
#include "../lib/avl_functions.hpp"


using namespace std;


int height(node *root) {
    if (root == nullptr) {
        return -1;
    }
    
    return 1 + max(height(root->left), height(root->right));
}


node *right_rotation(node *current, node* parent) {


    node *l_child = current->left;
    if (l_child != nullptr) {
        node *tmp = l_child->right;
        l_child->right = current;            
        current->left = tmp;

        

        if (parent == nullptr) {
            return l_child;
        }

        if (parent->val < current->val) {
            parent->right = l_child;
        } else {
            parent->left = l_child;
        }
}

    
    return l_child;
}


node *left_rotation(node *current, node *parent) {
    node *r_child = current->right;
    
    if (r_child != nullptr) {
        node *tmp = r_child->left;
        r_child->left = current;
        current->right = tmp;
        

        if (parent == nullptr) {
            return r_child;
        }

        if (parent->val > current->val) {
            parent->left = r_child;
        } else {
            parent->right = r_child;
        }
    }
    
    
    return r_child;
}


bool insert_bst(node *root, node *n, stack<node*> &st) {

    bool stop = false;
    // st.push(nullptr);

    node* prev = nullptr;



    while (!stop) {
        prev = root;
        
        if (root->val > n->val) {
            root = root->left;
            st.push(prev);
        } else if (root->val < n->val) {
            root = root->right;
            st.push(prev);
        } else {
            stop = true;
            return false;
        }

        if (root == nullptr) {
            stop = true;
        }
    }
    
    if ((prev)->val < n->val) { 
        (prev)->right = n;
    } else if ((prev)->val > n->val) {
        (prev)->left = n;
    } else {
        return false;
    }

    return true;

}

node *insert_avl(node *root, int val, int *sortie) {
    node *n = new_node(val);

    if (root == nullptr) {
        // DrawTree(node, sortie);
        return n;
    }


    
    stack<node*> path;
    bool inserted = insert_bst(root, n, path);


    node *current;
    node *parent;
    node *grand_parent;

    if (inserted == true) {
        parent = n;
        while (path.empty() == false) {
            current = parent;
            parent = path.top();
            path.pop();
            if (path.empty() == false)
                grand_parent = path.top();
            else {
                grand_parent = nullptr;
            }

            parent->ht = height(parent);
            
            // parent->ht = balance(parent);


            if (height(parent->left) - height(parent->right) == -2) {
                if (height(current->left) - height(current->right) == 1) {
                    current = right_rotation(current, parent);

                    current->ht = height(current);

                    current->right->ht = height(current->right);

                    parent = left_rotation(parent, grand_parent);

                    parent->ht = height(parent);

                    parent->left->ht = height(parent->left);


                } else if (height(current->left) - height(current->right) == -1) {
                    parent = left_rotation(parent, grand_parent);

                    // resetting heights and balances
                    parent->left->ht = height(parent->left);
                    parent->ht = height(parent);
                }
            } else if (height(parent->left) - height(parent->right) == 2) {
                if (height(current->left) - height(current->right) == 1) {
                    // rotation
                    parent = right_rotation(parent, grand_parent);

                    // resetting heights and balances
                    parent->right->ht = height(parent->right);
                    parent->ht = height(parent);
                } else if (height(current->left) - height(current->right) == -1) {
                    current = left_rotation(current, parent);
                    current->ht = height(current);

                    current->left->ht = height(current->left);


                    // rotation
                    parent = right_rotation(parent, grand_parent);

                    parent->ht = height(parent);

                    parent->right->ht = height(parent->right);
                }
            }
        }
    }


    else {
        parent = root;
    }


    // DrawTree(parent, sortie);
    

    return parent;

}
