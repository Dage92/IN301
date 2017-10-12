#include <stdio.h>
#include <stdlib.h>

struct Tableau				//A)
{
	int taille;				//4 octet
	int tab[100];			//400 octet
};							//donc taille de la struct est de 404 octet
typedef struct Tableau tableau;

int alea(int n)				//C)
{
	return rand()%n;
}

tableau init()				//D)
{
	tableau t;
	int i;
	t.taille = 10;
	for(i=0; i<t.taille; i++)
	{
		t.tab[i] = alea(20);
	}
	return t;
}

void affiche(tableau t)		//E)
{
	int i;
	for(i=0; i<t.taille; i++)
	{
		printf("%d \n",t.tab[i]);
	}
}

int produit(tableau t)		//F)
{
	int i;
	int res=1;
	for(i=0; i<t.taille; i++)
	{
		res *= t.tab[i];
	}
	return res;
}

int minimum(tableau t)		//G)
{
	int min=t.tab[i];
	int t;
	for(i=0; i<t.taille; i++)
	{
		if(t.tab[i]<min)
		{
			min=t.tab[i];
		}
	}
	return min;
}

tableau decale(tableau t)
{
	int i;
	t.taille++;
	for(i=t.taille-1; i>0; i--)
	{
		t.tab[i] = t.tab[i-1];
	}
	t.tab[i]=0;
	return tab;
}
tableau t=int();
t=decale (t);

void decale(tableau *pt)
{
	int i;
	(*pt).taille++;
	for(i=(*pt).taille; i>0; i--)
	{
		(*pt).tab[i]=(*pt).tab[i-1];
	}
	(*pt).tab[i]
	
int main()
{
	srand(time(NULL));
	tableau t = init();
}
