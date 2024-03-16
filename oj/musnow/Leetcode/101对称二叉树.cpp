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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty())
        {
            // 这里左右的顺序要和上面根节点插入左右的顺序一致
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if(left == nullptr && right == nullptr){
                continue; // 两个都是空，符合条件，跳过
            }
            // 有一个不为空，或者值不同，都是错误的
            if((left == nullptr || right == nullptr) || (left->val != right->val))
            {
                return false;
            }
            // 对称插入队列
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }   
};

// https://leetcode.cn/problems/symmetric-tree/