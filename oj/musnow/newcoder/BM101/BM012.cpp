/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <unistd.h>
#include <vector>
class Solution {
  public:
    void PrintList(ListNode* head, const string& pstr) {
        cout << pstr << "  ";
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
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
    // 递归函数
    ListNode* _sortInList(ListNode* head) {
        // 如果只有一个值，直接返回
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 如果是两个值，那就进行排序后返回新链表的头
        if (head->next->next == nullptr) {
            ListNode* low = head, *big = head->next;
            if (head->val > head->next->val) {
                low = head->next;
                big = head;
            }
            low->next = big;
            big->next = nullptr;
            return low; // 返回一个升序的链表
        }
        // 如果是超过两个链表，那就进行找中，并将其拆分为两个链表传给自己
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 走到这里，slow就是中间的值，将其拆分掉
        ListNode* Lhead = head;
        ListNode* Rhead = slow->next;
        slow->next = nullptr;
        // 传递给自己，继续分化
        Lhead = _sortInList(Lhead);
        Rhead = _sortInList(Rhead);
        // PrintList(Lhead, "L");
        // PrintList(Rhead, "R");
        // 最终获取到的两个链表都是有序的，将其连起来
        ListNode phead(0), *cur_next;
        while (Lhead != nullptr && Rhead != nullptr) {
            // 找出小的，头插
            if (Lhead->val < Rhead->val) {
                cur_next = Lhead->next; // 先记录下下一个值
                // 头插
                Lhead->next = phead.next;
                phead.next = Lhead;
                // 移动到原本的下一个值
                Lhead = cur_next;
            } else {
                cur_next = Rhead->next;  // 先记录下下一个值
                Rhead->next = phead.next;// 头插
                phead.next = Rhead;
                Rhead = cur_next;// 移动到原本的下一个值
            }
        }
        // 如果还有剩余值，那就全部头插
        ListNode* not_empty = Lhead != nullptr ? Lhead : Rhead;
        while (not_empty != nullptr) {
            cur_next = not_empty->next;// 先记录下下一个值
            not_empty->next = phead.next;// 头插
            phead.next = not_empty;
            not_empty = cur_next;// 移动到原本的下一个值
        }
        // 因为是把小值头插，最终得到的是降序序列，所以需要逆序
        return reverseNode(phead.next);
    }
    class BigListnode{
    public:
        bool operator()(ListNode*L,ListNode*R){
            return L->val > R->val;
        }
    };
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // return _sortInList(head); // 方法1，递归+归并
        // 方法2，用vector排序
        ListNode* cur = head;
        vector<ListNode*> nodev;
        while (cur != nullptr) {
            nodev.push_back(cur);
            cur = cur ->next;
        }
        // 排序，写个仿函数（排降序方便头插）
        sort(nodev.begin(),nodev.end(),BigListnode());
        ListNode phead(0);
        // 遍历一遍，重新连起来
        for(auto&e:nodev){
            // 头插
            e->next = phead.next;
            phead.next = e;
        }
        return phead.next;
    }
};

// https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Fcompany

