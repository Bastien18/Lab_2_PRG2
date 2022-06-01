/*
  ---------------------------------------------------------------------------
  Fichier     : Parking.h
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Ce fichier met à disposition :
                  -  Les fonctions permettant de vérifier la catégorie d'un
                     Véhicule (utile lors de la création des tableaux de taxe
                     pour chaque catégorie et le comptage du nombre de véhicules
                     d'une catégorie)

                  -  Une fonction permettant de compter le nombre de véhicules
                     d'une catégorie.

                  -  Une fonction d'affichage du parking (utilise la fonction
                     affichage d'un véhicule dans module AffichageVéhicule
                     pour tous les véhicules du parking).

                  -  Une fonction d'affichage des statistiques (somme, moyenne,
                     médiane, écart type) pour chaque catégorie.

  Remarque(s) : Les fonctions de vérification de catégorie retourne un type
                int au lieu d'un booléen, car évite de devoir inclure la
                librairie stdbool et la place mémoire n'est pas un problème
                pour ce laboratoire.

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LAB_02_PRG2_PARKING_H
#define LAB_02_PRG2_PARKING_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include "Vehicule.h"

//---------------------------------------------------------------------------
// Définition de type
//---------------------------------------------------------------------------

typedef int (*f)(const Vehicule*);

//---------------------------------------------------------------------------
// Definition des symboles
//---------------------------------------------------------------------------

#define SOMME_STR                   "Somme"
#define MOYENNE_STR                 "Moyenne"
#define MEDIANE_STR                 "Mediane"
#define ECART_STR                   "Ecart-type"

#define TYPE_VOITURE_STD_STR        "Voiture standard"
#define TYPE_VOITURE_HG_STR         "Voiture haut de gamme"
#define TYPE_CAMIONNETTE_STR        "Camionnette"
#define NBR_DE_TYPE                 3

#define ESPACEMENT_STAT             "13"

#define MSG_TABLEAU_VIDE            "Le parking est vide\n"
#define MSG_CATEGORIE_VIDE          "Il n'y a pas de "
#define AFFICHAGE_PARKING_STR       "************ Affichage parking ************\n"
#define AFFICHAGE_STATISTIQUE_STR   "********** Affichage statistique **********\n"

//---------------------------------------------------------------------------
// Déclaration des variables et constantes
//---------------------------------------------------------------------------

static const char* LISTE_TYPE[]   = {TYPE_VOITURE_STD_STR, TYPE_VOITURE_HG_STR,
												TYPE_CAMIONNETTE_STR};

//---------------------------------------------------------------------------
// Fonctions de comparaison de véhicule
//---------------------------------------------------------------------------

int estVoitureStandard(const Vehicule* vehicule);

int estVoitureHauteGamme(const Vehicule* vehicule);

int estCamionnette(const Vehicule* vehicule);

static f tabFonction[NBR_DE_TYPE] = {&estVoitureStandard,
												&estVoitureHauteGamme,
                                    &estCamionnette};

//---------------------------------------------------------------------------
// Compte le nombre de véhicules correspondant à une catégorie
//---------------------------------------------------------------------------
// Paramètre:
// Nom: debutParking       Desc: Pointeur sur le début du tableau (parking)
//                               contenant l'adresse de tous les véhicules
// Nom: tailleParking      Desc: Nbr d'adresses de véhicules dans le tableau
// Nom: estCategorie       Desc: Fonction de vérification de la catégorie de
//                               véhicule
//
// Retour:
// Le nombre de véhicules de la catégorie spécifié
//---------------------------------------------------------------------------

size_t compteVehicules(const Vehicule* debutParking[], size_t tailleParking,
                       int (* estCategorie)(const Vehicule*));

//---------------------------------------------------------------------------
// Fonctions d'affichage
//---------------------------------------------------------------------------

void affichageStatistique(const Vehicule* parking[], size_t taille);
void affichageParking(const Vehicule* parking[], size_t tailleParking);

#endif //LAB_02_PRG2_PARKING_H
