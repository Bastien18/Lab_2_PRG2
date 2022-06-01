/*
  ---------------------------------------------------------------------------
  Fichier     : AffichageVehicule.h
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento
  Date        : 01.06.2022
  But         : Met à disposition la fonction affichant un véhicule et sa
                taxe annuelle

  Remarque(s) : Réutilisation de la fonction de calcul et affichage de la taxe
                du module taxe.

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

#define VOITURE_STR        "Voiture"
#define CAMIONNETTE_STR    "Camionnette"
#define HAUTE_GAMME_STR    "Haut de gamme"
#define STANDARD_GAMME_STR "Standard"
#define MARQUE_STR         "Marque"
#define MATRICULE_STR      "Matricule"
#define CATEGORIE_STR      "Categorie"
#define GAMME_STR          "Gamme"
#define POIDS_STR          "Poids"
#define CYLINDREE_STR      "Cylindree"
#define REJET_STR          "Rejet CO2"
#define PUISSANCE_STR      "Puissance"
#define VOLUME_STR         "Volume de transport"

#define ESPACEMENT		   "20"
#define SEPARATEUR         "=================================================\n"

//---------------------------------------------------------------------------
// Déclaration des variables et constantes
//---------------------------------------------------------------------------

static const char* TYPES_VEHICULE[] = {VOITURE_STR, CAMIONNETTE_STR};
static const char* GAMME_VEHICULE[] = {STANDARD_GAMME_STR, HAUTE_GAMME_STR};

//---------------------------------------------------------------------------
// Affichage des caractéristiques d'un véhicule
//---------------------------------------------------------------------------

void affichage(const Vehicule* vehicule);

#endif //LAB_02_PRG2_AFFICHAGEVEHICULE_H
