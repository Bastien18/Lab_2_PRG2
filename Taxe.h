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
// Définition des symboles
//---------------------------------------------------------------------------

#define 	 TAXE_BASE_CAMIONNETTE 		700.
#define   TAXE_BASE_VOITURE		   400.
#define   TAXE_VOITURE_ECO   			0.
#define   TAXE_VOITURE_POL				50.
#define   TAUX_VOITURE_GROSSE_CYL 	0.05
#define   TAUX_CAMIONNETTE				10.
#define   TAXE_VOITURE_HG				200.
#define   TAXE_VOITURE_HG_PUISSANT	300.
#define   TAUX_VOITURE_HG_PUISSANT	20

#define   SEUIL_PUISSANCE   250
#define   SEUIL_CYLINDREE	 1400
#define   SEUIL_REJET_CO2	 130

#define   DEVISE       "CHF"
#define   ESPACEMENT   "20"

#define   CARACTERISTIQUE_TAXE  "Taxe annuelle"

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle d'un véhicule
//---------------------------------------------------------------------------

double taxe(const Vehicule* vehicule);


//---------------------------------------------------------------------------
// Fonction retournant un tableau des taxes des véhicules du critère
//---------------------------------------------------------------------------

double* tabDeTaxe(const Vehicule* parking[], size_t taille,
                  int(*estCritere)(const Vehicule*));


double arrondis5Centimes(double montant);

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules (utilisé pour qsort)
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2);


void affichageTaxe(const Vehicule* vehicule);


#endif //LAB_02_PRG2_TAXE_H
