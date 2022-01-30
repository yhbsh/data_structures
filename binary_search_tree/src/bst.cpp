/*  
    Created 23/01/2022 12:39
    By --HoussemBousmaha-- 
*/



#include "./bst_functions.cpp"

using namespace std;

main()
{
    srand(time(nullptr));
    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;

    nodeptr root = new_tree(n);

    DrawTree(root);

    const clock_t begin_time = clock();

    // preordre_recursive(root);
    // postorder_iterative(root);
    // preorder_iterative2(root);
    // postorder_iterative_twostacks(root);
    // inorder_iterative(root);
    // level_order_iterative(root);

    cout << "\n\ntime taken by the program : "
         << float(clock() - begin_time) / CLOCKS_PER_SEC << " seconds\n\n";

    return 0;
}
