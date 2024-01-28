CC=gcc
CFLAGS=-Wall



all: clean game awaleGame 

# Compilation de l'exécutable
awaleGame: build sourceFiles
	$(CC) $(CFLAGS) build/*.o -o game/$@

sourceFiles: utilities.o  score_handler.o  ascii_art.o  awale_game.o  main.o



# Création des dossiers nécessaires
build:
	mkdir -p build
	
game:
	mkdir -p game



# Compilation des fichiers source .c
main.o: main.c
	$(CC) $(CFLAGS) -c $< -o build/$@


utilities.o: utilities.c utilities.h
	$(CC) $(CFLAGS) -c $< -o build/$@


score_handler.o: score_handler.c score_handler.h awale_game_macros_structs.h
	$(CC) $(CFLAGS) -c $< -o build/$@


ascii_art.o: ascii_art.c ascii_art.h score_handler.h awale_game_macros_structs.h
	$(CC) $(CFLAGS) -c $< -o build/$@


awale_game.o: awale_game.c awale_game.h awale_game_macros_structs.h
	$(CC) $(CFLAGS) -c $< -o build/$@



# Nettoyage
clean:
	rm -rf build
	rm -rf game
