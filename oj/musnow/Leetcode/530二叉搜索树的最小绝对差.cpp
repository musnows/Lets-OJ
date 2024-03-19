class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    void _getMinimumDifference(TreeNode* root)
    {
        if(root == nullptr){
            return ;
        }
        // 遍历左侧
        _getMinimumDifference(root->left);

        // 计算差值
        if(prev != nullptr){
            minDiff = min(minDiff,root->val - prev->val);
        }
        // 所有情况都需要更新prev
        prev = root;
      
        // 遍历右侧
        _getMinimumDifference(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        _getMinimumDifference(root);
        return minDiff;
    }
};

// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/