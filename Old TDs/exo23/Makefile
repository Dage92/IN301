all: circonference.o surface.o principal.o
	gcc circonference.o surface.o principal.o -o exe

circonference.o: circonference.c PI.h
	gcc -c circonference.c -o circonference.o
	
surface.o: surface.c PI.h
	gcc -c surface.c -o surface.o
	
principal.o: principal.c PI.h
	gcc -c principal.c -o principal.o

clean:
	rm -f *.o
	rm -f exe
