# Simple makefile

OBJECTS = Main.c

HDRS = 

OBJ_NAME = game

CC = gcc

C_FLAGS = `sdl2-config --cflags` -lSDL2_image -lSDL2_ttf -std=c11 -xc -lm -Wall

L_FLAGS = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lm

all : $(OBJECTS) $(HDRS)
	$(CC) $(OBJECTS) $(C_FLAGS) $(L_FLAGS) -o $(OBJ_NAME)

clean :
	rm game
