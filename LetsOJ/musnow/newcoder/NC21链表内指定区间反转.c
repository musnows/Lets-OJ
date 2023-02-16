/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param head ListNode类 
 * @param m int整型 
 * @param n int整型 
 * @return ListNode类
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n ) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    // write code here
    int sz = n - m;
    if(sz==0)
        return head;//原地修改不进行操作
    
    struct ListNode phead;
    phead.next=head;//设置头节点是为了避免只有2两个元素，begin无处落脚的情况
    struct ListNode** arr=(struct ListNode**)malloc(sizeof(struct ListNode**)*(sz+2));
    struct ListNode* cur=&phead;
    struct ListNode* begin=cur;
    //1，先把cur移动到需要反转元素的首个位置，即m的位置（注意m和n都不是下标）
    int k=m,i=1;
    while(k--){
        begin=cur;//2.结束循环后，begin记下了需要逆置位置的前一个
        cur=cur->next;
    }
    //3，继续移动cur，到结束位置（n的位置）同时将m到n的所有节点的指针（包括m和n）插入数组
    k=sz;
    arr[0]=cur;//不这么操作会少一个元素
    while(k--){
        cur=cur->next;
        arr[i++]=cur;
    }
    struct ListNode* end=cur->next;//4. 记录n位置的下一个
    //5. 从后往前遍历数组，修改next
    int j=0;
    for(j=i-1;j>0;j--){
        struct ListNode* tmp=arr[j];
        tmp->next=arr[j-1];
    }
    //6. 最后修改m的前一个，和n的后一个，完成逆置
    arr[0]->next=end;
    begin->next=arr[i-1];
    
    return phead.next;   
}
//NC21 链表内指定区间反转
//https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=188&&tqId=38555&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
//思路如下：
//1，先把cur移动到需要反转元素的首个位置，即m的位置（注意m和n都不是下标）
//2，记录m位置的前一个
//3，继续移动cur，到结束位置（n的位置）同时将m到n的所有节点的指针（包括m和n）插入数组
//4. 记录n位置的下一个
//5. 从后往前遍历数组，修改next
//6. 最后修改m的前一个，和n的后一个，完成逆置
