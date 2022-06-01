/*
  ---------------------------------------------------------------------------
  Fichier     : Statistique.c
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento
  Date        : 01.06.2022
  But         : Fichier de définition des fonctions déclarées dans Statistique.h

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <math.h>
#include <string.h>
#include "Statistique.h"

//---------------------------------------------------------------------------
// Fonction comparaison de double pour le tri du tableau avant calcul médiane
//---------------------------------------------------------------------------

int compareDouble(const void* a, const void* b){
   return (*(double*)b - *(double*)a) < 0 ? -1 :
          *(double*)b - *(double*)a > 0 ? 1 : 0;
}

//---------------------------------------------------------------------------
// Fonction de statistiques
//---------------------------------------------------------------------------

double somme(const double* liste, size_t taille) {
   double sommePartielle = 0.;

   for (size_t i = 0; i < taille; ++i) {
      sommePartielle += (double) liste[i];
   }

   return sommePartielle;
}


double moyenne(const double* liste, size_t taille) {
   return somme(liste, taille) / (double)taille;
}

double mediane(const double* liste, size_t taille) {
   double mediane;
   double *tab = (double*) calloc(taille, sizeof(double));

   if (!tab) {
      return 0.;
   }

   memcpy(tab, liste, taille * sizeof(double));
   qsort(tab, taille, sizeof(double), compareDouble);

   if (taille % 2) {
      mediane = tab[taille / 2];
   } else {
      mediane = (tab[taille / 2 - 1] + tab[taille / 2]) / 2;
   }
   free(tab);
   return mediane;
}

double ecartType(const double* liste, size_t taille) {
   double sommeEcartCaree = 0;
   double m = moyenne(liste, taille);

   for (size_t i = 0; i < taille; ++i) {
      sommeEcartCaree += pow(liste[i] - m, 2.);
   }

   return sqrt(sommeEcartCaree / (double) taille);
}
