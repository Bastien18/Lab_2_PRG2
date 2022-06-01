/*
  ---------------------------------------------------------------------------
  Fichier     : Statistique.h
  Nom du labo : Laboratoire 2
  Auteur(s)   : Bastien Pillonel, Kylian Manzini, Stéphane Nascimento Santos
  Date        : 01.06.2022
  But         : Met à disposition les fonctions permettant d'effectuer la
                somme, moyenne, médiane et l'écart type d'un tableau de double
                passé en paramètre.

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LAB_02_PRG2_STATISTIQUE_H
#define LAB_02_PRG2_STATISTIQUE_H

//---------------------------------------------------------------------------
// Inclusions
//---------------------------------------------------------------------------

#include <stdlib.h>

//---------------------------------------------------------------------------
// Fonction de statistiques
//---------------------------------------------------------------------------

double somme(const double* liste, size_t taille);

double moyenne(const double* liste, size_t taille);

double mediane(const double* liste, size_t taille);

double ecartType(const double* liste, size_t taille);

#endif //LAB_02_PRG2_STATISTIQUE_H
