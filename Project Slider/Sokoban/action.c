/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include "action.h"
#include "constantes.h"
#include "time.h"

	// 3.2.5 Attend que l'on appuie soit sur une lettre, une flèche ou que l'on clique.
	// La fonction modifie la touche la flèche ou le point selon le premier événement qui arrive.
	// La fonction renvoie le type d'événement (touche, fleche ou point) 
	// Cette fonction est bloquante.
	
	/*modification de la fonction. Change SDL_KEYDOWN pour SDL_KEYUP*/
int wait_key_arrow_clic_modif (char *touche, int *fleche, POINT *P)
{ // Made by qst & pc
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE)) exit(0);
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_LEFT))  { *fleche = FLECHE_GAUCHE; return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_RIGHT)) { *fleche = FLECHE_DROITE; return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_UP))    { *fleche = FLECHE_HAUTE;  return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_DOWN))  { *fleche = FLECHE_BAS;    return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && ('a' <= event.key.keysym.sym) &&  (event.key.keysym.sym <= 'z'))  { *touche = event.key.keysym.sym-'a'+'A'; return EST_TOUCHE; }
//		if ((event.type == SDL_KEYUP)) { *touche = event.key.keysym.sym; return EST_TOUCHE; }
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) { P->x = event.button.x; P->y = HEIGHT-event.button.y; return EST_CLIC;}
	}
	return EST_RIEN;
}

/*initialise les valeurs de ACTION avec la fonction wait_key_arrow_clic_modif*/
ACTION recupereAction()
{
	ACTION A;
	A.typeAction = wait_key_arrow_clic_modif(&A.touche, &A.fleche, &A.P);
	return A;
}

/*la fonction qui modifie le SOKOBAN quand on appelle "undo" */
void retourArriere(SOKOBAN *S, historique *h)
{
	/*on gère les deux piles de l'historique*/
	if(!h->undo){printf("pas de pile undo\n");return;}
	POINT perso = S->posPersonnage;//pour plus de lisibilité
	pile dernierElement = malloc(sizeof(struct elemSokoban));//la pile qui stocke l'élément que l'on dépile
	h->undo = depiler(h->undo, dernierElement);
	POINT directionInverse = dernierElement->direction;//pour empiler sur la pile redo, on inverse la direction
	directionInverse.x = directionInverse.x * -1; directionInverse.y = directionInverse.y * -1;
	h->redo = empiler(directionInverse, perso, S->plateau[perso.x][perso.y], S->plateau[perso.x + directionInverse.x][perso.y + directionInverse.y], S->plateau[perso.x-directionInverse.x][perso.y-directionInverse.y], h->redo);
	
	/*on modifie le SOKOBAN selon le dernier élément de l'historique undo*/
	S->plateau[dernierElement->posPersonnage.x][dernierElement->posPersonnage.y] = dernierElement->c_posP;
	S->plateau[dernierElement->posPersonnage.x + dernierElement->direction.x][dernierElement->posPersonnage.y + dernierElement->direction.y] = dernierElement->c_posPlusUn;
	S->plateau[dernierElement->posPersonnage.x + 2*dernierElement->direction.x][dernierElement->posPersonnage.y + 2*dernierElement->direction.y] = dernierElement->c_posPlusDeux;
	S->posPersonnage = dernierElement->posPersonnage;
	/*libération de la mémoire de l'élément temporaire*/
	free(dernierElement);
}

/*la fonction qui modifie le sokoban quand on appelle "redo" */
void retourAvant(SOKOBAN *S, historique *h)
{
	/*on gère les deux piles de l'historique*/
	if(!h->redo){printf("pas de pile redo\n");return;}
	pile dernierElement = malloc(sizeof(struct elemSokoban));//la pile qui stocke l'élément que l'on dépile
	h->redo = depiler(h->redo, dernierElement);
	POINT perso = dernierElement->posPersonnage;//pour plus de lisibilité
	POINT directionInverse = dernierElement->direction;//pour empiler sur la pile undo, on inverse la direction
	directionInverse.x = directionInverse.x * -1; directionInverse.y = directionInverse.y * -1;
	h->undo = empiler(directionInverse, S->posPersonnage, S->plateau[S->posPersonnage.x][S->posPersonnage.y], S->plateau[S->posPersonnage.x + directionInverse.x][S->posPersonnage.y+directionInverse.y], S->plateau[S->posPersonnage.x+2*directionInverse.x][S->posPersonnage.y+2*directionInverse.y], h->undo);
	
	/*on modifie le SOKOBAN selon le dernier élément de l'historique redo*/
	S->plateau[perso.x][perso.y] = dernierElement->c_posP;
	S->plateau[perso.x + dernierElement->direction.x][perso.y + dernierElement->direction.y] = dernierElement->c_posPlusUn;
	S->plateau[dernierElement->posPersonnage.x - dernierElement->direction.x][dernierElement->posPersonnage.y - dernierElement->direction.y] = dernierElement->c_posPlusDeux;
	S->posPersonnage = dernierElement->posPersonnage;
	/*libération de la mémoire de l'élément temporaire*/
	free(dernierElement);
}

/*retourne au début du niveau. Malheureusement, efface l'historique.
 * Je ne voyais pas comment le conserver sans utiliser toute une structure de Sokoban dans mes piles undo et redo. */
void resetNiveau(SOKOBAN *S, historique *h)
{
	while(h->undo)
	{
		retourArriere(S, h);
	}
	S->nb_coups = 0;
}

/*gestion d'un clic de la souris dans le jeu*/
void clic(SOKOBAN *S, ACTION *A, historique *h)
{
	if(A->P.y < S->hauteur * TAILLE_CASE){return;}/*clic sur le plateau du sokoban*/
	if(A->P.x<largeur_bouton){A->typeAction = QUITTER; return;}/*clic sur le bouton QUIT*/
	if(A->P.x<2*largeur_bouton){A->typeAction = PRECEDENT; return;}/*clic sur le bouton niveau précédent*/
	if(A->P.x<3*largeur_bouton){A->typeAction = SUIVANT; return;}/*clic sur le bouton niveau suivant*/
	if(A->P.x<4*largeur_bouton){retourArriere(S, h); return;}/*clic sur le bouton < (undo)*/
	if(A->P.x<5*largeur_bouton){retourAvant(S, h); return;}/*clic sur le bouton > (redo)*/
	if(A->P.x<6*largeur_bouton){return;}/*clic sur le compteur de coups joués*/
	if(A->P.x<7*largeur_bouton){while(h->undo){retourArriere(S,h);}S->nb_coups = 0; return;}/*clic sur init*/
}

/*dans l'éditeur, la fonction qui place un élément sélectionné sur le niveau*/
void placer(SOKOBAN *S, ACTION A, char objet)
{
	POINT P;
	/*passer de l'adresse x,y de la souris à celle du plateau du SOKOBAN*/
	P.x = (A.P.x / TAILLE_CASE)+1;
	P.y = A.P.y / TAILLE_CASE;
	if(objet != QUITTER && objet != ENREGISTRER && P.x < S->largeur)
	{
		//if(objet != '#' && (P.x <=1 || P.x == S->largeur-1 || P.y == 0 || P.y == S->hauteur - 1)){}/*on interdit au joueur d'enlever les murs qui ceinturent le niveau*/
		//else
		//{
			S->plateau[P.x][P.y] = objet;
			if(objet == '@')
			{	
				if(S->posPersonnage.x != 0 && S->posPersonnage.y != 0){printf("il y a déjà un joueur\n"); S->plateau[S->posPersonnage.x][S->posPersonnage.y] = ' ';}/*on n'autorise qu'un seul joueur*/
				S->posPersonnage.x = P.x; S->posPersonnage.y = P.y;
			}
		//}
	}
}

/*gère les clics de la souris en mode edition*/
void clicEditeur(SOKOBAN *S, ACTION *A, char *objet)
{
	if(A->P.y < S->hauteur * TAILLE_CASE){placer(S, *A, *objet);return;}/*quand on clique sur le plateau, on place l'élément sélectionné*/
	if(A->P.x<largeur_bouton){*objet = QUITTER; return;}/*clic sur le bouton quit*/
	if(A->P.x<2*largeur_bouton){*objet = '@'; return;}/*clic sur joueur*/
	if(A->P.x<3*largeur_bouton){*objet = '*'; return;}/*clic sur caisse, qui est sur son objectif*/
	if(A->P.x<4*largeur_bouton){*objet = '#'; return;}/*clic sur mur*/
	if(A->P.x<5*largeur_bouton){*objet = ' '; return;}/*clic sur sol*/
	if(A->P.x<6*largeur_bouton){if(bonNiveau(S)){*objet = ENREGISTRER;}else{ *objet = '#'; printf("le niveau n'est pas fermé\n");} return;}//{*objet = ENREGISTRER; return;}/*clic sur le bouton enregistrer*/
}

/*la fonction qui appelle les fonctions de modification du SOKOBAN selon les actions du joueur*/
void changeSokobanAction(SOKOBAN *S, ACTION *A, historique *h)
{
	if(A->typeAction == EST_FLECHE)bougePersonnage(S, A->fleche, h);/*on gère le déplacement*/
	if(A->typeAction == EST_TOUCHE)
	{
		if(A->touche == 'U'){retourArriere(S,h);}
		if(A->touche == 'R'){retourAvant(S,h);}
		if(A->touche == 'I'){while(h->undo){retourArriere(S,h);}S->nb_coups = 0;}
		if(A->touche == 'Q'){A->typeAction = QUITTER;}
		if(A->touche == 'S'){A->typeAction = SUIVANT;}
		if(A->touche == 'P'){A->typeAction = PRECEDENT;}
	}
	if(A->typeAction == EST_CLIC){clic(S, A, h);}
}

/*La fonction renvoie 1 si le niveau est bon : un joueur, et le sokoban fermé et 0 sinon*/
int bonNiveau(SOKOBAN *S)
{
	if(S->posPersonnage.x == 0 || S->posPersonnage.y == 0){printf("pas de personnage sur l'espace de jeu\n"); return 0;}
	SOKOBAN test = copieSokoban(*S);
	int ferme = verifieFerme(test, S->posPersonnage);
	detruireSokoban(&test);
	return ferme;
}

/*la fonction qui appelle les fonctions de modifications du SOKOBAN dans l'éditeur selon les actions du joueur*/
void changeSokobanActionEditeur(SOKOBAN *S, ACTION *A, char *objet)
{
	if(A->typeAction == EST_FLECHE){}/*on n'utilise pas les fèche dans l'édition*/
	if(A->typeAction == EST_TOUCHE)
	{
		if(A->touche == 'Q'){*objet = QUITTER;}
		if(A->touche == 'E'){if(bonNiveau(S)){*objet = ENREGISTRER;}else{ *objet = '#'; printf("le niveau n'est pas fermé\n");}}
		if(A->touche == 'M'){int i; for(i = 0; i < MELANGE; i++){melange(S);}printf("fin du mélange\n");}
		if(A->touche == 'V')
		{
			SOKOBAN test = copieSokoban(*S);
			int i = verifieFerme(test, S->posPersonnage);
			detruireSokoban(&test);
			if(i)printf("le niveau est fermé\n");
			else printf("le niveau n'est pas fermé\n");
		}
	}
	if(A->typeAction == EST_CLIC){clicEditeur(S, A, objet);}
}

/*renvoie 1 si le joueur peut bouger selon les règles du SOKOBAN, sinon, renvoie 0*/
int peutBouger(char c, char d)
{
	if(((c=='$'|| c=='*') && (d=='$'||d=='*'||d=='#'))||c=='#'){return 0;}
	return 1;
}

/*Quand le joueur peut se déplacer, modifie le SOKOBAN en conséquence.
 * Prend en paramètre un point qui est la direction dans laquelle va le joueur.
 * on modifie 3 cases du SOKOBAN : 
 * 		-Celle sur laquelle se trouve le joueur
 * 		-celle qui est juste devant lui
 * 		-celle à une case de lui
 * Les cases modifiées sont celles qui vont dans la direction du point*/
void deplacement(SOKOBAN *S, POINT P)
{
	int x = S->posPersonnage.x; int y = S->posPersonnage.y;//pour plus de lisibilité
	int posUn_x = x+P.x; int posUn_y = y+P.y;
	int posDeux_x = x+2*P.x; int posDeux_y = y+2*P.y;
	
	if(!peutBouger(S->plateau[posUn_x][posUn_y], S->plateau[posDeux_x][y+P.y*2]))return;
	if(S->plateau[posUn_x][posUn_y] == '.')S->plateau[posUn_x][posUn_y] = '+';
	//bouger les caisses.
	if(S->plateau[posUn_x][posUn_y] == '$')
	{
		if(S->plateau[posDeux_x][posDeux_y] == '.')S->plateau[posDeux_x][posDeux_y] = '*';//caisse sur rangement
		else S->plateau[posDeux_x][posDeux_y] = '$';
	}
	if(S->plateau[posUn_x][posUn_y] == '*')
	{
		if(S->plateau[posDeux_x][posDeux_y] == '.')S->plateau[posDeux_x][posDeux_y] = '*';//caisse sur rangement
		else S->plateau[posDeux_x][posDeux_y] = '$';
	}
	//fin de bouger les caisses
	//bouge le personnage
	if(S->plateau[posUn_x][posUn_y] == ' ' || S->plateau[posUn_x][posUn_y] == '$') S->plateau[posUn_x][posUn_y] = '@';
	if(S->plateau[posUn_x][posUn_y] == '*')S->plateau[posUn_x][posUn_y] = '+';
	if(S->plateau[x][y] == '@')S->plateau[x][y] = ' ';
	else S->plateau[x][y] = '.';
	//fin de bouge le personnage
	//mise à jour de la position du personnage dans le Sokoban
	S->posPersonnage.x += P.x;
	S->posPersonnage.y += P.y;
}

/*renvoie un point aléatoire de déplacement (haut bas gauche droite)*/
POINT aleaDeplacement()
{
	int dir = rand() % 4;
	POINT direct;
	switch(dir)
	{
		case 0:
		{
			direct.x = -1;
			direct.y = 0;
			break;
		}
		case 1:
		{
			direct.x = 1;
			direct.y = 0;
			break;
		}
		case 2:
		{
			direct.x = 0;
			direct.y = -1;
			break;
		}
		default:
		{
			direct.x = 0;
			direct.y = 1;
			break;
		}
	}
	return direct;
}

/*vérifie si dans l'éditeur, le personnage peut bouger.*/
int peutBougerEditeur(char c)
{
	return (c != '#' && c != '$' && c != '*');
}

/*déplace le personnage dans l'éditeur*/
void deplacementEditeur(SOKOBAN *S, POINT P)
{
	int x = S->posPersonnage.x; int y = S->posPersonnage.y;
	int devant_x = x+P.x; int devant_y = y+P.y;
	int derriere_x = x-P.x; int derriere_y = y-P.y;
	if(!peutBougerEditeur(S->plateau[devant_x][devant_y])){return;}
	
	
	if(S->plateau[derriere_x][derriere_y] == ' ' || S->plateau[derriere_x][derriere_y] == '#')
	{
		if(S->plateau[x][y] == '+')S->plateau[x][y] = '.';
		else S->plateau[x][y] = ' ';
	}
	
	//si on tire une caisse
	if(S->plateau[derriere_x][derriere_y] == '*')
	{
		if(S->plateau[x][y] == '+')S->plateau[x][y] = '*';//si on est sur un objectif
		else S->plateau[x][y] = '$';
		S->plateau[derriere_x][derriere_y] = '.';
	}
	if(S->plateau[derriere_x][derriere_y] == '$')
	{
		//printf("on tire une caisse, qui n'est pas sur un objectif\n");
		if(S->plateau[x][y] == '+'){S->plateau[x][y] = '*';}//si on est sur un objectif
		else{S->plateau[x][y] = '$';}
		S->plateau[derriere_x][derriere_y] = ' ';
	}
	
	//bouge le personnage.
	if(S->plateau[devant_x][devant_y] == '.') S->plateau[devant_x][devant_y] = '+';//si on va sur un objectif
	else S->plateau[devant_x][devant_y] = '@';
	
	//mise à jour de la pos du personnage.
	S->posPersonnage.x = devant_x;
	S->posPersonnage.y = devant_y;
}

/*joue "en arière" dans l'éditeur pour bouger les caisses*/
void melange(SOKOBAN *S)
{
	srand(time(NULL));
	POINT d = aleaDeplacement();
	deplacementEditeur(S,d);
}

/*vérifie si le Sokoban est bien fermé*/
int verifieFerme(SOKOBAN S, POINT destination)
{
	if(destination.x >= S.largeur || destination.y >= S.hauteur) return 0;
	if(S.plateau[destination.x][destination.y] == '#' || S.plateau[destination.x][destination.y] == 'a') return 1;
	S.plateau[destination.x][destination.y] = 'a';
	POINT d; d.x = destination.x + 1; d.y = destination.y + 0;
	POINT g; g.x = destination.x -1; g.y = destination.y +0;
	POINT h; h.x = destination.x + 0; h.y = destination.y + 1;
	POINT b; b.x = destination.x + 0; b.y = destination.y -1;
	return verifieFerme(S,d) && verifieFerme(S,g) && verifieFerme(S,h) && verifieFerme(S,b);
}

/*initialise le point de direction du personnage en fonction de la fleche appuyée
 * supprime la pile des "redo" 
 * ajoute un nouvel élément à l'historique du jeu
 * puis déplace le personnage*/
void bougePersonnage(SOKOBAN *S, int fleche, historique *h)
{
	POINT P;
	POINT perso = S->posPersonnage;
	switch(fleche)
	{
		case FLECHE_GAUCHE:{P.x = -1; P.y = 0; break;}
		case FLECHE_DROITE:{P.x=1;P.y=0; break;}
		case FLECHE_HAUT:{P.x=0;P.y=1; break;}
		case FLECHE_BAS:{P.x=0;P.y=-1; break;}
		default:{printf("default\n"); break;}
	}
	
	h->redo = suppPile(h->redo);
	h->undo = empiler(P, perso, S->plateau[perso.x][perso.y], S->plateau[perso.x + P.x][perso.y + P.y], S->plateau[perso.x+2*P.x][perso.y+2*P.y], h->undo);
	deplacement(S,P);
}
