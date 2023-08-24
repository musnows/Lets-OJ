/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    // 无差别逆置
    ListNode* reverseNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* ans = reverseNode(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }

    void cout_vector(std::vector<ListNode*>& begin_node_v) {
        for (auto& e : begin_node_v) {
            cout << e->val << " " ;
        }
        cout << endl;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 只有一个节点，或者逆置区间为1的都不需要操作
        if (head == nullptr || head->next == nullptr || k <= 1) {
            return head;
        }
        // 头节点和遍历指针
        ListNode phead(0);
        phead.next = head;
        ListNode* cur = &phead;
        // 把每k个节点单独取出来，分别逆置后链接起来
        std::vector<ListNode*> begin_node_v,begin_node_prev_v;
        int index = k-1; // 初始化为k-1(忽略头节点)，原有链表第一个节点始终入栈
        int node_count = 0;// 节点总数（包含头节点）
        while (cur != nullptr) { // 不知道有多长，得死循环
            if(index+1 == k && cur != &phead){
                begin_node_prev_v.push_back(cur);
            }
            else if (index == k) {
                begin_node_v.push_back(cur);
                index = 0;
            }
            cur = cur->next;
            index++;
            node_count ++;
        }
        // 走到这里已经把每个需要逆置的开头节点给记录下来了
        // 如果节点总数量小于k则不逆置直接返回
        node_count --;//减-1 头节点
        if(node_count <k){
            return head;
        }
        // 不是整数倍，代表最后一个是不要处理的
        ListNode* last_link = nullptr; 
        if((node_count %k) != 0) {
            last_link = begin_node_v[begin_node_v.size()-1];// 最后一个
            begin_node_v.pop_back();// 删除最后一个
        }

        // cout_vector(begin_node_v);
        // cout_vector(begin_node_prev_v);

        // 将每个区间的末尾节点的next链接为Null作为递归标识
        for(auto&n:begin_node_prev_v){
            n->next = nullptr;
        }
        // 将每个区间交付给递归开始逆置，并将逆置的返回值与上一个区间的开头连起来
        cur = &phead;
        for(auto& n:begin_node_v){
            ListNode* ptr=reverseNode(n);
            cur->next = ptr;
            cur = n;
        }
        // 判断是否还有剩下的节点
        if(last_link !=nullptr){
            begin_node_v[begin_node_v.size()-1]->next = last_link;
        }
        return phead.next;
    }
};





//https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=295&tqId=722&ru=/exam/company&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fcompany