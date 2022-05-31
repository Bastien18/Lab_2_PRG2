//
// Created by name on 30.05.2022.
//

#ifndef LAB_02_PRG2_TAXE_H
#define LAB_02_PRG2_TAXE_H
#include "vehicule.h"

/**
 * Cette fonction calcule le montant de taxe annuel pour un véhicule en particulier.
 * @param vehicule
 * @return le resultat du calcule
 */
double taxe(const Vehicule *vehicule);

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

double arrondiAu5Centimes(double montant);

#endif //LAB_02_PRG2_TAXE_H
