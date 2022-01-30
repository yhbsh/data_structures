
#include "./avl_functions.cpp"




int main() {
    srand(time(nullptr));
    node *root = nullptr;
    int n, sortie = 1;

    cout << "Number of Nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        data = rand() % 1000;
        // cin >> data;
        cout << "data: " << data << endl;
        root = insert_avl(root, data, &sortie);
    }



    DrawTree(root, &sortie);

    return 0;
}