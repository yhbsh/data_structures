#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 300
#define COUNT 600

struct node_t {
  struct node_t *left, *right;
  int data;
};

void inorder(FILE *stream, struct node_t *root) {
  if (root == NULL)
    return;

  inorder(stream, root->left);
  if (root->right != NULL && root->left != NULL) {
    fprintf(stream, "\t%d\t->\t%d;\n", root->data, root->right->data);
    fprintf(stream, "\t%d\t->\t%d;\n", root->data, root->left->data);
  } else if (root->right != NULL) {
    fprintf(stream, "\t%d\t->\t%d;\n", root->data, root->right->data);
  } else if (root->left != NULL) {
    fprintf(stream, "\t%d\t->\t%d;\n", root->data, root->left->data);
  }
  inorder(stream, root->right);
}

int main(void) {
  srand(time(NULL));

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

  FILE *f = fopen("main.dot", "wb");
  fprintf(f, "digraph G {\n");
  inorder(f, root);
  fprintf(f, "}");
  fclose(f);

  system("dot -Tjpg -o main.jpg main.dot");
  system("open main.jpg");

  free(root);
  root = NULL;
}
