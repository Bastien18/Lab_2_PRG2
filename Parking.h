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

#ifndef LAB_02_PRG2_PARKING_H
#define LAB_02_PRG2_PARKING_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Vehicule.h"
#include "Statistique.h"

//---------------------------------------------------------------------------
// Definition des symboles
//---------------------------------------------------------------------------

#define SOMME_STR       "Somme"
#define MOYENNE_STR     "Moyenne"
#define MEDIANE_STR     "Mediane"
#define ECART_STR       "Ecart-type"
#define VOITURE_STD_STR "Voitures standard"
#define VOITURE_HG_STR  "Voitures haut de gamme"
#define CAMIONNETTE_STR "Camionnettes"

#define ESPACEMENT_STAT "13"

#define AFFICHAGE_PARKING_STR        "************ Affichage parking ************\n"
#define AFFICHAGE_STATISTIQUE_STR    "********** Affichage statistique **********\n"

void affichageParking(const Vehicule* parking[], size_t tailleParking);

//---------------------------------------------------------------------------
// Fonctions de comparaison de véhicule
//---------------------------------------------------------------------------

int estVoitureStandard(const Vehicule *vehicule);

int estVoitureHauteGamme(const Vehicule *vehicule);

int estCamionnette(const Vehicule *vehicule);

//---------------------------------------------------------------------------
// Compte le nombre de véhicules correspondant à une catégorie
//---------------------------------------------------------------------------

size_t compteVehicules(const Vehicule *debutParking[], size_t tailleParking,
                       int (*estCategorie)(const Vehicule *));

void affichageStatistique(const Vehicule *parking[], size_t taille);

#endif //LAB_02_PRG2_PARKING_H
