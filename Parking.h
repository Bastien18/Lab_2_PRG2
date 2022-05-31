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
// Fonction d'affichage du parking
//---------------------------------------------------------------------------

void affichageParking(const Vehicule* parking[], size_t tailleParking);

int estVoitureStandard(const Vehicule *vehicule);

int estVoitureHauteGamme(const Vehicule *vehicule);

int estCamionnette(const Vehicule *vehicule);

size_t compteVehicules(const Vehicule *debutParking, size_t tailleParking,
                       int (*estCategorie)(const Vehicule *));

Vehicule *sousGarage(const Vehicule *debutGarage, size_t tailleGarage,
                     int (*estCategorie)(const Vehicule *));

void affichageStatistique(const Vehicule *parking[], size_t taille);

#endif //LAB_02_PRG2_PARKING_H
