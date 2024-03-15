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
    int minDepth(TreeNode* root) {
        int retDepth = 0;
        if(root == nullptr){
            return retDepth;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            retDepth++; // 层数加一
            for(int i =0;i< size;i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                
                if(temp->left != nullptr){
                    que.push(temp->left);
                }
                if(temp->right != nullptr){
                    que.push(temp->right);
                }
                // 遇到叶子节点，说明就是最小深度，直接返回
                if(temp->left == nullptr && temp->right == nullptr){
                    return retDepth;
                }
            }
        }
        return retDepth;
    }
};

// https://leetcode.cn/problems/minimum-depth-of-binary-tree/