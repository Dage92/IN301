# include <stdio.h>
# include <stdlib.h>

struct element{
	int val;
	struct element* suiv;
};
typedef struct element element;
typedef struct element* liste;

liste creer_liste_vide(){
	return NULL;
}

int est_vide(liste l){
	return(l==NULL);
	}
	
void afficher_liste(liste l){
	while(l!=NULL){
		printf("%d\n",l->val);
		l=l->suiv;
	}
}

void libere (liste l){
	if(est_vide(l)){
		libere(l->suiv);
		free(l);
	}
}

liste ajout_debut(liste l,int e){
	liste tmp=malloc(sizeof(element));
	tmp->val=e;
	tmp->suiv=l;
	return tmp;
	}
	
liste ajout_fin(liste l,int e){
	liste tmp=l;
	if(est_vide(l)){return ajout_debut(l,e);}
	while(tmp->suiv!=NULL){
		tmp=tmp->suiv;
	}
	liste new=malloc(sizeof(element));
	new->val=e;
	new->suiv=NULL;
	tmp->suiv=new;
	return l;
}
	
int trie(liste l){
	liste tmp=l;
	while(tmp!=NULL){
		if (tmp->val>tmp->suiv->val){
			return 0;
		}
	}
	return 1;
}

liste ajout_trie(liste l,int e){
	liste tmp=l;
	liste new=malloc(sizeof(element));
	new->val=e;
	if(l==NULL || e<l->val){
		new->suiv=NULL ;
		return ajout_debut(l,e);
		}
	while(tmp->suiv!=NULL && e>tmp->suiv->val){
		tmp=tmp->suiv;
	}
	new->suiv=tmp->suiv;
	tmp->suiv=new;
	return l;
}

int taille(liste l){
	if(l==NULL) {
		return 0;
	}
	return 1+taille(l->suiv);
	}

liste alea_liste(int n){
	int x;
	srand(time());
	liste l=creer_liste_vide();
	while(1){
		x=rand()%n;
		if(x==0){return l;}
		else l=ajout_debut(l,x);
	}
}	
	
int main(){
	liste l;
	l=creer_liste_vide();
	est_vide(l);
	l=ajout_debut(l,1);
	l=ajout_fin(l,2);
	l=ajout_trie(l,5);
	afficher_liste(l);
}

