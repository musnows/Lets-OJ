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
    TreeNode* _trimBST(TreeNode* root, const int low,const int high) {
        if(root == nullptr){
            return root;
        }
        // 注意题目给出的是闭区间，所以这里超出的情况不包括=的情况
        // 如果当前节点值不在区间内，则往右边/左边找是否有符合条件的
        // 如果有则会正常返回符合条件的节点（也相当于通过返回值把当前节点删掉了）
        if(root->val < low){
            return _trimBST(root->right,low,high);
        }
        if(root->val > high){
            return _trimBST(root->left,low,high);
        }

        // 当前root的值符合范围，递归左子树和右子树，剔除不符合条件的节点
        root->left = _trimBST(root->left,low,high);
        root->right = _trimBST(root->right,low,high);
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return root;
        }
        return _trimBST(root,low,high);
    }
};

// https://leetcode.cn/problems/trim-a-binary-search-tree/