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
    void _inorderTravel(TreeNode* root,vector<int>& v)
    {
        if(root == nullptr){
            return ;
        }

        _inorderTravel(root->left,v);
        v.push_back(root->val);
        _inorderTravel(root->right,v);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        vector<int> v;
        _inorderTravel(root,v);
        for(int i =0;i<v.size()-1;i++){
            if(v[i] >= v[i+1]){
                return false;
            }
        }
        return true;
    }
};

// https://leetcode.cn/problems/validate-binary-search-tree/