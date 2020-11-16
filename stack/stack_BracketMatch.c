#include<stdio.h>
#define MAXSIZE 10
#define CORRECT 0
#define ERROR -1

int match(char *bracket); // bracket is a array contents '(' and ')'

int main(){
    char bracket[MAXSIZE];
    printf("input the bracket:\n");
    for(int i = 0;i < MAXSIZE;++i)
        scanf("%c",&bracket[i]);
    printf("%d",match(bracket)); // 0 for correct; 1 for error
    return 0;
}

int match(char *bracket){
    char stack[MAXSIZE]; int top = -1; //initialize the stack in a simple way
/*
 * a more formal way to init the stack
 * before the main funciton:
 * typedef struct Stack{
 *     int data[MAXSIZE];
 *     int top;
 * }Stack;
 * in match funciton:
 *     top = -1;
 * (for linked stack we also have to initialize: lst = (LNode *)malloc(sizeof(LNode)))
 */
    for(int i = 0;i < MAXSIZE;++i){
        if(bracket[i] == '(')
            stack[++top] = '('; //left bracket then go into the stack
        else
            --top; //right bracket go out the stack
    }
    if(top == -1) 
        return CORRECT; //empty stack means correct match
    else
        return ERROR;
}