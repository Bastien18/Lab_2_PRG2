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

const char* const TYPES_VEHICULE[] 		= {VOITURE_STR, CAMIONNETTE_STR};
const char* const GAMME_VEHICULE[] 		= {STANDARD_GAMME_STR, HAUTE_GAMME_STR};
const char* const CARACTERISTIQUES[]	= {MARQUE_STR, MATRICULE_STR,
                                          CATEGORIE_STR, GAMME_STR,
                                          POIDS_STR, CYLINDREE_STR,
                                          REJET_STR, PUISSANCE_STR,
                                          VOLUME_STR};


void affichage(const Vehicule* vehicule){
   printf(SEPARATEUR
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
   printf(SEPARATEUR);
   printf("\n");
}
