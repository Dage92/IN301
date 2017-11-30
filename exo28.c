#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int cmpt;
	cmpt = 0;
	FILE* f = fopen(argv[1], "r");
	if (argc < 2)
	{
		printf("Pas assez d'arguments.\n");
		return 1;
	}
	if (f == NULL)
	{
		printf("Erreur de l'ouverture de %s.\n",argv[1]);
		return 1;
	}
	while (fgetc(f) != EOF)
	{
		cmpt++;
	}
	printf("Il y a %d arguments dans %s \n", cmpt,argv[1]);
	return 0;
	fclose(f);
}
