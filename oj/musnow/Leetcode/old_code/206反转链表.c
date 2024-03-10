/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){

    struct ListNode* newhead=NULL;
    struct ListNode* cur=head;
    while(cur)
    {
        struct ListNode* next=cur->next;
        cur->next=newhead;

        newhead=cur;
        cur=next;
    }


    return newhead;
}

//https://leetcode.cn/problems/reverse-linked-list/