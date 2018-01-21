#include "mes_types.h"

void init_Tmur(SLIDER S){
	int i,j;
	for(i=0;i<20;i++){//attention chiffre 20
		for (j=0;j<20;j++){
			S.T[i][j]=1;
		//	printf("%d \n ", S.T[i][j]);
		}
		
	}
	printf("init_tmmur_fin \n");
}
