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

#include <inttypes.h>
#include <stdio.h>
#include "AffichageVehicule.h"
#include "Taxe.h"

//---------------------------------------------------------------------------
// Variables et constantes
//---------------------------------------------------------------------------

extern const char* const TYPES_VEHICULE[];
extern const char* const GAMME_VEHICULE[];
extern const char* const CARACTERISTIQUES[];

//---------------------------------------------------------------------------
// Fonction d'affichage d'un vehicule
//---------------------------------------------------------------------------

void affichage(const Vehicule* vehicule){
   printf("=================================================\n"
      "%-" ESPACEMENT "s" ": %s\n"
      "%-" ESPACEMENT "s" ": %s\n"
      "%-" ESPACEMENT "s" ": %s\n",
      CARACTERISTIQUES[0], vehicule->marque,
      CARACTERISTIQUES[1], vehicule->matricule,
      CARACTERISTIQUES[2], TYPES_VEHICULE[vehicule->typeVehicule]);

   switch (vehicule->typeVehicule) {
      case VOITURE:
         printf("%-" ESPACEMENT "s" ": %s\n"
            "%-" ESPACEMENT "s" ": %" PRIu16 POIDS_UNITEE "\n",
            CARACTERISTIQUES[3],
            GAMME_VEHICULE[vehicule->categorie.voiture.gammeVehicule],
            CARACTERISTIQUES[4], vehicule->categorie.voiture.poids);

         switch (vehicule->categorie.voiture.gammeVehicule) {
            case STANDARD:
               printf("%-" ESPACEMENT "s" ": %" PRIu16 CYLINDRE_UNITEE "\n"
                  "%-" ESPACEMENT "s" ": %" PRIu16 REJET_CO2_UNITEE "\n",
                  CARACTERISTIQUES[5],
                  vehicule->categorie.voiture.gamme.standard.cylindre,
                  CARACTERISTIQUES[6],
                  vehicule->categorie.voiture.gamme.standard.rejetCo2);
               break;

            case HAUT_GAMME:
               printf("%-" ESPACEMENT "s" ": %" PRIu16 PUISSANCE_UNITEE "\n",
                  CARACTERISTIQUES[7],
                  vehicule->categorie.voiture.gamme.hautGamme.puissance);
               break;
         }
         break;

      case CAMIONNETTE:
         printf("%-" ESPACEMENT "s" ": %.2f" VOLUME_UNITEE "\n",
            CARACTERISTIQUES[8],
            vehicule->categorie.camionnette.volumeTransport);
         break;
   }

   affichageTaxe(vehicule);
   printf("=================================================\n\n");
}
