//#define _CRT_SECURE_NO_WARNINGS 1
//
////https://leetcode-cn.com/problems/implement-stack-using-queues/
//
//
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QNode;
//
//typedef struct Queue
//{//这个结构体里有两个指针
//	QNode* head;//头
//	QNode* tail;//尾
//}Queue;
//
////初始化
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
////摧毁
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	QNode* findtail = pq->head;//找尾挨个挨个free
//	while (findtail)
//	{
//		QNode* next = findtail->next;
//		free(findtail);
//		findtail = next;
//	}
//
//	pq->head = NULL;
//	pq->tail = NULL;
//}
////插入（尾插）
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		printf("Push err\n");
//		exit(-1);
//	}
//
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->tail == NULL)
//	{
//		assert(pq->head == NULL);
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//	return;
//}
////删除（头删）
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head && pq->tail);//判断是否为空
//
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = NULL;
//		pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
////判断是否为空
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	//在C中bool类型和int类型可以直接混用
//	return pq->head == NULL && pq->tail == NULL;
//}
////返回它的长度
//size_t QueueSize(Queue* pq)
//{
//	assert(pq);
//
//	size_t size = 0;
//	QNode* findtail = pq->head;
//
//	while (findtail)
//	{
//		size++;
//		findtail = findtail->next;
//	}
//
//	return size;
//}
////返回头
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//
//	return pq->head->data;
//}
////返回尾部
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->tail);
//
//	return pq->tail->data;
//}
//
//
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	if (pst == NULL)
//		return NULL;
//
//	QueueInit(&pst->q1);
//	QueueInit(&pst->q2);
//
//	return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	assert(obj);
//
//	Queue* empty = &obj->q1;
//	Queue* unempty = &obj->q2;
//	if (!QueueEmpty(&obj->q1))
//	{
//		empty = &obj->q2;
//		unempty = &obj->q1;
//	}
//
//	while (QueueSize(unempty) > 1)
//	{
//		int top1 = QueueFront(unempty);
//		QueuePush(empty, top1);
//		QueuePop(unempty);
//	}
//
//	int top = QueueFront(unempty);
//	QueuePop(unempty);
//
//	return top;
//}
//
//int myStackTop(MyStack* obj) {
//	assert(obj);
//
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	assert(obj);
//
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	assert(obj);
//
//	QueueDestory(&obj->q1);
//	QueueDestory(&obj->q2);
//	free(obj);
//
//	return;
//}
//
//int main()
//{
//	MyStack* obj = myStackCreate();
//	myStackPush(obj, 1);
//	myStackPush(obj, 2);
//
//	printf("%d\n", myStackTop(obj));
//	printf("%d\n", myStackPop(obj));
//	printf("%d\n", myStackPop(obj));
//	printf("%d\n", myStackEmpty(obj));
//
//	return 0;
//}