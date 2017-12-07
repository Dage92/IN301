/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include <stdio.h>
#include <stdlib.h>
#include "lire_ecrire.h"
#include "affichage.h"
#include "constantes.h"

/*..........fonction qui modifie la valeur de hauteur et largeur du Sokoban, ainsi que celle de l'écran...........*/
SOKOBAN tailleNiveau(FILE *F, SOKOBAN S) //nécessite que le fichier soit sur le bon niveau.
{
	int largeurMax = 0;
	int largeur = 0;
	int hauteur = 0;
	S.nbObjectifs = 0;
	char c = 'a';
	int fin = 0;
	while(!fin)
	{
		largeur = 0;
		c = 'a';
		while(c != '\n')
		{
			if(c == ';'||c == EOF) fin = 1;
			if(c=='*'||c=='.') S.nbObjectifs++;
			largeur ++;
			c = fgetc(F);
		}
		if(largeur > largeurMax) largeurMax = largeur;
		hauteur++;
	}
	S.hauteur = hauteur;
	S.largeur = largeurMax;
	hauteur_ecran = hauteur*TAILLE_CASE;
	largeur_ecran = largeurMax*TAILLE_CASE+HAUTEUR_BOUTON;
	largeur_bouton = hauteur_ecran / NB_BOUTONS_JEU;
	return S;
}

/*..........met le fichier au niveau..........*/
void metAuNiveau(FILE *F, int niveau)
{
	char c = 'a';
	int niv = 0;
	while(c != EOF)
	{
		c = fgetc(F);
		while(c != ';')
		{
			c = fgetc(F);if(c == EOF){printf("le niveau %d n'existe pas.\n", niveau);exit(0);}
		}
		fscanf(F, "%d", &niv);
		if(niv == niveau)
		{
			while(c != '\n')
				c = fgetc(F);
			return;
		}
	}
}

/*..........insère dans le Sokoban les valeurs du niveau et du fichier..........*/
void lireFichierSokoban(FILE *F, SOKOBAN *S)//nécessite que le fichier soit au bon niveau
{
	int x,y,i;
	i = 0;
	char c = 'a';
	for(x = S->hauteur-1; x>0; x--)
	{
		c = 'a';
		y = 0;
		while(c != '\n')
		{
			c = fgetc(F);
			S->plateau[x][y] = c;
			if(c=='.'||c=='*'){S->objectifs[i].x = x; S->objectifs[i].y = y; i++;}
			if(c == '@' || c=='+'){S->posPersonnage.x = x; S->posPersonnage.y = y;}
			y++;
		}
	}
}

/*..........Ecrit dans le fichier ouvert le sokoban visible à l'écran..........*/
void ecritSokoban(FILE *F, SOKOBAN S)
{
	fputc(';', F); fputc(' ', F); fputc('1', F);
	int y, x;
	for(y = 0; y < S.largeur; y++)
	{
		for(x = 0; x < S.hauteur; x++)
		{
			fputc(S.plateau[y][x], F);
		}
		fputc('\n', F);
	}
	fputc(';', F);fputc(' ', F);
}

/*..........Ecrit dans un fichier(le nom du fichier est à mettre en paramètre) le sokoban..........*/
void sortie(char *fic, SOKOBAN S)
{
	FILE *F = fopen(fic, "w");
	ecritSokoban(F,S);
	fclose(F);
}
