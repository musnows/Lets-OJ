/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // 因为需要O(1)空间复杂度，所以我们不能用很蠢的将数据遍历出来后倒序放回的办法
        // 时间复杂度是O(N) 也要求我们写的代码相对来说效率需要高一些
        if (head == nullptr || head->next == nullptr) {
            return head;//只有一个或者为空的情况下，直接跳过
        }
        ListNode* old_head = head; // 单独存头
        ListNode* A, *B, *C; // 三个指针
        A = head;
        B = head->next;
        C = head->next->next;
        while (C != nullptr) {
            // B修改链接为B的前一个（A在原视链表中是B的前一个）
            B->next = A;
            A = B; // A变成B（也相当于A在原视链表中，往后走一步）
            B = C; // B往后走一步
            C = C->next; // C往后走一步
        }
        // 走到这里是B的下一个C已经为nullptr，代表B是最后一个节点
        B->next = A; // 依旧是链接
        old_head->next = nullptr;
        return B; // B是原视链表的最后一个节点，新链表的第一个节点
    }
};

//https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=295&tqId=23286&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj


