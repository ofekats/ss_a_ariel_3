CC = gcc
FLAG = -Wall -g

all: isort txtfind

isort.c:
	$(CC) $(FLAG) -o isort isort.c

txtfind.c: 
	$(CC) $(FLAG) -o txtfind txtfind.c

.PHONY: all clean


clean: 
	rm -f *.o isort txtfind



