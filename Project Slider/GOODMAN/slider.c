#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "ruleset.h"

int main (int argc, char*argv[]) {
	printf("Debut slider\n");
	
	SLIDER S;
	S = lire_fichier(argv[1]);
	initialiser_affichage(S);
	afficher_slider(S);

	MoveSlider(S);

	printf("Fin slider\n");
	
	finir_affichage(S);
	exit(0);
}
