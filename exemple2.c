#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE * f = fopen("testecriture.txt","w");
	
	char * str = "jecris dans mon fichier";
	int i = 0;
	
	while(str[i] !='\0')
	{
		fputc(str[i],f);
		i++;
	}
	fclose(f);
	return 0;
}
