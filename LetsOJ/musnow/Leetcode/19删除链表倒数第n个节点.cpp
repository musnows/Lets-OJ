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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode th(0,head);
        ListNode* slow=&th,*fast=&th;

        // 快指针先走n+1步，这样fast为空的时候，slow为需要删除节点的上一个
        for(int i=0;i<=n;i++)
        {
            fast = fast->next;
        }
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        //走到位置了
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return th.next;
    }
};
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/submissions/