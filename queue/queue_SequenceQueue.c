#include<stdio.h>
#define MAXSIZE 10

int main(){
    int data[MAXSIZE];
    int rear = 0, front = 0; //没有使用结构体的方式定义队列，而是用这种更贴近于实际应用的方式
    //入队
    //（在进行操作之前首先要对被操作对象的状态进行判断！）
    for(int i = 0;i < MAXSIZE;++i){
        if((rear+1)%MAXSIZE == front)
        //说明队满，千万注意这里不可以使用rear++，否则rear会自加
        //同时注意，为了区分队满和队空两种情况，只能舍弃一个地址不储存任何值
        //另一种经济的做法是使用一种标识符，当队满时置为一个值，这样做同时需要一个计数器
        //关于先赋值后自加以及先自加后赋值的不同入队方法，上述的队满判断条件都是一样的
            printf("the queue is full!\n");
        else{
            printf("enter a new data:\n");
            int in;
            scanf("%d",&in);
            rear = (rear+1)%MAXSIZE; //先自加再赋值
            data[rear] = in;
        }
    }
    //出队
    for(int i = 0;i < MAXSIZE;++i){
        if(rear == front) //队空
            printf("the queue is empty!\n");
        else{
            front = (front+1)%MAXSIZE;
            printf("the %dth data is:%d\n",i+1,data[front]);
        }
    }
    return 0;
}