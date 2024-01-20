CARGS= -Wall -Wextra -pedantic -std=c99 -O0 -g
main: HashTable.o main.c
	$(CC) main.c HashTable.o -o main $(CARGS) 
HashTable.o:HashTable.c
	$(CC) HashTable.c -c -o HashTable.o $(CARGS) 
