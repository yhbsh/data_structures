
#include "./huffman_functions.cpp"





int main() {




    char file_name[] = "..\\in\\in.txt";

    char *s = readFile(file_name);

    


    node *root = build_huffman_tree(s);
    
    
    Draw_Huffman_tree(root);



    return 0;
}