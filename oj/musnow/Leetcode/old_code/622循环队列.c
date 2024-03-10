//#define _CRT_SECURE_NO_WARNINGS 1
////https://leetcode-cn.com/problems/design-circular-queue/submissions/
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//
//typedef struct {
//    int* data;
//    int front;
//    int tail;
//    int k;
//} MyCircularQueue;
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);//为了让这个函数能在它之前使用
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* qt = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    if (qt == NULL)
//        return NULL;
//
//    qt->data = (int*)malloc(sizeof(int) * (k + 1));
//    qt->k = k;
//    qt->front = 0;
//    qt->tail = 0;
//
//    return qt;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    assert(obj);
//    if (myCircularQueueIsFull(obj))
//        return false;
//
//    obj->data[obj->tail] = value;
//    //obj->tail++;
//    //obj->tail %= obj->k+1;//保证数据在数组内部
//    if (obj->tail == obj->k)
//    {
//        obj->tail = 0;
//    }
//    else
//    {
//        obj->tail++;
//    }
//
//
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//        return false;
//
//    if (obj->front == obj->k)
//    {//front在预先开辟的第4个位置上
//        obj->front = 0;
//    }
//    else
//    {
//        obj->front++;
//    }
//
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//
//    return obj->data[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//
//    if (obj->tail == 0)
//    {
//        return obj->data[obj->k];
//    }
//    else
//    {
//        return obj->data[obj->tail - 1];
//    }
//
//    return -1;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->tail == obj->front;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    if ((obj->tail == obj->k) && obj->front == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return obj->tail + 1 == obj->front;
//    }
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    assert(obj);
//
//    free(obj->data);
//    free(obj);
//
//    return;
//}
