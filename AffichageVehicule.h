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

#ifndef LAB_02_PRG2_AFFICHAGEVEHICULE_H
#define LAB_02_PRG2_AFFICHAGEVEHICULE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Vehicule.h"

//---------------------------------------------------------------------------
// Definition des symboles
//---------------------------------------------------------------------------

#define POIDS_UNITEE       "[kg]"
#define CYLINDRE_UNITEE    "[cm3]"
#define VOLUME_UNITEE      "[m3]"
#define REJET_CO2_UNITEE   "[g/km]"
#define PUISSANCE_UNITEE   "[CV]"
#define ESPACEMENT			"20"

//---------------------------------------------------------------------------
// Affichage des caractéristiques d'un véhicule
//---------------------------------------------------------------------------

void affichage(const Vehicule* vehicule);

#endif //LAB_02_PRG2_AFFICHAGEVEHICULE_H
