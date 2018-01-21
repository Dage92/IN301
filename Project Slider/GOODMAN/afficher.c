#include <uvsqgraphics.h>
#include "mes_types.h"


void initialiser_affichage(SLIDER S) {									//initialisation de l'interface
	init_graphics ((CASE*S.L)+10,(CASE*S.H)+10);
	}

void afficher_grille(SLIDER S) {										//Affichage du grillage
	POINT p1, p2, p3, p4;
	int j = 0, i = 0;
	p1.x = 4; p1.y = 4;
	p2.x = (CASE*S.L)+6; p2.y = (CASE*S.H)+6;
	draw_fill_rectangle(p1, p2, white);
	p1.x = 5;
	p2.x = (CASE*S.L)+5;
	p3.y = 5;
	p4.y = (CASE*S.H)+5;
	while (p1.y < ((CASE*S.H)+10))										//ligne horizontal
	{
		p1.y = (CASE*i)+5;
		p2.y = p1.y;
		draw_line(p1,p2,silver);
		i++;
	}
	while (p3.x <((CASE*S.L)+10))										//ligne vertical
	{
		p3.x = (CASE*j)+5;
		p4.x = p3.x;
		draw_line(p3,p4,silver);
		j++;
	}
}

void afficher_border(SLIDER S) {										//Affichage du mur externe, toujours présent
	POINT p1, p2;
	int i = 0, j = 0;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 0;
	while (p2.y < CASE*S.H)
	{
		p1.x = (CASE*i)+5; p1.y = (CASE*j)+5;
		p2.x = (CASE*i)+8; p2.y = (CASE*j)+CASE+5;
		draw_fill_rectangle(p1,p2,slategray);
		j++;
	}
	i = S.L;
	j = 0;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 0;
	while (p2.y < CASE*S.H)
	{
		p1.x = (CASE*i)+2; p1.y = (CASE*j)+5;
		p2.x = (CASE*i)+5; p2.y = (CASE*j)+CASE+5;
		draw_fill_rectangle(p1,p2,slategray);
		j++;
	}
	i = 0;
	j = 0;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 0;
	while (p2.x < CASE*S.L)
	{
		p1.x = (CASE*i)+5; p1.y = (CASE*j)+5;
		p2.x = (CASE*i)+CASE+5; p2.y = (CASE*j)+8;
		draw_fill_rectangle(p1,p2,slategray);
		i++;
	}
	i = 0;
	j = S.H;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 0;
	while (p2.x < CASE*S.L)
	{
		p1.x = (CASE*i)+5; p1.y = (CASE*j)+2;
		p2.x = (CASE*i)+CASE+5; p2.y = (CASE*j)+5;
		draw_fill_rectangle(p1,p2,slategray);
		i++;
	}
}	

void afficher_murs(SLIDER S) {											//Affichage des mur présent dans les fichiers "niveau"
	FILE * F = fopen("niveau_001.slider", "r");							//A changer pour différents niveaux.
	POINT p1,p2;
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
		fscanf(F, "%d" , &S.d);
		printf("\n");
		if (S.d == 0)													//Mur en haut de la case
		{
			p1.x = (CASE*S.x)+5; p1.y = (CASE*S.y)+CASE+2;
			p2.x = (CASE*S.x)+CASE+5; p2.y = (CASE*S.y)+CASE+5;
			draw_fill_rectangle(p1,p2,slategray);
		}
		else if (S.d == 3)												//Mur à droite de la case
		{
			p1.x = (CASE*S.x)+CASE+2; p1.y = (CASE*S.y)+5;
			p2.x = (CASE*S.x)+CASE+5; p2.y = (CASE*S.y)+CASE+5;
			draw_fill_rectangle(p1,p2,slategray);
		}
		else if (S.d == 6)												//Mur en bas de la case
		{
			p1.x = (CASE*S.x)+5; p1.y = (CASE*S.y)+5;
			p2.x = (CASE*S.x)+CASE+5; p2.y = (CASE*S.y)+8;
			draw_fill_rectangle(p1,p2,slategray);
		}
		else if (S.d == 9)												//Mur à gauche de la case
		{
			p1.x = (CASE*S.x)+5; p1.y = (CASE*S.y)+5;
			p2.x = (CASE*S.x)+8; p2.y = (CASE*S.y)+CASE+5;
			draw_fill_rectangle(p1,p2,slategray);
		}
		//printf("%d %d %d\n", S.x, S.y, S.d);
	}
	fclose(F);
}

void afficher_le_slider(SLIDER S) {										//Affiche le slider (Le joueur)
	POINT p1;
	if (S.x_slider > S.L || S.y_slider > S.H)
	{
		printf("Erreur! Position initial du slider non conforme!\n");
		exit(1);
	}
	p1.x = (CASE*S.x_slider)+(CASE/2)+5; p1.y = (CASE*S.y_slider)+(CASE/2)+5;
	draw_fill_circle(p1,15,mediumpurple);
}

void afficher_sortie(SLIDER S) {										//Affiche la sortie, c'est a dire la condition de victoire
	POINT p1, p2;
	if (S.x_exit > S.L || S.y_exit > S.H)
	{
		printf("Erreur! Position de la sortie non conforme!\n");
		exit(1);
	}
	p1.x = (CASE*S.x_exit)+5; p1.y = (CASE*S.y_exit)+5;
	p2.x = (CASE*S.x_exit)+CASE+5; p2.y = (CASE*S.y_exit)+CASE+5;
	draw_fill_rectangle(p1,p2,mediumaquamarine);
}

void effacer_slider(SLIDER S) {											//Efface le slider afin de le déplacer
	POINT p1;
	p1.x = (CASE*S.x_slider)+(CASE/2)+5; p1.y = (CASE*S.y_slider)+(CASE/2)+5;
	draw_fill_circle(p1,15,white);
}

void afficher_slider(SLIDER S) {										//Affiche l'ensemble des fonctions
	afficher_grille(S);
	afficher_sortie(S);
	afficher_border(S);
	afficher_murs(S);
	afficher_le_slider(S);
}


void finir_affichage(SLIDER S) {										//Ferme l'interface apres que la touche echap est appuyer
	/*POINT p;
	p.x = (CASE*S.L)/2;
	p.y = (CASE*S.H)/(1/3);
	aff_pol_centre ("Victory!", 20, p, black);*/
	wait_escape();
}
