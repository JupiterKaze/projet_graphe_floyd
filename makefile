CC=gcc
CLIBS=-lm
CFLAGS=-Wall -Werror -Wfatal-errors -g
SRC=graphe.c main.c 
all: 
	$(CC) $(CFLAGS) $(SRC) $(CLIBS) -o exec

clean: 
	rm exec