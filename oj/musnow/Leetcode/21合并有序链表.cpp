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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* oldHead = head;
        ListNode* cur1 = l1, *cur2 = l2;
        while(cur1 != nullptr && cur2 != nullptr)
        {
            if(cur1->val >= cur2->val)
            {
                head->next = cur2;
                head = head->next;
                cur2 = cur2->next;
            }
            else
            {
                head->next = cur1;
                head = head->next;
                cur1 = cur1->next;
            }
        }


        if(cur1 == nullptr)
        {
            head->next = cur2;
        }
        else
        {
            head->next = cur1;
        }
        return oldHead->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* oldHead = head;
        ListNode* cur1 = list1, *cur2 = list2;
        while(cur1 != nullptr && cur2 != nullptr)
        {
            if(cur1->val >= cur2->val)
            {
                head->next = cur2;
                head = head->next;
                cur2 = cur2->next;
            }
            else
            {
                head->next = cur1;
                head = head->next;
                cur1 = cur1->next;
            }
        }


        if(cur1 == nullptr)
        {
            head->next = cur2;
        }
        else
        {
            head->next = cur1;
        }
        return oldHead->next;
    }
};
// 合并两个有序链表
// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/description/
// https://leetcode.cn/problems/merge-two-sorted-lists/description/