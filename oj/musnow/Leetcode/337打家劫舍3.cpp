/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto ret = travelRob(root);
        return max(ret[0], ret[1]);
    }
    // 下标0代表不偷当前树，1代表偷当前树
    vector<int> travelRob(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        // 后续遍历
        auto left = travelRob(root->left);
        auto right = travelRob(root->right);
        // 1.偷当前树，则不能偷孩子
        int val1 = root->val + left[0] + right[0];
        // 2.不偷当前树，则孩子可以投也可以不偷，计算子树返回数组中的最大值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        // 返回数组
        return vector<int>({val2, val1});
    }
};

// https://leetcode.cn/problems/house-robber-iii/