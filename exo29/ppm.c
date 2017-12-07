#include <stdio.h>
#include <stdlib.h>

typedef struct pixel{
	int r; 
	int g;
	int b;
} Pixel;

typedef struct img{
	int h;
	int l;
	int coul;
	Pixel ** image;
} Img;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Pas assez d'arguments.\n");
		return 1;
	}

	FILE * F = fopen(argv[1],"r");
	if(F == NULL)
	{
		printf("Erreur lors de l'ouverture de %s\n",argv[1]);
		return 2;
	}

	Img mon_image;
	fscanf(F,"P3");
	fscanf(F,"%d",&mon_image.l);
	fscanf(F,"%d",&mon_image.h);
	fscanf(F,"%d",&mon_image.coul);

	mon_image.image = (Pixel**)malloc(sizeof(Pixel*)*mon_image.h);
	for(int i=0;i<mon_image.h;i++)
	{
		mon_image.image[i] = (Pixel *)malloc(sizeof(Pixel)*mon_image.l);
	}

	for(int i=0;i<mon_image.h;i++)
	{
		for(int j=0;j<mon_image.l;j++)
		{
			fscanf(F,"%d",&mon_image.image[i][j].r);
			fscanf(F,"%d",&mon_image.image[i][j].g);
			fscanf(F,"%d",&mon_image.image[i][j].b);
		}
	}


	FILE * F2 = fopen("cpy.ppm","w");

	fprintf(F2,"P3\n");
	fprintf(F2,"%d %d\n",mon_image.l,mon_image.h);
	fprintf(F2,"%d \n", mon_image.coul);

	for(int i=0;i<mon_image.h;i++)
	{
		for(int j=0;j<mon_image.l;j++)
		{
			fprintf(F2,"%d %d %d ",mon_image.image[i][j].r,mon_image.image[i][j].g,mon_image.image[i][j].b);
		}
	}




	fclose(F);
	fclose(F2);
	return 0;
}