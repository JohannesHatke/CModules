#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>


int print_entry(void *entry){
	printf("entry:\t%d\n",*( (int*) entry));
	return 0;
}

int free_int_entry(void *entry){
	free( (int*) entry);
	return 0;
}



int main(int argc, char *argv[])
{
	HashTable *test = HashTable_init(HASH_FUNC_EXAMPLE_SIZE, HASH_FUNC_EXAMPLE);
	const int numtest[] = {0,4,10,1004,2004,1 };
	printf("[");
	for(int i = 0; i < (sizeof(numtest) / sizeof(int)); i++){
		printf("%d,",numtest[i]);
		void *a = malloc(sizeof(int));
		*((int* )a) = numtest[i];
		Hash_install(test,a);
	}
	printf("]\n");
	/*
	
	for(int i = 0; i < (sizeof(numtest) / sizeof(int)); i++){
		void *a = &(numtest[i]);
		int *b = (int*) Hash_remove(test,a,Hash_comp_int);
		printf("%d\n",*b);
		free(b);
	}
	*/


	Hash_foreach(test, &print_entry);
	Hash_foreach(test, &free_int_entry);
	HashTable_free(test);

	return 0;
}
