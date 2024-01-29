CC=gcc
CFLAGS=-Wall -Wextra
LIBS=-lSDL2-2.0 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

main: clean dir build
	rm -f bin/awalega.out
	$(CC) $(CFLAGS) build/*.o -o bin/awalega.out $(LIBS)

dir:
	mkdir -p build
	mkdir -p bin

build: main.o graphic_lib.o shapes.o colors.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o $(LIBS)

shapes.o: graphic_lib/shapes.c graphic_lib/shapes.h
	$(CC) $(CFLAGS) -c graphic_lib/shapes.c -o build/shapes.o $(LIBS)

colors.o: graphic_lib/colors.c graphic_lib/colors.h
	$(CC) $(CFLAGS) -c graphic_lib/colors.c -o build/colors.o $(LIBS)

graphic_lib.o: graphic_lib/graphic_lib.c graphic_lib/graphic_lib.h
	$(CC) $(CFLAGS) -c graphic_lib/graphic_lib.c -o build/graphic_lib.o $(LIBS)

clean:
	rm -rf build