class Solution {
public:
    int _sumOfLeftLeaves(TreeNode* root)
    {
        // 根节点为空，跳过
        if(root == nullptr){
            return 0;
        }
        // 叶子节点，跳过（因为左侧叶子节点不存在，值视作为0）
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
        int left = 0;
        // 判断左侧是否为叶子节点
        if(root->left && root->left->left == nullptr && root->left->right==nullptr)
        {
            left = root->left->val; // 左侧叶子节点的值
        }
        else
        {
            left = _sumOfLeftLeaves(root->left);// 遍历左侧
        }
        
        // 遍历右侧
        int right = _sumOfLeftLeaves(root->right);

        return right + left;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return _sumOfLeftLeaves(root);
    }
};
// https://leetcode.cn/problems/sum-of-left-leaves/