/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include "sokoban.h"
/*.....................DEFINITION DES STRUCTURES DE L'HISTORIQUE....................*/
/*..........structure utilisée comme élément d'historique pour le jeu..........*/
struct elemSokoban
{
	POINT direction;
	POINT posPersonnage;
	char c_posP;
	char c_posPlusUn;
	char c_posPlusDeux;
	struct elemSokoban* suivant;
};
typedef struct elemSokoban* pile;

/*..........structure utilisée comme l'historique général du jeu..........*/
struct Historique
{
	pile undo;
	pile redo;
};
typedef struct Historique historique;
/*....................*/

/*..........prototypes servant en dehors de historique.c..........*/
pile creerPileVide();/*...ligne 10...*/
pile empiler(POINT dir, POINT pos_perso, char posP, char posP_un, char posP_deux, pile p);/*...ligne 16...*/
pile depiler(pile p, pile target);/*...ligne 29...*/
pile suppPile(pile p);/*...ligne 39...*/

#endif
