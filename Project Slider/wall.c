#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//a
struct Tableau{						//b)
	int taille;						//4 octets.
	int tab[100];					//400 octets.
};
typedef struct Tableau tableau;		//En total: 404 octets.

//c
int alea(int n)						//rand()--> generateur pseudo aleatoire.
{										//renvoie un nombre entre [0, rand_MAX].
	return rand()%n;			//MAIS: Marche bien la premiere fois mais donne le meme ordre de # aleatoire apres la premiere fois.
}									//srand()-->choisi un point dans le tableau rand().
										//utiliser avec le temps pour generer un point de debut different.
										//srand(time(NULL).
//d
tableau init(tableau t,int taille_voulue,int taille_max)
{
	int i;
	t.taille=taille_voulue;
	for (i=0;i<t.taille;i++)
	{
		t.tab[i]=alea(taille_max);
	}
	return t;
}

//e
void affiche(tableau t)
{
	int i;
	printf("Elements du tableau: \n");
	for (i=0;i<t.taille;i++)
	{
		printf("%d\n",t.tab[i]);
	}
}
		
int main()
{
	srand(time(NULL));
	tableau t = init(t,10,20);
	printf("Taille de la structure: %ld\n",sizeof(t));
	printf("Valeur aleatoire retournee: %d\n", alea);
	affiche(t);
}
