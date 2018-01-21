#include "stdio.h"
#include "stdlib.h"

struct que_des_t{
	int t;
	int *T;
};

void f (int t, int T[3], struct que_des_t S){
	t = 1;
	T[0] = 1;
	S.t = 1;
	S.T[0] = 1;
}

int main(){
	int t;
	int T[3];
	struct que_des_t S;
	S.T = malloc(3*sizeof(int));
	if (!S.T)
	{
		exit (1);
	}
	t = 0;
	T[0] = 0;
	S.t = 0;
	S.T[0] = 0;
	f(t, T, S);
	printf("%d %d %d %d\n", t, T[0], S.t, S.T[0]);
	return 0;
}
