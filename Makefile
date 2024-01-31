CC=gcc
CFLAGS=-Wall -Wextra
LIBS=-lSDL2-2.0 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

main: clean dir build
	rm -f bin/awalega.out
	$(CC) $(CFLAGS) build/*.o -o bin/awalega.out $(LIBS)

dir:
	mkdir -p build
	mkdir -p bin

build: awale_game.o utilities.o shapes.o colors.o images.o score_handler.o graphic_lib.o gui.o audio_lib.o main.o 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o $(LIBS)

shapes.o: graphic_lib/shapes.c graphic_lib/shapes.h
	$(CC) $(CFLAGS) -c graphic_lib/shapes.c -o build/shapes.o $(LIBS)

colors.o: graphic_lib/colors.c graphic_lib/colors.h
	$(CC) $(CFLAGS) -c graphic_lib/colors.c -o build/colors.o $(LIBS)

images.o: graphic_lib/images.c graphic_lib/images.h graphic_lib/images_config.h
	$(CC) $(CFLAGS) -c graphic_lib/images.c -o build/images.o $(LIBS)

graphic_lib.o: graphic_lib/graphic_lib.c graphic_lib/graphic_lib.h
	$(CC) $(CFLAGS) -c graphic_lib/graphic_lib.c -o build/graphic_lib.o $(LIBS)

gui.o: graphic_lib/gui.c graphic_lib/gui.h
	$(CC) $(CFLAGS) -c graphic_lib/gui.c -o build/gui.o $(LIBS)

score_handler.o: score_handler.c score_handler.h
	$(CC) $(CFLAGS) -c score_handler.c -o build/score_handler.o $(LIBS)

awale_game.o: awale_game.c awale_game.h
	$(CC) $(CFLAGS) -c awale_game.c -o build/awale_game.o $(LIBS)

utilities.o: utilities.c utilities.h
	$(CC) $(CFLAGS) -c utilities.c -o build/utilities.o $(LIBS)

audio_lib.o: audio_lib/audio_lib.c audio_lib/audio_lib.h
	$(CC) $(CFLAGS) -c audio_lib/audio_lib.c -o build/audio_lib.o $(LIBS)

clean:
	rm -rf build
	rm -rf bin