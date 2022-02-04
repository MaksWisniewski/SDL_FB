# Simple makefile

OBJECTS = stary_main.c bird.c

HDRS = bird.h

OBJ_NAME = game

CC = gcc

C_FLAGS = `sdl2-config --cflags` -std=c11 -xc -Wall

L_FLAGS = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lm

bird.o : bird.c bird.h
	$(CC) bird.c $(C_FLAGS) $(L_FLAGS) -c -o bird.o

stary_main.o : stary_main.c bird.h
	$(CC) stary_main.c $(C_FLAGS) $(L_FLAGS) -c -o stary_main.o

game : stary_main.o bird.o
	$(CC) stary_main.o bird.o $(L_FLAGS) -o game

all : $(OBJECTS) $(HDRS)
	$(CC) $(OBJECTS) $(C_FLAGS) $(L_FLAGS) -o $(OBJ_NAME)

clean :
	rm game *.o
