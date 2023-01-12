#include <stdio.h>
#include "list.h"
int printList(List *ls){
    Node *c = ls->head;
    printf("[");
    while(c->next){
        printf("%d,",c->val);
        c = c->next;
    }
    printf("%d]\n",c->val);
    return 0;
}



int main(void){
    printf("Running tests...\n");
    List *ls = initList(0);
    insert(ls,0,-1);
    printList(ls);
    return 0;
}
