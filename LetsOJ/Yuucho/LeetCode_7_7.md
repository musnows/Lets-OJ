# 19.删除链表的倒数第 N 个结点

#### [删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

考虑极端情况，倒数第N个节点是不是头节点。

小技巧：我们可以再开一个头结点指向head，然后返回HEAD->next。

倒数第N个节点：我们可以使用快慢指针法：

让fast先走n步，再让两个指针同时走，fast走到null，slow就是倒数第n个节点。

```C++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
		ListNode* HEAD = new ListNode();
        HEAD->next = head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 0; i < n; ++i) fast = fast->next;
        
        //slow的前继指针
        ListNode* pre = HEAD;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            pre = pre->next;
        }
        pre->next = slow->next;
        free(slow);
        return HEAD->next;
    }
};
```

# 21. 合并两个有序链表

#### [合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

每次取小的节点尾插到新链表。如果`list1`先走完，把剩下的`list2`直接尾插给`tail`，反之，剩下的`list1`尾插给`tail`；

![img](https://img-1311912725.cos.ap-guangzhou.myqcloud.com/images/202207072014354.gif)

特殊情况处理：当`list1`为空，返回`list2`，当`list2`为空，返回`list1`。

```C++
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }
    struct ListNode* head=NULL, *tail=NULL;
    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            if(tail == NULL)
            {
                head = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = list1; 
            }
            list1 = list1->next;
        }
        else
        {
            if(tail == NULL)
            {
                head = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }
    if(list1)
    {
        tail->next = list1;
    }
    if(list2)
    {
        tail->next = list2;
    }
    return head;
}
```

# 22 括号生成

#### [22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)

其实就是暴力枚举的思想，我们用递归来枚举。

首先，我们先考虑最简单的情况，空串下或者前面的括号都是已匹配的，如果先填入右括号是没办法匹配的。由此可以推出：

**在任何情况下，填入的右括号的数量是不能大于左括号的。反过来说剩余的右括号数量>左括号。**

我们可以控制递归函数的参数R>L。

```C++
class Solution {
public:
    vector<string> ret;
    char buf[20];
    
    // left:剩余左括号
    // right:剩余右括号
    // cur:当前要填第几个括号
    // 最终字符串的长度: 2n
    void dfs(int left, int right, int cur){
        if(!left && !right){
            //用'\0'封底
            buf[cur] = '\0';
            ret.push_back(buf);
            return;
        }

        //放左括号：还有左括号才能放
        if(left){
        buf[cur] = '(';
    	dfs(left - 1, right, cur + 1);
        }
    
        //放右括号
        if(right > left){
        buf[cur] = ')';
        dfs(left, right-1, cur + 1);
        }
    
    }
    

    vector<string> generateParenthesis(int n) {
		dfs(n, n, 0);
        return ret;
    }
};
```

# 23 合并K个升序链表

#### [合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

合并链表，归并整体是最好的。k个链表就是每一轮用小顶堆选出每个链表的第一个元素的最小值。然后将被取出元素的链表指针后移。再把当前节点的值加入小顶堆进行新一轮选数。

记k个链表总的长度为LEN，那么时间复杂度为O(LEN*logk)。![image-20220707210857148](https://img-1311912725.cos.ap-guangzhou.myqcloud.com/images/202207072108278.png)

```C++
 // 先确认能不能改变原链表的结构
 // 可以改变原链表的结构（不能创建新节点，复用原本的结点）
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //要存储的元素
        using Elem = pair<int, ListNode*>;
        //建立小根堆
        priority_queue<Elem, vector<Elem>, greater<Elem>> pq;
		
        //遍历，如果节点不为空就push
        for (ListNode* node : lists) if (node) {
            pq.push({node->val, node});
        }

        // 合并后的链表的头结点
        ListNode* head = nullptr;
        // 合并后的链表的尾结点(用尾结点连接新合并进来的结点)
        ListNode* ptr = nullptr;

        while (!pq.empty()) {
            Elem elem = pq.top();
            pq.pop();

            if (!head) {
                head = ptr = elem.second;
            } else {
                ptr->next = elem.second;
                ptr = elem.second;
            }

            if (elem.second->next) {
                pq.push({elem.second->next->val, elem.second->next});
            }            
        }

        return head;
    }
};
```

