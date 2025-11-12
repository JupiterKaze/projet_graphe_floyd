#ifndef __GRAPHE_H__
#define __GRAPHE_H__

// Structure de matrice dynamique
typedef struct {
    int lignes;
    int colonnes;
    int **data;
} Matrice;

// fonctions d'initialisation et de liberation
Matrice* creerMatrice(int lignes, int colonnes);
void libererMatrice(Matrice *M);

// fonctions de lecture du fichier
// <prototypes des fonctions de lecture et affichage>

#endif