
#include "./avl_functions.cpp"

int main() {
  srand(time(nullptr));
  node *root = nullptr;
  int n;

  cout << "Number of Nodes: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int data;
    data = rand() % 1000;
    root = insert_avl(root, data);
  }

  DrawTree(root);

  return 0;
}
