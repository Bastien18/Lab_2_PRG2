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

int main(void) {

   //Vehicule voiture = {.matricule = "123456", .marque = "Peugeot"};
   //printf("%s\n%s", voiture.matricule, voiture.marque);

   // Test constructeur
   Vehicule voitureStd = voitureStandard("1234567","Toyota", 1287, 1540,34);
   Vehicule voitureHg = voitureHautGamme("12291387","Renault", 1287, 2);
   Vehicule camthar = camionnette("134353244567","Iveco", 10.567);

   affichage(&voitureStd);
   affichage(&voitureHg);
   affichage(&camthar);

   return 0;
}