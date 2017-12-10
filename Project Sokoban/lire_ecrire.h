/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef LIRE_ECRIRE_H
#define LIRE_ECRIRE_H

#include "sokoban.h"

SOKOBAN tailleNiveau(FILE *F, SOKOBAN S);/*...ligne 14...nécéssite que le fichier soit au bon niveau*/
void metAuNiveau(FILE *F, int niveau);/*...ligne 45...*/
void lireFichierSokoban(FILE *F, SOKOBAN *S);/*...ligne 67...*/
void sortie(char *fic, SOKOBAN S);/*ligne 104...*/

#endif
