/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            Node* prevNode = nullptr;
            Node* node = nullptr; // 始终指向当前节点
            for(int i =0; i< size;i++)
            {
                // 每层第一个节点，设置前一个节点的值
                if(i == 0){
                    prevNode = que.front(); // 前一个节点
                    que.pop();
                    node = prevNode; // 当前节点
                }
                else // 非第一个
                {
                    node = que.front(); // 当前节点
                    que.pop();
                    prevNode->next = node;
                    prevNode = prevNode->next; // 更新前一个节点为当前节点
                }

                // 插入后续节点
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

//https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/