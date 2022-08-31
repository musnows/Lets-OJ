//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
//1171. 从链表中删去总和值为零的连续节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode * pre=new ListNode(1);
    pre->next=head;
    ListNode * p=pre;
    while(p)
    {
        int sum=0;
        ListNode * q=p->next;
        while(q)
        {
            sum+=q->val;
        if(sum==0)
        {
            p->next=q->next;
            ListNode *del=p->next;
            while(del!=q->next)
            {
                ListNode *tmp = del;
                  del = del->next; 
                 free(tmp);
            }
        }
         q = q->next;
        }
        
        p = p->next;
    }
    head = pre->next;
   delete(pre); 
   return head;
    }
};
