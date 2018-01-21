#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "lire_ecrire.h"

int CanSliderMove(SLIDER S)										//Renvoi 0 si le slider ne peut pas bouger et 1 si il peut.
{
	if(S.x_slider < 30 || S.x_slider > ((CASE*S.L)-25) || S.y_slider < 30 || S.y_slider > ((CASE*S.H)-25))
	{
		return 0;
	}
	return 1;
}

SLIDER MoveUp(SLIDER S)											//Change la position du slider d'un case vers une direction preordonne
{
	effacer_slider(S);
	S.y_slider += CASE;
	afficher_le_slider(S);
	return S;
}

SLIDER MoveRight(SLIDER S)
{
	effacer_slider (S);
	S.x_slider += CASE;
	afficher_le_slider (S);
	return S;
}

SLIDER MoveLeft (SLIDER S)
{
	effacer_slider (S);
	S.x_slider -= CASE;
	afficher_le_slider (S);
	return S;
}

SLIDER MoveDown (SLIDER S)
{
	effacer_slider (S);
	S.y_slider -= CASE;
	afficher_le_slider (S);
	return S;
}

SLIDER MoveSlider(SLIDER S)										//Permet de bouger le slider grace aux fleches
{
	int i, arrow;
	char key;
	POINT click;
	i = wait_key_arrow_clic (&key, &arrow, &click);
	while (CanSliderMove(S) == 1)
	{
		if (i == EST_FLECHE)
		{
			if (arrow == FLECHE_HAUT)
			{
				S = MoveUp(S);
			}
			if (arrow == FLECHE_DROITE)
			{
				S = MoveRight(S);
			}
			if (arrow == FLECHE_BAS)
			{
				S = MoveDown(S);
			}
			if (arrow == FLECHE_GAUCHE)
			{
				S = MoveLeft(S);
			}
			return S;
		}
		else
		{
			printf("Appuyer sur une flèche pour bouger le slider.\n");
		}
	}
}
