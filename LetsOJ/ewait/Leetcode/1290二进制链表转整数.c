/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//1290. 二进制链表转整数
//https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/
//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。请你返回该链表所表示数字的 十进制值 。

int getDecimalValue(struct ListNode* head){
    struct ListNode* cur=head;
    int arr[32];
    int i=0;
    while(cur!=NULL)
    {
        arr[i++]=cur->val;
        cur=cur->next;
    }
    int sz=i;//遍历完之后i的大小就是链表长度
    int x=sz-1;//因为数组首位实则并不是二进制的最低位，所以要单独处理位权
    int sum=0;
    for(i=0;i<sz;i++)
    {
        sum+=arr[i]*pow(2,x);
        x--;
    }

    return sum;
}
