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
    // 两棵树按相同的方式进行遍历，就能判断出来
    bool _isSameTree(TreeNode* p, TreeNode* q) {
        // 两个都为空，相同
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // 有一个为空，不相同
        if (p == nullptr && q != nullptr) {
            return false;
        }
        if (p != nullptr && q == nullptr) {
            return false;
        }
        // 值不相同
        if (p->val != q->val) {
            return false;
        }
        // 同时递归判断左右子树
        bool left = _isSameTree(p->left, q->left);
        bool right = _isSameTree(p->right, q->right);
        return left && right; // 左右子树都相同才是同一棵树
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) { return _isSameTree(p, q); }
};
