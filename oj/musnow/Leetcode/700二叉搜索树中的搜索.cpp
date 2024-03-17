// https://leetcode.cn/problems/search-in-a-binary-search-tree/


class Solution {
    TreeNode* _searchBST(TreeNode* root,const int val) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == val){
            return root;
        }

        if(root->val > val){
            return _searchBST(root->left,val); // 左侧更小
        }
        else{
            return _searchBST(root->right,val); // 右侧更小
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        return _searchBST(root,val);
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // 用循环也可以
        while(root != nullptr)
        {
            if(root->val == val){
                return root;
            }
            
            if(root->val > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return nullptr;
    }
};