
#define CASE 50


struct slider {
	int L,H; // Largeur et hauteur de la grille
	int* X;//position du slider
	int* Y;//position du slider
	int SOX,SOY;//sortie
	int N ;// nombre de mur
	int T[20][20];// tableau pour les murs
	int M;//l'endroitdu mur'
	int A,B;
};

typedef struct slider SLIDER;
