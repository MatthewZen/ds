#include<stdio.h>
#include<malloc.h>

#define ERROR -1

typedef struct Elem{
    int id;
    int age;
    int grades;
}Elem;
typedef struct duLinkList{
    Elem data;
    struct duLinkList *pre;
    struct duLinkList *next;
}duLinkList;

Elem GetEinkList (duLinkList *L, int i); //获得链表中第i位的值
duLinkList *LocateElem(duLinkList *L, Elem target); // 在链表中查询指定值，有则返回地址，无则返回NULL
int ListInsert(duLinkList *L, Elem new, int i); // 在链表的第i位插入新数据
int ListDel(duLinkList *L, int i); // 在链表第i位删除数据

int main(){
    duLinkList *L, *lastPointer, *searchPointer;
    Elem data, search, new;
    int length, loc, insertpos, delpos;
    printf("input the length of data:\n");
    scanf("%d", &length);
    L = (duLinkList*)malloc(sizeof(duLinkList));
    L->next = NULL;
    L->pre = NULL; 
    // 双链表的头结点的前向指针指向NULL
    lastPointer = L; // lastPointer指向链表最后一位结点
    for(int i = 0;i < length;i++){
        duLinkList *p;
        p = (duLinkList*)malloc(sizeof(duLinkList));
        printf("input the %dth data:\n",i+1);
        scanf("%d %d %d", &(p->data.id), &(p->data.age), &(p->data.grades));
        lastPointer->next = p; // 建立新数据和原链表的连接，注意这里没有数据覆盖
        p->pre = lastPointer; 
        p->next = NULL;
        lastPointer = p;
    }
    // 存取测试
    printf("input index number to search:\n");
    scanf("%d", &loc);
    data = GetElem(L,loc);
    printf("the %dth data is:\nid:%d\nage:%d\ngrades:%d\n",loc,data.id,data.age,data.grades);
    // 查找测试
    printf("input the data to search:\n");
    scanf("%d %d %d", &(search.id), &(search.age), &(search.grades));
    searchPointer = LocateElem(L, search);
    printf("the date is at %p\n", searchPointer);
    // 插入测试
    printf("input the new data:\n");
    scanf("%d %d %d", &new.id, &new.age, &new.grades);
    printf("input the index to insert:\n");
    scanf("%d", &insertpos);
    ListInsert(L, new, insertpos);
    data = GetElem(L, insertpos);
    printf("the %dth data is:\nid:%d\nage:%d\ngrades:%d\n",insertpos,data.id,data.age,data.grades);
    // 删除测试
    printf("input index of data to delete:\n");
    scanf("%d", delpos);
    ListDel(L, delpos);
    data = GetElem(L, delpos);
    printf("the %dth data is:\nid:%d\nage:%d\ngrades:%d\n",delpos,data.id,data.age,data.grades);
    return 0;
}

Elem GetElem(duLinkList *L, int i){
    int j = 1;
    duLinkList *p = L->next;
    Elem target;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)
        printf("index is out of range!\n");
    target = p->data;
    return target;
}

duLinkList *LocateElem(duLinkList *L, Elem target){
    duLinkList *p = L->next;
    while(p && (p->data.age != target.age) || (p->data.grades != target.grades) 
          || (p->data.id != target.id)) // 对结构体进行逻辑运算时必须要在结构体成员层面运算！
        p = p->next;
    return p;
}

int ListInsert(duLinkList *L, Elem new, int i){
    duLinkList *p = L->next, *n; // 为新数据创建一个指向duLinkList的指针
    int j = 1;
    n = (duLinkList*)malloc(sizeof(duLinkList)); 
    /* 
     * 创建了n指针后只能说n指向的类型明确了，但不能确定n指向的是一个单个duLinklist结构
     * 还是一个duLinkList数组，这时必须要为n分配空间，切记！ 
     */
    while(p && j < i){ // 这里直接定位到第i个结点而非单链表中的i-1结点，因为可以使用双链表的pre指针
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return ERROR;
    n->data = new;
    /*
     * 必须注意，结构体可且仅可使用赋值符号=来将一个结构体赋值给另一个结构体，因为本质上结构体就是一个
     * 连续的空间，将空间中的每一个值对应赋值到另外一个大小完全相同的空间是没有问题的。但是不可以对结构体
     * 进行逻辑运算，例如!=、==等，必须对结构体的每一项进行比较和判断
     */
    n->pre = p->pre; // 会先被覆盖的信息先处理
    n->next = p;
    p->pre->next = n;
    p->pre = n;
}

int ListDel(duLinkList *L, int i){
    duLinkList *p = L->next;
    int j = 1;
    while(p && j < i){ // 同样是定位到了第i位结点
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return ERROR;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
}