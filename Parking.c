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

//---------------------------------------------------------------------------
// Fonction d'affichage du parking
//---------------------------------------------------------------------------

void affichageParking(Vehicule* parking[],size_t tailleParking){
	printf("********************** Affichage Parking **********************\n");

	for(size_t i = 0; i < tailleParking; ++i)
		affichage(parking[i]);
}