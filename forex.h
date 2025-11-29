#ifndef __FOREX_H__
#define __FOREX_H__

#include "graphe.h"

Matrice * lireGrapheTaux(char * filepath);
void trading(Matrice * M);
#endif