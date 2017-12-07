/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include "affichage.h"
#include <uvsqgraphics.h>

/*initialise la fenêtre d'affichage selon la taille du Sokoban*/
void initGraphiques()
{
	init_graphics(hauteur_ecran, largeur_ecran);
	affiche_auto_off();
}

/*affiche un boutton à la hauteur y, et à la position bouton*/
void afficheBouton(int bouton, char *text, int y, COULEUR coul)
{
	POINT bg, hd, centre;
	bg.x = bouton*largeur_bouton; bg.y = y;
	hd.x = bg.x+largeur_bouton;
	hd.y = bg.y+HAUTEUR_BOUTON;
	centre.x = (bg.x + hd.x)/2.0;
	centre.y = (bg.y + hd.y)/2.0;
	draw_fill_rectangle(bg, hd, coul);
	draw_rectangle(bg,hd,rouge);
	aff_pol_centre(text, 12, centre, rouge);
}

/*affiche les boutons necessaires au jeu*/
void afficheLesBoutonsJeu(SOKOBAN S)
{
	int y = S.largeur*TAILLE_CASE + 1;
	afficheBouton(QUIT, "QUIT", y, blanc);
	afficheBouton(PREC, "Niv Prec", y, blanc);
	afficheBouton(SUIV, "Niv Suiv", y, blanc);
	afficheBouton(UNDO, "<", y, blanc);
	afficheBouton(REDO, ">", y, blanc);
	char *c = malloc(1*sizeof(char));//pour écrire un nombre dans une chaîne de caractère.
	sprintf(c, "%d", S.nb_coups);
	afficheBouton(NB_COUPS, c, y, blanc);
	afficheBouton(RESET, "RESET", y, blanc);
	free(c);
}

/*affiche les boutons necessaires à l'editeur*/
void afficheLesBoutonsEditeur(SOKOBAN S)
{
	int y = S.largeur*TAILLE_CASE;
	afficheBouton(QUIT, "QUIT", y, blanc);
	afficheBouton(JOUEUR, "joueur", y, magenta);
	afficheBouton(CAISSE, "caisse", y, jaune);
	afficheBouton(MUR, "mur", y, noir);
	afficheBouton(SOL, "sol", y, gris);
	afficheBouton(ENREGISTRER, "enregistrer", y, blanc);
}

/*affiche la case du plateau[x][y] aurait pu prendre un SOKOBAN en parametre plutôt que la valeur de la case. C'est redondant.*/
void afficheCase(char c, int x, int y)
{
	POINT bg, hd;
	bg.x = x * TAILLE_CASE;
	bg.y = y * TAILLE_CASE;
	hd.x = bg.x - TAILLE_CASE;
	hd.y = bg.y + TAILLE_CASE;
	int couleur;
	switch(c)
	{
		case '#':{couleur = noir; break;}//mur
		case '$':{couleur = jaune; break;}//caisse
		case '.':{couleur = cyan; break;}//rangement de caisse
		case '@':{couleur = magenta; break;}//joueur
		case '*':{couleur = vert; break;}//caisse sur une zone de rangement
		case '+':{couleur = bleu; break;}//personnage sur une zone de rangement
		default:{couleur = gris; break;}
	}
	draw_fill_rectangle(bg, hd, couleur);
	draw_rectangle(bg,hd,rouge);
}

/*affiche toutes les cases du SOKOBAN*/
void affichePlateau(SOKOBAN S)
{
	int x;
	int y;
	for(x = S.hauteur -1; x >= 0; x--)
		for(y = 0; y < S.largeur; y++)
			afficheCase(S.plateau[x][y], x, y);
}

/*affiche Le SOKOBAN avec les boutons necessaires (d'où la mention du mod(JEU ou EDITEUR))*/
/*peut être deux fonctions différentes auraient été plus malin.
 * ainsi, le programme m'apparaissait comme plus modulaire, mais, on met en paramètre un mod sur toute la longueur du processus, et il ne sert que pour les boutons.
 * C'est un peu laborieux peut être. Voir la fonction main*/
void afficheSokoban(SOKOBAN S, int mod)
{
	fill_screen(noir);
	affichePlateau(S);
	if(mod == JEU)
		afficheLesBoutonsJeu(S);
	else
		afficheLesBoutonsEditeur(S);
	affiche_all();
}
