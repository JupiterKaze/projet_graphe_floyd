#include <stdio.h>
#include <stdlib.h>
#include "forex.h"
#include <string.h>

 Matrice * lireGrapheTaux(char * filepath) {

    FILE * file = fopen(filepath, "r");
    if(file == NULL) {
        fprintf(stderr, "Erreur de lecture du fichier %s.\n", filepath);
        return NULL;
    }

    int taille;
    fscanf(file, "%d", &taille);
    Matrice * M = creerMatrice(taille);
    if(M == NULL) return NULL;

    for(int i = 0; i < taille; i++) {
        char line[1024]; 
        fscanf(file, "%s", line);
        char * tok = strtok(line, ";");
        int j = 0;
        while(tok != NULL) {
            sscanf(tok, "%lf", &M->data[i][j]);
            tok = strtok(NULL, ";");
            j++;
        }
    }

    return M;
}

void trading(Matrice * M) {
    if(M == NULL) return;
    printf("Matrice des taux de base: \n");
    afficherMatrice(M->data, M->taille);

    for(int i = 0; i < M->taille; i++) {
        for(int j = 0; i < M->taille; i++) {
            M->data[i][j] = - log(M->data[i][j]);
        }
    }

    printf("Matrice des taux avec le - log : \n");
    afficherMatrice(M->data, M->taille);

    int ** p = plus_court_chemain(M);

    printf("Matrice des couts des plus petits chemin : \n");
    afficherMatrice(M->data, M->taille);

    printf("Matrice des chemins: \n");

    for(int i = 0; i < M->taille; i++){
         printf("|");
        for (int j = 0; j <  M->taille; j++){
            if (p[i][j] == INF){   
                printf("%5s ", "+∞");
            }
            else {
                printf("%3d ", p[i][j]);
            }
        }
        printf("|\n");
    }
}