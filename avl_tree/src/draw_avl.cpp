
#include "../lib/model.hpp"
#include "../lib/draw_avl.hpp"

using namespace std;

void DrawTree(node *root, int *sortie)
{

    int nbNil;
    FILE *f;

    if (root == nullptr)
        printf("> ERREUR : Arbre vide !");
    else
    {
        char fname[50];
        sprintf(fname, "../out/out%d.dot", *sortie);
        f = fopen(fname, "w");

        fprintf(f, "digraph arbre {\n");

        // fprintf(f, "\tordering = out;\n");
        // fprintf(f, "\tsplines = false;\n");

        nbNil = 0;
        dessinArbre(root, f, &nbNil);

        fprintf(f, "}\n");
        fclose(f);
        char cmd[50];

        sprintf(cmd, "dot -Tjpg ../out/out%d.dot -o ../out/out%d.jpg && ..\\out\\out%d.jpg", *sortie, *sortie, *sortie);

        system(cmd);
        (*sortie)++;
    }
}

void dessinArbre(node *R, FILE *f, int *nbNil)
{
    int info, info_fg, info_fd;
    if (R != nullptr)
    {
        info = R->val;
        // Dessiner un arc vers le fils gauche
        if (R->left != nullptr)
        {

            info_fg = R->left->val;
            fprintf(f, "  \"%d\" -> \"%d\" \n", info, info_fg);
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", info,(*nbNil)++);
            fprintf(f, " [style=invis];\n");
        }

        // Dessiner un fils NIL virtuel et invisible au milieu (pour une meilleure s�paration des fils gauches et droits)
        fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
        fprintf(f, "  \"%d\" -> \"NIL%d\" ", info ,(*nbNil)++);
        fprintf(f, " [style=invis];\n");

        // Dessiner un arc vers le fils droit
        if (R->right != nullptr)
        {
            info_fd = R->right->val;
            fprintf(f, "  \"%d\" -> \"%d\" \n", info, info_fd);
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", info, (*nbNil)++);
            fprintf(f, " [style=invis];\n");
        }

        // Dessiner les sous-arbres gauche et droit
        dessinArbre(R->left, f, nbNil);
        dessinArbre(R->right, f, nbNil);
    }
}
