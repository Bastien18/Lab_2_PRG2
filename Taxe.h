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


#ifndef LAB_02_PRG2_TAXE_H
#define LAB_02_PRG2_TAXE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Vehicule.h"

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle d'un véhicule
//---------------------------------------------------------------------------

double taxe(const Vehicule* vehicule);

//---------------------------------------------------------------------------
// Arrondis des prix à 5 centimes
//---------------------------------------------------------------------------

double arrondis5Centimes(double montant);

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules pour qsort
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2);

#endif //LAB_02_PRG2_TAXE_H
