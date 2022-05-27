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

#include <stdio.h>
#include <stdlib.h>
#include "Vehicule.h"
#include "Statistique.h"

int compare(const void* vhc1, const void* vhc2);

int main(void) {

   //Vehicule voiture = {.matricule = "123456", .marque = "Peugeot"};
   //printf("%s\n%s", voiture.matricule, voiture.marque);

   // Test constructeur
   Vehicule vs1 = voitureStandard("1234567","Toyota", 1287, 1320,119);
	Vehicule vs2 = voitureStandard("1654894","Mazda", 987, 1290,130);
	Vehicule vs3 = voitureStandard("1568531","Volkswagen", 1879, 1540,129);

   Vehicule vh1 = voitureHautGamme("1856482","Porsche", 1287, 250);
	Vehicule vh2 = voitureHautGamme("4582131","BMW", 1500, 500);

   Vehicule c1 = camionnette("6542184","Iveco", 10.567);
	Vehicule c2 = camionnette("3846854","ISUZU", 5.625);

	Vehicule* parking[] = {&vs1, &vs2, &vs3, &vh1, &vh2, &c1, &c2};

	const size_t TAILLE_PARKING = sizeof(parking) / sizeof(Vehicule*);

	printf("=============== AVANT QSORT ===============\n");

	for(size_t i = 0; i < TAILLE_PARKING; ++i){
		affichage(parking[i]);
	}

	qsort(parking, TAILLE_PARKING, sizeof(Vehicule*), compare);

	printf("=============== APRES QSORT ===============\n");

	for(size_t i = 0; i < TAILLE_PARKING; ++i){
		affichage(parking[i]);
	}

   return 0;
}

int compare(const void* vhc1, const void* vhc2){
	return (int)(taxe(*(Vehicule**)vhc2) - taxe(*(Vehicule**) vhc1));
}