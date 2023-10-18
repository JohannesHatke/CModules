#include <stdio.h>
#include <stdlib.h>


/*
 maximum Size (10^30) * startingSize
 */
typedef struct ArrayList{
	int len;
	int startSize;
	void ***entries;  /*
	2d array of void pointers
	has size [100][n_i] where n_i depends on the first index
	according to the following formula
		n_i = 2^i * startSize
	
	so 
	  [0][1 * startsize]
	  [1][2 * startsize]
	and so on	
	*/

}ArrayList;

/*
#define AL_get(AL,i) AL->entries[i ];
#define AL_set(AL,i,val) \
	free(AL->entries[i]); \
	AL->entries[i] = val;
*/


int ownPow(int base, int power){ // avoiding math.h
	if (power < 0)
		return 0;

	int output = 1;
	while (power--)
		output *= base;
	return output;

}
ArrayList *AL_init(int size){
	ArrayList *output = malloc(sizeof(ArrayList));
	output->len = size;
	output->startSize = size;
	output->entries = (void*) calloc(100 , sizeof(void*));
	output->entries[0] = (void*) calloc(size , sizeof(void*));
	return output;
}

void getIndex(ArrayList *al,int pos, int *index1, int *index2){
	for (*index1 = 0; *index1< 100; (*index1)++){
		if ( pos < al->startSize * ownPow(2, *index1))
			break;
	}
	*index2 = pos - al->startSize * ownPow(2, *index1-1);
}

void AL_set(ArrayList *al,int pos, void *val){
	int index1,index2;
	getIndex(al, pos, &index1, &index2);

	if (al->entries[index1] == NULL)
		al->entries[index1] = (void*) calloc(ownPow(2, index1), sizeof(void*)* al->startSize );

	al->entries[index1][index2] = val;
}
void *AL_get(ArrayList *al,int pos){
	int index1,index2;

	getIndex(al, pos, &index1, &index2);
	if (al->entries[index1] == NULL)
		return NULL;

	return al->entries[index1][index2];
}
