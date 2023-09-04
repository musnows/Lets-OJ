/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <pthread.h>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        else if(head->next == nullptr){
            // 只有一个节点的时候，返回的是空
            return nullptr;
        }
        // 头节点
        ListNode phead(0);
        phead.next = head; 
        // 三个指针
        ListNode* prev,*slow,*fast;
        prev = &phead;
        slow = fast = head;//快慢指针从头节点开始走
        int i = n;
        while(fast != nullptr && i>0)
        {
            fast = fast->next;
            i--;
        }
        // 本体保证n肯定有效，所以fast不可能为空
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            prev = prev->next;
        }
        // 删除节点
        prev->next = slow->next;
        return phead.next;
    }
};
// 这道题的思路和第八题是一样的，先找到倒数第K个节点，加上一个前置指针，直接重新连接进行删除就可以了

//https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=295&tqId=727&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290
