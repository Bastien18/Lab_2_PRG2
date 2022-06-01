/*
  ---------------------------------------------------------------------------
  Fichier     : AffichageVehicule.c
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Fichier de définition des fonctions déclarées dans
                AffichageVehicule.h

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <inttypes.h>
#include <stdio.h>
#include "AffichageVehicule.h"
#include "Taxe.h"

//---------------------------------------------------------------------------
// Affichage des caractéristiques d'un véhicule
//---------------------------------------------------------------------------

void affichage(const Vehicule* vehicule){
   printf(SEPARATEUR
      "%-" ESPACEMENT "s" ": %s\n"
      "%-" ESPACEMENT "s" ": %s\n"
      "%-" ESPACEMENT "s" ": %s\n",
      MARQUE_STR, vehicule->marque,
      MATRICULE_STR, vehicule->matricule,
      CATEGORIE_STR, TYPES_VEHICULE[vehicule->typeVehicule]);

   switch (vehicule->typeVehicule) {
      case VOITURE:
         printf("%-" ESPACEMENT "s" ": %s\n"
            "%-" ESPACEMENT "s" ": %" PRIu16 POIDS_UNITEE "\n",
            GAMME_STR,
            GAMME_VEHICULE[vehicule->categorie.voiture.gammeVehicule],
            POIDS_STR, vehicule->categorie.voiture.poids);

         switch (vehicule->categorie.voiture.gammeVehicule) {
            case STANDARD:
               printf("%-" ESPACEMENT "s" ": %" PRIu16 CYLINDRE_UNITEE "\n"
                  "%-" ESPACEMENT "s" ": %" PRIu16 REJET_CO2_UNITEE "\n",
                  CYLINDREE_STR,
                  vehicule->categorie.voiture.gamme.standard.cylindre,
                  REJET_STR,
                  vehicule->categorie.voiture.gamme.standard.rejetCo2);
               break;

            case HAUT_GAMME:
               printf("%-" ESPACEMENT "s" ": %" PRIu16 PUISSANCE_UNITEE "\n",
                  PUISSANCE_STR,
                  vehicule->categorie.voiture.gamme.hautGamme.puissance);
               break;
         }
         break;

      case CAMIONNETTE:
         printf("%-" ESPACEMENT "s" ": %.2f" VOLUME_UNITEE "\n",
            VOLUME_STR,
            vehicule->categorie.camionnette.volumeTransport);
         break;
   }

   affichageTaxe(vehicule);
   printf(SEPARATEUR);
   printf("\n");
}
