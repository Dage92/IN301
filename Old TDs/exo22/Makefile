all: ploum.o plim.o plam.o
	gcc plam.o plim.o ploum.o -o exe

plim.o: plim.c
	gcc -c plim.c -o plim.o
	
plam.o: plam.c
	gcc -c plam.c -o plam.o
	
ploum.o: plam.h plim.h ploum.c
	gcc -c ploum.c -o ploum.o
