# Nom : Delaunay
# Prenom : Damien
# NO_etudiant : 21602928

#option pour dire prends ce fichier en compte(ignorer les erreurs)
#valgrind --suppressions=nomFichier.supp

#valgrind : compil
	#valgrind --suppressions=SDL.supp ./$(EXEC) $(ARGS)

CFLAGS = -c -g -Wall -g

all: sokoban
	./sokoban

compil: sokoban
	make sokoban

test: sokoban
	make clean
	make compil
	./sokoban -n 8 sasquatch1.xsb

sokoban: main.o sokoban.o lire_ecrire.o affichage.o action.o historique.o
	gcc -o sokoban sokoban.o lire_ecrire.o main.o affichage.o action.o historique.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

main.o: main.c lire_ecrire.h affichage.h constantes.h action.h historique.h
	gcc $(CFLAGS) `sdl-config --cflags` main.c

sokoban.o: sokoban.c sokoban.h
	gcc $(CFLAGS) `sdl-config --cflags` sokoban.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h sokoban.h affichage.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` lire_ecrire.c

affichage.o: affichage.c affichage.h constantes.h sokoban.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c

action.o: action.c action.h historique.h constantes.h lire_ecrire.h
	gcc $(CFLAGS) `sdl-config --cflags` action.c

historique.o: historique.c historique.h sokoban.h
	gcc $(CFLAGS) `sdl-config --cflags` historique.c

valgrind: sokoban
	valgrind --suppressions=SDL.supp ./sokoban

clean:
	rm -f *.o
	rm -f sokoban
