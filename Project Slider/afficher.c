#include <uvsqgraphics.h>

#include "mes_types.h"


void initialiser_affichage(SLIDER S) {
	init_graphics (50*S.L,50*S.H);
}

void afficher_grille(SLIDER S) {
}

void afficher_murs(SLIDER S) {
}

void afficher_le_slider(SLIDER S) {
}

void afficher_sortie(SLIDER S) {
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
