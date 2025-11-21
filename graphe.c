#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

// Fonction pour créer une matrice dynamique
Matrice* creerMatrice(int taille) {
    Matrice *M = malloc(sizeof(Matrice));
    if (M == NULL) {
        fprintf(stderr,"Erreur d'allocation mémoire (structure).\n");
        return NULL; // renvoie null pour specifier l'erreur d'allocation
    }

    M->taille = taille;

    // Allocation des lignes
    M->data = calloc(taille, sizeof(int*));
    if (M->data == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire (lignes).\n");
        free(M);
        return NULL;
    }

    // Allocation des colonnes pour chaque ligne
    for (int i = 0; i < taille; i++) {
        M->data[i] = calloc(taille, sizeof(int));
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

    for (int i = 0; i < M->taille; i++)
        free(M->data[i]);
    free(M->data);
    free(M);
}

void afficherMatrice(Matrice *M) {
    if (M == NULL) {
        printf("Matrice nulle.\n");
        return;
    }

    for (int i = 0; i < M->taille; i++) {
        for (int j = 0; j < M->taille; j++) {
            printf("%d ", M->data[i][j]);
        }
        printf("\n");
    }
}

void lireGraphe(Matrice *M, int nb_aretes, FILE *file) {
    if (M == NULL || file == NULL) return;

    int init, term; //Stocke les indices des sommets initiaux et terminaux
    for (int i = 0; i < nb_aretes; i++) {
        fscanf(file, "%d", &init);
        fscanf(file, "%d", &term);
        fscanf(file, "%d", &M->data[init][term]);
    }
}