//
// Created by name on 30.05.2022.
//

#include "taxe.h"
#include "garage.h"
#include <math.h>
#include <stdlib.h>

#define TAILLE_TAXE 9
#define TAILLE_SEUIL 3
enum TAXE {
   BASE_CAMIONNETTE,
   BASE_VOITURE,
   VOITURE_ECO,
   VOITURE_POL,
   VOITURE_GROSSE_CYL,
   TAUX_CAMIONNETTE,
   VOITURE_HG,
   VOITURE_HG_PUISSANT,
   VOITURE_HG_POID
};
const double TAXE_DE[TAILLE_TAXE] = {700.,
                                     400.,
                                     0.,
                                     50.,
                                     0.05,
                                     10.,
                                     200.,
                                     300.,
                                     20.};

enum SEUIL {
   PUISSANCE,
   CYLINDREE,
   REJET_CO2
};
const uint16_t SEUIL_DE[TAILLE_SEUIL] = {250,
                                         1400,
                                         130};

double taxe(const Vehicule *vehicule) {
   const double KG_EN_TONNE = 0.001;
   double taxe;

   switch (vehicule->typeVehicule) {
      case VOITURE:
         switch (vehicule->categorie.voiture.gammeVehicule) {
            case STANDARD:
               if (vehicule->categorie.voiture.gamme.standard.cylindre <
                   SEUIL_DE[CYLINDREE])
                  if (vehicule->categorie.voiture.gamme.standard.rejetCo2 <
                      SEUIL_DE[REJET_CO2])
                     taxe = TAXE_DE[BASE_VOITURE] + TAXE_DE[VOITURE_ECO];
                  else
                     taxe = TAXE_DE[BASE_VOITURE] + TAXE_DE[VOITURE_POL];
               else
                  taxe = TAXE_DE[BASE_VOITURE] +
                         TAXE_DE[VOITURE_GROSSE_CYL] *
                         vehicule->categorie.voiture.gamme.standard.cylindre;
               break;

            case HAUT_GAMME:
               if (vehicule->categorie.voiture.gamme.hautGamme.puissance <=
                   SEUIL_DE[PUISSANCE])
                  taxe = TAXE_DE[BASE_VOITURE] + TAXE_DE[VOITURE_HG];
               else
                  taxe = TAXE_DE[BASE_VOITURE] + TAXE_DE[VOITURE_HG_PUISSANT]
                         + vehicule->categorie.voiture.poids * KG_EN_TONNE
                           * TAXE_DE[VOITURE_HG_POID];
               break;
         }
         break;

      case CAMIONNETTE:
         taxe = vehicule->categorie.camionnette.volumeTransport *
                TAXE_DE[TAUX_CAMIONNETTE]
                + TAXE_DE[BASE_CAMIONNETTE];
         break;
   }
   return arrondiAu5Centimes(taxe);
}

double *tabDeTaxe(const Vehicule *debutGarage, size_t taille,
                  int (*estCritere)(const Vehicule *)) {

   size_t nbVehicules = compteVehicules(debutGarage, taille, estCritere);
   double *tabTax = (double *) calloc(nbVehicules, sizeof(double));

   if (tabTax) {
      for (size_t i = 0; i < taille; ++i) {
         if (estCritere(debutGarage + i)) {
            *tabTax = taxe(debutGarage + i);
            ++tabTax;
         }
      }
      return tabTax - nbVehicules;
   }
   return NULL;
}

double arrondiAu5Centimes(double montant) {
   const double CINQ_CENTIEME = 0.05;
   return round(montant / CINQ_CENTIEME) * CINQ_CENTIEME;
}

