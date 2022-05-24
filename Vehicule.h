//
// Created by basti on 24.05.2022.
//

#ifndef LAB_02_PRG2_VEHICULE_H
#define LAB_02_PRG2_VEHICULE_H

#include "stdint.h"

typedef struct {
   uint16_t cylindree;
   uint16_t regetCo2;
} Standard;

typedef struct {
   uint16_t puissance;
} HautDeGamme;

typedef union {
   Standard standard;
   HautDeGamme hautDeGamme;
} Gamme;

typedef enum {STANDARD, HAUT_DE_GAMME} TypeGamme;
const char* LISTE_GAMME[] = {"standard", "Haut de gamme"};

typedef struct {
   uint16_t poids;
   TypeGamme typeGamme;
   Gamme gamme;
} Voiture;

typedef struct {
   double volumeTransport;
} Camionette;

typedef union {
   Voiture voiture;
   Camionette camionette;
} Type;

typedef enum {VOITURE, CAMIONETTE} TypeVehicule;
const char* LISTE_TYPE[] = {"voiture", "camionette"};

typedef struct {
   char* marque;
   char* immatriculation;
   TypeVehicule typeVehicule;
   Type Type;
} Vehicule;



#endif //LAB_02_PRG2_VEHICULE_H
