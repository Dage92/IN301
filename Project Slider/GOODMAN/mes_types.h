
#define CASE 50

struct slider {
	int L, H; 					//Largeur et hauteur de la grille
	int x_slider, y_slider;		//Position du slider
	int x_exit, y_exit;			//Position de la sortie
	int N;						//Nombre de murs
	int wall[20][20];			//Position des murs en forme de matrice
	int x;						//Position x d'un mur
	int y;						//Position y d'un mur
	int d;						//Orientation du mur (Haut, bad, droite, gauche) dans la case
};
typedef struct slider SLIDER;
