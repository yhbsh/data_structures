

void dessinArbre1(node *R, FILE *f, int *nbNil)
{
    int info, info_fg, info_fd;
    if (R != nullptr)
    {
        info = R->frequency;
        // Dessiner un arc vers le fils gauche
        if (R->left != nullptr && R->right != nullptr)
        {

            info_fg = R->left->frequency;
            if (R->left->data == '\0')
            {
                fprintf(f, "  \"{%d %c %d}\" -> \"{%d %c %d}\"[label=0, color=red] \n", info, R->data != '\0' ? R->data : ' ', R->pos, info_fg, ' ', R->left->pos);
            }
            else
            {
                fprintf(f, "  \"{%d %c %d}\" -> \"{%d - %c}\"[label=0, color=red] \n", info, R->data != '\0' ? R->data : ' ', R->pos, info_fg, R->left->data);
            }

            // Dessiner un fils NIL virtuel et invisible au milieu (pour une meilleure s�paration des fils gauches et droits)
            fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "  \"{%d %c %d}\" -> \"NIL%d\" ", info, R->data != '\0' ? R->data : ' ', R->pos, (*nbNil)++);
            fprintf(f, " [style=invis];\n");

            info_fd = R->right->frequency;

            if (R->right->data == '\0')
            {
                fprintf(f, "  \"{%d %c %d}\" -> \"{%d %c %d}\"[label=1, color=blue] \n", info, R->data != '\0' ? R->data : ' ', R->pos, info_fd, ' ', R->right->pos);
            }
            else
            {
                fprintf(f, "  \"{%d %c %d}\" -> \"{%d - %c}\"[label=1, color=blue] \n", info, R->data != '\0' ? R->data : ' ', R->pos, info_fd, R->right->data);
            }
        }

        // Dessiner les sous-arbres gauche et droit
        dessinArbre1(R->left, f, nbNil);
        dessinArbre1(R->right, f, nbNil);
    }
}

void Draw_Huffman_tree(node *root)
{

    int nbNil;
    FILE *f;

    if (root == nullptr)
        printf("> ERREUR : Arbre vide !");
    else
    {
        f = fopen("../out/out.dot", "w");

        fprintf(f, "digraph arbre {\n");

        nbNil = 0;
        dessinArbre1(root, f, &nbNil);

        fprintf(f, "}\n");

        fclose(f);

        system("dot -Tjpg ../out/out.dot -o ../out/out.jpg");
        system("open ../out/out.jpg");
    }
}
