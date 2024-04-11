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
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return;
        }
        // 返回链表中间节点，如果有两个中间节点则返回第1个（方便断开链表）
        ListNode* mid = middleNode(head);
        ListNode* left = head;
        // 逆置右半部分
        ListNode* right = reverseList(mid->next);
        mid->next = nullptr; // 让左半部分和右半部分断开
        // 归并两个链表，从左边开始一次链接一个右侧的链表
        while(left!=nullptr && right!=nullptr)
        {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;
            // 左边链接右边的
            // 右边的链接左边的下一个
            left->next = right;
            right->next = nextLeft;
            // 注意需要跳转到原本的左侧右侧链表的下一位才可以
            left = nextLeft;
            right = nextRight;
        }
        return;
    }

    // 返回链表中间节点，如果有两个中间节点则返回第1个
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 逆置链表
    ListNode* reverseList(ListNode* head) {
        // 链表为空时直接返回，链表不为空则到返回最后一个节点
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = new ListNode;
        ListNode* cur = head;
        ListNode* prev = newHead;
        while(cur != nullptr)
        {
            ListNode* temp = cur;
            cur = cur->next; // 要在cur的next被修改之前走到下一个节点
            temp->next = prev->next;
            prev->next = temp;
        }        
        return newHead->next;
    }
};