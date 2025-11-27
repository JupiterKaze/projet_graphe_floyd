#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    //Boucles qui replient toutes les cases ou il n'y a pas de chemains par un équivalent à + infini
    for(int i = 0; i < M->taille; i++){
        for(int j = 0; j < M->taille; j++) {
            if (i != j){
                M->data[i][j] = 999999;
            }
        }
    }
    printf("\n");
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

void afficherMatrice(Matrice *M){
    if(M == NULL) {
        printf("Matrice nulle.\n");
        return;
    }
    for(int i = 0; i < M->taille; i++){
        for (int j = 0; j < M->taille; j++){
            if (M->data[i][j] == 999999){       //évite d'avoir des "999999" dans la matrice d'agacence à l'affichage
                printf("| %-5s ","+∞ ");
            }
            else {
                printf("| %-3d ", M->data[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

void lireGraphe(Matrice *M, int nb_aretes, FILE *file){
    if (M == NULL || file == NULL) return;

    int init, term; //Stocke les indices des sommets initiaux et terminaux
    for (int i = 0; i < nb_aretes; i++) {
        fscanf(file, "%d", &init);
        fscanf(file, "%d", &term);
        fscanf(file, "%d", &M->data[init][term]);
    }
}

FILE* choix_graphe(){ // Demande à l'utilisateur de choisir un graphe à charger et renvoie le fichier correspondant
    FILE* file;
    bool file_vide = true;
    int numero;
    do{
        printf("Choisissez un graphe à charger (1-13).\n");
        printf("Entrez le numéro du graphe : ");
        scanf("%d", &numero);
        switch (numero)
        {
        case 1:
            file = fopen("graphes_test/graphe_1.txt", "r");
            file_vide = false;
            break;
        case 2:
            file = fopen("graphes_test/graphe_2.txt", "r");
            file_vide = false;
            break;
        case 3:
            file = fopen("graphes_test/graphe_3.txt", "r");
            file_vide = false;
            break;
        case 4: 
            file = fopen("graphes_test/graphe_4.txt", "r");
            file_vide = false;
            break;  
        case 5:
            file = fopen("graphes_test/graphe_5.txt", "r");
            file_vide = false;
            break;
        case 6:
            file = fopen("graphes_test/graphe_6.txt", "r");
            file_vide = false;
            break;
        case 7:
            file = fopen("graphes_test/graphe_7.txt", "r");
            file_vide = false;
            break;
        case 8:
            file = fopen("graphes_test/graphe_8.txt", "r");
            file_vide = false;
            break;  
        case 9:
            file = fopen("graphes_test/graphe_9.txt", "r");
            file_vide = false;          
            break;
        case 10:
            file = fopen("graphes_test/graphe_10.txt", "r");
            file_vide = false;
            break;
        case 11:
            file = fopen("graphes_test/graphe_11.txt", "r");
            file_vide = false;
            break;
        case 12:
            file = fopen("graphes_test/graphe_12.txt", "r");
            file_vide = false;
            break;  
        case 13:
            file = fopen("graphes_test/graphe_13.txt", "r");
            file_vide = false;
            break;
        case 14:
            file = fopen("graphes_test/graphe_14.txt", "r");
            file_vide = false;
            break;
        default:
            printf("Numéro de graphe invalide.\n");
            break;
        }
    }while(file_vide);
    printf("\n");
    return file;
}

void plus_court_chemain(Matrice *M){
    for(int k = 0; k < M->taille; k++){
        for(int i = 0; i < M->taille; i++){
            for(int j = 0; j < M->taille; j++){
                if (M->data[i][k] != 999999 && M->data[k][j] != 999999) {
                    if (M->data[i][j] > M->data[i][k] + M->data[k][j]) {
                        M->data[i][j] = M->data[i][k] + M->data[k][j];
                    }
                }
            }
        }
    }
    afficherMatrice(M);
}