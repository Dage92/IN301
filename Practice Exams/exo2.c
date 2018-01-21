#include <stdio.h>
#include <stdlib.h>

typedef struct ages{
	int N;
	int *A;
} ages;

ages lecture(FILE *F)
{
	int N;
	int A[N];
	
	if (F == NULL)
	{
		printf("Error\n");
	}
	else
	{
		fscanf(F,"%d", &N);
		printf("\nNombres d'âges stockés:\n%d\n", N);
		printf("Ages stockés:\n");
		while (!feof(F))
		{
			fscanf(F, "%d", A);
			printf("%d\n", *A);
		}
	}
}

/*int moyenne(FILE *F)
{
	int N;
	int A[N];
	int avg;
	fscanf(F,"%d", &N);
	printf("\nNombres d'âges stockés:\n%d\n", N);
	while (!feof(F))
	{
		fscanf(F, "%d", A);
		//avg = avg + A;
	}
	//printf("%d\n",avg);
	//avg = avg/N;
	//return avg;
}*/

int main(int argc, char **argv)
{
	FILE *F;
	F = fopen(argv[1], "r");
	lecture(F);
	//printf("\nLa moyennes des âges est de:  %d\n", moyenne(F));
	fclose(F);
	return 0;
}
