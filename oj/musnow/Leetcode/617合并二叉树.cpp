class Solution {
    TreeNode* _mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 如果一棵树为空了，就直接返回另外一棵树来拼接
        if(root1 == nullptr){
            return root2;
        }
        if(root2 == nullptr){
            return root1;
        }
        // 借用root1加上值
        root1->val += root2->val;
        // 这里因为root1和root2的遍历顺序都是一样的，所以肯定能匹配上
        root1->left = _mergeTrees(root1->left,root2->left);
        root1->right = _mergeTrees(root1->right,root2->right);
        return root1;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return _mergeTrees(root1,root2);
    }
};

// https://leetcode.cn/problems/merge-two-binary-trees/