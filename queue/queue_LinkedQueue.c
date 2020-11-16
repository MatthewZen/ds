#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 5

typedef struct elem{
    int data;
    struct elem *next;
}elem; //定义了一个单链表用于储存数据

int main(){
    elem *rear, *front;
    rear = front = NULL;
    //入栈
    //除非计算机内存满了，否则链队不会出现队满的情况
    for(int i = 0;i < MAXSIZE;++i){
        elem *p;
        p = (elem*)malloc(sizeof(elem));
        printf("input a new data:\n");
        scanf("%d",&(p->data));
        if(rear == NULL) //判断是否为空队列，是则同时要对队首指针操作
            rear = front = p;
        else{
            rear->next = p;
            rear = p;
        }
    }
    //出栈
    for(int i = 0;i < MAXSIZE;++i){
        elem *p;
        if(rear == NULL || front == NULL) //判断队列是否为空
            printf("the queue is empty!\n");
        else
            p = front; //取出当前要输出的元素
        if(rear == front) //只有一个元素时
            rear = front = NULL;
        else
            front = front->next;
        printf("the %dth data is: %d\n", i+1, p->data);
        free(p);
    }
    return 0;
}