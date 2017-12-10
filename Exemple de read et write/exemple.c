#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * f = fopen("fichiertxt.txt","r");
	
	char c;
	
	while((c = fgetc(f)) != EOF)
	{
		printf("%c", c);
	}
	printf("\n");
	
	fclose(f);
	return 0;
}
