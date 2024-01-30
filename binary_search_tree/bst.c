#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200000
#define COUNT 10000

struct node_t {
  struct node_t *left, *right;
  int data;
};

struct stack_t {
  struct node_t *data[COUNT];
  int size;
};

void inorder(struct node_t *root) {
  struct node_t *temp = root;
  struct stack_t st = {0};
  int count = MAX;

  while (true) {
    while (temp != NULL) {
      st.data[st.size++] = temp;
      temp = temp->left;
    }

    if (st.size == 0)
      break;

    temp = st.data[--st.size];

    if (temp->right != NULL && temp->left != NULL) {
      printf("\t%-5d->%5d%22c\n", temp->data, temp->right->data, ';');
      printf("\t%-5d->%5d%22c\n", temp->data, temp->left->data, ';');
    } else if (temp->right != NULL) {
      printf("\t%-5d->%5d%22c\n", temp->data, temp->right->data, ';');

      printf("\t%-13d%20s;\n", count, "[style=invis]");
      printf("\t%-5d->%5d %20s;\n", temp->data, count++, "[style=invis]");
    } else if (temp->left != NULL) {
      printf("\t%-5d->%5d%22c\n", temp->data, temp->left->data, ';');

      printf("\t%-13d%20s%c\n", count, "[style=invis]", ';');
      printf("\t%-5d->%5d %20s;\n", temp->data, count++, "[style=invis]");
    }

    temp = temp->right;
  };
}

int main(void) {
  //  srand(time(NULL));

  struct node_t *root, *temp;

  root = (struct node_t *)malloc(sizeof(struct node_t));
  root->left = root->right = NULL;
  root->data = rand() % MAX;

  for (int i = 0; i < COUNT; i++) {
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->left = node->right = NULL;
    node->data = rand() % MAX;

    temp = root;
    while (true) {
      if (node->data < temp->data) {
        if (temp->left == NULL) {
          temp->left = node;
          break;
        } else {
          temp = temp->left;
        }
      } else if (node->data > temp->data) {
        if (temp->right == NULL) {
          temp->right = node;
          break;
        } else {
          temp = temp->right;
        }
      } else {
        break;
      }
    }
  }

  printf("digraph G {\n");
  inorder(root);
  printf("}");
}
