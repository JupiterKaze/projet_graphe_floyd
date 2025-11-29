#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#include <math.h>

#define INF INFINITY

// Structure de matrice dynamique
typedef struct {
    int taille; //Si taille = 8, alors la matrice est de taille 8x8
    double **data;
} Matrice;

// fonctions d'initialisation et de liberation
Matrice* creerMatrice(int taille);
void libererMatrice(Matrice *M);
void afficherMatrice(double **M, int n);
void afficherChemin(int **M, int n);
void lireGraphe(Matrice *M, int nb_aretes, FILE *file);
FILE* choix_graphe();
// fonctions de lecture du fichier
// <prototypes des fonctions de lecture et affichage>
int ** plus_court_chemain(Matrice *M);
#endif