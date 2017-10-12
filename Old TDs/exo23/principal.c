#include <stdio.h>
#include "PI.h"
#include <stdlib.h>

int main (int argc, char **argv)
{
	int r;
	double s,c;
	printf("Radius of the circle: ");
	scanf("%d", &r);
	c=circonference(r);
	s=surface(r);
	printf("Circumference = %f || Surface = %f",c,s);
	return 0;
}
	
