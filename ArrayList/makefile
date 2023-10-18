main: ArrayList.o main.o
	$(CC) main.o ArrayList.o -o main -Wall -Wextra -pedantic -std=c99
ArrayList.o: ArrayList.c
	$(CC) -c ArrayList.c -o ArrayList.o -Wall -Wextra -pedantic -std=c99
main.o: main.c
	$(CC) -c main.c -o main.o -Wall -Wextra -pedantic -std=c99
clean:
	rm ArrayList.o
	rm main.o
	rm main
