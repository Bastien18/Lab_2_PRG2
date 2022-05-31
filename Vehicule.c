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

//---------------------------------------------------------------------------
// Constructeur de voiture de gamme standard
//---------------------------------------------------------------------------

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

//---------------------------------------------------------------------------
// Constructeur de voiture haut de gamme
//---------------------------------------------------------------------------

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

//---------------------------------------------------------------------------
// Constructeur de camionnette
//---------------------------------------------------------------------------

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


