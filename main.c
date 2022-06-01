/*
  ---------------------------------------------------------------------------
  Fichier     : main.c
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento
  Date        : 01.06.2022
  But         : Programme principal. Initialise un parking (tableau rempli avec
                l'adresse de plusieurs véhicules), le trie par taxes annuelles
                décroissantes, affiche tous les véhicules du parking avec leurs
                caractéristiques et leurs taxes annuelles. Enfin on affiche
                les statistiques par rapport à la taxe pour chaque catégorie de
                véhicules.

  Remarque(s) : Pour chaque module .h seules les fonctions jugées nécessaires ont
                été commentée selon format Doxygène.

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <stdlib.h>
#include "Vehicule.h"
#include "Taxe.h"
#include "Parking.h"

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
	affichageParking((const Vehicule **) parking, TAILLE_PARKING);
   affichageStatistique((const Vehicule **) parking, TAILLE_PARKING);

   return EXIT_SUCCESS;
}