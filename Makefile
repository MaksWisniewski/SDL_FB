OBJECTS = Window.c Main.c

DEPENDENCIES = Window.h Main.h

OBJECT_NAME = gra

CC = gcc

COMPILER_FLAGS = -std=c11 -xc

LINKER_FLAGS = `sdl2-config --cflags --libs`

all : $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJECT_NAME)
