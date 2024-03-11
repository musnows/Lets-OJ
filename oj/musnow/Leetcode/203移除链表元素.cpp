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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* phead = new ListNode;
        phead->next=head;
        ListNode* cur = phead;
        while(cur->next != nullptr)
        {
            // cur的下一个value为val，方便删除
            if(cur->next->val == val)
            {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp; // 避免内存泄漏，但OJ题目其实可以不用考虑
            }
            else
            {
                cur = cur->next;
            }
        }

        ListNode* ret = phead->next;
        delete phead;
        return ret;
    }
};

//https://leetcode.cn/problems/remove-linked-list-elements/description/