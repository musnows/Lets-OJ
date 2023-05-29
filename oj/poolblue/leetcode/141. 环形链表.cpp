https://leetcode.cn/problems/linked-list-cycle//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
         return NULL;
        //slow指针在head，fas指针在haed->next，利于后续while循环遍历
       ListNode *slow=head;
       ListNode *fast=head->next;
       while(slow!=fast)
       {
          if(fast==NULL || fast->next==NULL)//如果fast或fast->next遍历到空,证明没有成环
          {
              return false;
          }
          slow=slow->next;
          fast=fast->next->next;
       }
       return true;//fast和slow相遇，证明链表成环
    }
};
