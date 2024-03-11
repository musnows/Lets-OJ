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
    // 1.最简单的迭代方法
    ListNode* reverseList(ListNode* head) {
        // 注意判断链表中只有一个节点的情况，此时无法使用p
        // 也不需要使用p，直接返回就是了
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 1 2 3 4 5
        // c p n
        // 让p链接c，然后再往下一步走
        // 1 2 3 4 5
        //       c p n
        // 走到最末尾的时候，n为空，此时p就是新链表的头部
        // 将p的下一个指向c，返回p就行了。
        ListNode* cur = head;
        ListNode* prev = head->next;
        ListNode* next = head->next->next;
        // 先把cur的下一个设置为空
        cur -> next = nullptr;
        // 开始循环
        while(next != nullptr)
        {
            prev->next = cur;
            cur = prev;
            prev = next;
            next = next->next;
        }
        prev->next = cur;
        return prev;
    }
    
    // 2.还可以使用栈，所有节点入栈，然后再出栈一个一个链接就行了
    // 但是用栈的空间复杂度是O(N)

    // 3.头插方式
    // 把下一个节点头插到当前节点之前，然后移动头指针
    // h  1 2 3 4 5
    // p->c 
    // h  2 1 3 4 5
    // p->c
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

    // 4.递归方式
    ListNode* reverseList(ListNode* head) {
        // 链表为空时直接返回，链表不为空则到返回最后一个节点
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // 当链表不为空，递归会让newHead先指向最后一个节点，注意此时参数head是倒数第二个节点
        // 这一步很精妙，每一次newHead都是指向空指针（链表为空）或保留在原链表中的最后一个节点（链表不空），作用就是返回新的头结点
        ListNode* newHead = reverseList(head->next);
        // 1 2 3 4 5
        //       h n

        // 最后一个节点指向倒数第二个节点，newHead指向head
        head->next->next = head;
        // 倒数第二个节点的下一节点置空。
        head->next = nullptr;
        // 此时倒数第三个节点仍指向倒数第二个节点，newHead还是最后一个节点
        // 下一次递归中的 head->next->next = head 将倒数第二个节点下一节点指向倒数第三个节点，不断重复这一过程
        // 1 2 3 4 5
        //     h   n
        return newHead;
    }
};

// https://leetcode.cn/problems/reverse-linked-list/