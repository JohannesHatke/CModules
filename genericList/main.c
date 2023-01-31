#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//TODO: fix methods that remove stuff from list

struct Example{
    int a;
    int b;
    char *fp;
}Example;

//function to be used in for each tests
int func(void *vPointer){
    //struct Example workingPointer = (struct Example *) vPointer;
    struct Example *workingPointer = (struct Example *) vPointer;
    workingPointer->a++;
    return 0;
}



int printExample(struct Example *toPrint, char *output,int maxlen){
    char *buf = malloc(200*sizeof(char));
    buf[0] = '\0';
    output[0] = '\0';
    int a =toPrint->a;
    int b =toPrint->b;
    char *fp = toPrint->fp;
    snprintf(buf,199, "Example-Struct with the following values:\n\ta:\t%d\n\tb:\t%d\n\ts:\t%s\n",a,b,fp);
    if ((int)(strlen(buf)) > maxlen) return 1;
    strcpy(output,buf);//,maxlen);
    free(buf);
    return 0;
}
struct Example *initExample(int a,int b,char *f){
    struct Example *output = malloc(sizeof(Example));
    output->a = a;
    output->b = b;
    int len = strlen(f);
    output->fp = malloc((len+1)*sizeof(char));
    strcpy(output->fp,f);//,len);
    return output;
}
int freeExample(void *toDelete){
    struct Example *working = (struct Example*)(toDelete);
    free(working->fp);
    return 0;
}

/*    

int printList(List *ls){
    if(!ls->head){
        printf("[]\n");
        return 0;
    }
    Node *c = ls->head;
    printf("[");
    while(c->next){
        printval(c->val);
        printf(",");
        c = c->next;
    }
    printval(c->val);
    printf("]\n");
    return 0;
}
*/
int printExampleList(List *ls){
    if (!ls->head){
        printf("[]\n");
        return 0;
    }
    Node *c = ls->head;
    printf("List:\n[\n");
    int i = 0;
    while(c){
        char *str = malloc(sizeof(char)*150);
        printExample((c->val),str, 150);
        printf("%d\n",i);
        i++;
        printf(str);
        free(str);
        c = c->next;
    };
    printf("]\nEnde der Liste\n");
    return 0;
}


int main(void){
    struct Example *a = malloc(sizeof(struct Example));
    a->a = 0;
    a->b = 1;
    a->fp = malloc(12*sizeof(char));
    a->fp[0] = 'o';
    a->fp[1] = 'k';
    a->fp[2] = '\0';
    char *str = malloc(100*sizeof(char));
    printExample(a,str,100);
    printf(str);

    
    struct Example *x = initExample(10,211,"aaaaaaaa");
    char *str2 = malloc(200*sizeof(char));
    str2[0] = 'a';
    str2[0] = '\0';
    printExample(x,str2,200);
    printf(str2);


    List *ls = initList(x,NULL);
    //printExampleList(ls);

    //append(ls,a);

    printExampleList(ls);

    //printf("\nNew Tests (foreach):\n\n");
    foreach(ls,func);
    //printExampleList(ls);
    //free(x->fp);

    
    freeList(ls);
    free(ls);

    freeExample(x);
    freeExample(a);
    free(str2);
    free(str);

    free(a);
    free(x);
    return 0;
}
