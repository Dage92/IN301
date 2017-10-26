#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//a
struct Liste{
	int val;
	struct Liste* suiv;
};
typedef struct Liste* liste;

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

liste libere(liste l)
{
	liste tmp = l;
	while(!est_vide(l))
	{
		free(l);
		l = tmp->suiv;
	}
	return NULL;
}

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

int est_trie (liste l)
{
	liste tmp = l;
	if (tmp->suiv == NULL)
	{
		return 1;
	}
	else if (tmp->suiv->val <= tmp->val)
	{
		return 0;
	}
	return est_trie (tmp->suiv);
}

void affiche_est_trie (liste l)
{
	if (est_trie(l) == 1)
	{
		printf("Trié: OUI\n");
	}
	else
	{
		printf("Trié: NON\n");
	}
}
	
liste ajout_trie(liste l, int x)
{
	liste tmp = l;
	liste new = malloc(sizeof(liste));
	new->val = x;
	if (l == NULL || x < l->val)
	{
		new->suiv = NULL;
		return ajout_debut (l , x);
	}
	while (tmp->suiv != NULL && x > tmp->suiv->val)
	{
		tmp = tmp->suiv;
	}
	new->suiv = tmp->suiv;
	tmp->suiv = new;
	return l;
}

/*liste init_list_random(liste l, int x)
 * {
 * 		int tirage = rand()%n;
 * 		while(tirage != 0)
 * 		{
 * 			printf("On ajoute %d a la liste\n", tirage);
 * 			l = ajout_fin(l,tirage);
 * 			tirage = rand()%n;
 * 		}
 * 		return l;
 * }*/
//d
int taille(liste l)
{					
	if (l == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + taille(l->suiv);
	}
}

//e
/*int find(l, x)
{
	while (l->val != NULL)
	{*/
		
	
int main()
{
	srand(time(NULL));
	liste l;
	l=creer_liste_vide();					//Creation d'un liste.
	printf("Liste d'origine:\n");			//Affiche la liste en ajoutant chaque nouvel ajout au debut.
	for(int i=0;i<10;i++)
	{
		l = ajout_debut(l,rand()%100);
	}
	afficher_liste(l);
	est_trie(l);
	affiche_est_trie (l);
	printf("# d'éléments: %d\n", taille(l));
	int i = rand()%100;
	printf("\nAjoutons %d à la fin:\n", i);	//Affiche la liste en ajoutant a la fin.
	l = ajout_fin(l,i);
	afficher_liste(l);
	est_trie(l);
	affiche_est_trie (l);
	printf("# d'éléments: %d\n", taille(l));
	int j = rand()%100;
	printf("\nAjoutons %d en gardant le trie:\n", j);	//Affiche la liste en ajoutant d'un maniere trie.
	l = ajout_trie(l , j);
	afficher_liste(l);
	est_trie(l);
	affiche_est_trie (l);
	printf("# d'éléments: %d\n", taille(l));
	libere(l);
	return 0;
}
