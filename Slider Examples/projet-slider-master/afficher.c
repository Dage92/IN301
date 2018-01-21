#include <uvsqgraphics.h>

#include "mes_types.h"





void initialiser_affichage(SLIDER S) {
	init_graphics (50*S.L,50*S.H);
	//rajouter le tab mur init a 1
}

void afficher_grille(SLIDER S) {
	POINT a,b;
	int i,j;
	a.x=0;a.y=0;
	b.x=0;b.y=0;
	for(i=0;i<S.H;i++)
	{
		b.x=S.L*CASE;
		draw_line(a,b,rouge);
		b.y+=CASE;
		a.y+=CASE;
		//	printf("pute\n");
	}
	//printf("puteeee\n");
	a.y=0;
	b.x=0;
	for(j=0;j< S.L;j++)
		{
			//printf("salope\n");
			draw_line(a,b,rouge);
			a.x+=CASE;
			b.x+=CASE;
		}
}

void afficher_murs(SLIDER S) {
	int i,j;
	POINT a,b;
	for(i=0;i<20;i++){//ATTENTION TABLEAU NON VARIABLE
		for(j=0;j<20;j++){
			if (S.T[i][j]!=1){
				if(S.T[i][j]==0){// RAPHA ici le T es aleatoire(pas init)
					
					a.x=i*CASE;a.y=j*CASE+CASE+2;
					b.x=i*CASE+CASE;b.y=j*CASE+CASE-2;
					draw_fill_rectangle(a,b, blanc);
				}
				if(S.T[i][j]==3){
					
				}
				if(S.T[i][j]==6){
					
				}
				if(S.T[i][j]==9){
					
				}
			}
			
		}
	}
}

void afficher_le_slider(SLIDER S) {
	POINT a;
	
	a.x=S.X[0]*CASE+(CASE>>1);
	a.y=S.Y[0]*CASE+(CASE>>1);

	draw_fill_circle(a,24,blanc);
	draw_fill_circle(a,22,violet);
	
}

void afficher_sortie(SLIDER S) {
		POINT a,b,c;
	
	a.x=S.SOX*CASE+(CASE>>1);
	a.y=S.SOY*CASE+(CASE>>1); 
	
	b.x=a.x+(CASE>>1);b.y=a.y+(CASE>>1);
	c.x=a.x-(CASE>>1);c.y=a.y-(CASE>>1);
		
	draw_fill_rectangle(c,b,orange);
	draw_fill_circle(a,24,beige);
	draw_fill_circle(a,10,rouge);
	
}


void afficher_slider (SLIDER S) {
	afficher_grille(S);
	afficher_murs(S);
	afficher_le_slider(S);
	afficher_sortie(S);
}


void finir_affichage(SLIDER S) {
	wait_escape();
}
