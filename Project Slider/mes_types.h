
#define TAILLE_CASE 50

struct wall {
	int x;
	int y;
	int d;
};
typedef struct wall WALL;

struct slider {
	int L, H; 					//Largeur et hauteur de la grille
	int x_slider, y_slider;		//Position du slider
	int x_exit, y_exit;			//Position de la sortie
	int N;						//Nombre de murs
	int WALL[L][H];				//Position du mur
};
typedef struct slider SLIDER;
