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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head,*fast = head;
        ListNode* meet;
        ListNode* phead = head;
        while(fast!= nullptr && fast->next !=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                meet = fast;
                break;
            }
        }
        // 能走到空指针，说明链表不成环
        if(fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        // 此时fast和slow相遇，相遇点为meet指针
        // 死循环走，一定能找到对应位置
        while(true)
        {
            if(phead == meet){
                return phead;
            }
            phead=phead->next;
            meet=meet->next;
        }
        return nullptr;
    }
};

// https://leetcode.cn/problems/linked-list-cycle-ii/