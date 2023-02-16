//T1
//4.输入一个链表，输出该链表中倒数第k个结点。 
//OJ链接
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
//class Solution {
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//        if (pListHead == NULL)
//            return NULL;
//        struct ListNode* fast = pListHead;
//        struct ListNode* slow = pListHead;
//
//        int i = k;
//        while (i--)
//        {
//            if (fast == NULL)
//            {
//                return NULL;
//            }
//            fast = fast->next;
//        }
//
//
//        while (fast)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//
//        return slow;
//    }
//};


//t2
// //将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//
//
//    struct ListNode* H1 = list1;
//    struct ListNode* H2 = list2;
//    struct ListNode* newList = NULL;
//    struct ListNode* tail = NULL;
//    if (H1->val < H2->val)
//    {
//        newList = H1;
//        tail = H1;
//        H1 = H1->next;
//    }
//    else
//    {
//        newList = H2;
//        tail = H2;
//        H2 = H2->next;
//    }
//
//
//
//    while (H1 && H2)
//    {
//        if (H1->val < H2->val)
//        {
//
//
//            tail->next = H1;
//            tail = H1;//等同于tail=tail->next
//            H1 = H1->next;
//        }
//        else
//        {
//            tail->next = H2;
//            tail = H2;//等同于tail=tail->next
//
//
//            H2 = H2->next;
//        }
//    }
//
//
//    if (H1)
//    {
//        tail->next = H1;
//    }
//
//
//    if (H2)
//    {
//        tail->next = H2;
//    }
//
//    return newList;
//}


//T3
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 
//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//
//        struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* Bigger = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* head = newhead;
//        struct ListNode* big = Bigger;
//
//        while (pHead)
//        {
//            if (pHead->val < x)
//            {
//                head->next = pHead;
//                pHead = pHead->next;
//                head = head->next;
//
//            }
//            else
//            {
//                big->next = pHead;
//                pHead = pHead->next;
//                big = big->next;
//            }
//        }
//        big->next = NULL;
//        head->next = Bigger->next;
//
//        struct ListNode* list = newhead->next;
//        free(newhead);
//        free(Bigger);
//        return list;
//    }
//};


//t4
//7.链表的回文结构。
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//class PalindromeList {
//public:
//    //链表逆置（3.14）
//    struct ListNode* reverseList(struct ListNode* head) {
//
//
//        struct ListNode* newhead = NULL;
//        struct ListNode* cur = head;
//        while (cur)
//        {
//            struct ListNode* next = cur->next;
//            cur->next = newhead;
//
//
//            newhead = cur;
//            cur = next;
//        }
//
//
//
//
//        return newhead;
//    }
//
//    //中间节点返回（3.14的oj题目）
//    //1 2 3 4  偶数个，返回3
//    //1 2 3    奇数个，返回2
//    struct ListNode* middleNode(struct ListNode* head) {
//        if (head == NULL)
//            return NULL;
//
//
//        int count = 1;//计算链表一共的节点数
//        struct ListNode* tail = head;//找尾
//        while (tail->next != NULL)
//        {
//            tail = tail->next;
//            count++;
//        }
//        int half = (count / 2);
//        //如果是3结果为1，如果是4结果为2
//        //正好是需要从head开始寻找的次数
//        struct ListNode* mid = head;
//        while ((mid->next != NULL) && (half--))
//        {
//            mid = mid->next;
//        }
//
//
//        return mid;
//    }
//
//    bool chkPalindrome(ListNode* A) {
//        struct ListNode* mid = middleNode(A);
//        struct ListNode* ret = reverseList(mid);
//        //1 2 3 2 1 回文链表
//        //先逆转后面3个
//        //1 2 1 2 3
//        //这时候第二个2存放的next依旧是下一个3的地址
//        //使用while循环进行判断，都是判断3次是否相等
//        //相等就是回文，否则不是
//        while (A && ret)
//        {
//            if (A->val == ret->val)
//            {
//                A = A->next;
//                ret = ret->next;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//
//
//    }
//};


//判断链表相交（3.19的第一题）
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/


#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if ((headA == NULL) || (headB == NULL))//服了，找了几十分钟的错误，发现是等于号写错了，==写成了=
        return NULL;

    int countA = 1;
    int countB = 1;
    struct ListNode* HA = headA;
    struct ListNode* HB = headB;
    while (HA && HA->next)
    {
        countA++;
        HA = HA->next;
    }
    while (HB && HB->next)
    {
        countB++;
        HB = HB->next;
    }

    if (HB != HA)//结尾不相等，说明不相交
        return NULL;

    int num = abs(countA - countB);
    struct ListNode* fast = NULL;
    struct ListNode* slow = NULL;
    if (countA > countB)
    {
        fast = headA;
        slow = headB;
    }
    else
    {
        fast = headB;
        slow = headA;
    }

    while (num--)
    {
        fast = fast->next;
    }

    while (fast && slow)
    {
        if (fast == slow)
            return fast;

        fast = fast->next;
        slow = slow->next;
    }

    return NULL;
}

