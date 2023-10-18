#ifndef ARRAYLIST_H
#define ARRAYLIST_H
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
* initialises the arraylist with the starting size of size
* the maximum amount of void pointers this can hold will be (10^30) * startingSize
*/
ArrayList *AL_init(int size);

/*
* Set val at pos
*/
void AL_set(ArrayList *al,int pos, void *val);

/*
* get value at pos
*/
void AL_get(ArrayList *al,int pos);
#endif
