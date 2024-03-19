class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* cur = root;
        // 找到q和p中的最小值
        int min = q->val,max = p->val;
        if(min > max){
            min = max;
            max = q->val;
        }

        while(cur != nullptr)
        {
            // 符合条件
            if(cur->val >= min && cur->val <= max)
            {
                return cur;
            }
            // 如果大了，就往左走
            if(cur->val > max){
                cur = cur->left;
            }
            // 小了就往右边走
            if(cur->val < min){
                cur = cur->right;
            }
        }
        return nullptr;
    }
};

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/