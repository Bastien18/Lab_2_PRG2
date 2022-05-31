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

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Statistique.h"
#include <math.h>
#include <string.h>


double somme(const double *liste, size_t taille) {
   double sommePartielle = 0.;

   for (size_t i = 0; i < taille; ++i) {
      sommePartielle += (double) liste[i];
   }

   return sommePartielle;
}


double moyenne(const double *liste, size_t taille) {
   return somme(liste, taille) / (double)taille;
}

int compareDouble(const void* a, const void* b){
   return (*(double*)b - *(double*)a) < 0 ? -1 :
          *(double*)b - *(double*)a > 0 ? 1 : 0  ;
}

double mediane(const double *liste, size_t taille) {
   double mediane;
   double *tab = (double *) calloc(taille, sizeof(double));

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

double ecartType(const double *liste, size_t taille) {
   double sommeEcartCaree = 0;
   double m = moyenne(liste, taille);

   for (size_t i = 0; i < taille; ++i) {
      sommeEcartCaree += pow(liste[i] - m, 2.);
   }

   return sqrt(sommeEcartCaree / (double) taille);
}
