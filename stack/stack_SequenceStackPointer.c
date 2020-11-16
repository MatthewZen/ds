// 顺序栈使用指针实现

#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 5
#define ERROR -1
#define OK 1

typedef struct SeqStack{
    int *top; //栈顶指针，指向有值域的下一地址
    int *base; //栈底指针，也是数组的基地址
    int StackLength; //栈的长度，用于判断是否栈满
}SeqStack;

SeqStack InitStack(void);
int Push(SeqStack *Spointer);
int Pop(SeqStack *Spointer);

int main(){
    SeqStack S, *pointer;
    pointer = &S;
    S = InitStack();
    for(int i = 0;i < MAXSIZE;i++)
        Push(pointer); //数据依次入栈
    printf("the data input is:\n");
    for(int i = 0;i < MAXSIZE;i++)
        printf("%dth num is: %d\n", i+1, Pop(pointer));
    return 0;
}

//栈的初始化
SeqStack InitStack(){
    SeqStack S;
    S.StackLength = MAXSIZE;
    S.base = (int *)malloc(sizeof(int)*S.StackLength);
    S.top = S.base; //初始时top指针和base指针重合
    return S;
}

//入栈
int Push(SeqStack *Spointer){
    if((int)(Spointer->top - Spointer->base) == Spointer->StackLength) // 栈满
        return ERROR;
    printf("input new data:\n");
    scanf("%d",Spointer->top++);
    return OK;
}

// 出栈
int Pop(SeqStack *Spointer){
    if(Spointer->top == Spointer->base) // 栈空
        return ERROR;
    int elem;
    elem = *(--Spointer->top); // 出栈时需要取top-1的值，之后top就一直停在这个位置，直到下一次出栈
    return elem;
}