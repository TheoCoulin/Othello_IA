# Othello AI makefile
# Elise Pottier, Théo Coulin, 2017.
# Gros overkill comme makefile.
# Les sources sont retrouvées dynamiquement, pas besoin de modifier le makefile à chaque ajout de fichier

CC := g++ 

SRCDIR := src
BULDDIR := build
INCDIR := include
TARGET := bin/Othello_IA

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BULDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g
INC := -I include

%.o: $(SRCDIR)/%.$(SRCEXT) $(INCDIR)/%.h
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
