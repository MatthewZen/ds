//问题描述：顺序栈s0，s1共享一个储存区：elem[MaxSize]，设计此共享栈
//基本思路：栈的栈底是不改变的，故可以将两个栈的栈底分别放置于elem数组的两端，之后通过两个栈顶指针来实现两个栈的入栈且互不影响
//        栈满的特点为：左栈顶指针等于右栈顶指针时，而不一定非要等于MaxSize/2，可以充分地利用空间
#include<stdio.h>
#include<malloc.h>
#define MaxSize 5
#define DataSize 3

typedef struct ShareStack{
    int data[MaxSize];
    int top0; //s0的栈顶指针
    int top1; //s1的栈顶指针
}ShareStack; //一个问题：什么时候需要定义结构体？什么时候只需要简单的栈定义？


void Push(ShareStack *elem, int StackNo, int x);
int Pop(ShareStack *elem, int StackNo);

int main(){
    ShareStack *elem;
    elem = (ShareStack *)malloc(sizeof(ShareStack)); //对结构体定义时千万不要忘记使用malloc为其分配存储空间
    elem->top0 = -1;
    elem->top1 = MaxSize; //初始化，注意两个栈的入栈方向相反，栈顶指针的动作也是相反的！
    int data0, data1;
    //输入
    printf("input new data for stack0:\n");
    for(int i = 0;i < MaxSize-DataSize;++i){
        scanf("%d",&data0);
        Push(elem, 0, data0);
    }
    printf("input new data for stack1:\n");
    for(int i = 0;i < DataSize;++i){
        scanf("%d",&data1);
        Push(elem, 1, data1);
    }
    //输出
    printf("the data in stack0 are:\n");
    for(int i = 0;i < MaxSize-DataSize;++i)
        printf("%d···%d\n", i+1, Pop(elem, 0));
    printf("the data in stack1 are:\n");
    for(int i = 0;i < DataSize;++i)
        printf("%d···%d\n", i+1, Pop(elem, 1));
    return 0;
}

//入栈
void Push(ShareStack *elem, int StackNo, int x){ //使用指向ShareStack类型的指针就不需要考虑返回值的问题，也可以返回状态
    if(elem->top0 < elem->top1){ //首先判断栈是否已满，当top0 == top1时说明栈已满
        if(StackNo == 0)
            elem->data[++(elem->top0)] = x;
        else if(StackNo == 1)
            elem->data[--(elem->top1)] = x; //注意s1入栈的方向，及之后出栈的方向
        else
            printf("the index of stack is illegal!\n");
    }
    else
        printf("the sharing stack is full!\n");
}

//出栈
int Pop(ShareStack *elem, int StackNo){
    int data;
    if(StackNo == 0){
        if(elem->top0 == -1)//操作之前首先判断栈是否为空
            printf("the stack0 is empty!\n");
        else
            data = elem->data[elem->top0--];
    }
    else if(StackNo == 1){
        if(elem->top1 == MaxSize)
            printf("the stack1 is empty!\n");
        else
            data = elem->data[elem->top1++];
    }
    else
        printf("the index of stack is illegal!\n");
    return data;
}