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
#include <math.h>

const char* const TYPES_VEHICULE[] 		= {"Voiture", "Camionnette"};
const char* const GAMME_VEHICULE[] 		= {"Standard", "Haut de gamme"};
const char* const CARACTERISTIQUES[]	= {"Marque", "Matricule",
														"Categorie", "Gamme",
														"Poids", "Cylindree",
														"Rejet CO2", "Puissance",
														"Volume de transport",
														"Taxe annuelle"};

const double 	TAXE_BASE_CAMIONNETTE 	= 700.,
					TAXE_BASE_VOITURE			= 400.,
					TAXE_VOITURE_ECO   		= 0.,
					TAXE_VOITURE_POL			= 50.,
					TAUX_VOITURE_GROSSE_CYL = 0.05,
					TAUX_CAMIONNETTE			= 10.,
					TAXE_VOITURE_HG			= 200.,
					TAXE_VOITURE_HG_PUISSANT= 300,
					TAUX_VOITURE_HG_PUISSANT= 20.;

const uint16_t SEUIL_PUISSANCE	= 250,
					SEUIL_CYLINDREE	= 1400,
					SEUIL_REJET_CO2	= 130;

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

void affichage(const Vehicule *vehicule){
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
   printf("%-" ESPACEMENT "s" ": %g " DEVISE "\n"
		"=================================================\n",
		CARACTERISTIQUES[9], taxe(vehicule));
}

double taxe(const Vehicule *vehicule){
	double taxe;

	switch (vehicule->typeVehicule) {
		case VOITURE:
			switch (vehicule->categorie.voiture.gammeVehicule) {
				case STANDARD:
					if(vehicule->categorie.voiture.gamme.standard.cylindre < SEUIL_CYLINDREE)
						if(vehicule->categorie.voiture.gamme.standard.rejetCo2 < SEUIL_REJET_CO2)
							taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_ECO;
						else
							taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_POL;
					else
						taxe = TAXE_BASE_VOITURE +
						TAUX_VOITURE_GROSSE_CYL * vehicule->categorie.voiture.gamme.standard.cylindre;
					break;

				case HAUT_GAMME:
					if(vehicule->categorie.voiture.gamme.hautGamme.puissance <= SEUIL_PUISSANCE)
						taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_HG;
					else
						taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_HG_PUISSANT +
						TAUX_VOITURE_HG_PUISSANT *	vehicule->categorie.voiture.poids /
						1000.;
					break;
			}
			break;

		case CAMIONNETTE:
			taxe = vehicule->categorie.camionnette.volumeTransport * TAUX_CAMIONNETTE
			+ TAXE_BASE_CAMIONNETTE;
			break;
	}

	return arrondis5Centimes(taxe);
}

double arrondis5Centimes(double montant){
	return round(montant * 20) / 20.0;
}
