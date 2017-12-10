/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <uvsqgraphics.h>

struct Sokoban
{
	int hauteur;
	int largeur;
	int nb_coups;
	int nbObjectifs;
	POINT posPersonnage;
	POINT *objectifs;
	char **plateau;
};
typedef struct Sokoban SOKOBAN;

SOKOBAN initSokoban(SOKOBAN S);/*...ligne 12...*/
SOKOBAN initSokobanEditeur(SOKOBAN S);/*...ligne 35...*/
int estReussi(SOKOBAN S);/*...ligne 58...*/
void detruireSokoban(SOKOBAN *S);/*...ligne 73...*/
SOKOBAN copieSokoban(SOKOBAN S);/*...ligne 83...*/

#endif
