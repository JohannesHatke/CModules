#ifndef LIST_H
#define LIST_H

//typedef struct singleNode;

typedef struct Node{
    void *val;
    struct Node *next;
}Node;

typedef struct{
    Node *head; 
}List;


int appendNode(Node *curr,void *val); //append a new Node with val=val to Node curr

                                  
int insert(List *curr,int pos,void *val); //insert a new Node in ls at position pos
                                //insert(ls, lenght(ls), val) will append to end
                                //if pos is out of range function will fail, returning 1

int append(List *ls,void *val); //append val to end of List

                                          
int length(List *ls);// Number of elements in list
                       
int pop(List *ls, int pos);// removes item at index pos

int freeList(List *ls); //free complete List
                        //still need to call free(ls) afterwards

List *initList(void *val);

Node *initNode(void *val);

#endif
