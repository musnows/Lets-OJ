/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <climits>
#define elif else if
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead == nullptr || (pHead->next == nullptr && k>1)){
            return nullptr;
        }
        ListNode* slow,*fast;
        slow = fast = pHead;
        // fast先走k步
        int i = k;
        while(fast !=nullptr && i>0)
        {
            fast = fast->next;
            i--;
        }
        // fast到达null，k没有走完 - 返回空
        // fast到达null，k刚好走完 - 返回头节点
        // fast没有到达null - 执行下一步
        if(fast == nullptr && i>0){
            return nullptr;
        }
        elif(fast == nullptr && i==0){
            return pHead;
        }
        // 两个一起走
        while(fast!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
//https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=295&tqId=1377477&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290