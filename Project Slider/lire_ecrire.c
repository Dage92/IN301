#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char * nom)
{
	FILE * F = fopen("niveau_001.slider", "r");
	
	printf("Nom du niveau = %s\n","niveau_001.slider");
	
	if(F == NULL)
	{
		printf("Erreur lors de l'ouverture de %s\n", "niveau_001.slider");
	}
	
	wall W;
	SLIDER S;
	
	W = creer_liste_vide();
	
	fscanf(F, "%d", &S.L);
	fscanf(F, "%d", &S.H);
	fscanf(F, "%d", &S.x_slider);
	fscanf(F, "%d", &S.y_slider);
	fscanf(F, "%d", &S.x_exit);
	fscanf(F, "%d", &S.y_exit);
	fscanf(F, "%d", &S.N);
	
	if (S.N == 0)
	{
		return S;
	}
	
	else
	{
		for(i=0; i<S.N; i++)
		{
			fscanf(F, "%d", &W.x);
			W = ajout_debut(W, W.x);
			fscanf(F, "%d", &W.y)
			W = ajout_debut(W, W.y);
			fscanf(F, "%d", &W.d)
			W = ajout_debut(W, W.d);
			printf("\n");
		}
	}
	
	return S;
	fclose(F);
}


void ecrire_fichier(SLIDER S, char * nom)
{
	/*fputc(';', F); fputc(' ', F); fputc('1', F);
	int y, x;
	for(y = 0; y < S.largeur; y++)
	{
		for(x = 0; x < S.hauteur; x++)
		{
			fputc(S.plateau[y][x], F);
		}
		fputc('\n', F);
	}
	fputc(';', F);fputc(' ', F);*/
}
