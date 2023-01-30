#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Example{
    int a;
    int b;
    char *fp;
}Example;
int printExample(struct Example *toPrint, char *output,int maxlen){
    char *buf = malloc(200*sizeof(char));
    int a =toPrint->a;
    int b =toPrint->b;
    char *fp = toPrint->fp;
    snprintf(buf,199, "Example-Struct with the following values:\n\ta:\t%d\n\tb:\t%d\n\ts:\t%s\n",a,b,fp);
    if ((int)(strlen(buf)) > maxlen) return 1;
    strncpy(output,buf,maxlen);
    return 0;
}
struct Example *initExample(int a,int b,char *f){
    struct Example *output = malloc(sizeof(Example));
    output->a = a;
    output->b = b;
    int len = strlen(f);
    output->fp = malloc(len*sizeof(char));
    strncpy(output->fp,f,len);
    return output;
}
int freeExample(struct Example *toDelete){
    free(toDelete->fp);
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
    do{
        char *str = malloc(sizeof(char)*150);
        printExample((c->val),str, 150);
        printf(str);
        free(str);
    }while(c->next);
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
    char *str2 = malloc(100*sizeof(char));
    printExample(x,str2,100);
    printf(str2);


    List *ls = initList(x);
    printExampleList(ls);


    freeExample(x);
    freeExample(a);
    free(str2);
    free(str);



    return 0;
}
