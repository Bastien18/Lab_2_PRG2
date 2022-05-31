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

#include "Vehicule.h"

Vehicule voitureStandard(Matricule matricule, Marque marque, uint16_t poids,
                         uint16_t cylindre, uint16_t rejetCo2) {

   Vehicule vhc = {  .matricule 		= matricule,
                     .marque 			= marque,
                     .typeVehicule 	= VOITURE,
                     .categorie 		= {
								.voiture 		= {
									.poids 			= poids,
									.gammeVehicule = STANDARD,
									.gamme 			= {
										.standard 		= {
											.cylindre 		= cylindre,
											.rejetCo2 		= rejetCo2
										}
									}
								}
							}
	};

   return vhc;

}


Vehicule voitureHautGamme(Matricule matricule, Marque marque, uint16_t poids,
                          uint16_t puissance) {

   Vehicule vhc = {  .matricule 		= matricule,
                     .marque 			= marque,
                     .typeVehicule 	= VOITURE,
                     .categorie 		= {
								.voiture 		= {
									.poids 			= poids,
									.gammeVehicule = HAUT_GAMME,
									.gamme 			= {
										.hautGamme 		= {
											.puissance		= puissance
                              }
									}
								}
							}
   };

   return vhc;
}

Vehicule camionnette(Matricule matricule, Marque marque, double volumeTransport) {

   Vehicule vhc = {  .matricule 		= matricule,
      					.marque 			= marque,
      					.typeVehicule 	= CAMIONNETTE,
      					.categorie 		= {
								.camionnette	= {
									.volumeTransport = volumeTransport
                        }
							}
   };

   return vhc;
}


