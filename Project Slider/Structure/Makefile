NOM=PROJET_IN301

test: slider
	./slider niveau_01.slider

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o
	gcc slider.o lire_ecrire.o afficher.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h
	gcc -c -Wall slider.c

# Compilation
lire_ecrire.o: lire_ecrire.c
	gcc -c -Wall lire_ecrire.c

# Compilation
afficher.o: afficher.c
#	gcc -c -Wall   -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT  afficher.c
	gcc -c -Wall  `sdl-config --cflags`   afficher.c

editeur:
	geany Makefile mes_types.h slider.c afficher.c afficher.h &

# Pour creer le zip a deposer sur e-campus
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
#	cp -f *.slider $(NOM)
	zip $(NOM).zip $(NOM)/*
#	rm -fr $(NOM)



clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f lire_ecrire.o
	rm -f afficher.o
	rm -f slider.o
	rm -f slider
