
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
  public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return nullptr; // 只有1和2节点的时候不成环，没有入口节点
        }
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        ListNode* meet = pHead;
        // 这里必须要判断next是否为空
        // 否则循环体内的两次next会触发段错误（解引用空指针）
        while (fast && fast->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                meet = slow;
                break; // 相遇的节点不一定是入口节点
            }
        }
        // 如果fast是遇到空推出的，代表链表无环
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        // 直线部分为L，环的长度为C，相遇位置距离环入口b的长度为X
        // 走到这里，是找到了快慢指针二者相遇的位置meet
        ListNode* head = pHead;
        while(1)
        {
            if(head == meet)
            {
                return meet;
            }
            meet = meet->next;
            head = head->next;
        }
        return nullptr;
    }
};

// 获取有环链表的入口节点，解析看自己的笔记
// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Fcompany