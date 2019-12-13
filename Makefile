OBJS = TicTacToe.c

CC = gcc

COMPILER_FLAGS = -w -g -pedantic -std=c99 $(shell sdl2-config --cflags)

LINKER_FLAGS = $(shell sdl2-config --libs)

OBJ_NAME = tictactoe

all: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)

gridPrototype: gridPrototype.c Grid.o
	$(CC) gridPrototype.c $(COMPILER_FLAGS) -o gridPrototype $(LINKER_FLAGS) grid.o

Grid.o:
	$(CC) grid.c -c

clean:
	rm -f tictactoe gridPrototype *.o