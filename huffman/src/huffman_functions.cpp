
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <bits\stdc++.h>
#include "../lib/models.hpp"
#include "../lib/huffman_functions.hpp"
#include "./draw_tree.cpp"



node *new_node(char val, int freq) {
    node *n = new node;

    n->data = val;
    n->frequency = freq;
    n->left = n->right = nullptr;

    return n;
}

void heapify(heap *heap, int i) // also called sift_up
{
    int N = heap->capacity;
    int smallest = i;   // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && heap->elements[l]->frequency < heap->elements[smallest]->frequency)
        smallest = l;

    // If right child is larger than smallest so far
    if (r < N && heap->elements[r]->frequency < heap->elements[smallest]->frequency)
        smallest = r;

    // If smallest is not root
    if (smallest != i)
    {
        swap(heap->elements[i], heap->elements[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(heap, smallest);
    }
}

heap *build_heap(node **a, int size)
{
    heap* h = (heap*)malloc(sizeof(heap));
    h->elements = (node**)calloc(sizeof(node*), size);
    h->capacity = size;
    h->elements = a;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(h, i);
    }
    return h;
}

void insert_heap(heap *h, node *n)
{

    h->capacity++;

    int data_index = h->capacity - 1;
    h->elements[data_index] = n;

    

    int parent_index = (data_index - 1) / 2;

    while (h->elements[data_index]->frequency < h->elements[parent_index]->frequency)
    {
        node* tmp = h->elements[data_index];
        h->elements[data_index] = h->elements[parent_index];
        h->elements[parent_index] = tmp;

        data_index = parent_index;
        parent_index = (data_index - 1) / 2;
    }
}

node *delete_heap(heap *h)
{
    node *ans = h->elements[0];

    h->elements[0] = h->elements[h->capacity - 1];
    h->capacity--;
    

    heapify(h, 0);

    return ans;
}



node *build_huffman_tree(char *s) {

    vector<pair<int ,char>> a(256);

    long int size = strlen(s);

    for (int i = 0; i < size; i++) {
        a[s[i]].second = s[i];
        a[s[i]].first++;
    }


    
    sort(a.begin(), a.end());


    heap *h = (heap*)malloc(sizeof(heap));
    h->elements = (node**)calloc(sizeof(node*), 256);
    h->capacity = 0;

    int sortie = 0;

    for (int i = 0; i < 256; i++) {
        if (a[i].first != 0) {
            // printf("%c - %d\n", a[i].second, a[i].first);
            node *n = new_node(a[i].second, a[i].first);
            n->pos = i;
            insert_heap(h, n);
        }
    }



    while(h->capacity != 1) {
        
        node *first = delete_heap(h);
        node *second = delete_heap(h);

        node *top = new_node('\0', first->frequency + second->frequency);

        top->left = first;
        top->right = second;
        top->pos = max(first->pos,second->pos);


        insert_heap(h, top);

    }


    return h->elements[0];
    
}


char* readFile(char* filename)
{
    FILE* file = fopen(filename,"r");
    if(file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    char* content = (char*)calloc(size + 1, 1);

    fread(content,1,size,file);

    return content;
}