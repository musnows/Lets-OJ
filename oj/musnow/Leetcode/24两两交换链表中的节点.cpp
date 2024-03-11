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
    ListNode* swapPairs(ListNode* head) {
        ListNode* phead = new ListNode;
        phead->next = head;
        ListNode*cur = phead;

        // 必须要先判断cur->next再判断cur->next->next
        while(cur->next!= nullptr && cur->next->next !=nullptr)
        {
            ListNode* temp = cur->next->next->next; // 第三个
            ListNode* next = cur->next; // 第一个
            // next->next 是第二个

            cur->next = next->next;
            next->next->next = next;
            next->next = temp;

            cur = cur->next->next; // 一次性走两部
        }
        ListNode* ret = phead->next;
        delete phead;
        return ret;
    }
};