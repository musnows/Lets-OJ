/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr){
            return pHead2;
        }
        if(pHead2 == nullptr){
            return pHead1;
        }

        ListNode* left = pHead1;
        ListNode* right = pHead2;
        // 把小的哪一个作为新链表的开头，并且指针向后跳过一位
        ListNode* head = pHead1;
        if(pHead1->val > pHead2->val){
            head = pHead2;
            right = right->next;
        }
        else{
            left = left->next;
        }
        ListNode*cur = head;
        // 开始遍历
        while(left != nullptr && right != nullptr)
        {
            if(left->val > right->val)
            {
                cur->next = right;
                right = right->next;
            }
            else
            {
                cur->next = left;
                left=left->next;
            }
            cur = cur->next;
        }
        // 只要有一个变成null了就跳出
        // 将非null的连在已有链表之后
        if(left != nullptr){
            cur->next = left;
        }
        else if(right != nullptr){
            cur->next = right;
        }

        return head;
    }
};

//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=295&tqId=23267&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290