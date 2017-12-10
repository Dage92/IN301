#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE * f = fopen("test.txt","w");
	
	int tab[100];
	for (int i=0 ; i<100 ; i++)
	{
		tab[i] = i;
	}
	
	for (int i = 0; i<100;i++)
	{
		fprintf(f,"%d\n",tab[i]);
	}
	
	fclose(f);
	return 0;
}
