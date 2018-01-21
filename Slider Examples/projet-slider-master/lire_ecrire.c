#include <stdio.h>

#include "mes_types.h"


SLIDER lire_fichier(char *nom) {
	FILE *f= fopen("niveau01.slider", "r");//mettre niv1 dans un autre fichier 
	if(f==NULL){
		printf ("ereur ouverture fichier");
		//exit(0;
	}
	printf("nom = %s\n",nom);
	SLIDER S;
	fscanf(f, "%d %d", &S.L,&S.H);
	printf("lec_01");
	fscanf(f, " %d %d", S.X,S.Y);
	fscanf(f, " %d %d", &S.SOX,&S.SOY);
	fscanf(f, " %d", &S.N);
	printf("lec_millieux");
	while (S.N){
		fscanf(f, " %d %d %d ",&S.A,&S.B ,&S.M);
		S.T[S.A][S.B]=S.M;
		S.N-=1;
	}
	
	//S.L = 10;
//	S.H = 5;
	printf("fin_lecture");
	return S;
}


void ecrire_fichier(SLIDER S, char*nom) {
	
}
