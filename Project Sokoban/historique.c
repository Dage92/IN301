/*
 * Nom : Delaunay
 * Prenom : Damien
 * NO_etudiant : 21602928
 * */

#include "historique.h"

/*crée une pile vide*/
pile creerPileVide()
{
	return NULL;
}

/*ajoute un élément à une pile*/
pile empiler(POINT dir, POINT pos_perso, char posP, char posP_un, char posP_deux, pile p)
{
	pile nouv = malloc(sizeof(struct elemSokoban));
	nouv->direction = dir;
	nouv->posPersonnage = pos_perso;
	nouv->c_posP = posP;
	nouv->c_posPlusUn = posP_un;
	nouv->c_posPlusDeux = posP_deux;
	nouv->suivant = p;
	return nouv;
}

/*met dans target le dernier élément de la pile, et le supprime de celle-ci (vide la mémoire)*/
pile depiler(pile p, pile target)
{
	if(!p) return NULL;
	pile suiv = p->suivant;
	*target = *p;
	free(p);
	return suiv;
}

/*supprime une pile et vide la mémoire.*/
pile suppPile(pile p)
{
	if(!p){return NULL;}
	p->suivant = suppPile(p->suivant);
	free(p);
	p=NULL;
	return p;
}
