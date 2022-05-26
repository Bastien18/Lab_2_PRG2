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

#include "Vehicule.h"
#include <stdio.h>
#include <inttypes.h>

Vehicule voitureStandard(Matricule matricule, Marque marque, uint16_t poids,
                         uint16_t cylindre, uint16_t rejetCo2) {
   Vehicule vhc = {  .matricule = matricule,
                     .marque = marque,
                     .typeVehicule = VOITURE,
                     .categorie = {.voiture = {.poids = poids,
                                               .gammeVehicule = STANDARD,
                                               .gamme = {.standard = {.cylindre =
                                                                      cylindre,
                                                                      .rejetCo2 =
                                                                         rejetCo2
                                               }}}}
   };

   return vhc;

}

Vehicule voitureHautGamme(Matricule matricule, Marque marque, uint16_t poids,
                          uint16_t puissance) {
   Vehicule vhc = {  .matricule = matricule,
                     .marque = marque,
                     .typeVehicule = VOITURE,
                     .categorie = {.voiture = {.poids = poids,
                                               .gammeVehicule = HAUT_GAMME,
                                               .gamme = {.hautGamme = {.puissance
                                                                       = puissance
                                               }}}}
   };

   return vhc;
}

Vehicule camionnette(Matricule matricule, Marque marque, double volumeTransport) {
   Vehicule vhc = {  .matricule = matricule,
      .marque = marque,
      .typeVehicule = CAMIONNETTE,
      .categorie = {.camionnette = {.volumeTransport = volumeTransport
                                    }}
   };

   return vhc;
}

void affichage(Vehicule* vehicule){
   printf("=================================================\n"
          "Marque    : %s\n"
          "Matricule : %s\n"
          "Catégorie : %s\n",
          vehicule->marque, vehicule->matricule,
          TYPES_VEHICULE[vehicule->typeVehicule]);

   switch (vehicule->typeVehicule) {
      case VOITURE:
         printf("Gamme     : %s\n"
            "Poids : %" PRIu16 POIDS_UNITEE "\n",
            GAMME_VEHICULE[vehicule->categorie.voiture.gammeVehicule],
            vehicule->categorie.voiture.poids);

         switch (vehicule->categorie.voiture.gammeVehicule) {
            case STANDARD:
               printf("Cylindree : %" PRIu16 CYLINDRE_UNITEE "\n"
                  "Rejet CO2 : %" PRIu16 REJET_CO2_UNITEE "\n",
                  vehicule->categorie.voiture.gamme.standard.cylindre,
                  vehicule->categorie.voiture.gamme.standard.rejetCo2);
               break;

            case HAUT_GAMME:
               printf("Puissance : %" PRIu16 PUISSANCE_UNITEE "\n",
                      vehicule->categorie.voiture.gamme.hautGamme.puissance);
               break;
         }
         break;

      case CAMIONNETTE:
         printf("Volume de transport : %.2f" VOLUME_UNITEE "\n",
                vehicule->categorie.camionnette.volumeTransport);
         break;
   }
   printf("=================================================\n");
}
