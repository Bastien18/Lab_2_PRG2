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
// Fonction d'affichage du parking
//---------------------------------------------------------------------------

void affichageParking(const Vehicule* parking[],size_t tailleParking){
	printf("********************** Affichage Parking **********************\n");

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
const char* LISTE_TYPE[NBR_DE_TYPE] = {"Voitures standard","Voitures haut de gamme",
                                       "Camionnettes"};

void affichageStatistique(const Vehicule *parking[], size_t taille) {
   printf("********************** Affichage Statistiques **********************\n");
   for (size_t i = 0; i < NBR_DE_TYPE; ++i) {
      printf("=================================================\n");
      printf("Taxes : %s\n", LISTE_TYPE[i]);
      size_t nbrTaxes = compteVehicules(parking, taille, func[i]);
      if(!nbrTaxes) {
         printf("Il n'y a pas de %s\n", LISTE_TYPE[i]);
         continue;
      }
      double* tableauTaxes = tabDeTaxe(parking, taille, func[i]);
      if(!taille) printf("Liste vide\n");
      else{
         printf("Somme      : %.2f\n",somme(tableauTaxes,nbrTaxes));
         printf("Moyenne    : %.2f\n",moyenne(tableauTaxes,nbrTaxes));
         printf("Mediane    : %.2f\n",mediane(tableauTaxes,nbrTaxes));
         printf("Ecart type : %.2f\n",ecartType(tableauTaxes,nbrTaxes));
      }
      free(tableauTaxes);
      printf("=================================================\n\n");
   }
}

size_t compteVehicules(const Vehicule *debutParking, size_t tailleParking,
                       int (*estCategorie)(const Vehicule *)) {
   size_t compteur = 0;
   for (size_t i = 0; i < tailleParking; ++i) {
      if (estCategorie(debutParking + i)) {
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
