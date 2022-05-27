//
// Created by basti on 24.05.2022.
//

#ifndef LAB_02_PRG2_VEHICULE_H
#define LAB_02_PRG2_VEHICULE_H

#include <stdint.h>

#define POIDS_UNITEE       "[kg]"
#define CYLINDRE_UNITEE    "[cm3]"
#define VOLUME_UNITEE      "[m3]"
#define REJET_CO2_UNITEE   "[g/km]"
#define PUISSANCE_UNITEE   "[CV]"
#define DEVISE             "CHF"
#define ESPACEMENT			"20"

typedef const char* Matricule;
typedef const char* const Marque;
typedef enum {VOITURE, CAMIONNETTE} TypeVehicule;
typedef enum {STANDARD, HAUT_GAMME} GammeVehicule;

// Véhicule -> voiture -> standard
typedef struct {
   uint16_t cylindre,
      rejetCo2;
} Standard;

// Véhicule -> voiture -> haut de gamme
typedef struct {
   uint16_t puissance;
} HautGamme;

typedef union {
   Standard standard;
   HautGamme hautGamme;
} Gamme;

// Véhicule -> voiture
typedef struct {
   uint16_t poids;
   GammeVehicule gammeVehicule;
   Gamme gamme;
} Voiture;

// Véhicule -> camionnette
typedef struct {
   double volumeTransport;
} Camionnette;

typedef union {
   Voiture voiture;
   Camionnette camionnette;
} Categorie;

// Véhicule
typedef struct {
   Matricule matricule;
   Marque marque;
   TypeVehicule typeVehicule;
   Categorie categorie;
} Vehicule;

// Constructeur
Vehicule voitureStandard(Matricule matricule, Marque marque, uint16_t poids,
                         uint16_t cylindre, uint16_t rejetCo2);

Vehicule voitureHautGamme(Matricule matricule, Marque marque, uint16_t poids,
                          uint16_t puissance);

Vehicule camionnette(Matricule matricule, Marque marque, double volumeTransport);

// Fonctions
void affichage(Vehicule* vehicule);

double taxe(Vehicule* vehicule);

double arrondis5Centimes(double montant);

#endif //LAB_02_PRG2_VEHICULE_H

