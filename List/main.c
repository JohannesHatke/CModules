#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int printList(List *ls){
    if(!ls->head){
        printf("[]\n");
        return 0;
    }
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
    append(ls,1);
    append(ls,2);
    printList(ls);
    freeList(ls);
    free(ls);

    printf("Running pop testing...\n");
    List *b = initList(0);
    insert(b,0,-1);
    insert(b,0,-2);
    append(b,1);
    printList(b);
    printf("pop(0):\n");
    pop(b,0);
    printList(b);
    printf("pop(2):\n");
    pop(b,2);
    printList(b);
    printf("pop(0):\n");
    pop(b,0);
    printList(b);
    printf("pop(0):\n");
    pop(b,0);
    printList(b);
    freeList(b);
    free(b);
    return 0;
}
