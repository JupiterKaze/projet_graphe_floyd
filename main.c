#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <Windows.h>

int main()
{   
    SetConsoleOutputCP(CP_UTF8); // Pour afficher les caractères UTF-8 dans la console Windows
    int nb_sommets, nb_aretes;

    FILE* file = choix_graphe();
    fscanf(file, "%d", &nb_sommets);
    fscanf(file, "%d", &nb_aretes);

    Matrice *M = creerMatrice(nb_sommets);
    printf("Matrice d'adjacence :\n");
    lireGraphe(M, nb_aretes, file);
    afficherMatrice(M);

    plus_court_chemain(M);

    fclose(file);
    return 0;
}