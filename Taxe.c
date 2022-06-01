/*
  ---------------------------------------------------------------------------
  Fichier     : Taxe.c
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Fichier de définition des fonctions déclarées dans Taxe.h

  Remarque(s) : -

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

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle d'un véhicule
//---------------------------------------------------------------------------

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
                     * vehicule->categorie.voiture.poids / CONVERSION_TAXE_POIDS;
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

//---------------------------------------------------------------------------
// Fonction retournant un tableau des taxes des véhicules d'une catégorie
//---------------------------------------------------------------------------

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

//---------------------------------------------------------------------------
// Fonction retournant l'arrondis d'un prix à 5 centimes
//---------------------------------------------------------------------------

double arrondis5Centimes(double montant) {
   return round(montant * 20.) / 20.;
}

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules (utilisé pour qsort)
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2){
   return (taxe(*(Vehicule**)vhc2) - taxe(*(Vehicule**)vhc1))  < 0 ? -1 :
          taxe(*(Vehicule**)vhc2) - taxe(*(Vehicule**)vhc1)    > 0 ? 1 : 0;
}

//---------------------------------------------------------------------------
// Fonction d'affichage de la taxe d'un véhicule
//---------------------------------------------------------------------------

void affichageTaxe(const Vehicule* vehicule){
   printf("\n" "%-" ESPACEMENT_TAXE "s: " "%g" DEVISE "\n",
          TAXE_STR, taxe(vehicule));
}
