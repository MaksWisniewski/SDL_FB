OBJECTS = Game_window.c Main.c

OBJECT_NAME = FlappyBird

CC = gcc

COMPILER_FLAGS = -std=c11 -xc

LINKER_FLAGS = `sdl2-config --cflags --libs`

all : $(OBJECTS)
	$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJECT_NAME)