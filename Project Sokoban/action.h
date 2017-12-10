/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef ACTION_H
#define ACTION_H
#include <uvsqgraphics.h>
#include "sokoban.h"
#include "historique.h"
#include "lire_ecrire.h"
/*..........la structure d'action..........*/
struct Action
{
	int typeAction;
	int fleche;
	char touche;
	POINT P;
};
typedef struct Action ACTION;
/*....................*/

/*..........Les prototypes servant à l'exterieur de action.c..........*/
int wait_key_arrow_clic_modif (char *touche, int *fleche, POINT *P);/*...ligne 16...*/
ACTION recupereAction();/*...ligne 33...*/
void changeSokobanAction(SOKOBAN *S, ACTION *A, historique *h);/*...ligne 141...*/
void changeSokobanActionEditeur(SOKOBAN *S, ACTION *A, char *objet);/*...ligne 157...*/
void bougePersonnage(SOKOBAN *S, int fleche, historique *h);/*...ligne 213...*/
void melange(SOKOBAN *S);/*...ligne 290...*/
int verifieFerme(SOKOBAN S, POINT destination); /*...ligne 299...*/
/*....................*/

#endif
