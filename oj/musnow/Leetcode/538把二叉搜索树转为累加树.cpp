class Solution {
    int sum  = 0;
    TreeNode* _convertBST(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        _convertBST(root->right);
        sum += root->val;
        root->val = sum;
        _convertBST(root->left);
        return root;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        return _convertBST(root);
    }
};

// https://leetcode.cn/problems/convert-bst-to-greater-tree/