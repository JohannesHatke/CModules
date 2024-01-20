CARGS= -Wall -Wextra -pedantic -std=c99 -O0 -g

main: HashTable

HashTable: build HashTable.o ./HashTable/Test_HashTable.c 
	$(CC) ./HashTable/Test_HashTable.c ./build/HashTable.o -o ./build/Test_HashTable $(CARGS) 

HashTable.o:./HashTable/HashTable.c
	$(CC) ./HashTable/HashTable.c -c -o ./build/HashTable.o $(CARGS) 
clean_HashTable: 
	rm ./build/Test_HashTable
	rm ./build/HashTable.o

clean: 
	rm -r ./build
build: 
	mkdir ./build
