all : run

circonference.o : circonference.c pi.h
	gcc -c circonference.c -o circonference.o
	
principal.o : principal.c circonference.h surface.h
	gcc -g -c principal.c -o principal.o
	
surface.o : surface.c pi.h
	gcc -g -c surface.c -o surface.o
	
exe : circonference.o principal.o surface.o
	gcc -g circonference.o principal.o surface.o -o exe
	
run : exe
	./exe
	
clean 
	rm -f circonference.o principal.o surface.o exe
