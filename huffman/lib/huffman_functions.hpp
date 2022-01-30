using namespace std;

node *new_node(char val, int freq);
node *build_huffman_tree(string s);
node *delete_heap(heap *h);
heap *build_heap(node **a, int size);
void heapify(heap *heap, int i);
char* readFile(char* filename);
