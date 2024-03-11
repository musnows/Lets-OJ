/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0,count2=0;

        ListNode* cur1=headA;
        while(cur1!=nullptr)
        {
            cur1=cur1->next;
            count1++;
        }

        ListNode* cur2=headB;
        while(cur2!=nullptr)
        {
            cur2=cur2->next;
            count2++;
        }
        // 得出两个长度的差值以及谁更长
        ListNode* fast = headA,*slow = headB;
        if(count1<count2)
        {
            fast = headB;
            slow = headA;
        }
        int diff = abs(count1-count2);
        while(diff--)
        {
            fast = fast->next;
        }

        while(slow!=nullptr && fast!=nullptr)
        {
            if(slow == fast)
            {
                return slow;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return nullptr;
    }
};