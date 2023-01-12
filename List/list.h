#ifndef LIST_H
#define LIST_H

//typedef struct singleNode;
typedef struct{
    void *head; 
}List;

typedef struct{
    int val;
    void *next;
}Node;

int appendNode(Node *curr,int val); //append a new Node with val=val to Node curr

// int append(List *curr,int val); //append a new Node to the end of list ls with val=val
                                  
int insert(List *curr,int pos,int val); //insert a new Node in ls at position pos
                                //insert(ls, lenght(ls), val) will append to end

int length(List *ls);// Number of elements in list
                       
int pop(List *ls, int pos);// removes item at index pos
                      
List *initList(int val);

Node *initNode(int val);

#endif
