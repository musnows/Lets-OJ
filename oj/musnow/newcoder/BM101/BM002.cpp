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
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 只有一个节点或者为空不需要逆置，逆置区间为0也不需要逆置
        if (head == nullptr || head->next == nullptr || ((n-m) == 0)) {
            return head;
        }
        // 开头的上一个节点，开头节点，结尾节点
        ListNode* begin_node_prev,*begin_node, * end_node;
        // 虚拟头节点
        ListNode phead(0); 
        phead.next = head;
        // 开始遍历
        ListNode* cur = &phead;
        for (int i = 0; i <= n; i++) {
            // i必须从0开始，此时因为有了头节点，就可以直接把区间[m,n]看作数组下标
            // 因为使用了虚拟的头节点作为第一个节点，所以不管是什么情况都不会错过i+1的节点
            // 如果不用头节点，那如果是 {3,5},1,2 这种用例就会因为i+1错过第一个节点
            if (i + 1 == m) {
                begin_node_prev = cur;
                begin_node = cur->next;
            } else if (i == n) {
                end_node = cur;
                break;
            }
            // 往后走
            cur = cur->next;
        }
        // 需要记住末尾节点的下一个，最后需要用来链接
        ListNode* end_node_next = end_node->next;
        if(end_node_next != nullptr){
            end_node->next = nullptr; //将右边界节点修改为空指针，作为逆置函数的末尾标识
            // 如果不修改为空，逆置函数不会管区间，会一直把后续的节点都给你逆置了，不符合题目要求
        }
        // 开始逆置区间起始节点
        ListNode* new_begin_node = reverseNode(begin_node_prev->next);
        // 此时能获取到一个新的链表头指针
        // 1.将原有链表区间的前一个节点的next链接到这个新的头节点
        begin_node_prev->next = new_begin_node;
        // 2.将新链表的末尾节点（循环中记录下来的begin_node）的next设置为原本的末尾节点的下一个
        begin_node->next = end_node_next;
        // 返回新链表
        return phead.next;
    }
};

//https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=295&tqId=654&ru=/exam/intelligent&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fintelligent