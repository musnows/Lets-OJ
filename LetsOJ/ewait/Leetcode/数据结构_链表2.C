#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////判断链表相交（3.19的第一题）
////https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
//
//
//#include<stdio.h>
//#include<stdlib.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if ((headA == NULL) || (headB == NULL))//服了，找了几十分钟的错误，发现是等于号写错了，==写成了=
//        return NULL;
//
//    int countA = 1;
//    int countB = 1;
//    struct ListNode* HA = headA;
//    struct ListNode* HB = headB;
//    while (HA && HA->next)
//    {
//        countA++;
//        HA = HA->next;
//    }
//    while (HB && HB->next)
//    {
//        countB++;
//        HB = HB->next;
//    }
//
//    if (HB != HA)//结尾不相等，说明不相交
//        return NULL;
//
//    int num = abs(countA - countB);
//    struct ListNode* fast = NULL;
//    struct ListNode* slow = NULL;
//    if (countA > countB)
//    {
//        fast = headA;
//        slow = headB;
//    }
//    else
//    {
//        fast = headB;
//        slow = headA;
//    }
//
//    while (num--)
//    {
//        fast = fast->next;
//    }
//
//    while (fast && slow)
//    {
//        if (fast == slow)
//            return fast;
//
//        fast = fast->next;
//        slow = slow->next;
//    }
//
//    return NULL;
//}




//141链表相交
//https://leetcode-cn.com/problems/linked-list-cycle/
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool hasCycle(struct ListNode* head) {
//    if (head == NULL)
//        return false;
//
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//
//    struct ListNode* meet = NULL;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//
//}




//相交链表2-带返回节点
//https://leetcode-cn.com/problems/linked-list-cycle-ii/submissions/

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//    if (head == NULL)
//        return NULL;
//
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//
//    struct ListNode* meet = NULL;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            meet = fast;
//            break;
//        }
//    }
//    if ((fast == NULL) || (fast->next == NULL))
//        return NULL;
//
//    while (1)
//    {
//        if (head == meet)
//            return meet;
//        meet = meet->next;
//        head = head->next;
//    }
//
//    return NULL;
//}


//138.复制带随机指针的链表
//https://leetcode-cn.com/problems/copy-list-with-random-pointer/
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //1.复制原链表
    struct Node* HAED = head;//记录头节点
    while (head)//将新链表的每个节点链接在原链表之后
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = head->val;
        newnode->next = head->next;
        head->next = newnode;
        head = head->next->next;
    }
    //2.链接新链表的random
    struct Node* old = HAED;
    while (old)
    {
        struct Node* new = old->next;
        if (old->random == NULL)
            new->random = NULL;
        else
            new->random = old->random->next;

        old = old->next->next;
    }

    //3.将新链表解下来
    struct Node* ret = HAED->next;//记录最后的返回链表
    struct Node* oldlist = HAED;
    while (oldlist)
    {
        struct Node* copy = oldlist->next;
        struct Node* next = copy->next;

        oldlist->next = next;

        if (copy->next == NULL)
            copy->next = NULL;
        else
            copy->next = next->next;


        oldlist = next;
    }

    return ret;
}