#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *initNode(int val){
    Node *curr = malloc(sizeof(Node));
    if(!curr) return NULL;
    curr->next = NULL;
    curr->val = val;
    return curr;
}

int appendNode(Node *curr,int val){
    void *p = curr->next;
    Node *new = malloc(sizeof(Node));
    new->next = p;
    new->val = val;
    curr->next = new;
    return 0;
}

int removeNode(Node *curr){
    if (!curr->next) return 1;

    Node *p = curr->next;
    curr->next = p->next;
    free(p);
    return 0;

}

List *initList(int val){ 
    List *ls = malloc(sizeof(List));
    if(!ls) return NULL;
    Node *new = initNode(val);
    if (!new) return NULL;
    ls->head = new;
    return ls;
}
int append(List *ls, int val){
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
int insert(List *ls,int pos,int val){
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
int pop(List *ls,int pos){
    if(pos==0){
        if(!ls->head) return 1;
        Node *p = ls->head;
        ls->head = p->next;
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
    free(curr->next);
    return 0;
}
int freeList(List *ls){
    if(!ls->head){
        return 0;
    }

    freeNodes(ls->head);
    free(ls->head);
    return 0;
}
