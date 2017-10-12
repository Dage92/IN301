#include <stdio.h>
#include <stdlib.h>

//b
void permut(int *a, int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}
	
//c
void reinitPointeur(int* *p)
{
	*p=NULL;
}

int main()
{
	//a
	printf("a)\n");
	char xchar;
	int xint;
	double xdouble;
	
	printf("Taille d'un char: %ld octets\n",sizeof(xchar));
	printf("Taille d'un int: %ld octets\n",sizeof(xint));
	printf("Taille d'un double: %ld octets\n",sizeof(xdouble));
	printf("Taille d'un char*: %ld octets\n",sizeof(char*));			//Les pointeurs donne une taille qui recouvre la memoire: 4 sur 32bit et 8 sur 64bit.
	printf("Taille de void*: %ld octets\n",sizeof(void*));
	printf("Taille de int*: %ld octets\n",sizeof(int*));
	printf("Taille de double*: %ld octets\n",sizeof(double*));
	printf("Taille de int**: %ld octets\n",sizeof(int**));
	printf("Taille de int[10]: %ld octets\n",sizeof(int[10]));			//donne la taille d'un seul element.
	printf("Taille de char[7][3]: %ld octets\n",sizeof(char[7][3]));		
	
	char tab[10];
	printf("Taille de tab: %ld octets\n",sizeof(tab));
	printf("Taille de tab[0]: %ld octets\n",sizeof(tab[0]));
	printf("Taille de &tab[0]: %ld octets\n",sizeof(&tab[0]));
	printf("Taille de *&tab: %ld octets\n",sizeof(*&tab));
	printf("Taille de *&tab[0]: %ld octets\n",sizeof(*&tab[0]));
	
	//b
	printf("\nb)\n");
	int x,y;
	x=1;
	y=2;
	printf("Avant permutation x=%d et y=%d\n",x,y);
	permut(&x,&y);
	printf("Apres permutation x=%d et y=%d\n",x,y);
	
	//c
	printf("\nc)\n");
	int a=1;
	int* p=&a;
	printf("Avant reinitialisation: %p\n",p);
	reinitPointeur(&p);
	printf("Apres reinitialisation: %p\n",p);
	
	return 0;
}
