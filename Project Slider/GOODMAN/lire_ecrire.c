#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char * nom)
{
	FILE * F = fopen("niveau_001.slider", "r");								//Ouverture du fichier avec le info du niveau
	
	printf("Nom du niveau = %s\n","niveau_001.slider");
	
	SLIDER S;
	
	if(F == NULL)															//Verification que le fichier est conforme
	{
		printf("Erreur lors de l'ouverture de %s\n", "niveau_001.slider");
	}
	
	else
	{																		//Affectations a partir des fichiers .slider
		fscanf(F, "%d", &S.L);											
		fscanf(F, "%d", &S.H);
		fscanf(F, "%d", &S.x_slider);
		fscanf(F, "%d", &S.y_slider);
		fscanf(F, "%d", &S.x_exit);
		fscanf(F, "%d", &S.y_exit);
		fscanf(F, "%d", &S.N);
	
		for (int i=0; i<S.N; i++)
		{
				fscanf(F, "%d" , &S.x);
				fscanf(F, "%d" , &S.y);
				//fscanf(F, "%d" , &S.wall[S.x][S.y]);						//Essai avec les matrices que je n'ai pas reussi a faire marcher
				fscanf(F, "%d" , &S.d);
				S.wall[S.x][S.y] = S.d;
				printf("%d %d %d", S.x, S.y,S.d);
				printf("\n");
		}
	}
	return S;
	fclose(F);
}


void ecrire_fichier(SLIDER S, char * nom)
{
}
