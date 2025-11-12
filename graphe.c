#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

// Fonction pour créer une matrice dynamique
Matrice* creerMatrice(int lignes, int colonnes) {
    Matrice *M = malloc(sizeof(Matrice));
    if (M == NULL) {
        fprintf(stderr,"Erreur d'allocation mémoire (structure).\n");
        return NULL; // renvoie null pour specifier l'erreur d'allocation
    }

    M->lignes = lignes;
    M->colonnes = colonnes;

    // Allocation des lignes
    M->data = malloc(lignes * sizeof(int*));
    if (M->data == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire (lignes).\n");
        free(M);
        return NULL;
    }

    // Allocation des colonnes pour chaque ligne
    for (int i = 0; i < lignes; i++) {
        M->data[i] = malloc(colonnes * sizeof(int));
        if (M->data[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire (colonnes).\n");
            // Libération partielle en cas d’erreur
            for (int k = 0; k < i; k++)
                free(M->data[k]);
            free(M->data);
            free(M);
            return NULL;
        }
    }

    return M;
}

// Fonction pour libérer la matrice
void libererMatrice(Matrice *M) {
    if (M == NULL) return;

    for (int i = 0; i < M->lignes; i++)
        free(M->data[i]);
    free(M->data);
    free(M);
}

