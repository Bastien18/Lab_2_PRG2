/*
  ---------------------------------------------------------------------------
  Fichier     : taxe.h
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento
  Date        : 01.06.2022
  But         : Met à disposition les fonctions suivantes:
                  -  Fonction de calcul de la taxe annuelle d'un véhicule

                  -  Fonction retournant un tableau /!\ créé dynamiquement /!\
                     avec toutes les taxes d'une catégorie de véhicules.

                  -  Fonction d'arrondis du prix à 5 centimes.

                  -  Fonction de comparaison des taxes de 2 véhicules
                     => utilisée par qsort.

                  -  Fonction d'affichage de la taxe annuelle => réutilisée
                     dans la fonction d'affichage d'un véhicule.


  Remarque(s) : -

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

#define   DEVISE           "CHF"
#define   ESPACEMENT_TAXE  "20"
#define   TAXE_STR         "Taxe annuelle"

//---------------------------------------------------------------------------
// Déclaration des variables et constantes
//---------------------------------------------------------------------------

static const double     TAXE_BASE_CAMIONNETTE      =  700.,
                        TAXE_BASE_VOITURE          =  400.,
                        TAXE_VOITURE_ECO           =  0.,
                        TAXE_VOITURE_POL           =  50.,
                        TAUX_VOITURE_GROSSE_CYL    =  0.05,
                        TAUX_CAMIONNETTE           =	10.,
                        TAXE_VOITURE_HG            =  200.,
                        TAXE_VOITURE_HG_PUISSANT   =	300.,
                        TAUX_VOITURE_HG_PUISSANT   =	20.;

static const uint16_t   SEUIL_PUISSANCE            =  250,
                        SEUIL_CYLINDREE            =  1400,
                        SEUIL_REJET_CO2            =  130;

//---------------------------------------------------------------------------
// Calcul de la taxe annuelle d'un véhicule
//---------------------------------------------------------------------------

double taxe(const Vehicule* vehicule);


//---------------------------------------------------------------------------
// Fonction retournant un tableau des taxes des véhicules d'une catégorie
//---------------------------------------------------------------------------

double* tabDeTaxe(const Vehicule* parking[], size_t taille,
                  int(*estCritere)(const Vehicule*));

//---------------------------------------------------------------------------
// Fonction retournant l'arrondis d'un prix à 5 centimes
//---------------------------------------------------------------------------

double arrondis5Centimes(double montant);

//---------------------------------------------------------------------------
// Comparaison des taxes de véhicules
//---------------------------------------------------------------------------

int compare_taxe(const void* vhc1, const void* vhc2);

//---------------------------------------------------------------------------
// Fonction d'affichage de la taxe d'un véhicule
//---------------------------------------------------------------------------

void affichageTaxe(const Vehicule* vehicule);


#endif //LAB_02_PRG2_TAXE_H
