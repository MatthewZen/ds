#include<stdio.h>
#include<malloc.h>
#define EMPTY 0
#define NotEMPTY 1

typedef struct LStack{
    int data;
    struct LStack *next;
}LStack;

LStack *Push(LStack *Lst, int x);
int Pop(LStack *Lst);

int main(){
    LStack *Lst;
    for(int i = 0;i < 5;++i)
        Lst = Push(Lst,i);
    printf("%d",Pop(Lst));
    return 0;
}

LStack *Push(LStack *Lst, int x){
    LStack *p;
    p = (LStack *)malloc(sizeof(LStack));
    p->data = x;
    p->next = Lst;
    Lst = p;
    return p;
}

int Pop(LStack *Lst){
    LStack *p;
    int out;
    p = Lst->next;
    out = Lst->data;
    free(Lst);
    Lst = p;
    return out;
}