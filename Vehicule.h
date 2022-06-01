/*
  ---------------------------------------------------------------------------
  Fichier     : Vehicule.h
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Met à disposition les définitions de types utilisés dans
                la structure composée véhicule. Ainsi qu'un constructeur pour
                chaque catégorie de véhicule.

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LAB_02_PRG2_VEHICULE_H
#define LAB_02_PRG2_VEHICULE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <stdint.h>

//---------------------------------------------------------------------------
// Definition des types
//---------------------------------------------------------------------------

typedef const char* Matricule;
typedef const char* Marque;
typedef enum {VOITURE, CAMIONNETTE} TypeVehicule;
typedef enum {STANDARD, HAUT_GAMME} GammeVoiture;

//---------------------------------------------------------------------------
// Definition de la structure composée véhicule
// NB: De haut en bas : du plus spécifique au plus général
//---------------------------------------------------------------------------

typedef struct {
   uint16_t cylindre,
				rejetCo2;
} Standard;

typedef struct {
   uint16_t 	puissance;
} HautGamme;

typedef union {
   Standard 	standard;
   HautGamme 	hautGamme;
} Gamme;

typedef struct {
   uint16_t 		poids;
   GammeVoiture 	gammeVehicule;
   Gamme 			gamme;
} Voiture;

typedef struct {
   double volumeTransport;
  
} Camionnette;

typedef union {
   Voiture 		voiture;
   Camionnette	camionnette;
} Categorie;

typedef struct {
   Matricule 		matricule;
   Marque 			marque;
   TypeVehicule 	typeVehicule;
   Categorie 		categorie;
} Vehicule;

//---------------------------------------------------------------------------
// Constructeurs des différents véhicules
//---------------------------------------------------------------------------
// Paramètre:
// Prend les paramètres nécessaires au remplissage de chaque champ caractérisant
// chaque catégorie.
//
// Retour :
// Une structure véhicule correspondante
//---------------------------------------------------------------------------

Vehicule voitureStandard(Matricule matricule, Marque marque, uint16_t poids,
                         uint16_t cylindre, uint16_t rejetCo2);

Vehicule voitureHautGamme(Matricule matricule, Marque marque, uint16_t poids,
                          uint16_t puissance);

Vehicule camionnette(Matricule matricule, Marque marque, double volumeTransport);


#endif //LAB_02_PRG2_VEHICULE_H

