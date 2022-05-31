//
// Created by name on 30.05.2022.
//

#include "parking.h"
#include <stdlib.h>

int estVoitureStandard(const Vehicule *vehicule) {
   return vehicule->typeVehicule == VOITURE
          && vehicule->categorie.voiture.gammeVehicule == STANDARD;
}

int estCamionnette(const Vehicule *vehicule) {
   return vehicule->typeVehicule == CAMIONNETTE;
}


int estVoitureHauteGamme(const Vehicule *vehicule) {
   return vehicule->typeVehicule == VOITURE
          && vehicule->categorie.voiture.gammeVehicule == HAUT_GAMME;
}


size_t compteVehicules(const Vehicule *debutGarage, size_t tailleGarage,
                       int (*estCategorie)(const Vehicule *)) {
   size_t compteur = 0;
   for (size_t i = 0; i < tailleGarage; ++i) {
      if (estCategorie(debutGarage + i)) {
         ++compteur;
      }
   }
   return compteur;
}

Vehicule *sousGarage(const Vehicule *debutGarage, size_t tailleGarage,
                     int (*estCategorie)(const Vehicule *)) {
   size_t tailleSousGarages = compteVehicules(debutGarage, tailleGarage,
                                              estCategorie);
   Vehicule *sousGarage = (Vehicule *) calloc(tailleSousGarages, sizeof(Vehicule));

   for (size_t i = 0; i < tailleGarage; ++i) {
      if (estCategorie(debutGarage + i)) {
         sousGarage = (Vehicule *) sousGarage + i;
         ++sousGarage;
      }
   }
   return sousGarage - tailleSousGarages;
}


