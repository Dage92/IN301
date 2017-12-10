/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

/*malloc le plateau du sokoban selon la hauteur et sa largeur, son tableau d'objectifs, initialise les valeurs et la position du personnage*/
SOKOBAN initSokoban(SOKOBAN S)
{
	S.objectifs = malloc(S.nbObjectifs * sizeof(POINT));
	int i;
	S.plateau = malloc(S.hauteur * sizeof(char*));
	for(i = 0; i < S.hauteur; i++)
	{
		S.plateau[i] = malloc(S.largeur * sizeof(char));
	}
	for(i = 0; i < S.nbObjectifs; i++)
		{S.objectifs[i].x = 0; S.objectifs[i].y = 0;}
	int x;
	int y;
	for(x = 0; x < S.hauteur; x++)
		for(y = 0; y < S.largeur; y++)
			S.plateau[x][y] = ' ';
	S.posPersonnage.x = 0;
	S.posPersonnage.y = 0;
	S.nb_coups = 0;
	return S;
}

/*identique à initSokoban, mais, installe des murs à la périphérie du sokoban*/
SOKOBAN initSokobanEditeur(SOKOBAN S)
{
	S.objectifs = malloc(S.nbObjectifs * sizeof(POINT));
	int i;
	S.plateau = malloc(S.hauteur * sizeof(char*));
	for(i = 0; i < S.hauteur; i++)
	{
		S.plateau[i] = malloc(S.largeur * sizeof(char));
	}
	for(i = 0; i < S.nbObjectifs; i++)
		{S.objectifs[i].x = 0; S.objectifs[i].y = 0;}
	int x;
	int y;
	for(x = 0; x < S.hauteur; x++)
		for(y = 0; y < S.largeur; y++)
				S.plateau[x][y] = ' ';
	S.posPersonnage.x = 0;
	S.posPersonnage.y = 0;
	S.nb_coups = 0;
	return S;
}

/*vérifie si chaque emplacement d'objectif est occupé par une caisse*/
int estReussi(SOKOBAN S)
{
	int i;
	int x,y;
	x=0;y=0;
	for(i = 0; i < S.nbObjectifs; i++)
	{
		x = S.objectifs[i].x;
		y=S.objectifs[i].y;
		if(S.plateau[x][y] != '*')return 0;
	}
	return 1;
}

/*libère la mémoire prise par le sokoban*/
void detruireSokoban(SOKOBAN *S)
{
	int i;
	for(i = 0; i < S->hauteur; i++)
		free(S->plateau[i]);
	free(S->plateau);
	free(S->objectifs);
}


SOKOBAN copieSokoban(SOKOBAN S)
{
	SOKOBAN copie;
	copie.largeur = S.largeur;
	copie.hauteur = S.hauteur;
	copie = initSokoban(copie);
	int i,j;
	for(i = 0; i < S.hauteur; i++)
	{
		for(j = 0; j < S.largeur; j++)
		{
			copie.plateau[i][j] = S.plateau[i][j];
		}
	}
	return copie;
}
