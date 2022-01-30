using namespace std;


typedef struct node {
    int frequency;
    char data;
    int pos;
    node *left,*right;
} node;


typedef struct heap {
    int capacity;
    node **elements;
} heap;
