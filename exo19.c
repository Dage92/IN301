#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//a
struct element{
	int val;
	struct element* suiv;
};
typedef struct element* liste;

//b
liste creer_liste_vide()
{
	return NULL;
}

int est_vide(liste l)
{
	return (l==NULL);
}
		
void afficher_liste(liste l)				//iteratif
{
	while(l!=NULL)
	{
		printf("%d ", (*l).val);
		l=l->suiv;
	}
	printf("\n");
}

/*void afficher_liste(liste l)				//recursif
{
	if(!=est_vide(l));
	{
		printf("%d\n", (*l).val);
		afficher_liste(l->suiv);
	}
}*/

/*void libere(liste l)
{
	if(est_vide(l))
	{
	}
}*/
//c
liste ajout_debut(liste l, int x)
{
	liste new_elem=malloc(sizeof(liste));
	new_elem->val = x;
	new_elem->suiv = l;
	return new_elem;
}

liste ajout_fin(liste l, int x)
{
	liste tmp = l;
	if(est_vide(l))
	{
		return ajout_debut(l,x);
	}
	while (tmp->suiv!=NULL)
	{
		tmp = tmp->suiv;
	}
	liste new=malloc(sizeof(liste));
	new->val = x;
	new->suiv = NULL;
	tmp->suiv = new;
	return l;
}

int main()
{
	srand(time(NULL));
	liste l;
	l=creer_liste_vide();
	est_vide(l);
	printf("Premiere liste:\n");
	for(int i=0;i<10;i++)
	{
		l = ajout_debut(l,rand()%100);
	}
	afficher_liste(l);
	int i = rand()%100;
	printf("\nAjoutons %d a la fin:\n",i);
	l = ajout_fin(l,i);
	afficher_liste(l);
	return 0;
}
