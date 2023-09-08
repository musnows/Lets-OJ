/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstdio>
class Solution {
  public:

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        vector<int> nodev;
        ListNode* cur = head;
        while(cur!=nullptr){
            nodev.push_back(cur->val);
            cur= cur->next;
        }
        // 双指针遍历
        int begin=0,end=nodev.size()-1;
        while(begin<end){
            if(nodev[begin]!=nodev[end]){
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

//https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=295&tqId=1008769&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E8%25AF%25AD%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D290