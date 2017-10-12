# include <stdio.h>
# include <stdlib.h>

struct element								//A
{								
	int val;
	struct element* suiv;
};
typedef struct element element;
typedef struct element* liste;

liste creer_liste_vide()					//B
{					
	return NULL;
}

int est_vide(liste l)						//B
{						
	return(l==NULL);
}
	
void afficher_liste(liste l)				//B
{				
	while(!est_vide(l))
	{
		printf("%d\n",l->val);
		l=l->suiv;
	}
}

void libere (liste l)						//B
{						
	if(est_vide(l))
	{
		libere(l->suiv);
		free(l);
	}
}

liste ajout_debut(liste l,int e)			//C
{			
	liste tmp=malloc(sizeof(element));
	tmp->val=e;
	tmp->suiv=l;
	return tmp;
}
	
liste ajout_fin(liste l,int e)				//C
{				
	liste tmp=l;
	if(est_vide(l))
	{
		return ajout_debut(l,e);
	}
	while(tmp->suiv!=NULL)
	{
		tmp=tmp->suiv;
	}
	liste new=malloc(sizeof(element));
	new->val=e;
	new->suiv=NULL;
	tmp->suiv=new;
	return l;
}
/*liste inserer_fin(liste e, int n)
 * {
 * 	liste a;
 * 	if(e==NULL)
 * 	{
 * 		a=malloc(sizeof(struct elem));
 * 		if(a==NULL)
 * 		{
 * 			exit(1);
 * 		}...*/
	
int trie(liste l)							//C
{							
	liste tmp=l;
	while(tmp!=NULL)
	{
		if (tmp->val>tmp->suiv->val)
		{
			return 0;
		}
	}
	return 1;
}

/*int est_trie(liste l)
 * {
 * 	if(l->suiv==NULL)
 * 	{
 * 		return1;
 * 	else if((l->suiv)->val<=(l->val))
 * 	{
 * 		return 0;
 * 	}
 * 	return est_trie(l->suiv);
 * }
 * 
 * liste inserer_trie(liste l, int n)
 * {
 * 	liste a;
 * 	if((l==NULL)|| (n<=(l-<val)))
 * 	{...*/

liste ajout_trie(liste l,int e)				//C
{			
	liste tmp=l;
	liste new=malloc(sizeof(element));
	new->val=e;
	if(l==NULL || e<l->val)
	{
		new->suiv=NULL ;
		return ajout_debut(l,e);
	}
	while(tmp->suiv!=NULL && e>tmp->suiv->val)
	{
		tmp=tmp->suiv;
	}
	new->suiv=tmp->suiv;
	tmp->suiv=new;
	return l;
}

liste alea_liste(int n)						//C
{					
	int x;
	srand(time());
	liste l=creer_liste_vide();
	while(1)
	{
		x=rand()%n;
		if(x==0)
		{
			return l;
		}
		else l=ajout_debut(l,x);
	}
}	

int taille(liste l)							//D
{						
	if(l==NULL)
	{
		return 0;
	}
	return 1+taille(l->suiv);
}
	
/*int taillebis(liste l)				En une ligne
 * {
 * 	return (l==NULL) ? 0: 1+taillebis(l->suiv);
 * }*/
 
/*int find(liste l, int e)					//E
{					
	liste tmp=l;
	while (tmp!=NULL)
	{
		if(tmp->val==e)
		{
			return tmp;
		}
		tmp=tmp->suiv;
	}
	return NULL;
}

int delete(liste l, int e)					//F
{
	liste tmp=l;
	if(l!=NULL)
	{
		tmp->val=l->suiv;
		free(l);
		return tmp;
	}
	else
	{
		return 0;
	}
}*/

/*liste merge(liste l, liste n)				//G
{
	liste tmp=l;
	liste new=malloc(sizeof(element));
	*/
	
int main()
{
	liste l;
	l=creer_liste_vide();
	est_vide(l);
	l=alea_liste(10);
	l=ajout_debut(l,7);
	l=ajout_fin(l,2);
	l=ajout_trie(l,5);
	afficher_liste(l);
	free(l);
}
