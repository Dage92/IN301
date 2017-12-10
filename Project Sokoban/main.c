/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include <stdio.h>
#include <stdlib.h>
#include "lire_ecrire.h"
#include "affichage.h"
#include "sokoban.h"
#include <uvsqgraphics.h>
#include "constantes.h"
#include "action.h"
#include "historique.h"

/*Les structures de données propres au jeu*/
/*
 * 
 * */
/*la structure du Jeu à proprement parler*/
struct jeu
{
	FILE *F;
	int fin;
	SOKOBAN S;
	ACTION A;
	historique h;
};

/*La structure de l'éditeur de niveau*/
struct edition
{
	FILE *F;
	int fin;
	SOKOBAN S;
	ACTION A;
	char objet;
};

/*la structure d'interprétation de la ligne de commande*/
struct optionJeu
{
	int mode;
	char *fichier;
	int niveau;
};
/*
 * 
 * */
 
/*...............PROTOTYPES...............*/
/*
 * 
 * */
int stoi(char *s);/*...ligne 80...*/

/*Les prototypes pour manipuler struct jeu*/
struct jeu initJeu();/*...ligne 94...*/
void chargeNiveau(struct jeu *j, char *fic, int niveau, int mod);/*...ligne 105...*/
void jouer(char *fic, int niveau, int mod);/*...ligne 122...*/

/*Les prototypes pur manipuler struct optionJeu*/
struct optionJeu commande(int argc, char **argv)/*...ligne 156...*/;
struct optionJeu initOption(int md, char *fic, int niv);/*...ligne 170...*/
void detruitOption(struct optionJeu *o);/*...ligne 179...*/

/*les prototypes pour manipuler struct edition*/
struct edition initEditeur(int mod);/*...ligne 193...*/
void editeur(int mod, char *fic);/*...ligne 211...*/

/*....................LA FONCTION MAIN EST EN BAS DU FICHIER (ligne 231)....................*/
/*
 * 
 * */


/*...............FONCTIONS...............*/
/*
 * 
 * */
 int stoi(char *s)
{
	int i=0;int n=0;
	while(s[i]!= '\0')
	{
		n=10*n+s[i]-'0';
		i++;
	}
	return n;
}
 /*..........struct jeu..........*/
 /*
  * 
  * */
struct jeu initJeu()
{
	struct jeu j;
	j.fin = 0;
	pile undo = creerPileVide();
	pile redo = creerPileVide();
	j.h.undo = undo;
	j.h.redo = redo;
	return j;
}

void chargeNiveau(struct jeu *j, char *fic, int niveau, int mod)
{
	j->F = fopen(fic, "r");if(!j->F){printf("il n'existe pas de fichier %s\n", fic);return;}
	metAuNiveau(j->F, niveau);
	j->S = tailleNiveau(j->F, j->S);
	j->S = initSokoban(j->S);
		
	initGraphiques();
		
	fclose(j->F);
	j->F = fopen(fic, "r");
	metAuNiveau(j->F, niveau);
	lireFichierSokoban(j->F, &(j->S));
	fclose(j->F);
	afficheSokoban(j->S, mod);
}

void jouer(char *fic, int niveau, int mod)
{
	struct jeu j = initJeu();
	while(!j.fin)
	{
		chargeNiveau(&j, fic, niveau, mod);
		int i = 1;
		int finNiveau = 0;
		while(!finNiveau)
		{
			if(i == 9999){j.fin = 1; finNiveau = 1;}//sécurité
			j.S.nb_coups ++;
			j.A = recupereAction();
			changeSokobanAction(&(j.S), &(j.A), &(j.h));
			afficheSokoban(j.S, mod);
			if(estReussi(j.S) || j.A.typeAction == SUIVANT){printf("FELICITATIONS\n"); finNiveau = 1;}
			if(j.A.typeAction == QUITTER){j.fin = 1; finNiveau = 1;}
			if(j.A.typeAction == PRECEDENT){niveau = niveau - 2; finNiveau = 1;}
			i++;
		}
		j.h.undo = suppPile(j.h.undo);
		j.h.redo = suppPile(j.h.redo);
		niveau++;
	}
	detruireSokoban(&(j.S));
	wait_escape();
}
/*
 * 
 * */

/*..........struct optionJeu..........*/
/*
 * 
 * */
struct optionJeu commande(int argc, char **argv)
{
	struct optionJeu o;
	o.mode = JEU;
	if(argc<2){o = initOption(JEU, "sasquatch1.xsb", 1);return o;}//on lance le programme avec sasquatch et niv1
	if(argc == 2){o = initOption(JEU, argv[1], 1); return o;}
	if(argv[1][0] == '-')
	{
		if(argv[1][1] == 'n'||argv[1][1]=='N'){o = initOption(JEU, argv[3], stoi(argv[2])); return o;}
		if(argv[1][1] == 'c'||argv[1][1]=='C'){o = initOption(EDITEUR, argv[2], 1);return o;}
	}
	return o;
}

struct optionJeu initOption(int md, char *fic, int niv)
{
	struct optionJeu o;
	o.mode = md;
	o.fichier = fic;
	o.niveau = niv;
	return o;
}

void detruitOption(struct optionJeu *o)
{
	return;
}


/*
 * 
 * */

/*..........struct edition..........*/
/*
 * 
 * */
struct edition initEditeur(int mod)
{
	hauteur_ecran = 20*TAILLE_CASE; largeur_ecran = 20*TAILLE_CASE+HAUTEUR_BOUTON;
	largeur_bouton = hauteur_ecran / NB_BOUTONS_EDITEUR;
	initGraphiques();
	SOKOBAN S;
	ACTION A;
	struct edition e;
	e.fin = 0;
	e.objet = MUR;
	S.hauteur = 20; S.largeur = 20;
	S = initSokobanEditeur(S);
	e.S = S;
	e.A = A;
	afficheSokoban(e.S, mod);
	return e;
}

void editeur(int mod, char *fic)
{
	struct edition e = initEditeur(mod);
	do
	{
		e.A = recupereAction();
		changeSokobanActionEditeur(&(e.S), &(e.A), &(e.objet));
		afficheSokoban(e.S, mod);
		if(e.objet == ENREGISTRER){sortie(fic, e.S);printf("sokoban enregistré à l'adresse  : %s\n", fic);}
	}while(e.objet != QUITTER);
	detruireSokoban(&(e.S));
	wait_escape();
}
/*
 * 
 * */
 
/*..........La fontion main..........*/
int main(int argc, char **argv)
{
	struct optionJeu o = commande(argc, argv);
	if(o.mode == JEU){jouer(o.fichier, o.niveau, o.mode);detruitOption(&o);}
	if(o.mode == EDITEUR){editeur(o.mode, o.fichier);detruitOption(&o);}
	else printf("commande incomprise\n");
	printf("compilation ok!\n");
	exit(0);
}
