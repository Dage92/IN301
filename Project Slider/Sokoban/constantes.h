/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#ifndef CONSTANTES_H
#define CONSTANTES_H

/*..........la hauteur et largeur de l'écran..........*/
#define HAUTEUR 600
#define LARGEUR 800

#define TAILLE_CASE 30

/*..........les boutons du jeu et de l'éditeur..........*/
#define NB_BOUTONS_JEU 7
#define QUIT 0
#define PREC 1
#define SUIV 2
#define UNDO 3
#define REDO 4
#define NB_COUPS 5
#define RESET 6

#define NB_BOUTONS_EDITEUR 6
#define JOUEUR 1
#define CAISSE 2
#define MUR 3
#define SOL 4
#define ENREGISTRER 5

#define HAUTEUR_BOUTON 3*TAILLE_CASE

/*..........définit le mode dans lequel nous sommes..........*/
#define JEU 1
#define EDITEUR 2

/*..........des variables globales qui remplacent les constantes pour la hauteur et largeur de l'écran..........*/
/*Les variables globales me permettent de changer la valeur de la largeur et hauteur en fonction de la taille du Sokoban chargé*/
int hauteur_ecran;
int largeur_ecran;
int largeur_bouton;
/*...................................................................................................*/

/*..........les valeurs servant de point d'arrêt aux boucles de jeu ou d'édition..........*/
#define QUITTER 98
#define SUIVANT 97
#define PRECEDENT 96

/*un million*/
#define MELANGE 1000000

#endif
