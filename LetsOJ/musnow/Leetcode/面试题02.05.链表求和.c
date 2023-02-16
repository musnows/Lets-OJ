tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
    struct ListNode *next;
};
struct ListNode* BuyNode(int v){
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=v;
    head->next=NULL;
    return head;
}
//思路，先相加每一个位的数字，获取一个进位值和余数
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum=0, grand=0;//求和值和进位值
    struct ListNode* cur1=l1;
    struct ListNode* cur2=l2;
    struct ListNode* head=NULL;//返回值的头节点
    struct ListNode* cur=NULL;//用来遍历
    while(cur1 && cur2){
        sum=cur1->val+cur2->val+grand;
        if(sum>=10){
            sum%=10;
            grand=1;
        }
        else{
            grand=0;//需要清空进位值
        }
        struct ListNode* tmp=BuyNode(sum);//用余数创建一个节点
        if(head==NULL){
            head=tmp;//初始化
            cur=head;
        }
        else if(head->next==NULL){
            head->next=tmp;
            cur=head->next;
        }
        else if(head->next!=NULL){
            cur->next=tmp;
            cur=cur->next;
        }
        cur1=cur1->next;
        cur2=cur2->next;
    }
    printf("%d\n",grand);
    //把没走完的给链接上
    while(cur1){
        sum=cur1->val;
        if(grand==1){
            sum=cur1->val+grand;
            if(sum!=10)
                grand=0;
            else
                sum=0;
        }
        printf("cur1 %d\n",sum,grand);
        struct ListNode* tmp=BuyNode(sum);
        cur->next=tmp;
        cur1=cur1->next;
        cur= cur->next;
    }
    while(cur2){
        sum=cur2->val;
        if(grand==1){
            sum=cur2->val+grand;
            if(sum!=10)
                grand=0;
            else
                sum=0;
        }
        printf("cur2 %d %d\n",sum,grand);
        struct ListNode* tmp=BuyNode(sum);
        cur->next=tmp;
        cur2=cur2->next;
        cur= cur->next;
    }
    //上面两个都搞定以后，如果还有进位，说明是多了一个
    if(grand!=0){
        struct ListNode* tmp=BuyNode(grand);
        cur->next=tmp;
    }

    return head;
}
//面试题 02.05. 链表求和
//https://leetcode.cn/problems/sum-lists-lcci/
