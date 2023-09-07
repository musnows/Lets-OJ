/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstdio>
class Solution {
  public:
    // 无差别逆置
    ListNode* reverseNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* ans = reverseNode(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return head1 != nullptr ? head1 : head2;
        }
        // 先逆置两个链表
        ListNode* phead1 = reverseNode(head1);
        ListNode* phead2 = reverseNode(head2);
        ListNode ret(0); // 头节点
        ret.next = nullptr;
        // 开始相加
        int carry  = 0;// 是否要进位
        int cur_num = 0;
        ListNode* new_node;
        while (phead1 != nullptr && phead2 != nullptr) {
            cur_num = phead1->val + phead2->val + carry;
            if (cur_num >= 10) {
                carry = 1;
                cur_num %= 10;
            } else {
                carry = 0; // 没有进位，设置为1
            }
            // 插入到新链表中
            new_node = new ListNode(cur_num);
            if (ret.next == nullptr) {
                ret.next = new_node;
            } else { // 不为空执行头插
                new_node->next = ret.next;
                ret.next = new_node;
            }
            phead1 = phead1->next;
            phead2 = phead2->next;
        }
        // 判断是否还有空值，执行头插
        ListNode* phead = phead1!=nullptr?phead1:phead2;
        while (phead != nullptr) {
            cur_num =   phead->val + carry;
            if (cur_num >= 10) {
                carry = 1;
                cur_num %= 10;
            } else {
                carry = 0; // 没有进位，设置为1
            }
            new_node = new ListNode(cur_num);
            new_node->next = ret.next;
            ret.next = new_node;
            phead = phead->next;
        }
        // 最终在判断是否还有进位值
        if(carry == 1){
            new_node = new ListNode(carry);
            new_node->next = ret.next;
            ret.next = new_node;
        }

        return ret.next;
    }
};
//https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=295&tqId=1008772&ru=/exam/company&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fcompany