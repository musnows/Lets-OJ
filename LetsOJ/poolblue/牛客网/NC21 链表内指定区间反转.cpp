//https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=188&&tqId=38555&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
//NC21 链表内指定区间反转
 /**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if(head==nullptr||head->next==nullptr||m==n)
           return head;
        //借助临时头结点，可以统一所有的情况进行处理，尤其是翻转的链表从第一个节点开始
      ListNode* new_head =new ListNode(1);
        new_head->next=head;
        //pre指向翻转子链表的前驱节点
     ListNode *pre =new_head;
        for(int i=1;i<m;i++)
        {   
            pre=pre->next;
            //head指向翻转子链表的首部
            head=pre->next;
    
        }
        for(int i=m;i<n;i++)
        {
            //将p节点摘下进行子链表的头部插入
            ListNode *p =head->next;
            head->next=p->next;
            p->next=pre->next;
            pre->next=p;
        }
        head=new_head->next;
        delete new_head;
        return head;
        
         
    }
};
