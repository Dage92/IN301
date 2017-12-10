#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char *argv[])
{
	FILE * S = fopen(argv[1],"r");
	
	char c;
	
	while((c = fgetc(f)) != EOF)
	{
		printf("%c", c);
	}
	printf("\n");
	
	return 0;
	printf("nom = %s\n",argv[1]);
	SLIDER S;
	S.L = 10;
	S.H = 5;
	
	return S;
	fclose(f);
}


void ecrire_fichier(SLIDER S, char*nom) {
}
