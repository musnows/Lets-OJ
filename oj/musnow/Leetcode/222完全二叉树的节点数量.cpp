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
    // 递归计算
    int _countNodes(TreeNode* root)
    {
        if(root == nullptr){
            return 0;
        }

        int left = _countNodes(root->left);
        int right = _countNodes(root->right);
        return 1 + left + right;
    }

    // 迭代计算
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        while(!que.empty())
        {
            int size = que.size();
            for(int i =0;i<size;i++)
            {
                TreeNode* front = que.front();
                que.pop();
                count++; 
                if(front->left != nullptr){
                    que.push(front->left);
                }
                if(front->right != nullptr){
                    que.push(front->right);
                }
            }
        }
        return count;
    }

    // 适用完全二叉树计算思路的代码
     int countNodes1(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }
        // 开始根据左深度和右深度是否相同来判断该子树是不是满二叉树
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left) {  // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while (right) { // 求右子树深度
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，返回满足满二叉树的子树节点数量
        }
        // 后序遍历
        int leftTreeNum = countNodes(root->left);       // 左
        int rightTreeNum = countNodes(root->right);     // 右
        int result = leftTreeNum + rightTreeNum + 1;    // 中
        return result;
    }
};

// https://leetcode.cn/problems/count-complete-tree-nodes/ 