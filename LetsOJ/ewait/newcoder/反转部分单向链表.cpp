# include <bits/stdc++.h>
#include<vector>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

//需要反转的vector，提供下标位置
void reverse_v(vector<list_node*>& v,int begin,int end)
{
    reverse(v.begin() + begin, v.begin() + end + 1);
}

list_node * reverse_list(list_node * head, int L, int R)
{
    //////在下面完成代码
    
    //1.通过遍历得到所有节点的指针
    vector<list_node*> v;
    list_node* cur = head;
    while(cur)
    {
        v.push_back(cur);
        cur=cur->next;
    }
    //2.在vecotor中反转链表
    reverse_v(v,L-1,R-1);
    //3.重新链接节点
    for(int i=0;i<v.size()-1;i++)
    {
        v[i]->next=v[i+1];
    }
    v[v.size()-1]->next=nullptr;
    
    return v[0];
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}
//这里的其他代码都是预先帮你写好的，只有中间的反转部分是需要自己写的
