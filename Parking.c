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

#include <stdio.h>
#include "Parking.h"
#include "AffichageVehicule.h"
#include <stdlib.h>
#include "Taxe.h"

//---------------------------------------------------------------------------
// Variables et constantes
//---------------------------------------------------------------------------

const char* const STATISTIQUE[]	= {SOMME_STR, MOYENNE_STR, MEDIANE_STR, ECART_STR};
const char* LISTE_TYPE[] = {VOITURE_STD_STR, VOITURE_HG_STR,
                           CAMIONNETTE_STR};

void affichageParking(const Vehicule* parking[],size_t tailleParking){
	printf(AFFICHAGE_PARKING_STR);

	for(size_t i = 0; i < tailleParking; ++i)
		affichage(parking[i]);
}


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


typedef int (*f)(const Vehicule*);
#define NBR_DE_TYPE 3
f func[NBR_DE_TYPE] = {
   &estVoitureStandard,
   &estVoitureHauteGamme,
   &estCamionnette
};

void affichageStatistique(const Vehicule *parking[], size_t taille) {
   printf(AFFICHAGE_STATISTIQUE_STR);
   if(!taille) {
      printf("Liste vide\n");
      return;
   }
   for (size_t i = 0; i < NBR_DE_TYPE; ++i) {
      printf(SEPARATEUR);
      printf("%s\n", LISTE_TYPE[i]);
      size_t nbrTaxes = compteVehicules(parking, taille, func[i]);
      double* tableauTaxes = tabDeTaxe(parking, taille, func[i]);
      if(!tableauTaxes) {
         printf("Il n'y a pas de %s\n", LISTE_TYPE[i]);
         continue;
      }
      else{
         printf("%-" ESPACEMENT_STAT "s" ": %.2f\n",
                STATISTIQUE[0],
                somme(tableauTaxes,nbrTaxes));
         printf("%-" ESPACEMENT_STAT "s" ": %.2f\n",
                STATISTIQUE[1],
                moyenne(tableauTaxes,nbrTaxes));
         printf("%-" ESPACEMENT_STAT "s" ": %.2f\n",
                STATISTIQUE[2],
                mediane(tableauTaxes,nbrTaxes));
         printf("%-" ESPACEMENT_STAT "s" ": %.2f\n",
                STATISTIQUE[3],
                ecartType(tableauTaxes,nbrTaxes));
      }
      free(tableauTaxes);
      printf(SEPARATEUR);
      printf("\n");
   }
}

size_t compteVehicules(const Vehicule* debutParking[], size_t tailleParking,
                       int (*estCategorie)(const Vehicule *)) {
   size_t compteur = 0;
   for (size_t i = 0; i < tailleParking; ++i) {
      if (estCategorie(debutParking[i])) {
         ++compteur;
      }
   }
   return compteur;
}
