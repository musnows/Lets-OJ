/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
#include <stdexcept>
class Solution {
  public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if(pHead1 == nullptr || pHead2 == nullptr){
			return nullptr;
		}
        ListNode* p1, *p2;
        p1 = pHead1;
        p2 = pHead2;
        int len1 = 0, len2 = 0;
        while (p1->next != nullptr) {
            p1 = p1->next;
            len1++;
        }
        while (p2->next != nullptr) {
            p2 = p2->next;
            len2++;
        }
		// 两个不相等代表链表不相交
		if(p1!=p2){
			return nullptr;
		}
		// 计算出长度差
		int len_diff = abs(len2-len1);
		// 根据长度选择快慢指针
		ListNode* fast=pHead1,*slow=pHead2;
		if(len2>len1){
			fast = pHead2;
			slow = pHead1;
		}
		// 快指针先走
		for(int i=0;i<len_diff;i++){
			fast = fast->next;
		}
		// 两个一起走
		while(true)
		{
			if(fast == slow ){
				return slow;
			}
			slow = slow->next;
			fast = fast->next;
		}
		return nullptr;
    }
};

//https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=295&tqId=23257&ru=/exam/company&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fcompany