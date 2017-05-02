CC=g++
CFLAGS=-I.
DEPS = board.h display.h game.h moves.h play.h tree.h node.h definition.h
OBJ = board.o display.o game.o moves.o main.o play.o tree.o node.o tree.o

%.o: %.cpp $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

Othello_IA : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
