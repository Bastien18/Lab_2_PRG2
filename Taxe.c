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

#include <math.h>
#include <stdio.h>
#include "Taxe.h"
#include "stdlib.h"
#include "Parking.h"

double taxe(const Vehicule* vehicule){
   double taxe = 0;

   switch (vehicule->typeVehicule) {
      case VOITURE:
         switch (vehicule->categorie.voiture.gammeVehicule) {

            case STANDARD:
               if(vehicule->categorie.voiture.gamme.standard.cylindre
                  < SEUIL_CYLINDREE)
                  if(vehicule->categorie.voiture.gamme.standard.rejetCo2
                     < SEUIL_REJET_CO2)
                     taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_ECO;
                  else
                     taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_POL;
               else
                  taxe = TAXE_BASE_VOITURE
                         + TAUX_VOITURE_GROSSE_CYL
                         * vehicule->categorie.voiture.gamme.standard.cylindre;
               break;

            case HAUT_GAMME:
               if(vehicule->categorie.voiture.gamme.hautGamme.puissance
                  <= SEUIL_PUISSANCE)
                  taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_HG;
               else
                  taxe = TAXE_BASE_VOITURE
                         + TAXE_VOITURE_HG_PUISSANT
                         + TAUX_VOITURE_HG_PUISSANT
                         * vehicule->categorie.voiture.poids / 1000.;
               break;
         }
         break;

      case CAMIONNETTE:
         taxe = vehicule->categorie.camionnette.volumeTransport
                * TAUX_CAMIONNETTE
                + TAXE_BASE_CAMIONNETTE;
         break;
   }
   return arrondis5Centimes(taxe);
}

double* tabDeTaxe(const Vehicule* parking[], size_t taille,
                  int (*estCritere)(const Vehicule*)) {

   size_t nbVehicules = compteVehicules(parking, taille, estCritere);

   if (!nbVehicules)
      return NULL;

   double* tabTaxe = (double*) calloc(nbVehicules, sizeof(double));

   if(tabTaxe){
      for (size_t i = 0, j = 0; i < taille; ++i) {
         if (estCritere(parking[i])) {
            tabTaxe[j] = taxe(parking[i]);
            ++j;
         }
      }
   }
   return tabTaxe;
}

double arrondis5Centimes(double montant) {
   return round(montant * 20.) / 20.;
}


int compare_taxe(const void* vhc1, const void* vhc2){
	return (int)(taxe(*(Vehicule**)vhc2) - taxe(*(Vehicule**) vhc1));
}


void affichageTaxe(const Vehicule* vehicule){
   printf("\n" "%-" ESPACEMENT "s: " "%g" DEVISE "\n",
      CARACTERISTIQUE_TAXE, taxe(vehicule));
}