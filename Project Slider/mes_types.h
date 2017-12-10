
#define TAILLE_CASE 50


struct slider {
	int L, H; 					//Largeur et hauteur de la grille
	int x_slider, y_slider;		//Position du slider
	int x_exit, y_exit;			//Position de la sortie
	int N;						//Nombre de murs
	int xi, yi, di;				//Position du mur
};
typedef struct slider SLIDER;
