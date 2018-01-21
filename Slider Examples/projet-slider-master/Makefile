NOM=PROJET_IN301

test: slider
	./slider niveau_01.slider

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o initialisation.o
	gcc slider.o lire_ecrire.o afficher.o initialisation.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h  afficher.h initialisation.h
	gcc -c -Wall slider.c

# Compilation
lire_ecrire.o: lire_ecrire.c mes_types.h
	gcc -c -Wall lire_ecrire.c

# Compilation
afficher.o: afficher.c mes_types.h
#	gcc -c -Wall   -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT  afficher.c
	gcc -c -Wall  `sdl-config --cflags`   afficher.c
	
# Compilation
initialisation.o: initialisation.c mes_types.h
	gcc -c -Wall initialisation.c

go:
	geany Makefile mes_types.h slider.c afficher.c afficher.h lire_ecrire.c lire_ecrire.h niveau01.slider initialisation.c initialisation.h&

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
	rm -f *.o
	rm -f slider
