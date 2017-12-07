/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"
#include "constantes.h"

void initGraphiques();/*...ligne 11...*/
void afficheLesBoutonsJeu(SOKOBAN S);/*...ligne 32...*/
void afficheLesBoutonsEditeur(SOKOBAN S);/*...ligne 48...*/
void affichePlateau(SOKOBAN S);/*...ligne 83...*/
void afficheSokoban(SOKOBAN S, int mod);/*...ligne 96...*/

#endif
