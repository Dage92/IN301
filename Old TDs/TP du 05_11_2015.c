#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************  Constantes   *****************************/
#define NbPriorite 10    //nombre total de priorités
#define Nmax       8    //nombre de requêtes générées


/**************  Définition des structures ***************/

struct requete{
  int numero;    // numéro de la requête
  int priorite;  // priorité de la requête
};
typedef struct requete Requete;



/* Définir ici la structure Fap1 et Fap2 */

struct fap1
{
	Requete val;
	struct fap1 *suiv;
};
typedef struct fap1* Fap1;

struct fap2
{
	Requete val;
	struct fap2 *suiv;
};
typedef struct fap2* Fap2;


/**************  Fonctions de manipulation des structures *******/

// file initialisée vide
Fap1 initialiseFile1()
{
	return NULL;
}


void afficheFile1(Fap1 f)
{
	while(f!=NULL)			//Tant que le bout de la liste n'est pas atteint.
	{
	  printf("%d %d\n",f->val.numero,f->val.priorite); //Les numero et priorite sont affiches.
	  f=f->suiv;			//La case suivante.
	}
}



Fap1 ajoutFile1(Fap1 f, Requete r)
{
    Fap1 tmp=malloc(sizeof(Requete));  	//On reserve de l'espace memoire.
    tmp->val.numero=r.numero;			//La valeur est assigne pour la nouvelle valeur.
	tmp->val.priorite=r.numero;			
    return tmp;
}


Fap1 traiteRequete1(Fap1 f)
{
	Fap1 tmp1=f,tmp2=f;
	while(tmp1!=NULL)
	{
		if (tmp1->val.priorite>tmp2->val.priorite) 	//Recherche de l'element a plus grande priorite.
		{
			return tmp1;
			if(tmp1!=NULL)							//Suppression-Exctraction de cet element.
			{
				Fap1 Extract=tmp1->suiv;
				free(tmp1);
				return Extract;
			}
		}
		tmp1=tmp1->suiv;
	}
}


int est_vide(Fap1 f){
	return(f==NULL);
	}

void libereMemoire1(Fap1 f)
{
	if(est_vide(f))
	{
		libereMemoire1(f->suiv);
		free(f);
	}
}






/************** Génération des requêtes pour simulation *****************/

//retourne un entier aléatoire entre 0 et n-1
int alea(int n){
  return rand()%n;
}

Requete generationRequete(){
  static int numero = 0;
  Requete r;
  numero++;
  r.numero = numero;
  r.priorite = alea(NbPriorite);
  return r;
}



/************ Simulation file *****************************/


//structure 1
void simulationFile1(){
  Fap1 f1 = initialiseFile1();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f1 = traiteRequete1(f1);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f1 = ajoutFile1(f1, r);
    }
    afficheFile1(f1);
  }
  libereMemoire1(f1);
  printf("#######################################\n");
}


//structure 2
/*void simulationFile2(){
  Fap2 f2 = initialiseFile2();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f2 = traiteRequete2(f2);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f2 = ajoutFile2(f2, r);
    }
    afficheFile2(f2);
  }
  libereMemoire2(f2);
  printf("########################################\n");
}*/


/*************  Fonction main *******************************/

int main()
{
	srand(time(NULL));
  /********  à décommenter pour lancer une simulation *********/
	simulationFile1();
    
  //simulationFile2();


  
  return 0;
}






