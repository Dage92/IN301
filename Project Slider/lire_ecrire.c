#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(int argc, char * argv[])
{
	FILE * F = fopen(argv[1] , "r");
	
	printf("Nom du niveau = %s\n",argv[1]);
	
	if(F == NULL)
	{
		printf("Erreur lors de l'ouverture de %s\n", argv[1]);
	}
	
	char c;
	SLIDER S;
	
	fscanf(F, "%d", &S.L);
	fscanf(F, "%d", &S.H);
	fscanf(F, "%d", &S.x_slider);
	fscanf(F, "%d", &S.y_slider);
	fscanf(F, "%d", &S.x_exit);
	fscanf(F, "%d", &S.y_exit);
	fscanf(F, "%d", &S.N);
	
	while((c = fgetc(F)) != EOF)
	{
		S.xi = c;
		S.yi = c;
		S.di = c;
	}
	printf("\n");
	
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
