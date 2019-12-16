OBJS = TicTacToe.c

CC = gcc

COMPILER_FLAGS = -w -g -pedantic -std=c99 $(shell sdl2-config --cflags)

LINKER_FLAGS = $(shell sdl2-config --libs) -lSDL2_gfx

OBJ_NAME = tictactoe

all: grid.o
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS) grid.o

gridPrototype: grid.o
	$(CC) gridPrototype.c $(COMPILER_FLAGS) -o gridPrototype $(LINKER_FLAGS) grid.o

grid.o:
	$(CC) grid.c -c

clean:
	rm -f tictactoe gridPrototype *.o