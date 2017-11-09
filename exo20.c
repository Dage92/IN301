#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

/*int estFloat(char * mot)
{
	int taille = strlen(mot);
	int nb_dot = 0;
	if (!(mot[0] == '-') && !(isdigit(mot[0])))
	{
		return 0;
	}
	else
	{
		for (int i=1 ; i<taille ; i++)
		{
			if (isdigit(mot[i]) == 0)
			{
				if (mot[i] == '.')
				{
					if (nb_dot == 0)
					{
						nb_dot++;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}*/

int estFloat(char *c)
{
	int i = 1;
	int nb_dot = 0;
	if ( c[0] != '-' && !(isdigit(c[0])))
	{
		return 0;
	}
	while(c[i] != '\0')
	{
		if (!(isdigit(c[i])))
		{
			if (c[i] == '.')
			{
				if (nb_dot == 0)
				{
					nb_dot++;
				}
				else
				{
					return 0;
				}
			}
		}
		else if (isdigit(c[i]))
		{
			i++;	
		}
	}
	return 1;
}

int main (int argc , char* argv[])
{
	printf("Il y a %d arguments.\n\n", argc);
	int i;
	double s;
	for (i=1 ; i<argc ; i++)
	{
		printf("%s   ", argv[i]);
		if (estFloat(argv[i]))
		{
			s = s + atof(argv[i]);
		}
		else
		{
			printf ("\n\n%s n'est pas un argument valid.\n" , argv[i]);
			return 0;
		}
	}
	printf("\n\nLa somme des charactere est %f.\n", s);
	return 0;
}
