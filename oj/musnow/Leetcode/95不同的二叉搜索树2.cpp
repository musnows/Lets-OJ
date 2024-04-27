class Solution {
    vector<TreeNode*> _generateTrees(int begin, int end) {
        // 两个区间越界，返回空
        if (begin > end) {
            return {nullptr};
        }
        vector<TreeNode*> curTree; // 当前层可能的树的集合
        for (int i = begin; i <= end; i++) {
            // 获取左右子树的可能的树的集合，而不是单个树（递归子区间的树集合，直到空节点）
            vector<TreeNode*> leftTree = _generateTrees(begin, i - 1);
            vector<TreeNode*> rightTree = _generateTrees(i + 1, end);
            // 遍历左右子树，构造可能的树的集合
            // 如果是叶子节点，此时left和right应该都是一个{nullptr}
            for (auto& left : leftTree) {
                for (auto& right : rightTree) {
                    // 直接用构造函数传参
                    TreeNode* root = new TreeNode(i, left, right);
                    curTree.push_back(root);
                }
            }
        }
        // 返回给上一层
        return curTree;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        // 递归生成1到n的树
        return _generateTrees(1, n);
    }
};