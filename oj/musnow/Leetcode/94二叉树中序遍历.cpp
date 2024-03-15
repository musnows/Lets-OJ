/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> retV;
        if(root == nullptr){
            return retV;
        }

        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty())
        {
            if(cur != nullptr)
            {
                st.push(cur);
                // 往左走
                cur = cur->left;
            }
            else
            {
                // 走到空了，将cur更新为当前节点的父亲
                // 将父亲插入数组，再往右边走
                cur = st.top();
                st.pop();
                retV.push_back(cur->val);
                // 往右边走
                cur = cur->right;
            }
        }   
        return retV;
    }
};

// https://leetcode.cn/problems/binary-tree-inorder-traversal/