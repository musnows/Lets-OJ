/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL)
        return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    struct ListNode* meet = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            meet=fast;
            break;
        }
    }
    if((fast==NULL)|| (fast->next==NULL))
        return NULL;

    while(1)
    {
        if(head==meet)
            return meet;
        meet=meet->next;
        head=head->next;
        
    }
    // if(head==meet)
    //         return meet;

    return NULL;
}
//https://leetcode.cn/problems/linked-list-cycle-ii/submissions/