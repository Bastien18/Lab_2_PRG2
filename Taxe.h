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


#ifndef LAB_02_PRG2_TAXE_H
#define LAB_02_PRG2_TAXE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Vehicule.h"

//---------------------------------------------------------------------------
// Définition des symboles
//---------------------------------------------------------------------------

#define DEVISE             "CHF"
#define ESPACEMENT			"20"

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle d'un véhicule
//---------------------------------------------------------------------------

double taxe(const Vehicule* vehicule);

/**
 * Cette fonction établi un tableau regroupant le taxes annuelles de chaque véhicule
 * correspondant à un critère, selon l'ordre d'apparition du tableau d'origine.
 * @param debutGarage Le début du tableau de véhicules
 * @param taille      La taille du tableau
 * @param estCritere  une fonction de validation pour le critère souhaité
 * @return un tableau contenant la montant de la taxe annuel pour chaque véhicule
 *         qui correspond au critère.
 */
double* tabDeTaxe(const Vehicule* debutGarage, size_t taille,
                  int(*estCritere)(const Vehicule*));

//---------------------------------------------------------------------------
// Arrondis des prix à 5 centimes
//---------------------------------------------------------------------------

double arrondis5Centimes(double montant);

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules pour qsort
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2);

//---------------------------------------------------------------------------
// Affichage de la taxe
//---------------------------------------------------------------------------

void affichageTaxe(const Vehicule* vehicule);

double arrondiAu5Centimes(double montant);

#endif //LAB_02_PRG2_TAXE_H
