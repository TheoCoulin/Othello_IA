CC=g++
CFLAGS=-I.
DEPS = board.h display.h game.h play.h
OBJ = board.o display.o game.o play.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

Othello_IA : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
