/*
  ---------------------------------------------------------------------------
  Fichier     :
  Nom du labo :
  Auteur(s)   : Bastien Pillonel
  Date        :
  But         : le but du programme et non le but du laboratoire !!

  Remarque(s) : à compléter

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/


#ifndef LAB_02_PRG2_STATISTIQUE_H
#define LAB_02_PRG2_STATISTIQUE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <stdlib.h>


//---------------------------------------------------------------------------
// Fonction de statistiques
//---------------------------------------------------------------------------

double somme(const double *liste, size_t taille);

double moyenne(const double *liste, size_t taille);

double mediane(const double *liste, size_t taille);

double ecartType(const double *liste, size_t taille);

#endif //LAB_02_PRG2_STATISTIQUE_H