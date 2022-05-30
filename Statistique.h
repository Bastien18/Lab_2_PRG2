//
// Edited by Stéphane on 24.05.2022.
//

#ifndef LAB_02_PRG2_STATISTIQUE_H
#define LAB_02_PRG2_STATISTIQUE_H
#include "Vehicule.h"
double somme(const Vehicule *debutParking,
             size_t        tailleParking,
             TypeVehicule  type,
             GammeVehicule gamme);

double moyenne(const Vehicule *debutParking,
               size_t        tailleParking,
               TypeVehicule  type,
               GammeVehicule gamme);

double mediane(const Vehicule *debutParking,
               size_t        tailleParking,
               TypeVehicule  type,
               GammeVehicule gamme);

double ecartType(const Vehicule *debutParking,
                 size_t        tailleParking,
                 TypeVehicule  type,
                 GammeVehicule gamme);



#endif //LAB_02_PRG2_STATISTIQUE_H
