#include<stdio.h>
#include"malloc.h"
#define ERROR -1

typedef struct Elem{
    int num;
    int age;
    float grade;
}Elem;

typedef struct LNode{
    Elem data;
    struct LNode *next; 
    /* 
     * 注意这里不能使用LinkList *next;
     * 因为在初始化LNode结构时还没有定义LinkList,
     * 按照以上方法则编译器无法识别指针next的类型
     */
}LinkList;

// 增删改查功能实现
int ListInsert(LinkList *L, Elem new, int i); // 在链表指定位置插入新元素new
int ListDel(LinkList *L, int i); //删除链表指定位置的元素
Elem GetElem(LinkList *L, int i); //获得i位置的元素（可以用于指定位置元素的修改）
LinkList *LocateElem(LinkList *L, Elem target); // 在链表中查找是否有target元素，是则返回地址，否则返回NULL

int main(){
    LinkList *L,*r;
    int length;
    printf("input the length of data:\n");
    scanf("%d",&length);
    L = (LinkList*)malloc(sizeof(LinkList));
    /* 
     * malloc匿名地返回分配的内存块首地址，默认返回指向char的指针。
     * 使用malloc时应强制转换返回值以提高程序的可读性。
     * 强制转换的格式:（int *）或（p）(其中int* p)。
     */
    L->next = NULL;
    r = L; //这里使用后插法建立单链表，r指向链表最后一个结点
    for(int i = 0;i < length;i++){
        LinkList *p;
        p = (LinkList*)malloc(sizeof(LinkList)); //p为临时变量
        printf("input the %d th data:\n",i+1);
        scanf("%d %d %f",&(p->data.num),&(p->data.age),&(p->data.grade)); //输入数据
        r->next = p;
        p->next = NULL;
        r = p;//保持r始终指向最后一个结点
    }
    return 0;
}

// 在链表指定位置插入新元素new
int ListInsert(LinkList *L, Elem new, int i){
    int j = 1;//计数器
    LinkList *p,*n;
    p = L->next; // p指向首元结点
    n = (LinkList*)malloc(sizeof(LinkList));
    n->data = new; //根据待插入数据建立新结点
    while(p && (j<i-1)){
        /*
         * 这里“j<i-1”是为了取到第i-1个结点，
         * 而p是为了防止i超出链表长度，限制了
         * 最多只能取到最后一个结点，也就是在
         * 最后一位插入新值
         */
        p = p->next;
        j++;
    }
    if(!p || (j>i-1))
        return ERROR; 
        /*
         * 以上while不成立的情况有p=NULL(i>length)
         * 或j>=i-1(i<0),排除这两种情况保证j=i-1;
         */
    n->next = p->next;
    p->next = n;
}

// 删除链表指定位置的元素
int ListDel(LinkList *L, int i){
    int j = 1;
    LinkList *p,*d;
    p = L->next;
    while(p->next && (j<i-1)){
        /*
         * 注意这里判断条件是p->next，目的是最多取到
         * 第n-1个元素，因为最多只能删除最后一个元素 
         */
        p = p->next;
        j++;
    }
    if(!(p->next) || (j>i-1))
        return ERROR;
    d = p->next;
    p->next = d->next;
    free(d);
}

//获得i位置的元素
Elem GetElem(LinkList *L, int i){
    Elem target;
    LinkList *p = L->next;
    int j = 1;
    while(p && (j<i)){
        p = p->next;
        j++;
    }
    target = p->data;
    return target;
}

// 在链表中查找是否有target元素，是则返回地址，否则返回NULL
LinkList *LocateElem(LinkList *L, Elem target){
    LinkList* p;
    p = L->next;
    while(p && ((p->data.age!=target.age) || (p->data.grade != target.grade) 
                || (p->data.num != target.num)))
    /*
     *注意比较时不可以直接使用 p->data != target
     !=是数值运算符，左右值应为数值或字符，不可为结构体
     */
    p = p->next;
    return p; // 找到就返回地址，否则返回NULL(这时已经搜索到最后一个了，必为NULL)
}