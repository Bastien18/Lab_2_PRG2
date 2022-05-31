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
#include <stdlib.h>
#include "Vehicule.h"
#include "Taxe.h"
#include "Parking.h"

//---------------------------------------------------------------------------
// Variables et constantes
//---------------------------------------------------------------------------

const char* const TYPES_VEHICULE[] 		= {"Voiture", "Camionnette"};
const char* const GAMME_VEHICULE[] 		= {"Standard", "Haut de gamme"};
const char* const CARACTERISTIQUES[]	= {"Marque", "Matricule",
                                          "Categorie", "Gamme",
                                          "Poids", "Cylindree",
                                          "Rejet CO2", "Puissance",
                                          "Volume de transport"};

//---------------------------------------------------------------------------
// Programme principal
//---------------------------------------------------------------------------

int main(void) {

	// Construction de véhicules pour le parking
   Vehicule vs1 = voitureStandard("VD 1234567","Toyota", 1287, 1320,119);
	Vehicule vs2 = voitureStandard("GE 1654894","Mazda", 987, 1290,130);
	Vehicule vs3 = voitureStandard("FR 1568531","Volkswagen", 1879, 1400,129);

   Vehicule vh1 = voitureHautGamme("ZH 1856482","Porsche", 1000, 250);
	Vehicule vh2 = voitureHautGamme("TI 4582131","BMW", 1000, 251);

   Vehicule c1 = camionnette("VS 6542184","Iveco", 10.567);
	Vehicule c2 = camionnette("AG 3846854","ISUZU", 0.);

	// Création du parking
	Vehicule* parking[] = {&vs1, &vs2, &vs3, &vh1, &vh2, &c1, &c2};
	const size_t TAILLE_PARKING = sizeof(parking) / sizeof(Vehicule*);

	// Trier le parking par taxes annuelles décroissantes
	qsort(parking, TAILLE_PARKING, sizeof(Vehicule *), compare_taxe);

	// Afficher le parking
	affichageParking(parking, TAILLE_PARKING);

   return 0;
}