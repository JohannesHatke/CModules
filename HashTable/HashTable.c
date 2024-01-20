#include <stdlib.h>
#include "HashTable.h"


#define HASH_FUNC_EXAMPLE &example_hash
#define HASH_FUNC_EXAMPLE_SIZE 1000

int example_hash(void *val){
	return *( (int*) val) % HASH_FUNC_EXAMPLE_SIZE;
}



HashTable *HashTable_init(int size, int (*hash_func) (void *)){
	HashTable  *output;
	if((output = malloc(sizeof(HashTable))) != NULL){
		output->size = size;
		output->func = hash_func;
		output->entries = calloc(size,sizeof(Hash_node*));
	}
	return output;
}



void HashTable_free(HashTable  *table){
	int count = 0;
	Hash_node *p;
	Hash_node *curr,*old;
	for(int i = 0; i< table->size; i++){
		p = table->entries[i];
		if (p != NULL ){
			curr = p->next;
			free(p);
			while(curr){
				old = curr;
				curr = curr->next;
				free(old);
				count++;
			}
		}
		
	}

	free(table->entries);
	free(table);
}

int Hash_foreach(HashTable *table, int (*func) (void*)){
	int count = 0;
	Hash_node *p;
	Hash_node *curr;
	for(int i = 0; i< table->size; i++){
		p = table->entries[i];
		if (p != NULL && p->val != NULL){
			count++;
			func(p->val);
			curr = p->next;
			while(curr){
				count++;
				func(curr->val);
				curr = curr->next;
			}
		}
		
	}

	return count;
}

int Hash_install(HashTable *table, void *value){
	int pos;
	Hash_node *new;
	if (value ==NULL)
		return 1;

	pos = (*(table->func)) (value); //make sure function returns in [0, size]
	if (pos < 0 || pos > table->size)
		return 2;

	new = malloc(sizeof(Hash_node));
	new->val = value;

	new->next = table->entries[pos];
	table->entries[pos] = new;
	return 0;
}


/*
* removes the first (!) occurence of the value to be found
* table: 
* value: the value to be found
* comp: function that should return 1 if values are the same, and 0 if not
* returns pointer to the value if it was found
* returns Null if value was not found or error occurs
*/
void *Hash_remove(HashTable *table,void *value, int (*comp)(void*, void*)){
	int pos;
	Hash_node *curr,*found;
	void *output = NULL;
	if (value ==NULL)
		return NULL;
	pos = (*(table->func)) (value); //make sure function returns in [0, size]
	if (pos < 0 || pos > table->size)
		return NULL;

	curr = table->entries[pos];
	if((*comp)(value, curr->val)){ // first entry at pos
		found = curr;
		output = found->val;
		table->entries[pos] = found->next;

		free(found);
		return output;
	} else {
		for (; curr->next != NULL; 
		curr = curr->next){
			if( (*comp)(value, (curr->next)->val)){
				found = curr->next;
				curr->next = found->next;
				output = found->val;
				free(found);
				return output;
			};
		}
	}
	return output;
	


}


int Hash_comp_int(void *a, void *b){
	if ( *((int*) a) == *((int*) b))
		return 1;
	return 0;

}
