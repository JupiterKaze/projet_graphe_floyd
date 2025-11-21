#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main()
{   
    FILE *file = fopen("graphes_test/graphe_11.txt", "r");
    
    int nb_sommets, nb_aretes;
    fscanf(file, "%d", &nb_sommets);
    fscanf(file, "%d", &nb_aretes);
    printf("%d\n%d\n", nb_sommets, nb_aretes);
    
    Matrice *M = creerMatrice(nb_sommets);
    lireGraphe(M, nb_aretes, file);
    afficherMatrice(M);

    fclose(file);
    return 0;
}