#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char *nom) {

	printf("nom = %s\n",nom);
	SLIDER S;
	S.L = 10;
	S.H = 5;
	
	return S;
}


void ecrire_fichier(SLIDER S, char*nom) {
}
