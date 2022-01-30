#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
#include "../lib/bst_structures.hpp"
#include "../lib/bst_functions.hpp"
#include "./bst_draw.cpp"



nodeptr new_node(int val)
{
    nodeptr newnode = (nodeptr)malloc(sizeof(node));

    newnode->val = val;
    newnode->left = newnode->right = nullptr;

    return newnode;
}

nodeptr insert_node(nodeptr root, int val)
{
    /*
     * two cases,
     * 1- if the tree is empty then return in root, a new node.
     * 2- if we meet a null pointer (in recursion process) then return a new node.
     */
    if (root == nullptr) // Empty Tree
        root = new_node(val);
    /*
     * if the value to be inserted is bigger than the current subtree root value (i.e root->val)
     * we go to the the right sub_tree
     * the right_subtree becomes the new tree we want to insert the value in
     */
    if (val < root->val)
        root->left = insert_node(root->left, val);
    /*
     * if the value to be inserted is less than the current subtree root value (i.e root->val)
     * we go to the left sub_tree
     * the left_subtree becomes the new tree we want to insert the value in
     */
    else if (val > root->val)
        root->right = insert_node(root->right, val);
    /*
     * two cases
     * (avoid double nodes in the tree)
     * 1- if root->val == val return immidiatly the current root (do not proceed)
     * 2- after the insertion is done, it return the adress of the root linked
     */
    else
        return root;

    return root;
}

void insert_node_iterative(nodeptr &root, int val)
{
    // search for the element in the tree
    // if exited don't do anything, otherwise make it the propper child of its parent

    // empty tree
    if (root == nullptr)
    {
        root = new_node(val);
    }
    else
    {

        bool run = true, exist = false;
        nodeptr parent = nullptr, node = root;

        // this is a search operation to find the right place to insert "val"
        while (run == true && node != nullptr)
        {
            if (val < node->val)
            {
                parent = node;
                node = node->left;
            }
            else if (val > node->val)
            {
                parent = node;
                node = node->right;
            }
            else
            {
                exist = true;
                run = false;
            }
        }

        // the node does not exist in the tree
        // this is used to avoid duplicates
        if (exist == false)
        {
            // if the value to be inserted is less than its parent value then insert it in as a left child
            if (parent->val > val)
            {
                parent->left = new_node(val);
            }
            // otherwise insert is as a right child
            else
            {
                parent->right = new_node(val);
            }
        }
    }
}

nodeptr new_tree(int n)
{
    nodeptr root = nullptr;
    srand(time(nullptr)); // initialize random values

    int data;

    for (int i = 0; i < n; ++i)
    {
        // generate a random value
        data = rand();
        data *= data;
        data %= 1000;
        // cin >> data;

        // insert the value generated
        insert_node_iterative(root, data);
    }
    return root;
}

void preordre(nodeptr root) // nT1T2
{
    if (root == nullptr)
        return;
    // printf("%d | ", root->val);
    preordre(root->left);
    preordre(root->right);
}

void preorder_iterative(nodeptr root)
{
    stack<nodeptr> stack;
    nodeptr current = root;

    cout << '|';
    do
    {
        if (current != nullptr)
        {
            // cout << current->val << '|'; // visit the node
            stack.push(current->right);
            current = current->left;
        }
        else
        {
            current = stack.top();
            stack.pop();
        }
    } while (!(stack.empty() && current == nullptr));
}

void preorder_iterative2(nodeptr root)
{
    stack<nodeptr> stack;
    nodeptr current = root;

    stack.push(current);

    do
    {
        current = stack.top();
        stack.pop();
        cout << current->val << '|';

        if (current->right != nullptr)
            stack.push(current->right);
        if (current->left != nullptr)
            stack.push(current->left);

    } while (stack.empty() == false && current != nullptr);
}

void inorder_iterative(nodeptr root)
{
    stack<nodeptr> stack;

    nodeptr current = root;

    cout << '|';
    do
    {
        if (current != nullptr)
        {
            stack.push(current);
            current = current->left;
        }
        else
        {
            if (stack.empty() == false)
            {
                current = stack.top();
                stack.pop();
                // cout << current->val << '|'; // visit the node
                current = current->right; // visit the right subtree
            }
        }
    } while (stack.empty() == false || current != nullptr);

    cout << endl;
}

void postorder_iterative_twostacks(nodeptr root)
{
    stack<nodeptr> stack1, stack2;
    nodeptr current = root;

    cout << '|';
    do
    {
        if (current != nullptr)
        {
            stack2.push(current);
            stack1.push(current->left);
            current = current->right;
        }
        else
        {
            current = stack1.top();
            stack1.pop();
        }
    } while (!(stack1.empty() && current == nullptr));

    while (stack2.empty() == false)
    {
        current = stack2.top();
        // cout << current->val << '|';
        stack2.pop();
    }
}

void postorder_iterative_onestack(nodeptr root)
{
    nodeptr current = root;
    stack<nodeptr> stack;
    if (root == nullptr)
        return;
    do
    {
        // go as left as possible
        // while going left push the right child of the current node to a stack
        // and then push the current node to a stack
        if (current != nullptr)
        {
            if (current->right != nullptr)
                stack.push(current->right);
            stack.push(current);

            current = current->left;
        }
        else
        {
            current = stack.top();
            stack.pop();

            // this condition if true if current right sub_tree is not yet fully visited
            // so we then need to visit it before visiting current
            // if this condition is false then we just visit current
            // remember that posorder traversal does (left-right-node)
            // so this means before visiting any node we need to visit its left and then right sub_trees
            if (stack.empty() == false && current->right != nullptr && current->right == stack.top())
            {
                stack.pop();
                stack.push(current);
                current = current->right;
            }
            else
            {
                // cout << current->val << '|'; // visit the node
                current = nullptr;
            }
        }

    } while (stack.empty() == false);
}

void level_order_iterative(nodeptr root)
{
    if (root == nullptr)
        return;

    nodeptr current = root;
    queue<nodeptr> queue;

    queue.push(root);

    do
    {
        current = queue.front();
        // cout << current->val << '|';
        queue.pop();

        if (current->left != nullptr)
            queue.push(current->left);
        if (current->right != nullptr)
            queue.push(current->right);

    } while (queue.empty() == false);
}

nodeptr tree_from_preorder(vector<pair<int, bool>> preorder)
{
    int n = preorder.size();
    stack<nodeptr> stack;
    nodeptr tmp;

    vector<nodeptr> new_values;

    for (int i = 0; i < n; i++)
    {
        new_values.push_back(new_node(preorder[i].first));
    }

    // for each node in preoder traversal
    for (int i = 0; i < n - 1; i++)
    {
        // if current node is an internal node then
        // its left child is the node exactly after it in preorder traversal
        if (preorder[i].second == true)
        {
            // set the next node in preorder as left child of current node
            new_values[i]->left = new_values[i + 1];
            // postpone the current node
            // to retreive it later and set its right child
            stack.push(new_values[i]);
        }
        // if current node is a leaf node then the node after it
        // is a right child of its parent
        // the top of the stack if the parent of the current node
        // so we pop the parent from the stack and we set the next node to be its right child
        else
        {
            tmp = stack.top();
            tmp->right = new_values[i + 1];
            stack.pop();
        }
    }

    return new_values[0];
}

bool pathsum(nodeptr root, int ts)
{
    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr)
        if (ts == root->val)
            return true;

    bool l = pathsum(root->left, ts - root->val);
    bool r = pathsum(root->right, ts - root->val);

    if (l || r)
        return true;

    return false;
}
