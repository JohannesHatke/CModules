#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASH_FUNC_EXAMPLE &example_hash
#define HASH_FUNC_EXAMPLE_SIZE 1000

int example_hash(void *val);


typedef struct Hash_node{
	void *val;
	struct Hash_node *next;
} Hash_node;

typedef struct HashTable{
	int size;
	int (*func)(void *);
	Hash_node **entries; //save memory for empty slots by using two pointers
} HashTable;

HashTable *HashTable_init(int size, int (*hash_func) (void *));

int Hash_foreach(HashTable *table, int (*func) (void*));
int Hash_install(HashTable *table, void *value);

/*
* removes the first (!) occurence of the value to be found
* table: 
* value: the value to be found
* comp: function that should return 1 if values are the same, and 0 if not
* returns pointer to the value if it was found
* returns Null if value was not found or error occurs
*/
void *Hash_remove(HashTable *table,void *value, int (*comp)(void*, void*));


int Hash_comp_int(void *a, void *b);

/*
* does not free the values of the HashTable
*
*/
void HashTable_free(HashTable  *table);

#endif
