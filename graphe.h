#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#define INF 999999

// Structure de matrice dynamique
typedef struct {
    int taille; //Si taille = 8, alors la matrice est de taille 8x8
    int **data;
} Matrice;

// fonctions d'initialisation et de liberation
Matrice* creerMatrice(int taille);
void libererMatrice(Matrice *M);
void afficherMatrice(Matrice *M);
void lireGraphe(Matrice *M, int nb_aretes, FILE *file);
FILE* choix_graphe();
// fonctions de lecture du fichier
// <prototypes des fonctions de lecture et affichage>
int ** plus_court_chemain(Matrice *M);
#endif