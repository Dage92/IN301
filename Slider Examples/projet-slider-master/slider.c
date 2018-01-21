#include <stdio.h>
#include <stdlib.h>

#include "mes_types.h"

#include "initialisation.h"
#include "lire_ecrire.h"
#include "afficher.h"

int main (int argc, char*argv[]) {
	printf("Debut slider\n");

	SLIDER S;
	init_Tmur(S);
	S = lire_fichier(argv[1]);
	printf("blop");
	initialiser_affichage(S);//le T es bien init
	printf("fffffffffffffffffffffffffffff\n");
	afficher_slider(S);//yolo le t n est pas init
	
	int i,j;
for (i=0;i<20;i++){
		for(j=0;j<20;j++){
			
			printf("%d \n ",S.T[i][j]);
		}
	}

	printf("Fin slider\n");
	
	finir_affichage(S);
	exit(0);
}
