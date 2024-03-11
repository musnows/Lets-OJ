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
        ListNode* phead = new ListNode;
        phead->next = head;
        ListNode* slow = phead,*fast = phead;
        // 块指针先走n+1步，这样可以让最终slow停在需要删除节点的前一位
        // 不管有没有头指针都是走n+1步
        int count = n+1;
        while(count-- && fast!=nullptr)
        {
            fast = fast->next;
        }
        // 两个一起走
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 此时slow是需要删除的节点的前一个
        slow->next = slow->next->next;
        return phead->next;
    }
};

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/