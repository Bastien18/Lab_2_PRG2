/*
  ---------------------------------------------------------------------------
  Fichier     : Parking.c
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Fichier de définition des fonctions déclarées dans Parking.h

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "Parking.h"
#include "Taxe.h"
#include "AffichageVehicule.h"
#include "Statistique.h"

//---------------------------------------------------------------------------
// Fonctions de comparaison de véhicule
//---------------------------------------------------------------------------

int estVoitureStandard(const Vehicule* vehicule) {
   return vehicule->typeVehicule == VOITURE
          && vehicule->categorie.voiture.gammeVehicule == STANDARD;
}

int estVoitureHauteGamme(const Vehicule *vehicule) {
   return vehicule->typeVehicule == VOITURE
          && vehicule->categorie.voiture.gammeVehicule == HAUT_GAMME;
}

int estCamionnette(const Vehicule *vehicule) {
   return vehicule->typeVehicule == CAMIONNETTE;
}

//---------------------------------------------------------------------------
// Fonction de comptage du nombre de véhicules correspondant à une catégorie
//---------------------------------------------------------------------------

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

//---------------------------------------------------------------------------
// Fonctions d'affichage
//---------------------------------------------------------------------------

void affichageStatistique(const Vehicule* parking[], size_t taille) {
   printf(AFFICHAGE_STATISTIQUE_STR);

   if(!taille) {
      printf(MSG_TABLEAU_VIDE);
      return;
   }

   // Iteration principale pour chaque type de véhicule
   for (size_t i = 0; i < NBR_DE_TYPE; ++i) {
      printf(SEPARATEUR);
      printf("%s\n", LISTE_TYPE[i]);

      size_t nbrTaxes = compteVehicules(parking, taille, tabFonction[i]);
      double* tableauTaxes = tabDeTaxe(parking, taille, tabFonction[i]);

      if(!tableauTaxes) {
         printf(MSG_CATEGORIE_VIDE "%s\n", LISTE_TYPE[i]);
         continue;
      }

      else{
         printf("%-" ESPACEMENT_STAT "s" ": %.2f\n",
                SOMME_STR,
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
   }
   printf(SEPARATEUR);
   printf("\n");
}

void affichageParking(const Vehicule* parking[],size_t tailleParking){
   printf(AFFICHAGE_PARKING_STR);

   for(size_t i = 0; i < tailleParking; ++i)
      affichage(parking[i]);
}

