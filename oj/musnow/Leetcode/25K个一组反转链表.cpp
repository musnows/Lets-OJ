class Solution {
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prv = nullptr;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            // 先记录下下一个节点
            ListNode* next = cur->next;
            // 当前节点链接上一个节点
            cur->next = prv;
            // 更新上一个节点和当前节点
            prv = cur;
            cur = next;
        }
        // cur->next为空了代表走到了原始链表的末尾了
        cur->next = prv;
        return cur;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 头节点
        ListNode* newHead = new ListNode(0, head);

        ListNode* prev = newHead;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            int kcount = k - 1; // k = 3时只用走两步
            while (kcount > 0 && fast->next != nullptr) {
                fast = fast->next;
                kcount--;
            }
            // 判断有效性,kcount还有说明末尾的不够用了，不用逆置
            if (fast->next == nullptr && kcount > 0) {
                break;
            }
            // 记录原本的下一位
            ListNode* next = fast->next;
            // 将f的下一个设置为空，让当前链表分离开
            fast->next = nullptr;
            // 逆置slow
            reverseList(slow);
            // 此时fast是新链表的开头，slow是新链表的结尾
            // 将slow的next设置为原本的next，复原到原有链表中
            slow->next = next;
            // 将prev链接为新链表的头
            prev->next = fast;
            // 更新三个指针
            prev = slow;
            slow = next;
            fast = next;
        }
        return newHead->next;
    }
};

// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/