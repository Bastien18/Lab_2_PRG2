//
// Edited by Stéphane on 30.05.2022
//

#include <stdlib.h>
#include <math.h>
#include "Statistique.h"

int estMemeFormat(const Vehicule *vehicule, TypeVehicule type, GammeVehicule gamme) {
   return vehicule->typeVehicule == type
          && (type == CAMIONNETTE
              || (type == VOITURE
                  && vehicule->categorie.voiture.gammeVehicule == gamme));
}

int compareTax(const void *a, const void *b) {

   return taxe(*(const Vehicule **) a) - taxe(*((Vehicule **) b)) > 0. ?
          1 : (int) floor(taxe(*(const Vehicule **) a) - taxe(*((Vehicule **) b)));

}

double somme(const Vehicule *debutParking,
             size_t tailleParking,
             TypeVehicule type,
             GammeVehicule gamme) {
   double somme = 0.;

   for (size_t i = 0; i < tailleParking; ++i) {
      if (estMemeFormat(debutParking + i, type, gamme)) {
         somme += taxe(debutParking + i);
      }
   }
   return somme;
}


double moyenne(const Vehicule *debutParking,
               size_t tailleParking,
               TypeVehicule type,
               GammeVehicule gamme) {

   size_t compteur = 0;
   double somme = 0.;

   for (size_t i = 0; i < tailleParking; ++i) {
      if (estMemeFormat(debutParking + i, type, gamme)) {
         ++compteur;
         somme += taxe(debutParking + i);
      }
   }
   return somme / (double) compteur;
}

double mediane(const Vehicule *debutParking,
               size_t tailleParking,
               TypeVehicule type,
               GammeVehicule gamme) {
   const int IMPAIR = 2;
   size_t compteur = 0;
   double mediane = 0.;

   for (size_t i = 0; i < tailleParking; ++i) {
      if (estMemeFormat(debutParking + i, type, gamme)) {
         ++compteur;
      }
   }
   const Vehicule **tableau = (const Vehicule **)
                              calloc(compteur, sizeof(Vehicule *));

   if (!tableau) {
      // Assert(tableau)
      return 0.;
   }

   compteur = 0;
   for (size_t i = 0; i < tailleParking; ++i) {
      if (estMemeFormat(debutParking + i, type, gamme)) {
         tableau[compteur] = debutParking + i;
         ++compteur;
      }
   }
   qsort(tableau, sizeof(Vehicule *), compteur, compareTax);

   if (compteur % IMPAIR) {
      mediane = taxe(tableau[compteur / 2]);
   } else {    // PAIR
      mediane = (taxe(tableau[compteur / 2]) + taxe(tableau[compteur / 2 + 1]) / 2);
   }
   free(tableau);
   return mediane;
}

double ecartType(const Vehicule *debutParking,
                 size_t tailleParking,
                 TypeVehicule type,
                 GammeVehicule gamme) {
   const int AU_CARRE = 2;
   size_t compteur = 0;
   double sommeEcartCaree = 0;
   double moyenneType = moyenne(debutParking, tailleParking, type, gamme);
   for (size_t i = 0; i < tailleParking; ++i) {
      if (estMemeFormat(debutParking + i, type, gamme)) {
         sommeEcartCaree += pow(taxe(debutParking + i) - moyenneType, AU_CARRE);
         ++compteur;
      }
   }
   return sqrt(sommeEcartCaree / (double) compteur);
}
