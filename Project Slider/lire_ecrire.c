#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char * argv[])
{
	FILE * F = fopen(argv[1] , "r");
	
	printf("Nom du niveau = %s\n",argv[1]);
	
	if(F == NULL)
	{
		printf("Erreur lors de l'ouverture de %s\n", argv[1]);
	}
	
	SLIDER S;
	
	fscanf(F, "%d", S.L);
	fscanf(F, "%d", S.H);
	fscanf(F, "%d", S.x_slider);
	fscanf(F, "%d", S.y_slider);
	fscanf(F, "%d", S.x_exit);
	fscanf(F, "%d", S.y_exit);
	fscanf(F, "%d", S.N);
	
	while(fgetc(F) != EOF)
	{
		fscanf(F, "%d", S.xi);
		fscanf(F, "%d", S.yi);
		fscanf(F, "%d", S.di);
	}
	printf("\n");
	
	return S;
	fclose(F);
}


void ecrire_fichier(SLIDER S, char*nom) {
}
