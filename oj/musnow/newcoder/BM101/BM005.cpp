// 题目要求合并n个有序链表
// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290


// 方法1 使用顺序合并，依次交付给合并函数
class Solution {
  public:
    //合并两个链表
    ListNode* Merge2List(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) {
            return pHead2;
        }
        if (pHead2 == nullptr) {
            return pHead1;
        }

        ListNode* left = pHead1;
        ListNode* right = pHead2;
        // 把小的哪一个作为新链表的开头，并且指针向后跳过一位
        ListNode* head = pHead1;
        if (pHead1->val > pHead2->val) {
            head = pHead2;
            right = right->next;
        } else {
            left = left->next;
        }
        ListNode* cur = head;
        // 开始遍历
        while (left != nullptr && right != nullptr) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        // 只要有一个变成null了就跳出
        // 将非null的连在已有链表之后
        if (left != nullptr) {
            cur->next = left;
        } else if (right != nullptr) {
            cur->next = right;
        }

        return head;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* head = Merge2List(lists[0], lists[1]);
        // 循环依次调用，将数组中的链表依次合并
        for(int i=2;i<lists.size();i++)
        {
            head = Merge2List(head, lists[i]);
        }

        return head;
    }
};

// 方法2，使用归并合并，先依次两两合并，再合并最后的结果
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <vector>
class Solution {
  public:
    //合并两个链表
    ListNode* Merge2List(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) {
            return pHead2;
        }
        if (pHead2 == nullptr) {
            return pHead1;
        }

        ListNode* left = pHead1;
        ListNode* right = pHead2;
        // 把小的哪一个作为新链表的开头，并且指针向后跳过一位
        ListNode* head = pHead1;
        if (pHead1->val > pHead2->val) {
            head = pHead2;
            right = right->next;
        } else {
            left = left->next;
        }
        ListNode* cur = head;
        // 开始遍历
        while (left != nullptr && right != nullptr) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        // 只要有一个变成null了就跳出
        // 将非null的连在已有链表之后
        if (left != nullptr) {
            cur->next = left;
        } else if (right != nullptr) {
            cur->next = right;
        }

        return head;
    }
    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if(begin == end){
            return lists[begin];
        }
        if(begin > end){
            return nullptr;
        }
        int mid = (begin + end) / 2;
        return Merge2List(merge(lists,begin,mid),merge(lists,mid+1, end));
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        return merge(lists,0,lists.size()-1);
    }
};


// 方法3，使用优先级队列对链表进行排序，然后再合并起来
#include <queue>
class Solution {
  public:
    template<class T>
    struct geater_listnode {
        bool operator()(const T& a, const T& b)const {
            return a->val > b->val;
        }
    };
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* cur  = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, geater_listnode<ListNode*>> prv;
        // 将原视lists中的所有链表入优先级队列
        for(auto&n:lists)
        {
            cur = n;
            while(cur !=nullptr)
            {
                prv.push(cur);
                cur = cur->next;
            }
        }
        // 链表完全是空的
        if(prv.empty()){
            return nullptr;
        }
        // 依次遍历小堆，链接新的链表
        ListNode* head = prv.top();
        cur = head;
        while(!prv.empty())
        {
            prv.pop();
            cur ->next = prv.top();
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }
};