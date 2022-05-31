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

#include <math.h>
#include <stdio.h>
#include "Taxe.h"

//---------------------------------------------------------------------------
// Variables et constantes
//---------------------------------------------------------------------------

const double 	   TAXE_BASE_CAMIONNETTE 		= 700.,
					   TAXE_BASE_VOITURE				= 400.,
					   TAXE_VOITURE_ECO   			= 0.,
					   TAXE_VOITURE_POL				= 50.,
					   TAUX_VOITURE_GROSSE_CYL 	= 0.05,
					   TAUX_CAMIONNETTE				= 10.,
					   TAXE_VOITURE_HG				= 200.,
					   TAXE_VOITURE_HG_PUISSANT	= 300.,
					   TAUX_VOITURE_HG_PUISSANT	= 20.;

const uint16_t    SEUIL_PUISSANCE	= 250,
					   SEUIL_CYLINDREE	= 1400,
					   SEUIL_REJET_CO2	= 130;

const char* const CARACTERISTIQUE_TAXE = "Taxe annuelle";

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle
//---------------------------------------------------------------------------

double taxe(const Vehicule* vehicule){
	double taxe = 0;

	switch (vehicule->typeVehicule) {
		case VOITURE:
			switch (vehicule->categorie.voiture.gammeVehicule) {

				case STANDARD:
					if(vehicule->categorie.voiture.gamme.standard.cylindre
					   < SEUIL_CYLINDREE)
						if(vehicule->categorie.voiture.gamme.standard.rejetCo2
						   < SEUIL_REJET_CO2)
							taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_ECO;
						else
							taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_POL;
					else
						taxe = 	TAXE_BASE_VOITURE
									+ TAUX_VOITURE_GROSSE_CYL
									* vehicule->categorie.voiture.gamme.standard.cylindre;
					break;

				case HAUT_GAMME:
					if(vehicule->categorie.voiture.gamme.hautGamme.puissance
						<= SEUIL_PUISSANCE)
						taxe = TAXE_BASE_VOITURE + TAXE_VOITURE_HG;
					else
						taxe = 	TAXE_BASE_VOITURE
							 		+ TAXE_VOITURE_HG_PUISSANT
									+ TAUX_VOITURE_HG_PUISSANT
									* vehicule->categorie.voiture.poids / 1000.;
					break;
			}
			break;

		case CAMIONNETTE:
			taxe = 	vehicule->categorie.camionnette.volumeTransport
						* TAUX_CAMIONNETTE
					 	+ TAXE_BASE_CAMIONNETTE;
			break;
	}

	return arrondis5Centimes(taxe);
}

//---------------------------------------------------------------------------
// Arrondis des prix à 5 centimes
//---------------------------------------------------------------------------

double arrondis5Centimes(double montant){
	return round(montant * 20.) / 20.;
}

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules pour qsort
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2){
	return (int)(taxe(*(Vehicule**)vhc2) - taxe(*(Vehicule**) vhc1));
}

//---------------------------------------------------------------------------
// Affichage de la taxe
//---------------------------------------------------------------------------

void affichageTaxe(const Vehicule* vehicule){
   printf("\n" "%-" ESPACEMENT "s: " "%g" DEVISE "\n",
      CARACTERISTIQUE_TAXE, taxe(vehicule));
}