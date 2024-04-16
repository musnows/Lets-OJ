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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 有一个为空的时候可以直接返回另外一个
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }

        ListNode* phead = new ListNode;
        ListNode* cur = phead;

        int carry = 0; // 进位制
        ListNode* left = l1,*right = l2;
        // 有一个不为空就需要继续
        while(left != nullptr || right !=nullptr)
        {
            int a = left != nullptr?left->val:0;
            int b = right != nullptr?right->val:0;

            int sum = a+b+carry;
            int val = sum % 10; // 当前值
            carry = sum>=10?1:0;
            // 注意，题目要求的是按相同的方式（数字逆序存放）来返回一个链表
            // 所以我们需要进行尾插操作
            cur->next = new ListNode(val);
            cur = cur->next;
            // 去下一位
            if(left != nullptr){    
                left=left->next;
            }
            if(right != nullptr){
                right=right->next;
            }
        }
        // 还有值，需要再尾插一个。
        if(carry!=0){
            cur->next = new ListNode(1);
        }
        return phead->next;
    }
};