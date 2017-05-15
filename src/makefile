CC=g++
CFLAGS=-I.
DEPS = board.h display.h game.h moves.h play.h definition.h
OBJ = board.o display.o game.o moves.o main.o play.o

%.o: %.cpp $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

Othello_IA : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
