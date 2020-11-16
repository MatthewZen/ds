#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 5
#define ERROR -1
#define OK 0

typedef struct SeqStack{
    int data[MAXSIZE];
    int top;//栈顶指针
}SeqStack;

void InitStack(SeqStack *Spointer);
int Push(SeqStack *Spointer);
int Pop(SeqStack *Spointer);

int main(){
    SeqStack *Spointer;
    InitStack(Spointer);
    for(int i = 0;i < MAXSIZE;i++)
        Push(Spointer);
    printf("the data is:\n");
    for(int i = 0;i < MAXSIZE;i++)
        printf("the %dth data is: %d\n", i+1, Pop(Spointer));
    return 0;
}

void InitStack(SeqStack *Spointer){
    Spointer->top = -1; //top=-1时先自增后入栈，top始终指向栈顶值；top=0时先入栈后自增，top指向栈顶值的下一个地址
}

int Push(SeqStack *Spointer){ //这里使用指向SeqStack的指针作为参数是为了能够向SeqStack变量返回值，而非形式参数！
    if(Spointer->top == MAXSIZE-1)//full
        return ERROR;
    printf("input new data:\n");
    scanf("%d",&(Spointer -> data[++(Spointer->top)]));
    return OK;
}

int Pop(SeqStack *Spointer){
    if(Spointer->top == -1)//empty
        return ERROR;
    int temp;
    temp = Spointer->data[(Spointer->top)--];
    return temp;
}