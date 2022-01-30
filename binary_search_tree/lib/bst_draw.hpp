// ** > this program uses graphviz tool
// ** > given a root of a binary search tree, it generates a file arbre.dot
// ** > this file is written in dot language
// ** > it is compiled and rendered to a png image that contains a visulasation of the tree structure

void DrawTree(nodeptr root);
void dessinArbre(nodeptr R, FILE *f, int *nbNil);
