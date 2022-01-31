# Simple makefile

OBJECTS = Main.c

HDRS = 

OBJ_NAME = game

CC = gcc

C_FLAGS = -std=c11 -xc -lm -Wall

L_FLAGS = `sdl2-config --cflags --libs`

all : $(OBJECTS) $(HDRS)
	$(CC) $(OBJECTS) $(C_FLAGS) $(L_FLAGS) -o $(OBJ_NAME)

clean :
	rm game
