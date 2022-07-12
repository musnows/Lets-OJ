//#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/implement-queue-using-stacks/submissions/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top; // 栈顶
    int capacity; // 容量
}Stack;

// 初始化
void StackInit(Stack* ps)
{
    STDataType* new = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (new == NULL)
    {
        exit(-1);
    }
    else
    {
        ps->a = new;
        ps->top = 0;
        ps->capacity = 4;
    }
}

// 销毁栈
void StackDestroy(Stack* ps)
{
    assert(ps);

    free(ps->a);
    ps->a = NULL;

    ps->capacity = 0;
    ps->top = 0;
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * (ps->capacity) * 2);
        if (new == NULL)
        {
            exit(-1);
        }
        else
        {
            ps->a = new;
            ps->capacity *= 2;
        }
    }
    ps->a[ps->top] = data;
    ps->top++;
}
// 出栈
void StackPop(Stack* ps)
{
    assert(ps);
    if (ps->top > 0)
        (ps->top)--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];

}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
    assert(ps);
    return ps->top;
}
// 检测栈是否为空，如果为空返回true，如果不为空返回false
bool StackEmpty(Stack* ps)
{
    assert(ps);
    if (ps->top == 0)
        return true;
    else
        return false;
}

void StackPrint(Stack* ps)
{
    assert(ps);
    int n = ps->top;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}


typedef struct {
    Stack st1;
    Stack st2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* qt = (MyQueue*)malloc(sizeof(MyQueue));
    if (qt == NULL)
        return NULL;

    StackInit(&qt->st1);
    StackInit(&qt->st2);

    return qt;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    if (!StackEmpty(&obj->st1))
    {
        StackPush(&obj->st1, x);
    }
    else
    {
        StackPush(&obj->st2, x);
    }
    return;
}

int myQueuePop(MyQueue* obj) {
    assert(obj);

    Stack* empty = &obj->st1;
    Stack* nonempty = &obj->st2;
    if (!StackEmpty(&obj->st1))
    {
        Stack* empty = &obj->st2;
        Stack* nonempty = &obj->st1;
    }

    while (StackSize(nonempty) > 1)
    {
        int top1 = StackTop(nonempty);
        StackPush(empty, top1);
        StackPop(nonempty);
    }

    int top = StackTop(nonempty);
    StackPop(nonempty);//原本不为空的的最后一个top被取出
    //需要将数据再倒放一遍，否则访问是反的
    while (StackSize(empty) > 0)
    {
        int top2 = StackTop(empty);
        StackPush(nonempty, top2);
        StackPop(empty);
    }

    return top;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);

    Stack* empty = &obj->st1;
    Stack* nonempty = &obj->st2;
    if (!StackEmpty(&obj->st1))
    {
        Stack* empty = &obj->st2;
        Stack* nonempty = &obj->st1;
    }

    // while(StackSize(nonempty)>1)
    // {
    //     int top1=StackTop(nonempty);
    //     StackPush(empty,top1);
    //     StackPop(nonempty);
    // }

    // int top=StackTop(nonempty);
    // //StackPop(nonempty);//原本不为空的的最后一个top被取出
    // //需要将数据再倒放一遍，否则访问是反的
    // while(StackSize(empty)>0)
    // {
    //     int top2=StackTop(empty);
    //     StackPush(nonempty,top2);
    //     StackPop(empty);
    // }
  
    //这里的栈是用数组实现的，可以直接访问首位元素
    return nonempty->a[0];
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);

    return StackEmpty(&obj->st1) && StackEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj) {
    assert(obj);

    StackDestroy(&obj->st1);
    StackDestroy(&obj->st2);
    free(obj);

    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/