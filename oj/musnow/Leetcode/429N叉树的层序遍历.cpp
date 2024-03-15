/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> retV;
        if(root == nullptr){
            return retV;
        }
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> tempV;
            for(int j = 0; j < size ; j++){
                Node* temp = que.front();
                que.pop();
                tempV.push_back(temp->val);
                for(int i =0;i<temp->children.size();i++)
                {
                    que.push(temp->children[i]);
                }
            }
            retV.push_back(tempV);
        }
        return retV;
    }
};

// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/