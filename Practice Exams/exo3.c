#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int val;
	struct element *g;
	struct element *d;
} node;

int gauche_non_rec(struct element *e)
{
	if(head == NULL)
	{
		printf("List is Empty!!! Deletion not possible!!!");
	}
	else
	{
		struct element *temp = node;
		if(temp -> previous == temp -> next)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			head = temp -> next;
			head -> previous = NULL;
			free(temp);
		}
	}
}

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

