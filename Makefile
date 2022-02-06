#	all : $(OBJECTS) $(HDRS)
#		$(CC) $(OBJECTS) $(C_FLAGS) $(L_FLAGS) -o $(OBJ_NAME)

CC = gcc

C_FLAGS = `sdl2-config --cflags` -std=c11 -xc -Wall

L_FLAGS = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lm

bird.o : bird.c bird.h
	$(CC) bird.c $(C_FLAGS) $(L_FLAGS) -c -o bird.o

pipe.o : pipe.c pipe.h
	$(CC) pipe.c $(C_FLAGS) $(L_FLAGS) -c -o pipe.o

engine.o : engine.c engine.h bird.c bird.h pipe.c pipe.h
	$(CC) engine.c $(C_FLAGS) $(L_FLAGS) -c -o engine.o

main.o : main.c
	$(CC) main.c $(C_FLAGS) $(L_FLAGS) -c -o main.o

all : bird.o engine.o pipe.o main.o
	$(CC) bird.o engine.o pipe.o main.o $(C_FLAGS) $(L_FLAGS) -o game

clean :
	rm *.o game
