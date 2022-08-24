/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* removeZeroSumSublists(struct ListNode* head){
    ListNode* phead =(ListNode*)malloc(sizeof(ListNode));
    phead->next=head;
    ListNode* ptr = phead;//慢指针
    while(ptr != NULL)
    {
        //int sum = ptr->val;//这样会少头节点的判断
        int sum=0;
        //cur为快指针，去查找相加为0的节点位置
        ListNode* cur = ptr->next;
        while(cur != NULL)
        {
            sum += cur->val;
            if(sum==0)
            {
                //找到了，将慢指针的下一个置为相加为0节点的下一个
                //中间不释放数据会导致内存泄漏
                ptr->next=cur->next;
                //break;
            }
            //没找到，继续往后走
            cur=cur->next;
        }
        //快指针遍历完还没找到，慢指针走一步
        ptr=ptr->next;
    }

    ListNode* ret = phead->next;
    free(phead);
    return ret;
}
//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/
//1171. 从链表中删去总和值为零的连续节点
