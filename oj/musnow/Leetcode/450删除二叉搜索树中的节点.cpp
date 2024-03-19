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
private:

    TreeNode* deleteOneNode(TreeNode* target) {
        if (target == nullptr) {
            return target;
        }
        // 右侧为空，无论如何都返回左侧
        if (target->right == nullptr) {
            return target->left;
        }
        // 右侧不为空，统一处理，找到右子树的最左侧节点，进行链接
        TreeNode* cur = target->right;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* cur = root;
        TreeNode* pre = nullptr; // 记录cur的父节点，用来删除cur
        while (cur != nullptr) {
            if (cur->val == key) {
                break;
            }

            pre = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (pre == nullptr) { // 如果搜索树只有头结点
            return deleteOneNode(cur);
        }
        // 判断删左孩子还是右孩子
        if (pre->left != nullptr && pre->left == cur) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right != nullptr && pre->right == cur) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};


// https://leetcode.cn/problems/delete-node-in-a-bst/