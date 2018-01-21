#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel{
	int r;
	int g;
	int b;
} pixel;

typedef struct Img
{
	int h;
	int l;
	int coul;
	pixel image;
} img;

int main (int argc, char **argv)
{
	if(argc <2)
	{
		printf("Pas assez d'arguments.\n");
		return 1;
	}
	
	FILE * f = fopen(argv[1],"r");
	if(f == NULL)
	{
		printf("Erreur lors de l'ouverture de %s\n", argv[1]);
		return 2;
	}
	
	img mi;
	fscanf(f,"P3");
	fscanf(f,"%d",&mi.l);
	fscanf(f,"%d",&mi.h);
	fscanf(f,"%d",&mi.coul);
	
	mi.image = (pixel**)malloc(sizeof(pixel*)*mi.l);
	for(int i=0; i<mi.l; i++)
	{
		mi.image[i] = (pixel *)malloc(sizeof(pixel)*mi.h);
	}
	
	for(int i=0; i<mi.h;j++)
	{
		for(int j=0;j<mi.j;j++)
		{
			fscanf(f,"%d",&mi.image[i][j].r);
			fscanf(f,"%d",&mi.image[i][j].g);
			fscanf(f,"%d",&mi.image[i][j].b);
		}
	}
	
	FILE * f2 = fopen("cpy.ppm","w");
	
	fprintf(f2,"P3");
	fprintf(f2,"%d\n", mi.l, mi.h);
	fprintf(f2,"%d",mi.coul);
	
	for(int i=0; i<mi.h;j++)
	{
		for(int j=0;j<mi.j;j++)
		{
			fscanf(f2,"%d %d %d", mi.image[i][j].r, mi.image[i][j].g, mi.image[i][j].b);
		}
	}
}
