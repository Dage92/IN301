#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isFloat(char *c)
{
	int i=0;
	while(c[i]!='\0')
	{
		if (isdigit(c[i]) || c[i]=='.' || c[i]=='-')
		{
			printf("%s is a digit.\n", c);
			i++;	
		}
		else
		{
			printf("%s is not a digit.\n", c);
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	int i,check;
	//double sum;							//1_c
	for(i=1;i<argc;i++)						
	{
		check=isFloat(argv[i]);
		//printf("%s\n", argv[i]);			//1_a
		//sum=sum+atof(argv[i]);			//1_c
	}
	//printf("The sum is %f\n", sum);		//1_c
	return 0;
}
