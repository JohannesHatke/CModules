CFLAGS= -Wall -Wextra -pedantic -std=c99 -O0 -g

main: HashTable ArrayList SingleLinkedList

clean: 
	rm -r ./build
build: 
	mkdir ./build

#Hashtable
HashTable: HashTable.o ./HashTable/Test_HashTable.c 
	$(CC) ./HashTable/Test_HashTable.c ./build/HashTable.o -o ./build/Test_HashTable $(CFLAGS) 

HashTable.o: build ./HashTable/HashTable.c
	$(CC) ./HashTable/HashTable.c -c -o ./build/HashTable.o $(CFLAGS) 
clean_HashTable: 
	rm ./build/Test_HashTable
	rm ./build/HashTable.o


#ArrayList
ArrayList: ArrayList.o ./ArrayList/Test_ArrayList.c
	$(CC) ./ArrayList/Test_ArrayList.c ./build/ArrayList.o -o ./build/Test_ArrayList $(CFLAGS) 
ArrayList.o: build ./ArrayList/ArrayList.c
	$(CC) ./ArrayList/ArrayList.c -c -o ./build/ArrayList.o $(CFLAGS) 

clean_ArrayList: 
	rm ./build/Test_ArrayList
	rm ./build/ArrayList.o


#SingleLinkedList
SingleLinkedList: SingleLinkedList.o ./SingleLinkedList/Test_SingleLinkedList.c
	$(CC) ./SingleLinkedList/Test_SingleLinkedList.c ./build/SingleLinkedList.o -o ./build/Test_SingleLinkedList $(CFLAGS) 

SingleLinkedList.o: build ./SingleLinkedList/list.c
	$(CC) ./SingleLinkedList/list.c -c -o ./build/SingleLinkedList.o $(CFLAGS)

clean_SingleLinkedList: 
	rm ./build/SingleLinkedList.o
	rm ./build/Test_SingleLinkedList

