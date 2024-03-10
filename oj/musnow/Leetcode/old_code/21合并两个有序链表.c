/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;

    struct ListNode* H1=list1;
    struct ListNode* H2=list2;
    struct ListNode* newList=NULL;
    struct ListNode* tail=NULL;
    if(H1->val<H2->val)
    {
        newList=H1;
        tail=H1;
        H1=H1->next;
    }
    else
    {
        newList=H2;
        tail=H2;
        H2=H2->next;
    }


    while(H1 && H2)
    {
        if(H1->val<H2->val)
        {

            tail->next=H1;
            tail=H1;//等同于tail=tail->next
            H1=H1->next;
        }
        else
        {
            tail->next=H2;
            tail=H2;//等同于tail=tail->next

            H2=H2->next;
        }
    }

    if(H1)
    {
        tail->next=H1;
    }

    if(H2)
    {
        tail->next=H2;
    }
    
    return newList;
}
//21
//https://leetcode.cn/problems/merge-two-sorted-lists/submissions/
