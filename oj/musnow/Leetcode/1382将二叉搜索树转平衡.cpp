class Solution {
    // 中序遍历转数组
    void treeToVector(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        treeToVector(root->left,v);
        v.push_back(root->val);
        treeToVector(root->right,v);
    }

    TreeNode* vectorToBanlanceBST(vector<int>& v, int left, int right) {
        // right是开区间，left=right的情况也是无效的
        if (left >= right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = vectorToBanlanceBST(v, left, mid);
        root->right = vectorToBanlanceBST(v, mid + 1, right);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        vector<int> v;
        // 先用中序遍历转成数组（题目给的已经是一个二叉搜索树，中序遍历肯定有序）
        treeToVector(root, v);
        // 然后用108有序数组转成二叉平衡树的思路来转换
        return vectorToBanlanceBST(v, 0, v.size());
    }
};
