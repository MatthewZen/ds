#include<stdio.h>
#define MAXSIZE 9

float op(float a, float b, char Op);
float com(char *exp);

int main(){
    char exp[MAXSIZE];
    float answer;
    printf("input the suffix:\n");
    for(int i = 0;i < MAXSIZE;++i)
        scanf("%c",exp+i);
    answer = com(exp);
    printf("the answer is %f\n",answer);
    return 0;
}

float com(char *exp){
    float stack[MAXSIZE]; int top = -1;
    float ans = 0;
    for(int i = 0;exp[i] != '\0';++i){
        if(exp[i] >= '0' && exp[i] <= '9')
            stack[++top] = exp[i]-'0'; //读入的值为字符型，可以直接将其与'0'相减得到真实的数字，这是一个很好用的小技巧
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            ans = op(stack[top--],stack[top--],exp[i]); //每遇到一个运算符，就将栈中的两个操作数弹出，做相应的运算
            stack[++top] = ans; //运算结果是下一个运算符的操作数之一，故需要将其保存至栈中
        }
    }
    return ans;
}

float op(float a, float b, char Op){ //规定不同运算符下应执行的操作
    if(Op == '+')
        return a + b;
    if(Op == '-')
        return a - b;
    if(Op == '*')
        return a * b;
    if(Op == '/'){
        if(b == 0)
            printf("the data is illegal!\n");
        else
            return a / b;
        
    }
}