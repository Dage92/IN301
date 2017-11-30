#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>

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
	
	img mon_image;
	fscanf(f,"P3");
	fscanf(f,"%d",&mon_image.l);
	fscanf(f,"%d",&mon_image.h);
	fscanf(f,"%d",&mon_image.coul);
	
	mon_image.image = (pixel**)malloc(sizeof(pixel*)*mon_image.l
	for(int i=0; i<mon_image.l; i++)
	{
		mon_image.image[i] = (pixel *)malloc(sizeof(pixel)*mon_image.h);
	}
	
	for(int i=0; i<mon_image.h;j++)
	{
		for(int j=0;j<mon_image.j;j++)
		{
			fscanf(f,"%d",&mon_image.image[i][j].r);
			fscanf(f,"%d",&mon_image.image[i][j].g);
			fscanf(f,"%d",&mon_image.image[i][j].b);
		}
	}
	
	FILE * f2 = fopen("cpy.ppm","w");
	
	fprintf(f2,"P3");
	fprintf(f2,"%d\n",mon_image.l,mon_image.h);
	fprintf(f2,"%d",mon_image.coul);
	
	for(int i=0; i<mon_image.h;j++)
	{
		for(int j=0;j<mon_image.j;j++)
		{
			fscanf(f2,"%d %d %d",mon_image.image[i][j].r,mon_image.image[i][j].g,mon_image.image[i][j].b);
		}
	}
}
