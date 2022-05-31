//
// Edited by Stéphane on 30.05.2022
//


#include "Statistique.h"
#include <math.h>   // pow
#include <string.h> // memcpy
#include "Taxe.h"   // compareTaxe



double somme(const double *liste, size_t taille) {
   double sommePartielle = 0.;

   for (size_t i = 0; i < taille; ++i) {
      sommePartielle += (double) liste[i];
   }

   return sommePartielle;
}


double moyenne(const double *liste, size_t taille) {
   return somme(liste, taille) / taille;
}

int compareDouble(const void* a, const void* b){
   // La notation bizzare est du au mauvais comportement entre (-1 et 1)
   return (*(double*)b - *(double*)a) < 0 ? -1 :
          *(double*)b - *(double*)a > 0 ? 1 : 0  ;
}


double mediane(const double *liste, size_t taille) {
   const int PARITEE = 2;
   const int LA_DEMI = 2;
   double mediane = 0.;
   double *tab = (double *) calloc(taille, sizeof(double));

   if (!tab) { // Assert(tab)
      return 0.;
   }
   memcpy(tab, liste, taille * sizeof(double));
   qsort(tab, sizeof(double), taille, compareDouble);

   if (taille % PARITEE) { // IMPAIRE
      mediane = tab[taille / LA_DEMI];
   } else {                // PAIRE
      mediane = (tab[taille / LA_DEMI - 1] + tab[taille / LA_DEMI]) / LA_DEMI;
   }
   free(tab);
   return mediane;
}

double ecartType(const double *liste, size_t taille) {
   const int AU_CARRE = 2;

   double sommeEcartCaree = 0;
   double moyenneType = moyenne(liste, taille);

   for (size_t i = 0; i < taille; ++i) {
      sommeEcartCaree += pow(liste[i] - moyenneType, AU_CARRE);
   }

   return sqrt(sommeEcartCaree / (double) taille);
}