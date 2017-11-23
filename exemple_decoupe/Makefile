all : run

plam.o : plam.c
	gcc -g -c plam.c -o plam.o
	
plim.o : plim.c
	gcc -g -c plim.c -o plim.o

ploum.o : ploum.c plam.h plim.h
	gcc -g -c ploum.c -o ploum.o

exe : plam.o plim.o ploum.o
	gcc -g plam.o plim.o ploum.o -o exe

run : exe
	./exe
	
clean:
	rm -f plam.o plim.o ploum.o exe
