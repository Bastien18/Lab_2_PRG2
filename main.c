#include <stdio.h>
#include "Vehicule.h"

int main() {

   //exemple de creation de vehicule

   Vehicule voitureLuxe =
      {"Lambo","GE 123456",VOITURE, {.voiture =
         {1000,HAUT_DE_GAMME, {.hautDeGamme = {200}}}}};
   Vehicule voitureTuktuk =
      {"BestTukTuk","VS 134256",VOITURE, {.voiture =
         {350,STANDARD, {.standard = {2,150}}}}};
   Vehicule camionetteMichel =
      {"Peugot","VD 532323",CAMIONETTE, {.camionette = {35}}};

   Vehicule *listVehicule[3] = {&voitureLuxe,&voitureTuktuk,&camionetteMichel};

   //exemple affichage
   for (int i = 0; i < 3; ++i) {
      printf("Vehicule numero %d : \n", i+1);
      printf("marque : %s\n", listVehicule[i]->marque);
      printf("immatr : %s\n", listVehicule[i]->immatriculation);
      printf("type : %s\n", LISTE_TYPE[listVehicule[i]->typeVehicule]);
      if (listVehicule[i]->typeVehicule == VOITURE){
         printf("gamme : %s\n", LISTE_GAMME[listVehicule[i]->Type.voiture
         .typeGamme]);
         printf("poids : %d\n", listVehicule[i]->Type.voiture.poids);

         if (listVehicule[i]->Type.voiture.typeGamme == STANDARD){
            printf("cylindree : %d\n", listVehicule[i]->Type.voiture.gamme.standard
            .cylindree);
            printf("reget co2 : %d\n", listVehicule[i]->Type.voiture.gamme.standard
            .regetCo2);
         }
         else if (listVehicule[i]->Type.voiture.typeGamme == HAUT_DE_GAMME){
            printf("Cv : %d\n", listVehicule[i]->Type.voiture.gamme.hautDeGamme
            .puissance);
         }
      }
      else if (listVehicule[i]->typeVehicule == CAMIONETTE){
         printf("vol : %f\n", listVehicule[i]->Type.camionette.volumeTransport);
      }
      printf("\n");
   }


   return 0;
}
