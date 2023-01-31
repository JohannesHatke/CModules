#include "list.h"
#include <stdio.h>
#include <stdlib.h>


//TODO: fix pop
//fix removeNode
//

Node *initNode(void *val){
    Node *curr = malloc(sizeof(Node));
    if(!curr) return NULL;
    curr->next = NULL;
    curr->val = val;
    return curr;
}

int appendNode(Node *curr,void *val){
    void *p = curr->next;
    Node *new = malloc(sizeof(Node));
    new->next = p;
    new->val = val;
    curr->next = new;
    return 0;
}

int removeNode(Node *curr){//TODO: use free function
    if (!curr->next) return 1;

    Node *p = curr->next;
    curr->next = p->next;
    free(p);
    return 0;

}

List *initList(void *val,int (*freePtr)(void*)){ 
    List *ls = malloc(sizeof(List));
    if(!ls) return NULL;
    Node *new = initNode(val);
    if (!new) return NULL;
    ls->head = new;
    ls->freePointer = freePtr;
    return ls;
}
int append(List *ls,void *val){
    if(!ls->head){
        insert(ls,0,val);
        return 0;
    }

    Node *new = initNode(val);
    Node *curr =ls->head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = new;
    return 0;
}
int insert(List *ls,int pos,void *val){
    if (pos==0){
        Node *new = initNode(val);
        if(!new) return 1;

        new->next = ls->head;
        ls->head = new;
        return 0;
    }

    Node *curr = ls->head;
    int i = 0;
    while(curr && i < pos-1){
        i++;
        curr = curr->next;
    }
    if(i != pos-1) return 1;

    appendNode(curr,val);
    return 0;
}
int pop(List *ls,int pos){ //TODO: at least need to test
    if(pos==0){
        if(!ls->head) return 1;
        Node *p = ls->head;
        ls->head = p->next;
        if (ls->freePointer != NULL) (*(ls->freePointer))(p);
        free(p);
        return 0;
    }

    int i = 0;
    Node *curr = ls->head;
    while (curr && i<pos-1){
        i++;
        curr = curr->next;
    }
    if (!curr || !curr->next) return 1;
    removeNode(curr);
    return 0;
}
int length(List *ls){
    Node *curr =ls->head;
    int i = 0;
    while(curr){
        i++;
        curr = curr->next;
    }
    return i;
}
int freeNodes(Node *curr){
    if(!curr->next){
        return 0;
    }
    freeNodes(curr->next);
    free((curr->next)->val);
    free(curr->next);
    return 0;
}
int freeList(List *ls){
    if(!ls->head){
        return 0;
    }
    if (ls->freePointer != NULL) foreach(ls,ls->freePointer);
    freeNodes(ls->head);
    free((ls->head)->val);
    free(ls->head);
    return 0;
}
int foreach(List *ls,int (*funcPtr)(void*)){
    Node *curr = ls->head;
    int i = 0;
    while(curr){
        i++;
        if (((*funcPtr)(curr->val))!=0){
            printf("ERROR at index %d\n",i);
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}
