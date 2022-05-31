//
// Created by name on 30.05.2022.
//

#ifndef LAB_02_PRG2_PARKING_H
#define LAB_02_PRG2_PARKING_H

#include "statistique.h"
#include "vehicule.h"

int estVoitureStandard(const Vehicule *vehicule);

int estVoitureHauteGamme(const Vehicule *vehicule);

int estCamionnette(const Vehicule *vehicule);

size_t compteVehicules(const Vehicule *debutGarage, size_t tailleGarage,
                       int (*estCategorie)(const Vehicule *));

Vehicule *sousGarage(const Vehicule *debutGarage, size_t tailleGarage,
                     int (*estCategorie)(const Vehicule *));


#endif //LAB_02_PRG2_PARKING_H
