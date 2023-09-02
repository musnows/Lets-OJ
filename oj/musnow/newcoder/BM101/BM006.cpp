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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        // 这里必须要判断next是否为空
        // 否则循环体内的两次next会触发段错误（解引用空指针）
        while(fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

//https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9?tpId=295&tqId=605&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290