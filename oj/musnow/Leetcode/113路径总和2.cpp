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
    void _pathSum(TreeNode* root, const int targetSum,int curSum, vector<vector<int>>& retV,vector<int> curV) {
        // 空节点跳过
        if(root == nullptr){
            return ;
        }
        // 叶子节点，且值相等，插入
        curSum += root->val;
        curV.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && curSum == targetSum){
            retV.push_back(curV);
            return;
        }
        // 左右递归
        _pathSum(root->left,targetSum,curSum,retV,curV);
        _pathSum(root->right,targetSum,curSum,retV,curV);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> retV;
        if(root == nullptr){
            return retV;
        }

        _pathSum(root,targetSum,0,retV,vector<int>());
        return retV;
    }   
};

// https://leetcode.cn/problems/path-sum-ii/